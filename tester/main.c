#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

// ==========================================
// OS detection and basic settings
// ==========================================

#if defined(_WIN32)
    #include <windows.h>
    #include <direct.h> // for _mkdir
    #define LIB_EXT ".dll"
    #define PATH_SEP "\\"
    #define MKDIR(d) _mkdir(d)

    // Windows wrappers to look more POSIX-like
    #define DL_HANDLE HMODULE
    #define DL_OPEN(lib) LoadLibrary(lib)
    #define DL_SYM(h, name) GetProcAddress(h, name)
    #define DL_CLOSE(h) FreeLibrary(h)
    #define DL_ERROR() "Win32 LoadLibrary Error"
#else
    #include <unistd.h>
    #include <dlfcn.h>
    #include <pthread.h>
    #define PATH_SEP "/"
    #define MKDIR(d) mkdir(d, 0777)

    #define DL_HANDLE void*
    #define DL_OPEN(lib) dlopen(lib, RTLD_LAZY)
    #define DL_SYM(h, name) dlsym(h, name)
    #define DL_CLOSE(h) dlclose(h)
    #define DL_ERROR() dlerror()

    #if defined(__APPLE__)
        #define LIB_EXT ".dylib"
    #else
        #define LIB_EXT ".so"
    #endif
#endif

// ==========================================
// Simulation settings
// ==========================================

#define SIMULATED_DURATION_SEC (6 * 3600) // 6 hours
#define CPU_USAGE_PERCENTAGE 0.8f
#define VIDEO_NAME "test_video_6h"

// Library base names (without extension)
#define BASE_NAME_FILTER "filter"
#define BASE_NAME_POS    "positiveness"
#define BASE_NAME_SAMP   "samp"

// ==========================================
// Portable RNG (LCG) for reproducible results
// ==========================================

static unsigned int g_seed = 123456789;

void portable_srand(unsigned int seed) {
    g_seed = seed;
}

// Returns a value in [0, 32767] (like rand())
int portable_rand() {
    g_seed = g_seed * 1103515245 + 12345;
    return (unsigned int)(g_seed / 65536) % 32768;
}

// ==========================================
// Types
// ==========================================

typedef void   (*VideoInferenceFunc)(float* frames, int num_frames,
                                     float* results, int* progress);
typedef double (*PredictSAMPFunc)(const char* epp_path, const char* efp_path);

typedef struct {
    int start_index;
    int num_frames_chunk;
    int width;
    int height;
    int output_dim;
    float* frames_buffer;
    float* results_buffer;
    int* progress_ptr;         // shared progress counter from the library
    volatile int* done_flag;   // per-thread "I'm finished" flag
    VideoInferenceFunc inference_func;
} ThreadData;

// Global function pointers to dynamically loaded symbols
VideoInferenceFunc filter_VideoInference        = NULL;
VideoInferenceFunc positiveness_VideoInference  = NULL;
PredictSAMPFunc    predictSAMP                  = NULL;

// ==========================================
// Helper functions
// ==========================================

int get_available_cores() {
#if defined(_WIN32)
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return (int)sysinfo.dwNumberOfProcessors;
#else
    long nprocs = sysconf(_SC_NPROCESSORS_ONLN);
    return (nprocs < 1) ? 1 : (int)nprocs;
#endif
}

// Choose frame sampling interval (in seconds) based on total video duration
int GetFrameSecInterval(double totalSeconds) {
    if (totalSeconds <= 20 * 60) return 1;
    if (totalSeconds <= 1 * 3600) return 2;
    if (totalSeconds <= 1.8 * 3600) return 3;
    if (totalSeconds <= 2.1 * 3600) return 4;
    if (totalSeconds <= 3 * 3600) return 5;
    return 6;
}

// Check whether an RGB frame is mostly dark (average intensity below threshold)
int IsFrameMostlyDark(float* frame_start, int w, int h, float threshold) {
    double sum = 0;
    int count = 0;
    int pixel_count = w * h;
    float* ch0 = frame_start;
    float* ch1 = frame_start + pixel_count;
    float* ch2 = frame_start + (pixel_count * 2);

    for (int i = 0; i < pixel_count; i++) {
        sum += (ch0[i] + ch1[i] + ch2[i]) / 3.0f;
        count++;
    }
    return ((float)(sum / count)) < threshold;
}

// Generate synthetic/random frames (data source for models)
void GenerateRandomFrames(float* frames, int num_frames, int w, int h, int useImageNetMean) {
    printf("Generating frames (%d frames, %dx%d)...\n", num_frames, w, h);

    float meanValues[3] = { 104.00698793f, 116.66876762f, 122.67891434f };
    long long pixel_per_frame = (long long)h * w;
    long long channel_stride  = pixel_per_frame;
    long long frame_stride    = channel_stride * 3;

    // Reset the seed before each generation so data for Filter and Positiveness
    // are reproducible and independent of the call order.
    portable_srand(42);

    for (int i = 0; i < num_frames; i++) {
        for (int c = 0; c < 3; c++) {
            for (int px = 0; px < pixel_per_frame; px++) {
                long long idx = (long long)i * frame_stride +
                                (long long)c * channel_stride +
                                px;

                float val = (float)(portable_rand() % 256);

                if (useImageNetMean) {
                    frames[idx] = val - meanValues[c];
                } else {
                    frames[idx] = val / 255.0f;
                }
            }
        }
    }
}

void SaveResults(const char* filename, int num_frames, int interval,
                 float* results, int dim) {
    FILE* f = fopen(filename, "wb");
    if (!f) {
        printf("Error opening %s\n", filename);
        return;
    }
    fwrite(&num_frames, sizeof(int), 1, f);
    fwrite(&interval, sizeof(int), 1, f);
    fwrite(results, sizeof(float), (size_t)num_frames * dim, f);
    fclose(f);
    printf("Saved %s\n", filename);
}

// Format seconds -> h, m, s
static void format_hms(int total_seconds, int* h, int* m, int* s) {
    if (total_seconds < 0) total_seconds = 0;
    *h = total_seconds / 3600;
    *m = (total_seconds % 3600) / 60;
    *s = total_seconds % 60;
}

// Print progress and ETA for a model
static void print_progress(const char* modelName,
                           int progress, int total,
                           time_t start_time) {
    if (total <= 0) {
        printf("\r[%s] Waiting... (unknown total)", modelName);
        fflush(stdout);
        return;
    }

    if (progress < 0)     progress = 0;
    if (progress > total) progress = total;

    double elapsed_d = difftime(time(NULL), start_time);
    int elapsed = (int)elapsed_d;
    int eta = -1;

    if (progress > 0 && progress < total && elapsed > 0) {
        eta = (int)(elapsed_d * (double)(total - progress) / (double)progress);
    } else if (progress >= total) {
        eta = 0;
    }

    int e_h, e_m, e_s;
    format_hms(elapsed, &e_h, &e_m, &e_s);

    int eta_h = 0, eta_m = 0, eta_s = 0;
    if (eta >= 0) {
        format_hms(eta, &eta_h, &eta_m, &eta_s);
    }

    int percent = (int)((double)progress * 100.0 / (double)total + 0.5);
    if (percent > 100) percent = 100;

    if (eta >= 0) {
        printf("\r[%s] %3d%% | elapsed %02d:%02d:%02d | ETA %02d:%02d:%02d   ",
               modelName, percent,
               e_h, e_m, e_s,
               eta_h, eta_m, eta_s);
    } else {
        printf("\r[%s] %3d%% | elapsed %02d:%02d:%02d | ETA --:--:--        ",
               modelName, percent,
               e_h, e_m, e_s);
    }
    fflush(stdout);
}

// Simple cross‑platform sleep in milliseconds
static void portable_sleep_ms(int ms) {
#if defined(_WIN32)
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

// ==========================================
// Thread wrappers
// ==========================================

#if defined(_WIN32)
DWORD WINAPI ThreadRoutineWin(LPVOID lpParam) {
    ThreadData* data = (ThreadData*)lpParam;
    long long frame_size = (long long)3 * data->height * data->width;

    data->inference_func(
        data->frames_buffer + ((long long)data->start_index * frame_size),
        data->num_frames_chunk,
        data->results_buffer + ((long long)data->start_index * data->output_dim),
        data->progress_ptr   // shared progress counter from library
    );

    if (data->done_flag) {
        *(data->done_flag) = 1;
    }
    return 0;
}
#else
void* ThreadRoutinePosix(void* lpParam) {
    ThreadData* data = (ThreadData*)lpParam;
    long long frame_size = (long long)3 * data->height * data->width;

    data->inference_func(
        data->frames_buffer + ((long long)data->start_index * frame_size),
        data->num_frames_chunk,
        data->results_buffer + ((long long)data->start_index * data->output_dim),
        data->progress_ptr   // shared progress counter from library
    );

    if (data->done_flag) {
        *(data->done_flag) = 1;
    }
    return NULL;
}
#endif

// ==========================================
// Multithreaded inference with progress/ETA
// ==========================================

void RunInference(const char* modelName,
                  VideoInferenceFunc func,
                  int num_frames,
                  int w, int h,
                  int out_dim,
                  int isPositiveness,
                  int interval,
                  float* shared_frames_ptr) 
{
    printf("Processing %s model...\n", modelName);

    float* results = (float*)malloc((size_t)num_frames * out_dim * sizeof(float));
    if (!results) {
        printf("Failed to allocate results buffer.\n");
        return;
    }

    int numThreads = (int)(get_available_cores() * CPU_USAGE_PERCENTAGE);
    if (numThreads < 1) numThreads = 1;
    if (numThreads > num_frames) numThreads = num_frames;

    printf("Threads: %d\n", numThreads);

    ThreadData* tData = (ThreadData*)malloc(numThreads * sizeof(ThreadData));
    if (!tData) {
        printf("Failed to allocate thread data.\n");
        free(results);
        return;
    }

    int* prog = (int*)malloc(sizeof(int));
    if (!prog) {
        printf("Failed to allocate progress counter.\n");
        free(tData);
        free(results);
        return;
    }
    *prog = 0;

    volatile int* doneFlags = (volatile int*)calloc(numThreads, sizeof(int));
    if (!doneFlags) {
        printf("Failed to allocate done flags.\n");
        free(prog);
        free(tData);
        free(results);
        return;
    }

    int framesPerThread = num_frames / numThreads;

#if defined(_WIN32)
    HANDLE* threads = (HANDLE*)malloc(numThreads * sizeof(HANDLE));
    if (!threads) {
        printf("Failed to allocate thread handles.\n");
        free((void*)doneFlags);
        free(prog);
        free(tData);
        free(results);
        return;
    }

    for (int i = 0; i < numThreads; i++) {
        int start = i * framesPerThread;
        int end   = (i == numThreads - 1) ? num_frames : (start + framesPerThread);

        tData[i].start_index      = start;
        tData[i].num_frames_chunk = end - start;
        tData[i].width            = w;
        tData[i].height           = h;
        tData[i].output_dim       = out_dim;
        tData[i].frames_buffer    = shared_frames_ptr;
        tData[i].results_buffer   = results;
        tData[i].progress_ptr     = prog;              // shared between all threads (for library)
        tData[i].done_flag        = &doneFlags[i];     // per-thread done flag
        tData[i].inference_func   = func;

        threads[i] = CreateThread(NULL, 0, ThreadRoutineWin, &tData[i], 0, NULL);
    }
#else
    pthread_t* threads = (pthread_t*)malloc(numThreads * sizeof(pthread_t));
    if (!threads) {
        printf("Failed to allocate thread handles.\n");
        free((void*)doneFlags);
        free(prog);
        free(tData);
        free(results);
        return;
    }

    for (int i = 0; i < numThreads; i++) {
        int start = i * framesPerThread;
        int end   = (i == numThreads - 1) ? num_frames : (start + framesPerThread);

        tData[i].start_index      = start;
        tData[i].num_frames_chunk = end - start;
        tData[i].width            = w;
        tData[i].height           = h;
        tData[i].output_dim       = out_dim;
        tData[i].frames_buffer    = shared_frames_ptr;
        tData[i].results_buffer   = results;
        tData[i].progress_ptr     = prog;              // shared between all threads (for library)
        tData[i].done_flag        = &doneFlags[i];     // per-thread done flag
        tData[i].inference_func   = func;

        pthread_create(&threads[i], NULL, ThreadRoutinePosix, &tData[i]);
    }
#endif

    // Progress + ETA loop
    // We use *prog only for display, not for termination.
    time_t start_time      = time(NULL);
    time_t last_print_time = start_time - 1;
    int    last_progress   = -1;

    while (1) {
        // Check if all threads are done (based on doneFlags)
        int allDone = 1;
        for (int i = 0; i < numThreads; i++) {
            if (!doneFlags[i]) {
                allDone = 0;
                break;
            }
        }

        int current = *prog;
        if (current < 0) current = 0;
        if (current > num_frames) current = num_frames;

        time_t now = time(NULL);
        if ((current != last_progress || allDone) &&
            (difftime(now, last_print_time) >= 1.0 || allDone)) {

            print_progress(modelName, current, num_frames, start_time);
            last_print_time = now;
            last_progress   = current;
        }

        if (allDone) {
            break;
        }

        portable_sleep_ms(200);
    }

    // Ensure final 100% line (even if library lost some increments in *prog)
    print_progress(modelName, num_frames, num_frames, start_time);
    printf("\n");

#if defined(_WIN32)
    WaitForMultipleObjects(numThreads, threads, TRUE, INFINITE);
    for (int i = 0; i < numThreads; i++) {
        CloseHandle(threads[i]);
    }
    free(threads);
#else
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }
    free(threads);
#endif

    free((void*)doneFlags);
    free(tData);
    free(prog);

    // Post-processing for the Filter model: mark dark frames as [-1, -1, -1]
    if (!isPositiveness) {
        printf("Applying post-processing for dark frames...\n");
        long long frame_stride = (long long)w * h * 3;
        for (int i = 0; i < num_frames; i++) {
            if (IsFrameMostlyDark(shared_frames_ptr + (i * frame_stride), w, h, 0.02f)) {
                for (int k = 0; k < 3; k++) {
                    results[i * 3 + k] = -1.0f;
                }
            }
        }
    }

    MKDIR("Output");
    char path[256];
    sprintf(path, "Output%s%s.%s", PATH_SEP, VIDEO_NAME, isPositiveness ? "epp" : "efp");
    SaveResults(path, num_frames, interval, results, out_dim);

    free(results);
}

// ==========================================
// MAIN
// ==========================================

int main() {
    // 1. Build library file names
    char libNameFilter[128], libNamePos[128], libNameSamp[128];

#if !defined(_WIN32)
    snprintf(libNameFilter, sizeof(libNameFilter), "./%s%s", BASE_NAME_FILTER, LIB_EXT);
    snprintf(libNamePos,    sizeof(libNamePos),    "./%s%s", BASE_NAME_POS,    LIB_EXT);
    snprintf(libNameSamp,   sizeof(libNameSamp),   "./%s%s", BASE_NAME_SAMP,   LIB_EXT);
#else
    snprintf(libNameFilter, sizeof(libNameFilter), "%s%s", BASE_NAME_FILTER, LIB_EXT);
    snprintf(libNamePos,    sizeof(libNamePos),    "%s%s", BASE_NAME_POS,    LIB_EXT);
    snprintf(libNameSamp,   sizeof(libNameSamp),   "%s%s", BASE_NAME_SAMP,   LIB_EXT);
#endif

    printf("Loading libs: %s, %s, %s\n", libNameFilter, libNamePos, libNameSamp);

    DL_HANDLE hFilter = DL_OPEN(libNameFilter);
    DL_HANDLE hPos    = DL_OPEN(libNamePos);
    DL_HANDLE hSamp   = DL_OPEN(libNameSamp);

    if (!hFilter || !hPos || !hSamp) {
        printf("Error loading libraries.\nLast Error: %s\n", DL_ERROR());
        return 1;
    }

    // Load exported functions from libraries
    filter_VideoInference       = (VideoInferenceFunc)DL_SYM(hFilter, "filter_VideoInference");
    positiveness_VideoInference = (VideoInferenceFunc)DL_SYM(hPos,    "positiveness_VideoInference");
    predictSAMP                 = (PredictSAMPFunc)   DL_SYM(hSamp,   "predictSAMP");

    if (!filter_VideoInference || !positiveness_VideoInference || !predictSAMP) {
        printf("Error locating functions in libraries.\n");
        DL_CLOSE(hFilter);
        DL_CLOSE(hPos);
        DL_CLOSE(hSamp);
        return 1;
    }

    // 2. Simulation logic
    int interval        = GetFrameSecInterval(SIMULATED_DURATION_SEC);
    int frame_interval  = 30 * interval; // 30 fps * seconds per sampled frame
    int num_frames      = (int)(SIMULATED_DURATION_SEC * 30) / frame_interval;

    // Positiveness model (227x227, 2D output)
    float* frames = (float*)malloc((size_t)num_frames * 3 * 227 * 227 * sizeof(float));
    if (frames) {
        GenerateRandomFrames(frames, num_frames, 227, 227, 1); // ImageNet mean
        RunInference("Positiveness", positiveness_VideoInference,
                     num_frames, 227, 227, 2, 1, interval, frames);
        free(frames);
    } else {
        printf("Failed to allocate frames for Positiveness.\n");
    }

    // Filter model (224x224, 3D output)
    frames = (float*)malloc((size_t)num_frames * 3 * 224 * 224 * sizeof(float));
    if (frames) {
        GenerateRandomFrames(frames, num_frames, 224, 224, 0); // [0,1] scaling
        RunInference("Filter", filter_VideoInference,
                     num_frames, 224, 224, 3, 0, interval, frames);
        free(frames);
    } else {
        printf("Failed to allocate frames for Filter.\n");
    }

    // Final SAMP classification
    char epp[256], efp[256];
    sprintf(epp, "Output%s%s.epp", PATH_SEP, VIDEO_NAME);
    sprintf(efp, "Output%s%s.efp", PATH_SEP, VIDEO_NAME);

    double rating = predictSAMP(epp, efp);

    printf("------------------------------------------------\n");
    printf("Result Rating Value: %f\n", rating); // Ref: 0.538838
    if (rating == 2.0) {
        printf("Status: UNSAFE (Blocked)\n");
    } else {
        const char* mpaa = "R";
        if (rating < 0.0796)      mpaa = "G";
        else if (rating < 0.216)  mpaa = "PG";
        else if (rating < 0.464)  mpaa = "PG-13";
        printf("Status: Safe, MPAA: %s\n", mpaa);
    }
    printf("------------------------------------------------\n");

    DL_CLOSE(hFilter);
    DL_CLOSE(hPos);
    DL_CLOSE(hSamp);

    return 0;
}
