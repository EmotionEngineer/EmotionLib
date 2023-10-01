#ifndef ACTIVATION_H_
#define ACTIVATION_H_

#include <stdint.h>

#include "common.h"

LIB_HIDDEN extern void
add_1_896_14_14 (const float A[1][896][14][14],
                 const float B[1][896][14][14],
                 float       C[1][896][14][14]);

LIB_HIDDEN extern void
fold_1_896_14_14 (const float A[1][896][14][14],
                  const float B[1],
                  float       C[1][896][14][14]);

LIB_HIDDEN extern void
mul_1_896_14_14 (const float A[1][896][14][14],
                 const float B[1][896][14][14],
                 float       C[1][896][14][14]);

LIB_HIDDEN extern void
sigmoid_1_896_14_14 (const float X[1][896][14][14],
                     float       Y[1][896][14][14]);

LIB_HIDDEN extern void
softplus_1_896_14_14 (const float X[1][896][14][14],
                      float       Y[1][896][14][14]);

LIB_HIDDEN extern void
tanh_1_896_14_14 (const float X[1][896][14][14],
                  float       Y[1][896][14][14]);

LIB_HIDDEN extern void
conv_1_896_14_14_w896_896_1_1_y1_896_14_14 (const float x[1][896][14][14],
                                            const float w[896][896][1][1],
                                            const float bias[896],
                                            float       y[1][896][14][14]);

LIB_HIDDEN extern void
add_1_448_28_28 (const float A[1][448][28][28],
                 const float B[1][448][28][28],
                 float       C[1][448][28][28]);

LIB_HIDDEN extern void
func_fe352416748 (const float A[1][448][28][28],
                  const float B[1][448][28][28],
                  float       C[1][448][28][28]);

LIB_HIDDEN extern void
tanh_1_448_28_28 (const float X[1][448][28][28],
                  float       Y[1][448][28][28]);

LIB_HIDDEN extern void
softplus_1_448_28_28 (const float X[1][448][28][28],
                      float       Y[1][448][28][28]);

LIB_HIDDEN extern void
sigmoid_1_448_28_28 (const float X[1][448][28][28],
                     float       Y[1][448][28][28]);

LIB_HIDDEN extern void
fold_1_448_28_28 (const float A[1][448][28][28],
                  const float B[1],
                  float       C[1][448][28][28]);

LIB_HIDDEN extern void
sigmoid_1_896_1_1 (const float X[1][896][1][1],
                   float       Y[1][896][1][1]);

LIB_HIDDEN extern void
sigmoid_1_224_1_1 (const float X[1][224][1][1],
                   float       Y[1][224][1][1]);

LIB_HIDDEN extern void
add_1_224_1_1 (const float A[1][224][1][1],
               const float B[1][224][1][1],
               float       C[1][224][1][1]);

LIB_HIDDEN extern void
func_7637f5931c0 (const float A[1][896][14][14],
                  const float B[1][896][1][1],
                  float       C[1][896][14][14]);

LIB_HIDDEN extern void
fold_1_224_1_1 (const float A[1][224][1][1],
                const float B[1],
                float       C[1][224][1][1]);

LIB_HIDDEN extern void
avgpool_1_896_14_14 (const float in[1][896][14][14],
                     float       out[1][896][1][1]);

LIB_HIDDEN extern void
func_3fd747a7427 (const float A[1][224][1][1],
                  const float B[1][224][1][1],
                  float       C[1][224][1][1]);

LIB_HIDDEN extern void
tanh_1_224_1_1 (const float X[1][224][1][1],
                float       Y[1][224][1][1]);

LIB_HIDDEN extern void
softplus_1_224_1_1 (const float X[1][224][1][1],
                    float       Y[1][224][1][1]);

LIB_HIDDEN extern void
func_dbbae7cbb81 (const float x[1][896][1][1],
                  const float w[224][896][1][1],
                  const float bias[224],
                  float       y[1][224][1][1]);

LIB_HIDDEN extern void
func_8c9c2b9a537 (const float x[1][896][14][14],
                  const float w[896][56][3][3],
                  const float bias[896],
                  float       y[1][896][14][14]);

LIB_HIDDEN extern void
func_24bd64319b5 (const float x[1][224][1][1],
                  const float w[896][224][1][1],
                  const float bias[896],
                  float       y[1][896][1][1]);

LIB_HIDDEN extern void
func_d83947690c8 (const float x[1][448][28][28],
                  const float w[448][448][1][1],
                  const float bias[448],
                  float       y[1][448][28][28]);

LIB_HIDDEN extern void
add_1_168_56_56 (const float A[1][168][56][56],
                 const float B[1][168][56][56],
                 float       C[1][168][56][56]);

LIB_HIDDEN extern void
softplus_1_168_56_56 (const float X[1][168][56][56],
                      float       Y[1][168][56][56]);

LIB_HIDDEN extern void
func_a8fcef9491d (const float X[1][168][56][56],
                  float       Y[1][168][56][56]);

LIB_HIDDEN extern void
func_7ae0037bce3 (const float A[1][168][56][56],
                  const float B[1][168][56][56],
                  float       C[1][168][56][56]);

LIB_HIDDEN extern void
tanh_1_168_56_56 (const float X[1][168][56][56],
                  float       Y[1][168][56][56]);

LIB_HIDDEN extern void
fold_1_168_56_56 (const float A[1][168][56][56],
                  const float B[1],
                  float       C[1][168][56][56]);

LIB_HIDDEN extern void
func_fe391e43ecd (const float X[1][112][1][1],
                  float       Y[1][112][1][1]);

LIB_HIDDEN extern void
softplus_1_112_1_1 (const float X[1][112][1][1],
                    float       Y[1][112][1][1]);

LIB_HIDDEN extern void
add_1_112_1_1 (const float A[1][112][1][1],
               const float B[1][112][1][1],
               float       C[1][112][1][1]);

LIB_HIDDEN extern void
func_9c5643a6f0a (const float X[1][448][1][1],
                  float       Y[1][448][1][1]);

LIB_HIDDEN extern void
tanh_1_112_1_1 (const float X[1][112][1][1],
                float       Y[1][112][1][1]);

LIB_HIDDEN extern void
avgpool_1_448_28_28 (const float in[1][448][28][28],
                     float       out[1][448][1][1]);

LIB_HIDDEN extern void
func_4e66d83a223 (const float A[1][112][1][1],
                  const float B[1][112][1][1],
                  float       C[1][112][1][1]);

LIB_HIDDEN extern void
func_33fbc985d50 (const float A[1][448][28][28],
                  const float B[1][448][1][1],
                  float       C[1][448][28][28]);

LIB_HIDDEN extern void
fold_1_112_1_1 (const float A[1][112][1][1],
                const float B[1],
                float       C[1][112][1][1]);

LIB_HIDDEN extern void
func_c2f45289b07 (const float x[1][448][28][28],
                  const float w[448][56][3][3],
                  const float bias[448],
                  float       y[1][448][28][28]);

LIB_HIDDEN extern void
func_a8d1ba02fec (const float x[1][168][56][56],
                  const float w[168][168][1][1],
                  const float bias[168],
                  float       y[1][168][56][56]);

LIB_HIDDEN extern void
add_1_2016_7_7 (const float A[1][2016][7][7],
                const float B[1][2016][7][7],
                float       C[1][2016][7][7]);

LIB_HIDDEN extern void
func_638785b3659 (const float x[1][112][1][1],
                  const float w[448][112][1][1],
                  const float bias[448],
                  float       y[1][448][1][1]);

LIB_HIDDEN extern void
func_190bd454425 (const float x[1][448][1][1],
                  const float w[112][448][1][1],
                  const float bias[112],
                  float       y[1][112][1][1]);

LIB_HIDDEN extern void
tanh_1_2016_7_7 (const float X[1][2016][7][7],
                 float       Y[1][2016][7][7]);

LIB_HIDDEN extern void
avgpool_1_168_56_56 (const float in[1][168][56][56],
                     float       out[1][168][1][1]);

LIB_HIDDEN extern void
avgpool_1_2016_7_7 (const float in[1][2016][7][7],
                    float       out[1][2016][1][1]);

LIB_HIDDEN extern void
fold_1_2016_7_7 (const float A[1][2016][7][7],
                 const float B[1],
                 float       C[1][2016][7][7]);

LIB_HIDDEN extern void
func_b7e2f9b2d8b (const float A[1][42][1][1],
                  const float B[1][42][1][1],
                  float       C[1][42][1][1]);

LIB_HIDDEN extern void
softplus_1_2016_7_7 (const float X[1][2016][7][7],
                     float       Y[1][2016][7][7]);

LIB_HIDDEN extern void
func_a9f65a497cb (const float A[1][2016][7][7],
                  const float B[1][2016][7][7],
                  float       C[1][2016][7][7]);

LIB_HIDDEN extern void
func_8e83ce12053 (const float X[1][42][1][1],
                  float       Y[1][42][1][1]);

LIB_HIDDEN extern void
func_673643b7d31 (const float A[1][168][56][56],
                  const float B[1][168][1][1],
                  float       C[1][168][56][56]);

LIB_HIDDEN extern void
softplus_1_42_1_1 (const float X[1][42][1][1],
                   float       Y[1][42][1][1]);

LIB_HIDDEN extern void
tanh_1_42_1_1 (const float X[1][42][1][1],
               float       Y[1][42][1][1]);

LIB_HIDDEN extern void
fold_1_42_1_1 (const float A[1][42][1][1],
               const float B[1],
               float       C[1][42][1][1]);

LIB_HIDDEN extern void
sigmoid_1_2016_7_7 (const float X[1][2016][7][7],
                    float       Y[1][2016][7][7]);

LIB_HIDDEN extern void
add_1_42_1_1 (const float A[1][42][1][1],
              const float B[1][42][1][1],
              float       C[1][42][1][1]);

LIB_HIDDEN extern void
func_0396437e541 (const float X[1][168][1][1],
                  float       Y[1][168][1][1]);

LIB_HIDDEN extern void
softplus_1_8_1_1 (const float X[1][8][1][1],
                  float       Y[1][8][1][1]);

LIB_HIDDEN extern void
sigmoid_1_8_1_1 (const float X[1][8][1][1],
                 float       Y[1][8][1][1]);

LIB_HIDDEN extern void
func_f737763e33a (const float x[1][168][1][1],
                  const float w[42][168][1][1],
                  const float bias[42],
                  float       y[1][42][1][1]);

LIB_HIDDEN extern void
func_f24b878e18a (const float x[1][168][56][56],
                  const float w[448][168][1][1],
                  const float bias[448],
                  float       y[1][448][56][56]);

LIB_HIDDEN extern void
func_e98ea15dc69 (const float X[1][896][28][28],
                  float       Y[1][896][28][28]);

LIB_HIDDEN extern void
matmul_2016_4 (const float A[1][2016],
               const float B[2016][4],
               float       Y[1][4]);

LIB_HIDDEN extern void
softplus_1_2016_14_14 (const float X[1][2016][14][14],
                       float       Y[1][2016][14][14]);

LIB_HIDDEN extern void
func_d76e9ccfb30 (const float X[1][2016][14][14],
                  float       Y[1][2016][14][14]);

LIB_HIDDEN extern void
func_d6ae3647f1b (const float A[1][168][112][112],
                  const float B[1][168][112][112],
                  float       C[1][168][112][112]);

LIB_HIDDEN extern void
fold_1_32_112_112 (const float A[1][32][112][112],
                   const float B[1],
                   float       C[1][32][112][112]);

LIB_HIDDEN extern void
func_d61c9a21a5c (const float x[1][2016][7][7],
                  const float w[2016][2016][1][1],
                  const float bias[2016],
                  float       y[1][2016][7][7]);

LIB_HIDDEN extern void
func_ce6378ecf4f (const float x[1][2016][14][14],
                  const float w[2016][56][3][3],
                  const float bias[2016],
                  float       y[1][2016][7][7]);

LIB_HIDDEN extern void
func_c6af25897cd (const float x[1][448][28][28],
                  const float w[896][448][1][1],
                  const float bias[896],
                  float       y[1][896][14][14]);

LIB_HIDDEN extern void
tanh_1_2016_14_14 (const float X[1][2016][14][14],
                   float       Y[1][2016][14][14]);

LIB_HIDDEN extern void
softmax_1_4 (const float in[1][4],
             float       out[1][4]);

LIB_HIDDEN extern void
func_c2fbc93cabe (const float A[1][2016][14][14],
                  const float B[1][2016][14][14],
                  float       C[1][2016][14][14]);

LIB_HIDDEN extern void
func_c288fe43fe8 (const float x[1][168][56][56],
                  const float w[448][168][1][1],
                  const float bias[448],
                  float       y[1][448][28][28]);

LIB_HIDDEN extern void
conv_1_112_1_1 (const float x[1][112][1][1],
                const float w[896][112][1][1],
                const float bias[896],
                float       y[1][896][1][1]);

LIB_HIDDEN extern void
softplus_1_448_56_56 (const float X[1][448][56][56],
                      float       Y[1][448][56][56]);

LIB_HIDDEN extern void
conv_1_896_14_14 (const float x[1][896][14][14],
                  const float w[2016][896][1][1],
                  const float bias[2016],
                  float       y[1][2016][7][7]);

LIB_HIDDEN extern void
fold_1_2016_14_14 (const float A[1][2016][14][14],
                   const float B[1],
                   float       C[1][2016][14][14]);

LIB_HIDDEN extern void
fold_1_896_28_28 (const float A[1][896][28][28],
                  const float B[1],
                  float       C[1][896][28][28]);

LIB_HIDDEN extern void
softplus_1_896_28_28 (const float X[1][896][28][28],
                      float       Y[1][896][28][28]);

LIB_HIDDEN extern void
tanh_1_896_28_28 (const float X[1][896][28][28],
                  float       Y[1][896][28][28]);

LIB_HIDDEN extern void
add_1_4 (const float A[1][4],
         const float B[4],
         float       C[1][4]);

LIB_HIDDEN extern void
tanh_1_168_112_112 (const float X[1][168][112][112],
                    float       Y[1][168][112][112]);

LIB_HIDDEN extern void
softplus_1_32_112_112 (const float X[1][32][112][112],
                       float       Y[1][32][112][112]);

LIB_HIDDEN extern void
func_9cf1befb936 (const float x[1][42][1][1],
                  const float w[168][42][1][1],
                  const float bias[168],
                  float       y[1][168][1][1]);

LIB_HIDDEN extern void
func_97b144c3b9a (const float X[1][168][112][112],
                  float       Y[1][168][112][112]);

LIB_HIDDEN extern void
add_1_168_112_112 (const float A[1][168][112][112],
                   const float B[1][168][112][112],
                   float       C[1][168][112][112]);

LIB_HIDDEN extern void
conv_1_896_14_14_w2016_896_1_1_y1_2016_14_14 (const float x[1][896][14][14],
                                              const float w[2016][896][1][1],
                                              const float bias[2016],
                                              float       y[1][2016][14][14]);

LIB_HIDDEN extern void
func_8e2441e0d80 (const float x[1][896][28][28],
                  const float w[896][56][3][3],
                  const float bias[896],
                  float       y[1][896][14][14]);

LIB_HIDDEN extern void
func_8d7ee594121 (const float x[1][448][28][28],
                  const float w[896][448][1][1],
                  const float bias[896],
                  float       y[1][896][28][28]);

LIB_HIDDEN extern void
conv_1_224_1_1_w2016_224_1_1_y1_2016_1_1 (const float x[1][224][1][1],
                                          const float w[2016][224][1][1],
                                          const float bias[2016],
                                          float       y[1][2016][1][1]);

LIB_HIDDEN extern void
conv_1_896_1_1_w112_896_1_1_y1_112_1_1 (const float x[1][896][1][1],
                                        const float w[112][896][1][1],
                                        const float bias[112],
                                        float       y[1][112][1][1]);

LIB_HIDDEN extern void
func_804a22f193b (const float x[1][3][224][224],
                  const float w[32][3][3][3],
                  const float bias[32],
                  float       y[1][32][112][112]);

LIB_HIDDEN extern void
func_7672188cb32 (const float x[1][168][112][112],
                  const float w[168][56][3][3],
                  const float bias[168],
                  float       y[1][168][56][56]);

LIB_HIDDEN extern void
func_74f52a68cb0 (const float X[1][32][112][112],
                  float       Y[1][32][112][112]);

LIB_HIDDEN extern void
func_743ae64fdb9 (const float X[1][448][56][56],
                  float       Y[1][448][56][56]);

LIB_HIDDEN extern void
func_6ba9e121261 (const float x[1][42][1][1],
                  const float w[448][42][1][1],
                  const float bias[448],
                  float       y[1][448][1][1]);

LIB_HIDDEN extern void
sigmoid_1_2016_1_1 (const float X[1][2016][1][1],
                    float       Y[1][2016][1][1]);

LIB_HIDDEN extern void
add_1_2016_14_14 (const float A[1][2016][14][14],
                  const float B[1][2016][14][14],
                  float       C[1][2016][14][14]);

LIB_HIDDEN extern void
tanh_1_448_56_56 (const float X[1][448][56][56],
                  float       Y[1][448][56][56]);

LIB_HIDDEN extern void
avg_pool_mean_squeeze (const float   input[1][2016][1][1],
                       const int64_t axes_tensor[2],
                       float         output[1][2016]);

LIB_HIDDEN extern void
func_629e2dbf06d (const float x[1][168][1][1],
                  const float w[8][168][1][1],
                  const float bias[8],
                  float       y[1][8][1][1]);

LIB_HIDDEN extern void
func_4f55e66099e (const float x[1][8][1][1],
                  const float w[168][8][1][1],
                  const float bias[168],
                  float       y[1][168][1][1]);

LIB_HIDDEN extern void
func_4962051e51f (const float A[1][32][112][112],
                  const float B[1][32][112][112],
                  float       C[1][32][112][112]);

LIB_HIDDEN extern void
conv_1_32_112_112_w168_32_1_1_y1_168_112_112 (const float x[1][32][112][112],
                                              const float w[168][32][1][1],
                                              const float bias[168],
                                              float       y[1][168][112][112]);

LIB_HIDDEN extern void
tanh_1_8_1_1 (const float X[1][8][1][1],
              float       Y[1][8][1][1]);

LIB_HIDDEN extern void
fold_1_168_112_112 (const float A[1][168][112][112],
                    const float B[1],
                    float       C[1][168][112][112]);

LIB_HIDDEN extern void
add_1_448_56_56 (const float A[1][448][56][56],
                 const float B[1][448][56][56],
                 float       C[1][448][56][56]);

LIB_HIDDEN extern void
add_1_8_1_1 (const float A[1][8][1][1],
             const float B[1][8][1][1],
             float       C[1][8][1][1]);

LIB_HIDDEN extern void
func_3969f380e32 (const float A[1][8][1][1],
                  const float B[1][8][1][1],
                  float       C[1][8][1][1]);

LIB_HIDDEN extern void
add_1_896_28_28 (const float A[1][896][28][28],
                 const float B[1][896][28][28],
                 float       C[1][896][28][28]);

LIB_HIDDEN extern void
func_2eb9726b206 (const float x[1][448][56][56],
                  const float w[448][56][3][3],
                  const float bias[448],
                  float       y[1][448][28][28]);

LIB_HIDDEN extern void
conv_1_32_112_112_w168_32_1_1_y1_168_56_56 (const float x[1][32][112][112],
                                            const float w[168][32][1][1],
                                            const float bias[168],
                                            float       y[1][168][56][56]);

LIB_HIDDEN extern void
func_29de84547b6 (const float A[1][448][56][56],
                  const float B[1][448][56][56],
                  float       C[1][448][56][56]);

LIB_HIDDEN extern void
func_22243caf0c5 (const float A[1][2016][7][7],
                  const float B[1][2016][1][1],
                  float       C[1][2016][7][7]);

LIB_HIDDEN extern void
func_1ea51fee924 (const float A[1][896][28][28],
                  const float B[1][896][28][28],
                  float       C[1][896][28][28]);

LIB_HIDDEN extern void
add_1_32_112_112 (const float A[1][32][112][112],
                  const float B[1][32][112][112],
                  float       C[1][32][112][112]);

LIB_HIDDEN extern void
fold_1_8_1_1 (const float A[1][8][1][1],
              const float B[1],
              float       C[1][8][1][1]);

LIB_HIDDEN extern void
conv_1_2016_1_1 (const float x[1][2016][1][1],
                 const float w[224][2016][1][1],
                 const float bias[224],
                 float       y[1][224][1][1]);

LIB_HIDDEN extern void
softplus_1_168_112_112 (const float X[1][168][112][112],
                        float       Y[1][168][112][112]);

LIB_HIDDEN extern void
tanh_1_32_112_112 (const float X[1][32][112][112],
                   float       Y[1][32][112][112]);

LIB_HIDDEN extern void
fold_1_448_56_56 (const float A[1][448][56][56],
                  const float B[1],
                  float       C[1][448][56][56]);

LIB_HIDDEN extern void
conv_1_448_1_1 (const float x[1][448][1][1],
                const float w[42][448][1][1],
                const float bias[42],
                float       y[1][42][1][1]);

LIB_HIDDEN extern void
func_024f701e4f6 (const float x[1][168][56][56],
                  const float w[168][56][3][3],
                  const float bias[168],
                  float       y[1][168][56][56]);

#endif // ACTIVATION_H_
