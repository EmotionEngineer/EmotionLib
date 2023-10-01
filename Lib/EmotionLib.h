#ifndef EMOTIONLIB_H_
#define EMOTIONLIB_H_

#if defined(_MSC_VER) || defined(_WIN32)
# define EMOTIONLIB_API_EXPORT  __declspec(dllexport)
#else
# define EMOTIONLIB_API_EXPORT  __attribute__((visibility("default")))
#endif

typedef float EmotionLibImage[3][224][224];
typedef float EmotionLibPrediction[4];

// Image inference
EMOTIONLIB_API_EXPORT void
EmotionLib_imageSentiment (EmotionLibImage const *image,
                           EmotionLibPrediction  *result);

// Video inference
EMOTIONLIB_API_EXPORT void
EmotionLib_videoSentiment (EmotionLibImage const *frames,
                           int                    num_frames,
                           EmotionLibPrediction  *results,
                           int                   *progress);

#undef EMOTIONLIB_API_EXPORT

#endif // EMOTIONLIB_H_
