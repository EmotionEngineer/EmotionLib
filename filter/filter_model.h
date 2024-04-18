#ifndef FILTER_MODEL_H_
#define FILTER_MODEL_H_

#include "filter.h"

#include "filter_tensor.h"

LIB_HIDDEN void
model_infer (struct tensors *ts,
             ModelInput const *image,
             ModelOut *result);

#endif // FILTER_MODEL_H_
