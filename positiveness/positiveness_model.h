#ifndef POSITIVENESS_MODEL_H_
#define POSITIVENESS_MODEL_H_

#include "positiveness.h"
#include "positiveness_tensor.h"

LIB_HIDDEN void
model_infer (struct tensors *ts,
             ModelInput const *image,
             ModelOut *result);

#endif // POSITIVENESS_MODEL_H_
