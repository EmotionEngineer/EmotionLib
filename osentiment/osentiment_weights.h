#ifndef OSENTIMENT_WEIGHTS_H_
#define OSENTIMENT_WEIGHTS_H_

#include <stdint.h>
#include "common.h"

LIB_HIDDEN extern const float tensor_conv1_W[96][3][11][11];
LIB_HIDDEN extern const float tensor_conv1_b[96];
LIB_HIDDEN extern const float tensor_conv2_W[256][48][5][5];
LIB_HIDDEN extern const float tensor_conv2_b[256];
LIB_HIDDEN extern const float tensor_conv3_W[384][256][3][3];
LIB_HIDDEN extern const float tensor_conv3_b[384];
LIB_HIDDEN extern const float tensor_conv4_W[384][192][3][3];
LIB_HIDDEN extern const float tensor_conv4_b[384];
LIB_HIDDEN extern const float tensor_conv5_W[256][192][3][3];
LIB_HIDDEN extern const float tensor_conv5_b[256];
LIB_HIDDEN extern const int64_t tensor_fc6_shape[2];
LIB_HIDDEN extern const float tensor_fc6_W[4096][9216];
LIB_HIDDEN extern const float tensor_fc6_B[4096];
LIB_HIDDEN extern const float tensor_fc7_W[4096][4096];
LIB_HIDDEN extern const float tensor_fc7_B[4096];
LIB_HIDDEN extern const float tensor_fc8_W[2][4096];
LIB_HIDDEN extern const float tensor_fc8_B[2];

#endif // OSENTIMENT_WEIGHTS_H_
