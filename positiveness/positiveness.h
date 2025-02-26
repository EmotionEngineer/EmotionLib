#ifndef POSITIVENESS_H_
#define POSITIVENESS_H_

#if defined(_MSC_VER) || defined(_WIN32)
# define POSITIVENESS_API_EXPORT  __declspec(dllexport)
#else
# define POSITIVENESS_API_EXPORT  __attribute__((visibility("default")))
#endif

typedef float ModelInput[3][227][227]; // NCHW BGR, ImageNet weights scale ≈ [0..128]
typedef float ModelOut[2];

// Model inference
POSITIVENESS_API_EXPORT void
positiveness_Inference (ModelInput const *image,
                       ModelOut  *result);

// Video inference
POSITIVENESS_API_EXPORT void
positiveness_VideoInference (ModelInput const *frames,
                       int                    num_frames,
                       ModelOut  *results,
                       int                   *progress);

#undef POSITIVENESS_API_EXPORT

#endif // POSITIVENESS_H_
