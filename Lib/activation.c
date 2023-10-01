#include <math.h>

#include "activation.h"

LIB_HIDDEN void
add_1_896_14_14 (const float A[1][896][14][14],
                 const float B[1][896][14][14],
                 float       C[1][896][14][14])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		for (unsigned j = 0; j < sizeof A[0][0] / sizeof A[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof A[0][0][0] / sizeof A[0][0][0][0]; k++) {
				C[0][i][j][k] = A[0][i][j][k] + B[0][i][j][k];
			}
		}
	}
}

LIB_HIDDEN void
fold_1_896_14_14 (const float A[1][896][14][14],
                  const float B[1],
                  float       C[1][896][14][14])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		for (unsigned j = 0; j < sizeof A[0][0] / sizeof A[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof A[0][0][0] / sizeof A[0][0][0][0]; k++) {
				C[0][i][j][k] = A[0][i][j][k] * B[0];
			}
		}
	}
}

LIB_HIDDEN void
mul_1_896_14_14 (const float A[1][896][14][14],
                 const float B[1][896][14][14],
                 float       C[1][896][14][14])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i1 = 0; i1 < 896; i1++) {
		for (unsigned i2 = 0; i2 < 14; i2++) {
			for (unsigned i3 = 0; i3 < 14; i3++) {
				C[0][i1][i2][i3] = A[0][i1][i2][i3] * B[0][i1][i2][i3];
			}
		}
	}
}

LIB_HIDDEN void
sigmoid_1_896_14_14 (const float X[1][896][14][14],
                     float       Y[1][896][14][14])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = 1.0f / (1.0f + expf(-X[0][i][j][k]));
			}
		}
	}
}

LIB_HIDDEN void
softplus_1_896_14_14 (const float X[1][896][14][14],
                      float       Y[1][896][14][14])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = logf(expf(X[0][i][j][k]) + 1.0f);
			}
		}
	}
}

LIB_HIDDEN void
tanh_1_896_14_14 (const float X[1][896][14][14],
                  float       Y[1][896][14][14])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = tanhf(X[0][i][j][k]);
			}
		}
	}
}

LIB_HIDDEN void
conv_1_896_14_14_w896_896_1_1_y1_896_14_14 (const float x[1][896][14][14],
                                            const float w[896][896][1][1],
                                            const float bias[896],
                                            float       y[1][896][14][14])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (unsigned m = 0; m < sizeof y[0] / sizeof y[0][0]; m++) {
		for (int o0 = 0; o0 < 14; o0++) {
			for (int o1 = 0; o1 < 14; o1++) {
				y[0][m][o0][o1] = bias[m];
				for (int c = 0; c < 896; c++) {
					y[0][m][o0][o1] += x[0][c][o0][o1] * w[m][c][0][0];
				} /* c */
			}         /* o */
		}                 /* o */
	}                         /* m */
}

LIB_HIDDEN void
add_1_448_28_28 (const float A[1][448][28][28],
                 const float B[1][448][28][28],
                 float       C[1][448][28][28])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		for (unsigned j = 0; j < sizeof A[0][0] / sizeof A[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof A[0][0][0] / sizeof A[0][0][0][0]; k++) {
				C[0][i][j][k] = A[0][i][j][k] + B[0][i][j][k];
			}
		}
	}
}

LIB_HIDDEN void
func_fe352416748 (const float A[1][448][28][28],
                  const float B[1][448][28][28],
                  float       C[1][448][28][28])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 448; i1++) {
			for (unsigned i2 = 0; i2 < 28; i2++) {
				for (unsigned i3 = 0; i3 < 28; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0][i1][i2][i3];
				}
			}
		}
	}
}

LIB_HIDDEN void
tanh_1_448_28_28 (const float X[1][448][28][28],
                  float       Y[1][448][28][28])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = tanhf(X[0][i][j][k]);
			}
		}
	}
}

LIB_HIDDEN void
softplus_1_448_28_28 (const float X[1][448][28][28],
                      float       Y[1][448][28][28])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = logf(expf(X[0][i][j][k]) + 1.0f);
			}
		}
	}
}

LIB_HIDDEN void
sigmoid_1_448_28_28 (const float X[1][448][28][28],
                     float       Y[1][448][28][28])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i = 0; i < sizeof Y[0] / sizeof Y[0][0]; i++) {
		for (unsigned j = 0; j < sizeof Y[0][0] / sizeof Y[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof Y[0][0][0] / sizeof Y[0][0][0][0]; k++) {
				Y[0][i][j][k] = 1.0f / (1.0f + expf(-X[0][i][j][k]));
			}
		}
	}
}

LIB_HIDDEN void
fold_1_448_28_28 (const float A[1][448][28][28],
                  const float B[1],
                  float       C[1][448][28][28])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 448; i1++) {
			for (unsigned i2 = 0; i2 < 28; i2++) {
				for (unsigned i3 = 0; i3 < 28; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0];
				}
			}
		}
	}
}

LIB_HIDDEN void
sigmoid_1_896_1_1 (const float X[1][896][1][1],
                   float       Y[1][896][1][1])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i1 = 0; i1 < sizeof Y[0] / sizeof Y[0][0]; i1++) {
		Y[0][i1][0][0] = 1.0f / (1.0f + expf(-X[0][i1][0][0]));
	}
}

LIB_HIDDEN void
sigmoid_1_224_1_1 (const float X[1][224][1][1],
                   float       Y[1][224][1][1])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		Y[0][i][0][0] = 1.0f / (1.0f + expf(-X[0][i][0][0]));
	}
}

LIB_HIDDEN void
add_1_224_1_1 (const float A[1][224][1][1],
               const float B[1][224][1][1],
               float       C[1][224][1][1])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		C[0][i][0][0] = A[0][i][0][0] + B[0][i][0][0];
	}
}

LIB_HIDDEN void
func_7637f5931c0 (const float A[1][896][14][14],
                  const float B[1][896][1][1],
                  float       C[1][896][14][14])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 896; i1++) {
			for (unsigned i2 = 0; i2 < 14; i2++) {
				for (unsigned i3 = 0; i3 < 14; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0][i1][0][0];
				}
			}
		}
	}
}

LIB_HIDDEN void
fold_1_224_1_1 (const float A[1][224][1][1],
                const float B[1],
                float       C[1][224][1][1])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 224; i1++) {
			for (unsigned i2 = 0; i2 < 1; i2++) {
				for (unsigned i3 = 0; i3 < 1; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][0][0] * B[0];
				}
			}
		}
	}
}

LIB_HIDDEN void
avgpool_1_896_14_14 (const float in[1][896][14][14],
                     float       out[1][896][1][1])
{
	/* GlobalAveragePool */
	for (unsigned c = 0; c < sizeof in[0] / sizeof in[0][0]; c++) {
		float dimsum = 0.0f;
		for (unsigned d0 = 0; d0 < sizeof in[0][0] / sizeof in[0][0][0]; d0++) {
			for (unsigned d1 = 0; d1 < sizeof in[0][0][0] / sizeof in[0][0][0][0]; d1++) {
				dimsum += in[0][c][d0][d1];
			}
		}
		out[0][c][0][0] = dimsum / (float)((sizeof in[0][0]    / sizeof in[0][0][0]) *
		                                   (sizeof in[0][0][0] / sizeof in[0][0][0][0]));
	}
}

LIB_HIDDEN void
func_3fd747a7427 (const float A[1][224][1][1],
                  const float B[1][224][1][1],
                  float       C[1][224][1][1])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 224; i1++) {
			for (unsigned i2 = 0; i2 < 1; i2++) {
				for (unsigned i3 = 0; i3 < 1; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][0][0] * B[0][i1][0][0];
				}
			}
		}
	}
}

LIB_HIDDEN void
tanh_1_224_1_1 (const float X[1][224][1][1],
                float       Y[1][224][1][1])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		Y[0][i][0][0] = tanhf(X[0][i][0][0]);
	}
}

LIB_HIDDEN void
softplus_1_224_1_1 (const float X[1][224][1][1],
                    float       Y[1][224][1][1])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		Y[0][i][0][0] = logf(expf(X[0][i][0][0]) + 1.0f);
	}
}

LIB_HIDDEN void
func_dbbae7cbb81 (const float x[1][896][1][1],
                  const float w[224][896][1][1],
                  const float bias[224],
                  float       y[1][224][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 224; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 1; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 1; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 896; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 1)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 1)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
func_8c9c2b9a537 (const float x[1][896][14][14],
                  const float w[896][56][3][3],
                  const float bias[896],
                  float       y[1][896][14][14])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 16
	 * kernel_shape: 3 3
	 * pads: 1 1 1 1
	 * strides: 1 1
	 */
	for (int g = 0; g < 16; g++) {
		for (int m = 56 * g; m < 56 * (g + 1); m++) {
			for (int o0 = 0, i0 = -1; o0 < 14; o0++, i0 += 1) {
				for (int o1 = 0, i1 = -1; o1 < 14; o1++, i1 += 1) {
					y[0][m][o0][o1] = bias[m];
					for (int c = 56 * g; c < 56 * (g + 1); c++) {
						for (int k0 = 0; k0 < 3; k0++) {
							for (int k1 = 0; k1 < 3; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 14)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 14)
									continue;
								y[0][m][o0][o1] += x[0][c][ii0][ii1] * w[m][c - (56 * g)][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* g */
}

LIB_HIDDEN void
func_24bd64319b5 (const float x[1][224][1][1],
                  const float w[896][224][1][1],
                  const float bias[896],
                  float       y[1][896][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 896; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 1; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 1; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 224; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 1)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 1)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
func_d83947690c8 (const float x[1][448][28][28],
                  const float w[448][448][1][1],
                  const float bias[448],
                  float       y[1][448][28][28])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 448; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 28; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 28; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 448; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 28)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 28)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
add_1_168_56_56 (const float A[1][168][56][56],
                 const float B[1][168][56][56],
                 float       C[1][168][56][56])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		for (unsigned j = 0; j < sizeof A[0][0] / sizeof A[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof A[0][0][0] / sizeof A[0][0][0][0]; k++) {
				C[0][i][j][k] = A[0][i][j][k] + B[0][i][j][k];
			}
		}
	}
}

LIB_HIDDEN void
softplus_1_168_56_56 (const float X[1][168][56][56],
                      float       Y[1][168][56][56])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = logf(expf(X[0][i][j][k]) + 1.0f);
			}
		}
	}
}

LIB_HIDDEN void
func_a8fcef9491d (const float X[1][168][56][56],
                  float       Y[1][168][56][56])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i1 = 0; i1 < 168; i1++) {
		for (unsigned i2 = 0; i2 < 56; i2++) {
			for (unsigned i3 = 0; i3 < 56; i3++) {
				Y[0][i1][i2][i3] = 1.0f / (1.0f + expf(-X[0][i1][i2][i3]));
			}
		}
	}
}

LIB_HIDDEN void
func_7ae0037bce3 (const float A[1][168][56][56],
                  const float B[1][168][56][56],
                  float       C[1][168][56][56])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i1 = 0; i1 < 168; i1++) {
		for (unsigned i2 = 0; i2 < 56; i2++) {
			for (unsigned i3 = 0; i3 < 56; i3++) {
				C[0][i1][i2][i3] = A[0][i1][i2][i3] * B[0][i1][i2][i3];
			}
		}
	}
}

LIB_HIDDEN void
tanh_1_168_56_56 (const float X[1][168][56][56],
                  float       Y[1][168][56][56])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = tanhf(X[0][i][j][k]);
			}
		}
	}
}

LIB_HIDDEN void
fold_1_168_56_56 (const float A[1][168][56][56],
                  const float B[1],
                  float       C[1][168][56][56])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 168; i1++) {
			for (unsigned i2 = 0; i2 < 56; i2++) {
				for (unsigned i3 = 0; i3 < 56; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0];
				}
			}
		}
	}
}

LIB_HIDDEN void
func_fe391e43ecd (const float X[1][112][1][1],
                  float       Y[1][112][1][1])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i1 = 0; i1 < sizeof Y[0] / sizeof Y[0][0]; i1++) {
		Y[0][i1][0][0] = 1.0f / (1.0f + expf(-X[0][i1][0][0]));
	}
}

LIB_HIDDEN void
softplus_1_112_1_1 (const float X[1][112][1][1],
                    float       Y[1][112][1][1])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		Y[0][i][0][0] = logf(expf(X[0][i][0][0]) + 1.0f);
	}
}

LIB_HIDDEN void
add_1_112_1_1 (const float A[1][112][1][1],
               const float B[1][112][1][1],
               float       C[1][112][1][1])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		C[0][i][0][0] = A[0][i][0][0] + B[0][i][0][0];
	}
}

LIB_HIDDEN void
func_9c5643a6f0a (const float X[1][448][1][1],
                  float       Y[1][448][1][1])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i1 = 0; i1 < sizeof Y[0] / sizeof Y[0][0]; i1++) {
		Y[0][i1][0][0] = 1.0f / (1.0f + expf(-X[0][i1][0][0]));
	}
}

LIB_HIDDEN void
tanh_1_112_1_1 (const float X[1][112][1][1],
                float       Y[1][112][1][1])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		Y[0][i][0][0] = tanhf(X[0][i][0][0]);
	}
}

LIB_HIDDEN void
avgpool_1_448_28_28 (const float in[1][448][28][28],
                     float       out[1][448][1][1])
{
	/* GlobalAveragePool */
	for (unsigned c = 0; c < sizeof in[0] / sizeof in[0][0]; c++) {
		float dimsum = 0.0f;
		for (unsigned d0 = 0; d0 < sizeof in[0][0] / sizeof in[0][0][0]; d0++) {
			for (unsigned d1 = 0; d1 < sizeof in[0][0][0] / sizeof in[0][0][0][0]; d1++) {
				dimsum += in[0][c][d0][d1];
			}
		}
		out[0][c][0][0] = dimsum / (float)((sizeof in[0][0]    / sizeof in[0][0][0]) *
		                                   (sizeof in[0][0][0] / sizeof in[0][0][0][0]));
	}
}

LIB_HIDDEN void
func_4e66d83a223 (const float A[1][112][1][1],
                  const float B[1][112][1][1],
                  float       C[1][112][1][1])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 112; i1++) {
			for (unsigned i2 = 0; i2 < 1; i2++) {
				for (unsigned i3 = 0; i3 < 1; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][0][0] * B[0][i1][0][0];
				}
			}
		}
	}
}

LIB_HIDDEN void
func_33fbc985d50 (const float A[1][448][28][28],
                  const float B[1][448][1][1],
                  float       C[1][448][28][28])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 448; i1++) {
			for (unsigned i2 = 0; i2 < 28; i2++) {
				for (unsigned i3 = 0; i3 < 28; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0][i1][0][0];
				}
			}
		}
	}
}

LIB_HIDDEN void
fold_1_112_1_1 (const float A[1][112][1][1],
                const float B[1],
                float       C[1][112][1][1])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 112; i1++) {
			for (unsigned i2 = 0; i2 < 1; i2++) {
				for (unsigned i3 = 0; i3 < 1; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][0][0] * B[0];
				}
			}
		}
	}
}

LIB_HIDDEN void
func_c2f45289b07 (const float x[1][448][28][28],
                  const float w[448][56][3][3],
                  const float bias[448],
                  float       y[1][448][28][28])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 8
	 * kernel_shape: 3 3
	 * pads: 1 1 1 1
	 * strides: 1 1
	 */
	for (int g = 0; g < 8; g++) {
		for (int m = 56 * g; m < 56 * (g + 1); m++) {
			for (int o0 = 0, i0 = -1; o0 < 28; o0++, i0 += 1) {
				for (int o1 = 0, i1 = -1; o1 < 28; o1++, i1 += 1) {
					y[0][m][o0][o1] = bias[m];
					for (int c = 56 * g; c < 56 * (g + 1); c++) {
						for (int k0 = 0; k0 < 3; k0++) {
							for (int k1 = 0; k1 < 3; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 28)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 28)
									continue;
								y[0][m][o0][o1] += x[0][c][ii0][ii1] * w[m][c - (56 * g)][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* g */
}

LIB_HIDDEN void
func_a8d1ba02fec (const float x[1][168][56][56],
                  const float w[168][168][1][1],
                  const float bias[168],
                  float       y[1][168][56][56])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 168; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 56; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 56; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 168; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 56)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 56)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
add_1_2016_7_7 (const float A[1][2016][7][7],
                const float B[1][2016][7][7],
                float       C[1][2016][7][7])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		for (unsigned j = 0; j < sizeof A[0][0] / sizeof A[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof A[0][0][0] / sizeof A[0][0][0][0]; k++) {
				C[0][i][j][k] = A[0][i][j][k] + B[0][i][j][k];
			}
		}
	}
}

LIB_HIDDEN void
func_638785b3659 (const float x[1][112][1][1],
                  const float w[448][112][1][1],
                  const float bias[448],
                  float       y[1][448][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 448; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 1; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 1; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 112; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 1)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 1)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
func_190bd454425 (const float x[1][448][1][1],
                  const float w[112][448][1][1],
                  const float bias[112],
                  float       y[1][112][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 112; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 1; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 1; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 448; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 1)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 1)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
tanh_1_2016_7_7 (const float X[1][2016][7][7],
                 float       Y[1][2016][7][7])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = tanhf(X[0][i][j][k]);
			}
		}
	}
}

LIB_HIDDEN void
avgpool_1_168_56_56 (const float in[1][168][56][56],
                     float       out[1][168][1][1])
{
	/* GlobalAveragePool */
	for (unsigned c = 0; c < sizeof in[0] / sizeof in[0][0]; c++) {
		float dimsum = 0.0f;
		for (unsigned d0 = 0; d0 < sizeof in[0][0] / sizeof in[0][0][0]; d0++) {
			for (unsigned d1 = 0; d1 < sizeof in[0][0][0] / sizeof in[0][0][0][0]; d1++) {
				dimsum += in[0][c][d0][d1];
			}
		}
		out[0][c][0][0] = dimsum / (float)((sizeof in[0][0]    / sizeof in[0][0][0]) *
		                                   (sizeof in[0][0][0] / sizeof in[0][0][0][0]));
	}
}

LIB_HIDDEN void
avgpool_1_2016_7_7 (const float in[1][2016][7][7],
                   float       out[1][2016][1][1])
{
	/* GlobalAveragePool */
	for (unsigned c = 0; c < sizeof in[0] / sizeof in[0][0]; c++) {
		float dimsum = 0.0f;
		for (unsigned d0 = 0; d0 < sizeof in[0][0] / sizeof in[0][0][0]; d0++) {
			for (unsigned d1 = 0; d1 < sizeof in[0][0][0] / sizeof in[0][0][0][0]; d1++) {
				dimsum += in[0][c][d0][d1];
			}
		}
		out[0][c][0][0] = dimsum / (float)((sizeof in[0][0]    / sizeof in[0][0][0]) *
		                                   (sizeof in[0][0][0] / sizeof in[0][0][0][0]));
	}
}

LIB_HIDDEN void
fold_1_2016_7_7 (const float A[1][2016][7][7],
                 const float B[1],
                 float       C[1][2016][7][7])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 2016; i1++) {
			for (unsigned i2 = 0; i2 < 7; i2++) {
				for (unsigned i3 = 0; i3 < 7; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0];
				}
			}
		}
	}
}

LIB_HIDDEN void
func_b7e2f9b2d8b (const float A[1][42][1][1],
                  const float B[1][42][1][1],
                  float       C[1][42][1][1])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 42; i1++) {
			for (unsigned i2 = 0; i2 < 1; i2++) {
				for (unsigned i3 = 0; i3 < 1; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][0][0] * B[0][i1][0][0];
				}
			}
		}
	}
}

LIB_HIDDEN void
softplus_1_2016_7_7 (const float X[1][2016][7][7],
                     float       Y[1][2016][7][7])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = logf(expf(X[0][i][j][k]) + 1.0f);
			}
		}
	}
}

LIB_HIDDEN void
func_a9f65a497cb (const float A[1][2016][7][7],
                  const float B[1][2016][7][7],
                  float       C[1][2016][7][7])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 2016; i1++) {
			for (unsigned i2 = 0; i2 < 7; i2++) {
				for (unsigned i3 = 0; i3 < 7; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0][i1][i2][i3];
				}
			}
		}
	}
}

LIB_HIDDEN void
func_8e83ce12053 (const float X[1][42][1][1],
                  float       Y[1][42][1][1])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i1 = 0; i1 < sizeof Y[0] / sizeof Y[0][0]; i1++) {
		Y[0][i1][0][0] = 1.0f / (1.0f + expf(-X[0][i1][0][0]));
	}
}

LIB_HIDDEN void
func_673643b7d31 (const float A[1][168][56][56],
                  const float B[1][168][1][1],
                  float       C[1][168][56][56])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 168; i1++) {
			for (unsigned i2 = 0; i2 < 56; i2++) {
				for (unsigned i3 = 0; i3 < 56; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0][i1][0][0];
				}
			}
		}
	}
}

LIB_HIDDEN void
softplus_1_42_1_1 (const float X[1][42][1][1],
                   float       Y[1][42][1][1])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		Y[0][i][0][0] = logf(expf(X[0][i][0][0]) + 1.0f);
	}
}

LIB_HIDDEN void
tanh_1_42_1_1 (const float X[1][42][1][1],
               float       Y[1][42][1][1])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		Y[0][i][0][0] = tanhf(X[0][i][0][0]);
	}
}

LIB_HIDDEN void
fold_1_42_1_1 (const float A[1][42][1][1],
               const float B[1],
               float       C[1][42][1][1])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 42; i1++) {
			for (unsigned i2 = 0; i2 < 1; i2++) {
				for (unsigned i3 = 0; i3 < 1; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][0][0] * B[0];
				}
			}
		}
	}
}

LIB_HIDDEN void
sigmoid_1_2016_7_7 (const float X[1][2016][7][7],
                    float       Y[1][2016][7][7])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i = 0; i < sizeof Y[0] / sizeof Y[0][0]; i++) {
		for (unsigned j = 0; j < sizeof Y[0][0] / sizeof Y[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof Y[0][0][0] / sizeof Y[0][0][0][0]; k++) {
				Y[0][i][j][k] = 1.0f / (1.0f + expf(-X[0][i][j][k]));
			}
		}
	}
}

LIB_HIDDEN void
add_1_42_1_1 (const float A[1][42][1][1],
              const float B[1][42][1][1],
              float       C[1][42][1][1])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		C[0][i][0][0] = A[0][i][0][0] + B[0][i][0][0];
	}
}

LIB_HIDDEN void
func_0396437e541 (const float X[1][168][1][1],
                  float       Y[1][168][1][1])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i = 0; i < sizeof Y[0] / sizeof Y[0][0]; i++) {
		Y[0][i][0][0] = 1.0f / (1.0f + expf(-X[0][i][0][0]));
	}
}

LIB_HIDDEN void
softplus_1_8_1_1 (const float X[1][8][1][1],
                  float       Y[1][8][1][1])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		Y[0][i][0][0] = logf(expf(X[0][i][0][0]) + 1.0f);
	}
}

LIB_HIDDEN void
sigmoid_1_8_1_1 (const float X[1][8][1][1],
                 float       Y[1][8][1][1])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i = 0; i < sizeof Y[0] / sizeof Y[0][0]; i++) {
		Y[0][i][0][0] = 1.0f / (1.0f + expf(-X[0][i][0][0]));
	}
}

LIB_HIDDEN void
func_f737763e33a (const float x[1][168][1][1],
                  const float w[42][168][1][1],
                  const float bias[42],
                  float       y[1][42][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 42; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 1; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 1; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 168; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 1)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 1)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
func_f24b878e18a (const float x[1][168][56][56],
                  const float w[448][168][1][1],
                  const float bias[448],
                  float       y[1][448][56][56])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 448; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 56; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 56; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 168; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 56)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 56)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
func_e98ea15dc69 (const float X[1][896][28][28],
                  float       Y[1][896][28][28])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 896; i1++) {
			for (unsigned i2 = 0; i2 < 28; i2++) {
				for (unsigned i3 = 0; i3 < 28; i3++) {
					Y[i0][i1][i2][i3] = 1 / (1 + expf(-X[i0][i1][i2][i3]));
				}
			}
		}
	}
}

LIB_HIDDEN void
matmul_2016_4 (const float A[1][2016],
               const float B[2016][4],
               float       Y[1][4])
{
	/* MatMul */
	for (unsigned c = 0; c < sizeof Y[0] / sizeof Y[0][0]; c++) {
		Y[0][c] = 0;
		for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
			Y[0][c] += A[0][i] * B[i][c];
		}
	}
}

LIB_HIDDEN void
softplus_1_2016_14_14 (const float X[1][2016][14][14],
                       float       Y[1][2016][14][14])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = logf(expf(X[0][i][j][k]) + 1.0f);
			}
		}
	}
}

LIB_HIDDEN void
func_d76e9ccfb30 (const float X[1][2016][14][14],
                  float       Y[1][2016][14][14])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 2016; i1++) {
			for (unsigned i2 = 0; i2 < 14; i2++) {
				for (unsigned i3 = 0; i3 < 14; i3++) {
					Y[i0][i1][i2][i3] = 1 / (1 + expf(-X[i0][i1][i2][i3]));
				}
			}
		}
	}
}

LIB_HIDDEN void
func_d6ae3647f1b (const float A[1][168][112][112],
                  const float B[1][168][112][112],
                  float       C[1][168][112][112])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 168; i1++) {
			for (unsigned i2 = 0; i2 < 112; i2++) {
				for (unsigned i3 = 0; i3 < 112; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0][i1][i2][i3];
				}
			}
		}
	}
}

LIB_HIDDEN void
fold_1_32_112_112 (const float A[1][32][112][112],
                   const float B[1],
                   float       C[1][32][112][112])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 32; i1++) {
			for (unsigned i2 = 0; i2 < 112; i2++) {
				for (unsigned i3 = 0; i3 < 112; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0];
				}
			}
		}
	}
}

LIB_HIDDEN void
func_d61c9a21a5c (const float x[1][2016][7][7],
                  const float w[2016][2016][1][1],
                  const float bias[2016],
                  float       y[1][2016][7][7])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 2016; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 7; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 7; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 2016; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 7)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 7)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
func_ce6378ecf4f (const float x[1][2016][14][14],
                  const float w[2016][56][3][3],
                  const float bias[2016],
                  float       y[1][2016][7][7])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 36
	 * kernel_shape: 3 3
	 * pads: 1 1 1 1
	 * strides: 2 2
	 */
	for (int g = 0; g < 36; g++) {
		for (int m = 56 * g; m < 56 * (g + 1); m++) {
			for (int o0 = 0, i0 = -1; o0 < 7; o0++, i0 += 2) {
				for (int o1 = 0, i1 = -1; o1 < 7; o1++, i1 += 2) {
					y[0][m][o0][o1] = bias[m];
					for (int c = 56 * g; c < 56 * (g + 1); c++) {
						for (int k0 = 0; k0 < 3; k0++) {
							for (int k1 = 0; k1 < 3; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 14)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 14)
									continue;
								y[0][m][o0][o1] += x[0][c][ii0][ii1] * w[m][c - (56 * g)][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* g */
}

LIB_HIDDEN void
func_c6af25897cd (const float x[1][448][28][28],
                  const float w[896][448][1][1],
                  const float bias[896],
                  float       y[1][896][14][14])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 2 2
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 896; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 14; o0++, i0 += 2) {
				for (int32_t o1 = 0, i1 = 0; o1 < 14; o1++, i1 += 2) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 448; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 28)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 28)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
tanh_1_2016_14_14 (const float X[1][2016][14][14],
                   float       Y[1][2016][14][14])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = tanhf(X[0][i][j][k]);
			}
		}
	}
}

LIB_HIDDEN void
softmax_1_4 (const float in[1][4],
             float       out[1][4])
{
	/* Softmax 13 (TF, pytorch style)
	 * axis = -1
	 */
	float max  = in[0][0];
	unsigned i = 0;
	while (++i < sizeof in[0] / sizeof in[0][0]) {
		if (in[0][i] > max)
			max = in[0][i];
	}

	float sum = expf(in[0][0] - max);
	out[0][0] = sum;
	i = 0;
	while (++i < sizeof in[0] / sizeof in[0][0]) {
		sum += (out[0][i] = expf(in[0][i] - max));
	}

	i = 0;
	do {
		out[0][i] /= sum;
	} while (++i < sizeof in[0] / sizeof in[0][0]);
}

LIB_HIDDEN void
func_c2fbc93cabe (const float A[1][2016][14][14],
                  const float B[1][2016][14][14],
                  float       C[1][2016][14][14])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 2016; i1++) {
			for (unsigned i2 = 0; i2 < 14; i2++) {
				for (unsigned i3 = 0; i3 < 14; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0][i1][i2][i3];
				}
			}
		}
	}
}

LIB_HIDDEN void
func_c288fe43fe8 (const float x[1][168][56][56],
                  const float w[448][168][1][1],
                  const float bias[448],
                  float       y[1][448][28][28])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 2 2
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 448; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 28; o0++, i0 += 2) {
				for (int32_t o1 = 0, i1 = 0; o1 < 28; o1++, i1 += 2) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 168; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 56)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 56)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
conv_1_112_1_1 (const float x[1][112][1][1],
                const float w[896][112][1][1],
                const float bias[896],
                float       y[1][896][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (int m = 0; m < 896; m++) {
		for (int o0 = 0, i0 = 0; o0 < 1; o0++, i0 += 1) {
			for (int o1 = 0, i1 = 0; o1 < 1; o1++, i1 += 1) {
				y[0][m][o0][o1] = bias[m];
				for (int c = 0; c < 112; c++) {
					for (int k0 = 0; k0 < 1; k0++) {
						for (int k1 = 0; k1 < 1; k1++) {
							int ii0 = i0 + k0 * 1;
							if (ii0 < 0)
								continue;
						if (ii0 >= 1)
								continue;
							int ii1 = i1 + k1 * 1;
							if (ii1 < 0)
								continue;
							if (ii1 >= 1)
								continue;
							y[0][m][o0][o1] += x[0][c][ii0][ii1] * w[m][c][k0][k1];
						} /* k */
					}         /* k */
				}                 /* c */
			}                         /* o */
		}                                 /* o */
	}                                         /* m */
}

LIB_HIDDEN void
softplus_1_448_56_56 (const float X[1][448][56][56],
                      float       Y[1][448][56][56])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = logf(expf(X[0][i][j][k]) + 1.0f);
			}
		}
	}
}

LIB_HIDDEN void
conv_1_896_14_14 (const float x[1][896][14][14],
                  const float w[2016][896][1][1],
                  const float bias[2016],
                  float       y[1][2016][7][7])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 2 2
	 */
	for (int m = 0; m < 2016; m++) {
		for (int o0 = 0, i0 = 0; o0 < 7; o0++, i0 += 2) {
			for (int o1 = 0, i1 = 0; o1 < 7; o1++, i1 += 2) {
				y[0][m][o0][o1] = bias[m];
				for (int c = 0; c < 896; c++) {
					for (int k0 = 0; k0 < 1; k0++) {
						for (int k1 = 0; k1 < 1; k1++) {
							int ii0 = i0 + k0 * 1;
							if (ii0 < 0)
								continue;
							if (ii0 >= 14)
								continue;
							int ii1 = i1 + k1 * 1;
							if (ii1 < 0)
								continue;
							if (ii1 >= 14)
								continue;
							y[0][m][o0][o1] += x[0][c][ii0][ii1] * w[m][c][k0][k1];
						} /* k */
					}         /* k */
				}                 /* c */
			}                         /* o */
		}                                 /* o */
	}                                         /* m */
}

LIB_HIDDEN void
fold_1_2016_14_14 (const float A[1][2016][14][14],
                   const float B[1],
                   float       C[1][2016][14][14])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 2016; i1++) {
			for (unsigned i2 = 0; i2 < 14; i2++) {
				for (unsigned i3 = 0; i3 < 14; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0];
				}
			}
		}
	}
}

LIB_HIDDEN void
fold_1_896_28_28 (const float A[1][896][28][28],
                  const float B[1],
                  float       C[1][896][28][28])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 896; i1++) {
			for (unsigned i2 = 0; i2 < 28; i2++) {
				for (unsigned i3 = 0; i3 < 28; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0];
				}
			}
		}
	}
}

LIB_HIDDEN void
softplus_1_896_28_28 (const float X[1][896][28][28],
                      float       Y[1][896][28][28])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = logf(expf(X[0][i][j][k]) + 1.0f);
			}
		}
	}
}

LIB_HIDDEN void
tanh_1_896_28_28 (const float X[1][896][28][28],
                  float       Y[1][896][28][28])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = tanhf(X[0][i][j][k]);
			}
		}
	}
}

LIB_HIDDEN void
add_1_4 (const float A[1][4],
         const float B[4],
         float       C[1][4])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		C[0][i] = A[0][i] + B[i];
	}
}

LIB_HIDDEN void
tanh_1_168_112_112 (const float X[1][168][112][112],
                    float       Y[1][168][112][112])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = tanhf(X[0][i][j][k]);
			}
		}
	}
}

LIB_HIDDEN void
softplus_1_32_112_112 (const float X[1][32][112][112],
                       float       Y[1][32][112][112])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = logf(expf(X[0][i][j][k]) + 1.0f);
			}
		}
	}
}

LIB_HIDDEN void
func_9cf1befb936 (const float x[1][42][1][1],
                  const float w[168][42][1][1],
                  const float bias[168],
                  float       y[1][168][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 168; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 1; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 1; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 42; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 1)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 1)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
func_97b144c3b9a (const float X[1][168][112][112],
                  float       Y[1][168][112][112])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 168; i1++) {
			for (unsigned i2 = 0; i2 < 112; i2++) {
				for (unsigned i3 = 0; i3 < 112; i3++) {
					Y[i0][i1][i2][i3] = 1 / (1 + expf(-X[i0][i1][i2][i3]));
				}
			}
		}
	}
}

LIB_HIDDEN void
add_1_168_112_112 (const float A[1][168][112][112],
                   const float B[1][168][112][112],
                   float       C[1][168][112][112])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		for (unsigned j = 0; j < sizeof A[0][0] / sizeof A[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof A[0][0][0] / sizeof A[0][0][0][0]; k++) {
				C[0][i][j][k] = A[0][i][j][k] + B[0][i][j][k];
			}
		}
	}
}

LIB_HIDDEN void
conv_1_896_14_14_w2016_896_1_1_y1_2016_14_14 (const float x[1][896][14][14],
                                              const float w[2016][896][1][1],
                                              const float bias[2016],
                                              float       y[1][2016][14][14])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (unsigned m = 0; m < sizeof y[0] / sizeof y[0][0]; m++) {
		for (int o0 = 0; o0 < 14; o0++) {
			for (int o1 = 0; o1 < 14; o1++) {
				y[0][m][o0][o1] = bias[m];
				for (int c = 0; c < 896; c++) {
					y[0][m][o0][o1] += x[0][c][o0][o1] * w[m][c][0][0];
				} /* c */
			}         /* o */
		}                 /* o */
	}                         /* m */
}

LIB_HIDDEN void
func_8e2441e0d80 (const float x[1][896][28][28],
                  const float w[896][56][3][3],
                  const float bias[896],
                  float       y[1][896][14][14])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 16
	 * kernel_shape: 3 3
	 * pads: 1 1 1 1
	 * strides: 2 2
	 */
	for (int g = 0; g < 16; g++) {
		for (int m = 56 * g; m < 56 * (g + 1); m++) {
			for (int o0 = 0, i0 = -1; o0 < 14; o0++, i0 += 2) {
				for (int o1 = 0, i1 = -1; o1 < 14; o1++, i1 += 2) {
					y[0][m][o0][o1] = bias[m];
					for (int c = 56 * g; c < 56 * (g + 1); c++) {
						for (int k0 = 0; k0 < 3; k0++) {
							for (int k1 = 0; k1 < 3; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 28)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 28)
									continue;
								y[0][m][o0][o1] += x[0][c][ii0][ii1] * w[m][c - (56 * g)][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* g */
}

LIB_HIDDEN void
func_8d7ee594121 (const float x[1][448][28][28],
                  const float w[896][448][1][1],
                  const float bias[896],
                  float       y[1][896][28][28])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 896; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 28; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 28; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 448; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 28)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 28)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
conv_1_224_1_1_w2016_224_1_1_y1_2016_1_1 (const float x[1][224][1][1],
                                          const float w[2016][224][1][1],
                                          const float bias[2016],
                                          float       y[1][2016][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (unsigned m = 0; m < sizeof y[0] / sizeof y[0][0]; m++) {
		y[0][m][0][0] = bias[m];
		for (int c = 0; c < 224; c++) {
			y[0][m][0][0] += x[0][c][0][0] * w[m][c][0][0];
		} /* c */
	}         /* m */
}

LIB_HIDDEN void
conv_1_896_1_1_w112_896_1_1_y1_112_1_1 (const float x[1][896][1][1],
                                        const float w[112][896][1][1],
                                        const float bias[112],
                                        float       y[1][112][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (unsigned m = 0; m < sizeof y[0] / sizeof y[0][0]; m++) {
		y[0][m][0][0] = bias[m];
		for (int c = 0; c < 896; c++) {
			y[0][m][0][0] += x[0][c][0][0] * w[m][c][0][0];
		} /* c */
	}         /* m */
}

LIB_HIDDEN void
func_804a22f193b (const float x[1][3][224][224],
                  const float w[32][3][3][3],
                  const float bias[32],
                  float       y[1][32][112][112])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 3 3
	 * pads: 1 1 1 1
	 * strides: 2 2
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 32; m++) {
			for (int32_t o0 = 0, i0 = -1; o0 < 112; o0++, i0 += 2) {
				for (int32_t o1 = 0, i1 = -1; o1 < 112; o1++, i1 += 2) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 3; c++) {
						for (uint32_t k0 = 0; k0 < 3; k0++) {
							for (uint32_t k1 = 0; k1 < 3; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 224)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 224)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
func_7672188cb32 (const float x[1][168][112][112],
                  const float w[168][56][3][3],
                  const float bias[168],
                  float       y[1][168][56][56])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 3
	 * kernel_shape: 3 3
	 * pads: 1 1 1 1
	 * strides: 2 2
	 */
	for (int g = 0; g < 3; g++) {
		for (int m = 56 * g; m < 56 * (g + 1); m++) {
			for (int o0 = 0, i0 = -1; o0 < 56; o0++, i0 += 2) {
				for (int o1 = 0, i1 = -1; o1 < 56; o1++, i1 += 2) {
					y[0][m][o0][o1] = bias[m];
					for (int c = 56 * g; c < 56 * (g + 1); c++) {
						for (int k0 = 0; k0 < 3; k0++) {
							for (int k1 = 0; k1 < 3; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 112)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 112)
									continue;
								y[0][m][o0][o1] += x[0][c][ii0][ii1] * w[m][c - (56 * g)][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* g */
}

LIB_HIDDEN void
func_74f52a68cb0 (const float X[1][32][112][112],
                  float       Y[1][32][112][112])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i1 = 0; i1 < 32; i1++) {
		for (unsigned i2 = 0; i2 < 112; i2++) {
			for (unsigned i3 = 0; i3 < 112; i3++) {
				Y[0][i1][i2][i3] = 1 / (1 + expf(-X[0][i1][i2][i3]));
			}
		}
	}
}

LIB_HIDDEN void
func_743ae64fdb9 (const float X[1][448][56][56],
                  float       Y[1][448][56][56])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 448; i1++) {
			for (unsigned i2 = 0; i2 < 56; i2++) {
				for (unsigned i3 = 0; i3 < 56; i3++) {
					Y[i0][i1][i2][i3] = 1 / (1 + expf(-X[i0][i1][i2][i3]));
				}
			}
		}
	}
}

LIB_HIDDEN void
func_6ba9e121261 (const float x[1][42][1][1],
                  const float w[448][42][1][1],
                  const float bias[448],
                  float       y[1][448][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 448; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 1; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 1; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 42; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 1)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 1)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
sigmoid_1_2016_1_1 (const float X[1][2016][1][1],
                    float       Y[1][2016][1][1])
{
	/* Sigmoid
	   alpha = 0.00000
	   beta = 0.00000
	*/
	for (unsigned i = 0; i < sizeof Y[0] / sizeof Y[0][0]; i++) {
		Y[0][i][0][0] = 1.0f / (1.0f + expf(-X[0][i][0][0]));
	}
}

LIB_HIDDEN void
add_1_2016_14_14 (const float A[1][2016][14][14],
                  const float B[1][2016][14][14],
                  float       C[1][2016][14][14])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		for (unsigned j = 0; j < sizeof A[0][0] / sizeof A[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof A[0][0][0] / sizeof A[0][0][0][0]; k++) {
				C[0][i][j][k] = A[0][i][j][k] + B[0][i][j][k];
			}
		}
	}
}

LIB_HIDDEN void
tanh_1_448_56_56 (const float X[1][448][56][56],
                  float       Y[1][448][56][56])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = tanhf(X[0][i][j][k]);
			}
		}
	}
}

LIB_HIDDEN void
avg_pool_mean_squeeze (const float   input[1][2016][1][1],
                       const int64_t axes_tensor[2] __attribute__((unused)),
                       float         output[1][2016])
{
	/*Squeeze*/
	for (int i = 0; i < 2016; i++) {
		output[0][i] = input[0][i][0][0];
	}
}

LIB_HIDDEN void
func_629e2dbf06d (const float x[1][168][1][1],
                  const float w[8][168][1][1],
                  const float bias[8],
                  float       y[1][8][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 8; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 1; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 1; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 168; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 1)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 1)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
func_4f55e66099e (const float x[1][8][1][1],
                  const float w[168][8][1][1],
                  const float bias[168],
                  float       y[1][168][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (uint32_t b = 0; b < 1; b++) {
		for (uint32_t m = 0; m < 168; m++) {
			for (int32_t o0 = 0, i0 = 0; o0 < 1; o0++, i0 += 1) {
				for (int32_t o1 = 0, i1 = 0; o1 < 1; o1++, i1 += 1) {
					y[b][m][o0][o1] = bias[m];
					for (int32_t c = 0; c < 8; c++) {
						for (uint32_t k0 = 0; k0 < 1; k0++) {
							for (uint32_t k1 = 0; k1 < 1; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 1)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 1)
									continue;
								y[b][m][o0][o1] += x[b][c][ii0][ii1] * w[m][c][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* b */
}

LIB_HIDDEN void
func_4962051e51f (const float A[1][32][112][112],
                  const float B[1][32][112][112],
                  float       C[1][32][112][112])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 32; i1++) {
			for (unsigned i2 = 0; i2 < 112; i2++) {
				for (unsigned i3 = 0; i3 < 112; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0][i1][i2][i3];
				}
			}
		}
	}
}

LIB_HIDDEN void
conv_1_32_112_112_w168_32_1_1_y1_168_112_112 (const float x[1][32][112][112],
                                              const float w[168][32][1][1],
                                              const float bias[168],
                                              float       y[1][168][112][112])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (unsigned m = 0; m < sizeof y[0] / sizeof y[0][0]; m++) {
		for (int o0 = 0; o0 < 112; o0++) {
			for (int o1 = 0; o1 < 112; o1++) {
				y[0][m][o0][o1] = bias[m];
				for (int c = 0; c < 32; c++) {
					y[0][m][o0][o1] += x[0][c][o0][o1] * w[m][c][0][0];
				} /* c */
			}         /* o */
		}                 /* o */
	}                         /* m */
}

LIB_HIDDEN void
tanh_1_8_1_1 (const float X[1][8][1][1],
              float       Y[1][8][1][1])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		Y[0][i][0][0] = tanhf(X[0][i][0][0]);
	}
}

LIB_HIDDEN void
fold_1_168_112_112 (const float A[1][168][112][112],
                    const float B[1],
                    float       C[1][168][112][112])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		for (unsigned j = 0; j < sizeof A[0][0] / sizeof A[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof A[0][0][0] / sizeof A[0][0][0][0]; k++) {
				C[0][i][j][k] = A[0][i][j][k] * B[0];
			}
		}
	}
}

LIB_HIDDEN void
add_1_448_56_56 (const float A[1][448][56][56],
                 const float B[1][448][56][56],
                 float       C[1][448][56][56])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		for (unsigned j = 0; j < sizeof A[0][0] / sizeof A[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof A[0][0][0] / sizeof A[0][0][0][0]; k++) {
				C[0][i][j][k] = A[0][i][j][k] + B[0][i][j][k];
			}
		}
	}
}

LIB_HIDDEN void
add_1_8_1_1 (const float A[1][8][1][1],
             const float B[1][8][1][1],
             float       C[1][8][1][1])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		C[0][i][0][0] = A[0][i][0][0] + B[0][i][0][0];
	}
}

LIB_HIDDEN void
func_3969f380e32 (const float A[1][8][1][1],
                  const float B[1][8][1][1],
                  float       C[1][8][1][1])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 8; i1++) {
			for (unsigned i2 = 0; i2 < 1; i2++) {
				for (unsigned i3 = 0; i3 < 1; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][0][0] * B[0][i1][0][0];
				}
			}
		}
	}
}

LIB_HIDDEN void
add_1_896_28_28 (const float A[1][896][28][28],
                 const float B[1][896][28][28],
                 float       C[1][896][28][28])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		for (unsigned j = 0; j < sizeof A[0][0] / sizeof A[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof A[0][0][0] / sizeof A[0][0][0][0]; k++) {
				C[0][i][j][k] = A[0][i][j][k] + B[0][i][j][k];
			}
		}
	}
}

LIB_HIDDEN void
func_2eb9726b206 (const float x[1][448][56][56],
                  const float w[448][56][3][3],
                  const float bias[448],
                  float       y[1][448][28][28])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 8
	 * kernel_shape: 3 3
	 * pads: 1 1 1 1
	 * strides: 2 2
	 */
	for (int g = 0; g < 8; g++) {
		for (int m = 56 * g; m < 56 * (g + 1); m++) {
			for (int o0 = 0, i0 = -1; o0 < 28; o0++, i0 += 2) {
				for (int o1 = 0, i1 = -1; o1 < 28; o1++, i1 += 2) {
					y[0][m][o0][o1] = bias[m];
					for (int c = 56 * g; c < 56 * (g + 1); c++) {
						for (int k0 = 0; k0 < 3; k0++) {
							for (int k1 = 0; k1 < 3; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 56)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 56)
									continue;
								y[0][m][o0][o1] += x[0][c][ii0][ii1] * w[m][c - (56 * g)][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* g */
}

LIB_HIDDEN void
conv_1_32_112_112_w168_32_1_1_y1_168_56_56 (const float x[1][32][112][112],
                                            const float w[168][32][1][1],
                                            const float bias[168],
                                            float       y[1][168][56][56])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 2 2
	 */
	for (unsigned m = 0; m < sizeof y[0] / sizeof y[0][0]; m++) {
		for (unsigned o0 = 0, i0 = 0; o0 < sizeof y[0][0] / sizeof y[0][0][0]; o0++, i0 += 2) {
			for (unsigned o1 = 0, i1 = 0; o1 < sizeof y[0][0][0] / sizeof y[0][0][0][0]; o1++, i1 += 2) {
				y[0][m][o0][o1] = bias[m];
				for (unsigned c = 0; c < sizeof x[0] / sizeof x[0][0]; c++) {
					y[0][m][o0][o1] += x[0][c][i0][i1] * w[m][c][0][0];
				} /* c */
			}         /* o */
		}                 /* o */
	}                         /* m */
}

LIB_HIDDEN void
func_29de84547b6 (const float A[1][448][56][56],
                  const float B[1][448][56][56],
                  float       C[1][448][56][56])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 448; i1++) {
			for (unsigned i2 = 0; i2 < 56; i2++) {
				for (unsigned i3 = 0; i3 < 56; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0][i1][i2][i3];
				}
			}
		}
	}
}

LIB_HIDDEN void
func_22243caf0c5 (const float A[1][2016][7][7],
                  const float B[1][2016][1][1],
                  float       C[1][2016][7][7])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 2016; i1++) {
			for (unsigned i2 = 0; i2 < 7; i2++) {
				for (unsigned i3 = 0; i3 < 7; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0][i1][0][0];
				}
			}
		}
	}
}

LIB_HIDDEN void
func_1ea51fee924 (const float A[1][896][28][28],
                  const float B[1][896][28][28],
                  float       C[1][896][28][28])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 896; i1++) {
			for (unsigned i2 = 0; i2 < 28; i2++) {
				for (unsigned i3 = 0; i3 < 28; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0][i1][i2][i3];
				}
			}
		}
	}
}

LIB_HIDDEN void
add_1_32_112_112 (const float A[1][32][112][112],
                  const float B[1][32][112][112],
                  float       C[1][32][112][112])
{
	for (unsigned i = 0; i < sizeof A[0] / sizeof A[0][0]; i++) {
		for (unsigned j = 0; j < sizeof A[0][0] / sizeof A[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof A[0][0][0] / sizeof A[0][0][0][0]; k++) {
				C[0][i][j][k] = A[0][i][j][k] + B[0][i][j][k];
			}
		}
	}
}

LIB_HIDDEN void
fold_1_8_1_1 (const float A[1][8][1][1],
              const float B[1],
              float       C[1][8][1][1])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 8; i1++) {
			for (unsigned i2 = 0; i2 < 1; i2++) {
				for (unsigned i3 = 0; i3 < 1; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][0][0] * B[0];
				}
			}
		}
	}
}

LIB_HIDDEN void
conv_1_2016_1_1 (const float x[1][2016][1][1],
                 const float w[224][2016][1][1],
                 const float bias[224],
                 float       y[1][224][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (int m = 0; m < 224; m++) {
		for (int o0 = 0, i0 = 0; o0 < 1; o0++, i0 += 1) {
			for (int o1 = 0, i1 = 0; o1 < 1; o1++, i1 += 1) {
				y[0][m][o0][o1] = bias[m];
				for (int c = 0; c < 2016; c++) {
					for (int k0 = 0; k0 < 1; k0++) {
						for (int k1 = 0; k1 < 1; k1++) {
							int ii0 = i0 + k0 * 1;
							if (ii0 < 0)
								continue;
							if (ii0 >= 1)
								continue;
							int ii1 = i1 + k1 * 1;
							if (ii1 < 0)
								continue;
							if (ii1 >= 1)
								continue;
							y[0][m][o0][o1] += x[0][c][ii0][ii1] * w[m][c][k0][k1];
						} /* k */
					}         /* k */
				}                 /* c */
			}                         /* o */
		}                                 /* o */
	}                                         /* m */
}

LIB_HIDDEN void
softplus_1_168_112_112 (const float X[1][168][112][112],
                        float       Y[1][168][112][112])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = logf(expf(X[0][i][j][k]) + 1.0f);
			}
		}
	}
}

LIB_HIDDEN void
tanh_1_32_112_112 (const float X[1][32][112][112],
                   float       Y[1][32][112][112])
{
	for (unsigned i = 0; i < sizeof X[0] / sizeof X[0][0]; i++) {
		for (unsigned j = 0; j < sizeof X[0][0] / sizeof X[0][0][0]; j++) {
			for (unsigned k = 0; k < sizeof X[0][0][0] / sizeof X[0][0][0][0]; k++) {
				Y[0][i][j][k] = tanhf(X[0][i][j][k]);
			}
		}
	}
}

LIB_HIDDEN void
fold_1_448_56_56 (const float A[1][448][56][56],
                  const float B[1],
                  float       C[1][448][56][56])
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0 = 0; i0 < 1; i0++) {
		for (unsigned i1 = 0; i1 < 448; i1++) {
			for (unsigned i2 = 0; i2 < 56; i2++) {
				for (unsigned i3 = 0; i3 < 56; i3++) {
					C[i0][i1][i2][i3] = A[0][i1][i2][i3] * B[0];
				}
			}
		}
	}
}

LIB_HIDDEN void
conv_1_448_1_1 (const float x[1][448][1][1],
                const float w[42][448][1][1],
                const float bias[42],
                float       y[1][42][1][1])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 1
	 * kernel_shape: 1 1
	 * pads: 0 0 0 0
	 * strides: 1 1
	 */
	for (int m = 0; m < 42; m++) {
		for (int o0 = 0, i0 = 0; o0 < 1; o0++, i0 += 1) {
			for (int o1 = 0, i1 = 0; o1 < 1; o1++, i1 += 1) {
				y[0][m][o0][o1] = bias[m];
				for (int c = 0; c < 448; c++) {
					for (int k0 = 0; k0 < 1; k0++) {
						for (int k1 = 0; k1 < 1; k1++) {
							int ii0 = i0 + k0 * 1;
							if (ii0 < 0)
								continue;
							if (ii0 >= 1)
								continue;
							int ii1 = i1 + k1 * 1;
							if (ii1 < 0)
								continue;
							if (ii1 >= 1)
								continue;
							y[0][m][o0][o1] += x[0][c][ii0][ii1] * w[m][c][k0][k1];
						} /* k */
					}         /* k */
				}                 /* c */
			}                         /* o */
		}                                 /* o */
	}                                         /* m */
}

LIB_HIDDEN void
func_024f701e4f6 (const float x[1][168][56][56],
                  const float w[168][56][3][3],
                  const float bias[168],
                  float       y[1][168][56][56])
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1
	 * group: 3
	 * kernel_shape: 3 3
	 * pads: 1 1 1 1
	 * strides: 1 1
	 */
	for (int g = 0; g < 3; g++) {
		for (int m = 56 * g; m < 56 * (g + 1); m++) {
			for (int o0 = 0, i0 = -1; o0 < 56; o0++, i0 += 1) {
				for (int o1 = 0, i1 = -1; o1 < 56; o1++, i1 += 1) {
					y[0][m][o0][o1] = bias[m];
					for (int c = 56 * g; c < 56 * (g + 1); c++) {
						for (int k0 = 0; k0 < 3; k0++) {
							for (int k1 = 0; k1 < 3; k1++) {
								int ii0 = i0 + k0 * 1;
								if (ii0 < 0)
									continue;
								if (ii0 >= 56)
									continue;
								int ii1 = i1 + k1 * 1;
								if (ii1 < 0)
									continue;
								if (ii1 >= 56)
									continue;
								y[0][m][o0][o1] += x[0][c][ii0][ii1] * w[m][c - (56 * g)][k0][k1];
							} /* k */
						}         /* k */
					}                 /* c */
				}                         /* o */
			}                                 /* o */
		}                                         /* m */
	}                                                 /* g */
}
