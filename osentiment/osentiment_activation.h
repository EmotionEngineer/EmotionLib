#ifndef OSENTIMENT_ACTIVATION_H_
#define OSENTIMENT_ACTIVATION_H_

#include <stdint.h>

#include "common.h"

LIB_HIDDEN extern void node_conv1( const float x[1][3][227][227], const float w[96][3][11][11], const float bias[96], float y[1][96][55][55] );
LIB_HIDDEN extern void node_relu1( const float X[1][96][55][55], float Y[1][96][55][55] );
LIB_HIDDEN extern void node_pool1( const float x[1][96][55][55], float y[1][96][27][27] );
LIB_HIDDEN extern void node_norm1( const float X[1][96][27][27], float Y[1][96][27][27] );
LIB_HIDDEN extern void node_conv2( const float x[1][96][27][27], const float w[256][48][5][5], const float bias[256], float y[1][256][27][27] );
LIB_HIDDEN extern void node_relu2( const float X[1][256][27][27], float Y[1][256][27][27] );
LIB_HIDDEN extern void node_pool2( const float x[1][256][27][27], float y[1][256][13][13] );
LIB_HIDDEN extern void node_norm2( const float X[1][256][13][13], float Y[1][256][13][13] );
LIB_HIDDEN extern void node_conv3( const float x[1][256][13][13], const float w[384][256][3][3], const float bias[384], float y[1][384][13][13] );
LIB_HIDDEN extern void node_relu3( const float X[1][384][13][13], float Y[1][384][13][13] );
LIB_HIDDEN extern void node_conv4( const float x[1][384][13][13], const float w[384][192][3][3], const float bias[384], float y[1][384][13][13] );
LIB_HIDDEN extern void node_relu4( const float X[1][384][13][13], float Y[1][384][13][13] );
LIB_HIDDEN extern void node_conv5( const float x[1][384][13][13], const float w[256][192][3][3], const float bias[256], float y[1][256][13][13] );
LIB_HIDDEN extern void node_relu5( const float X[1][256][13][13], float Y[1][256][13][13] );
LIB_HIDDEN extern void node_pool5( const float x[1][256][13][13], float y[1][256][6][6] );
LIB_HIDDEN extern void node_fc6_Reshape( const float data[1][256][6][6], const int64_t shape[2], float reshaped[1][9216] );
LIB_HIDDEN extern void node_fc6( const float A[1][9216], const float B[4096][9216], const float C[4096], float Y[1][4096] );
LIB_HIDDEN extern void node_relu6( const float X[1][4096], float Y[1][4096] );
LIB_HIDDEN extern void node_fc7( const float A[1][4096], const float B[4096][4096], const float C[4096], float Y[1][4096] );
LIB_HIDDEN extern void node_relu7( const float X[1][4096], float Y[1][4096] );
LIB_HIDDEN extern void node_fc8( const float A[1][4096], const float B[2][4096], const float C[2], float Y[1][2] );
LIB_HIDDEN extern void node_prob( const float input[1][2], float output[1][2] );

#endif // OSENTIMENT_ACTIVATION_H_
