#ifndef EMOTIONLIB_MODEL_H_
#define EMOTIONLIB_MODEL_H_

#include "EmotionLib.h"
#include "tensor.h"

LIB_HIDDEN extern void
model_infer (struct tensors        *ts,
             EmotionLibImage const *image,
             EmotionLibPrediction  *result);

#endif // EMOTIONLIB_MODEL_H_
