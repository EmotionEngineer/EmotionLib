#ifndef POSITIVENESS_TENSOR_H_
#define POSITIVENESS_TENSOR_H_

#include "common.h"

struct tensors;

LIB_HIDDEN extern struct tensors *
tensors_create (int *error);

LIB_HIDDEN extern void
tensors_destroy (struct tensors **pp);

union tensor_union_0 {
float tensor_conv1[1][96][55][55];
float tensor_pool1[1][96][27][27];
float tensor_conv2[1][256][27][27];
float tensor_pool2[1][256][13][13];
float tensor_conv3[1][384][13][13];
float tensor_conv4[1][384][13][13];
float tensor_conv5[1][256][13][13];
float tensor_pool5[1][256][6][6];
float tensor_fc6[1][4096];
float tensor_fc7[1][4096];
float tensor_fc8[1][2];
};

union tensor_union_1 {
float tensor_relu1[1][96][55][55];
float tensor_norm1[1][96][27][27];
float tensor_relu2[1][256][27][27];
float tensor_norm2[1][256][13][13];
float tensor_relu3[1][384][13][13];
float tensor_relu4[1][384][13][13];
float tensor_relu5[1][256][13][13];
float tensor_fc6_Reshape[1][9216];
float tensor_relu6[1][4096];
float tensor_relu7[1][4096];
};

struct tensors {
	union tensor_union_0 tu0;
	union tensor_union_1 tu1;
};

#endif // POSITIVENESS_TENSOR_H_
