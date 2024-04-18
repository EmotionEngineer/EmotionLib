#ifndef FILTER_H_
#define FILTER_H_

#if defined(_MSC_VER) || defined(_WIN32)
# define FILTER_API_EXPORT  __declspec(dllexport)
#else
# define FILTER_API_EXPORT  __attribute__((visibility("default")))
#endif

typedef float ModelInput[3][224][224]; // NCHW
typedef float ModelOut[3];

// Model inference
FILTER_API_EXPORT void
filter_Inference (ModelInput const *image,
                  ModelOut  *result);

// Video inference
FILTER_API_EXPORT void
filter_VideoInference (ModelInput const *frames,
                       int                    num_frames,
                       ModelOut  *results,
                       int                   *progress);

#undef FILTER_API_EXPORT

#endif // FILTER_H_
