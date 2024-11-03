#ifndef OSENTIMENT_H_
#define OSENTIMENT_H_

#if defined(_MSC_VER) || defined(_WIN32)
# define OSENTIMENT_API_EXPORT  __declspec(dllexport)
#else
# define OSENTIMENT_API_EXPORT  __attribute__((visibility("default")))
#endif

typedef float ModelInput[3][227][227]; // NCHW BGR
typedef float ModelOut[2];

// Model inference
OSENTIMENT_API_EXPORT void
osentiment_Inference (ModelInput const *image,
                       ModelOut  *result);

// Video inference
OSENTIMENT_API_EXPORT void
osentiment_VideoInference (ModelInput const *frames,
                       int                    num_frames,
                       ModelOut  *results,
                       int                   *progress);

#undef OSENTIMENT_API_EXPORT

#endif // OSENTIMENT_H_
