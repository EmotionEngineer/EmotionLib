#ifndef OSENTIMENT_MODEL_H_
#define OSENTIMENT_MODEL_H_

#include "osentiment.h"

#include "osentiment_tensor.h"

LIB_HIDDEN void
model_infer (struct tensors *ts,
             ModelInput const *image,
             ModelOut *result);

#endif // OSENTIMENT_MODEL_H_
