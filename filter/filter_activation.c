#include <math.h>

#include "filter_activation.h"

/*
 * Operand:           Conv
 * Name: filtermodel/stem_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stem_conv_Conv2D( const float x[1][3][224][224], const float w[32][3][3][3], const float bias[32], float y[1][32][112][112] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<32; m++) {
		for( int32_t o0=0, i0=-1; o0<112; o0++, i0+=2) {
		for( int32_t o1=0, i1=-1; o1<112; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<3; c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=224) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=224) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stem_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stem_relu_Relu( const float X[1][32][112][112], float Y[1][32][112][112] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<401408; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack1_block1_shortcut_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack1_block1_shortcut_conv_Conv2D( const float x[1][32][112][112], const float w[168][32][1][1], const float bias[168], float y[1][168][56][56] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<168; m++) {
		for( int32_t o0=0, i0=0; o0<56; o0++, i0+=2) {
		for( int32_t o1=0, i1=0; o1<56; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<32; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=112) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=112) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack1_block1_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack1_block1_deep_1_conv_Conv2D( const float x[1][32][112][112], const float w[168][32][1][1], const float bias[168], float y[1][168][112][112] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<168; m++) {
		for( int32_t o0=0, i0=0; o0<112; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<112; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<32; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=112) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=112) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack1_block1_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack1_block1_deep_1_relu_Relu( const float X[1][168][112][112], float Y[1][168][112][112] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<2107392; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack1_block1_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack1_block1_deep_2_GC_conv_Conv2D( const float x[1][168][112][112], const float w[168][56][3][3], const float bias[168], float y[1][168][56][56] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<3; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<56; o0++, i0+=2) {
		for( int32_t o1=0, i1=-1; o1<56; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=112) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=112) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack1_block1_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack1_block1_deep_2_relu_Relu( const float X[1][168][56][56], float Y[1][168][56][56] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<526848; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_Mean( const float input[1][168][56][56], float output[1][168][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<168; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<56; d0++ ) {
		for( int32_t d1 = 0; d1<56; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 3136;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack1_block1_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack1_block1_deep_2_se_1_conv_BiasAdd( const float x[1][168][1][1], const float w[8][168][1][1], const float bias[8], float y[1][8][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<8; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<168; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack1_block1_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack1_block1_deep_2_se_relu_Relu( const float X[1][8][1][1], float Y[1][8][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<8; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack1_block1_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack1_block1_deep_2_se_2_conv_BiasAdd( const float x[1][8][1][1], const float w[168][8][1][1], const float bias[168], float y[1][168][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<168; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<8; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack1_block1_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack1_block1_deep_2_se_sigmoid_Sigmoid( const float X[1][168][1][1], float Y[1][168][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<168; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack1_block1_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack1_block1_deep_2_se_out_mul( const float A[1][168][56][56], const float B[1][168][1][1], float C[1][168][56][56] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<168; i1++) {
	for (unsigned i2=0; i2<56; i2++) {
	for (unsigned i3=0; i3<56; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack1_block1_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack1_block1_deep_3_conv_Conv2D( const float x[1][168][56][56], const float w[168][168][1][1], const float bias[168], float y[1][168][56][56] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<168; m++) {
		for( int32_t o0=0, i0=0; o0<56; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<56; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<168; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=56) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=56) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack1_block1_add/add
 */
LIB_HIDDEN void node_filtermodel_stack1_block1_add_add( const float A[1][168][56][56], const float B[1][168][56][56], float C[1][168][56][56] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<168; i1++) {
	for (unsigned i2=0; i2<56; i2++) {
	for (unsigned i3=0; i3<56; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack1_block1_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack1_block1_out_relu_Relu( const float X[1][168][56][56], float Y[1][168][56][56] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<526848; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack1_block2_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack1_block2_deep_1_conv_Conv2D( const float x[1][168][56][56], const float w[168][168][1][1], const float bias[168], float y[1][168][56][56] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<168; m++) {
		for( int32_t o0=0, i0=0; o0<56; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<56; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<168; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=56) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=56) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack1_block2_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack1_block2_deep_1_relu_Relu( const float X[1][168][56][56], float Y[1][168][56][56] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<526848; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack1_block2_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack1_block2_deep_2_GC_conv_Conv2D( const float x[1][168][56][56], const float w[168][56][3][3], const float bias[168], float y[1][168][56][56] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<3; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<56; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<56; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=56) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=56) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack1_block2_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack1_block2_deep_2_relu_Relu( const float X[1][168][56][56], float Y[1][168][56][56] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<526848; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_1/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_1_Mean( const float input[1][168][56][56], float output[1][168][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<168; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<56; d0++ ) {
		for( int32_t d1 = 0; d1<56; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 3136;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack1_block2_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack1_block2_deep_2_se_1_conv_BiasAdd( const float x[1][168][1][1], const float w[42][168][1][1], const float bias[42], float y[1][42][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<42; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<168; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack1_block2_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack1_block2_deep_2_se_relu_Relu( const float X[1][42][1][1], float Y[1][42][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<42; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack1_block2_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack1_block2_deep_2_se_2_conv_BiasAdd( const float x[1][42][1][1], const float w[168][42][1][1], const float bias[168], float y[1][168][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<168; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<42; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack1_block2_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack1_block2_deep_2_se_sigmoid_Sigmoid( const float X[1][168][1][1], float Y[1][168][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<168; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack1_block2_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack1_block2_deep_2_se_out_mul( const float A[1][168][56][56], const float B[1][168][1][1], float C[1][168][56][56] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<168; i1++) {
	for (unsigned i2=0; i2<56; i2++) {
	for (unsigned i3=0; i3<56; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack1_block2_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack1_block2_deep_3_conv_Conv2D( const float x[1][168][56][56], const float w[168][168][1][1], const float bias[168], float y[1][168][56][56] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<168; m++) {
		for( int32_t o0=0, i0=0; o0<56; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<56; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<168; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=56) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=56) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack1_block2_add/add
 */
LIB_HIDDEN void node_filtermodel_stack1_block2_add_add( const float A[1][168][56][56], const float B[1][168][56][56], float C[1][168][56][56] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<168; i1++) {
	for (unsigned i2=0; i2<56; i2++) {
	for (unsigned i3=0; i3<56; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack1_block2_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack1_block2_out_relu_Relu( const float X[1][168][56][56], float Y[1][168][56][56] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<526848; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block1_shortcut_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack2_block1_shortcut_conv_Conv2D( const float x[1][168][56][56], const float w[448][168][1][1], const float bias[448], float y[1][448][28][28] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<448; m++) {
		for( int32_t o0=0, i0=0; o0<28; o0++, i0+=2) {
		for( int32_t o1=0, i1=0; o1<28; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<168; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=56) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=56) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block1_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack2_block1_deep_1_conv_Conv2D( const float x[1][168][56][56], const float w[448][168][1][1], const float bias[448], float y[1][448][56][56] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<448; m++) {
		for( int32_t o0=0, i0=0; o0<56; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<56; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<168; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=56) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=56) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block1_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block1_deep_1_relu_Relu( const float X[1][448][56][56], float Y[1][448][56][56] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<1404928; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block1_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack2_block1_deep_2_GC_conv_Conv2D( const float x[1][448][56][56], const float w[448][56][3][3], const float bias[448], float y[1][448][28][28] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<8; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<28; o0++, i0+=2) {
		for( int32_t o1=0, i1=-1; o1<28; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=56) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=56) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block1_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block1_deep_2_relu_Relu( const float X[1][448][28][28], float Y[1][448][28][28] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<351232; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_2/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_2_Mean( const float input[1][448][28][28], float output[1][448][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<448; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<28; d0++ ) {
		for( int32_t d1 = 0; d1<28; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 784;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block1_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack2_block1_deep_2_se_1_conv_BiasAdd( const float x[1][448][1][1], const float w[42][448][1][1], const float bias[42], float y[1][42][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<42; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<448; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block1_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block1_deep_2_se_relu_Relu( const float X[1][42][1][1], float Y[1][42][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<42; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block1_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack2_block1_deep_2_se_2_conv_BiasAdd( const float x[1][42][1][1], const float w[448][42][1][1], const float bias[448], float y[1][448][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<448; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<42; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack2_block1_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack2_block1_deep_2_se_sigmoid_Sigmoid( const float X[1][448][1][1], float Y[1][448][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<448; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack2_block1_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack2_block1_deep_2_se_out_mul( const float A[1][448][28][28], const float B[1][448][1][1], float C[1][448][28][28] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<448; i1++) {
	for (unsigned i2=0; i2<28; i2++) {
	for (unsigned i3=0; i3<28; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block1_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack2_block1_deep_3_conv_Conv2D( const float x[1][448][28][28], const float w[448][448][1][1], const float bias[448], float y[1][448][28][28] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<448; m++) {
		for( int32_t o0=0, i0=0; o0<28; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<28; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<448; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=28) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=28) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack2_block1_add/add
 */
LIB_HIDDEN void node_filtermodel_stack2_block1_add_add( const float A[1][448][28][28], const float B[1][448][28][28], float C[1][448][28][28] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<448; i1++) {
	for (unsigned i2=0; i2<28; i2++) {
	for (unsigned i3=0; i3<28; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block1_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block1_out_relu_Relu( const float X[1][448][28][28], float Y[1][448][28][28] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<351232; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block2_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack2_block2_deep_1_conv_Conv2D( const float x[1][448][28][28], const float w[448][448][1][1], const float bias[448], float y[1][448][28][28] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<448; m++) {
		for( int32_t o0=0, i0=0; o0<28; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<28; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<448; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=28) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=28) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block2_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block2_deep_1_relu_Relu( const float X[1][448][28][28], float Y[1][448][28][28] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<351232; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block2_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack2_block2_deep_2_GC_conv_Conv2D( const float x[1][448][28][28], const float w[448][56][3][3], const float bias[448], float y[1][448][28][28] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<8; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<28; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<28; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=28) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=28) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block2_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block2_deep_2_relu_Relu( const float X[1][448][28][28], float Y[1][448][28][28] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<351232; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_3/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_3_Mean( const float input[1][448][28][28], float output[1][448][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<448; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<28; d0++ ) {
		for( int32_t d1 = 0; d1<28; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 784;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block2_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack2_block2_deep_2_se_1_conv_BiasAdd( const float x[1][448][1][1], const float w[112][448][1][1], const float bias[112], float y[1][112][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<112; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<448; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block2_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block2_deep_2_se_relu_Relu( const float X[1][112][1][1], float Y[1][112][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<112; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block2_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack2_block2_deep_2_se_2_conv_BiasAdd( const float x[1][112][1][1], const float w[448][112][1][1], const float bias[448], float y[1][448][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<448; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<112; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack2_block2_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack2_block2_deep_2_se_sigmoid_Sigmoid( const float X[1][448][1][1], float Y[1][448][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<448; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack2_block2_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack2_block2_deep_2_se_out_mul( const float A[1][448][28][28], const float B[1][448][1][1], float C[1][448][28][28] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<448; i1++) {
	for (unsigned i2=0; i2<28; i2++) {
	for (unsigned i3=0; i3<28; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block2_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack2_block2_deep_3_conv_Conv2D( const float x[1][448][28][28], const float w[448][448][1][1], const float bias[448], float y[1][448][28][28] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<448; m++) {
		for( int32_t o0=0, i0=0; o0<28; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<28; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<448; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=28) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=28) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack2_block2_add/add
 */
LIB_HIDDEN void node_filtermodel_stack2_block2_add_add( const float A[1][448][28][28], const float B[1][448][28][28], float C[1][448][28][28] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<448; i1++) {
	for (unsigned i2=0; i2<28; i2++) {
	for (unsigned i3=0; i3<28; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block2_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block2_out_relu_Relu( const float X[1][448][28][28], float Y[1][448][28][28] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<351232; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block3_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack2_block3_deep_1_conv_Conv2D( const float x[1][448][28][28], const float w[448][448][1][1], const float bias[448], float y[1][448][28][28] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<448; m++) {
		for( int32_t o0=0, i0=0; o0<28; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<28; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<448; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=28) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=28) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block3_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block3_deep_1_relu_Relu( const float X[1][448][28][28], float Y[1][448][28][28] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<351232; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block3_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack2_block3_deep_2_GC_conv_Conv2D( const float x[1][448][28][28], const float w[448][56][3][3], const float bias[448], float y[1][448][28][28] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<8; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<28; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<28; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=28) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=28) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block3_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block3_deep_2_relu_Relu( const float X[1][448][28][28], float Y[1][448][28][28] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<351232; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_4/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_4_Mean( const float input[1][448][28][28], float output[1][448][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<448; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<28; d0++ ) {
		for( int32_t d1 = 0; d1<28; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 784;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block3_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack2_block3_deep_2_se_1_conv_BiasAdd( const float x[1][448][1][1], const float w[112][448][1][1], const float bias[112], float y[1][112][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<112; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<448; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block3_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block3_deep_2_se_relu_Relu( const float X[1][112][1][1], float Y[1][112][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<112; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block3_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack2_block3_deep_2_se_2_conv_BiasAdd( const float x[1][112][1][1], const float w[448][112][1][1], const float bias[448], float y[1][448][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<448; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<112; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack2_block3_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack2_block3_deep_2_se_sigmoid_Sigmoid( const float X[1][448][1][1], float Y[1][448][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<448; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack2_block3_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack2_block3_deep_2_se_out_mul( const float A[1][448][28][28], const float B[1][448][1][1], float C[1][448][28][28] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<448; i1++) {
	for (unsigned i2=0; i2<28; i2++) {
	for (unsigned i3=0; i3<28; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block3_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack2_block3_deep_3_conv_Conv2D( const float x[1][448][28][28], const float w[448][448][1][1], const float bias[448], float y[1][448][28][28] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<448; m++) {
		for( int32_t o0=0, i0=0; o0<28; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<28; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<448; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=28) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=28) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack2_block3_add/add
 */
LIB_HIDDEN void node_filtermodel_stack2_block3_add_add( const float A[1][448][28][28], const float B[1][448][28][28], float C[1][448][28][28] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<448; i1++) {
	for (unsigned i2=0; i2<28; i2++) {
	for (unsigned i3=0; i3<28; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block3_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block3_out_relu_Relu( const float X[1][448][28][28], float Y[1][448][28][28] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<351232; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block4_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack2_block4_deep_1_conv_Conv2D( const float x[1][448][28][28], const float w[448][448][1][1], const float bias[448], float y[1][448][28][28] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<448; m++) {
		for( int32_t o0=0, i0=0; o0<28; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<28; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<448; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=28) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=28) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block4_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block4_deep_1_relu_Relu( const float X[1][448][28][28], float Y[1][448][28][28] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<351232; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block4_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack2_block4_deep_2_GC_conv_Conv2D( const float x[1][448][28][28], const float w[448][56][3][3], const float bias[448], float y[1][448][28][28] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<8; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<28; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<28; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=28) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=28) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block4_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block4_deep_2_relu_Relu( const float X[1][448][28][28], float Y[1][448][28][28] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<351232; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_5/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_5_Mean( const float input[1][448][28][28], float output[1][448][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<448; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<28; d0++ ) {
		for( int32_t d1 = 0; d1<28; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 784;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block4_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack2_block4_deep_2_se_1_conv_BiasAdd( const float x[1][448][1][1], const float w[112][448][1][1], const float bias[112], float y[1][112][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<112; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<448; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block4_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block4_deep_2_se_relu_Relu( const float X[1][112][1][1], float Y[1][112][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<112; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block4_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack2_block4_deep_2_se_2_conv_BiasAdd( const float x[1][112][1][1], const float w[448][112][1][1], const float bias[448], float y[1][448][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<448; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<112; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack2_block4_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack2_block4_deep_2_se_sigmoid_Sigmoid( const float X[1][448][1][1], float Y[1][448][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<448; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack2_block4_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack2_block4_deep_2_se_out_mul( const float A[1][448][28][28], const float B[1][448][1][1], float C[1][448][28][28] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<448; i1++) {
	for (unsigned i2=0; i2<28; i2++) {
	for (unsigned i3=0; i3<28; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack2_block4_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack2_block4_deep_3_conv_Conv2D( const float x[1][448][28][28], const float w[448][448][1][1], const float bias[448], float y[1][448][28][28] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<448; m++) {
		for( int32_t o0=0, i0=0; o0<28; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<28; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<448; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=28) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=28) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack2_block4_add/add
 */
LIB_HIDDEN void node_filtermodel_stack2_block4_add_add( const float A[1][448][28][28], const float B[1][448][28][28], float C[1][448][28][28] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<448; i1++) {
	for (unsigned i2=0; i2<28; i2++) {
	for (unsigned i3=0; i3<28; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack2_block4_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack2_block4_out_relu_Relu( const float X[1][448][28][28], float Y[1][448][28][28] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<351232; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block1_shortcut_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block1_shortcut_conv_Conv2D( const float x[1][448][28][28], const float w[896][448][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=2) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<448; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=28) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=28) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block1_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block1_deep_1_conv_Conv2D( const float x[1][448][28][28], const float w[896][448][1][1], const float bias[896], float y[1][896][28][28] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<28; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<28; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<448; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=28) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=28) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block1_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block1_deep_1_relu_Relu( const float X[1][896][28][28], float Y[1][896][28][28] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<702464; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block1_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block1_deep_2_GC_conv_Conv2D( const float x[1][896][28][28], const float w[896][56][3][3], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<16; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<14; o0++, i0+=2) {
		for( int32_t o1=0, i1=-1; o1<14; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=28) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=28) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block1_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block1_deep_2_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_6/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_6_Mean( const float input[1][896][14][14], float output[1][896][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<896; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<14; d0++ ) {
		for( int32_t d1 = 0; d1<14; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 196;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block1_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block1_deep_2_se_1_conv_BiasAdd( const float x[1][896][1][1], const float w[112][896][1][1], const float bias[112], float y[1][112][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<112; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block1_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block1_deep_2_se_relu_Relu( const float X[1][112][1][1], float Y[1][112][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<112; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block1_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block1_deep_2_se_2_conv_BiasAdd( const float x[1][112][1][1], const float w[896][112][1][1], const float bias[896], float y[1][896][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<112; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack3_block1_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack3_block1_deep_2_se_sigmoid_Sigmoid( const float X[1][896][1][1], float Y[1][896][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack3_block1_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack3_block1_deep_2_se_out_mul( const float A[1][896][14][14], const float B[1][896][1][1], float C[1][896][14][14] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block1_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block1_deep_3_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack3_block1_add/add
 */
LIB_HIDDEN void node_filtermodel_stack3_block1_add_add( const float A[1][896][14][14], const float B[1][896][14][14], float C[1][896][14][14] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block1_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block1_out_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block2_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block2_deep_1_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block2_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block2_deep_1_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block2_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block2_deep_2_GC_conv_Conv2D( const float x[1][896][14][14], const float w[896][56][3][3], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<16; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block2_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block2_deep_2_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_7/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_7_Mean( const float input[1][896][14][14], float output[1][896][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<896; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<14; d0++ ) {
		for( int32_t d1 = 0; d1<14; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 196;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block2_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block2_deep_2_se_1_conv_BiasAdd( const float x[1][896][1][1], const float w[224][896][1][1], const float bias[224], float y[1][224][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<224; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block2_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block2_deep_2_se_relu_Relu( const float X[1][224][1][1], float Y[1][224][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<224; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block2_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block2_deep_2_se_2_conv_BiasAdd( const float x[1][224][1][1], const float w[896][224][1][1], const float bias[896], float y[1][896][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<224; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack3_block2_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack3_block2_deep_2_se_sigmoid_Sigmoid( const float X[1][896][1][1], float Y[1][896][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack3_block2_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack3_block2_deep_2_se_out_mul( const float A[1][896][14][14], const float B[1][896][1][1], float C[1][896][14][14] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block2_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block2_deep_3_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack3_block2_add/add
 */
LIB_HIDDEN void node_filtermodel_stack3_block2_add_add( const float A[1][896][14][14], const float B[1][896][14][14], float C[1][896][14][14] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block2_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block2_out_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block3_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block3_deep_1_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block3_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block3_deep_1_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block3_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block3_deep_2_GC_conv_Conv2D( const float x[1][896][14][14], const float w[896][56][3][3], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<16; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block3_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block3_deep_2_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_8/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_8_Mean( const float input[1][896][14][14], float output[1][896][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<896; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<14; d0++ ) {
		for( int32_t d1 = 0; d1<14; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 196;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block3_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block3_deep_2_se_1_conv_BiasAdd( const float x[1][896][1][1], const float w[224][896][1][1], const float bias[224], float y[1][224][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<224; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block3_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block3_deep_2_se_relu_Relu( const float X[1][224][1][1], float Y[1][224][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<224; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block3_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block3_deep_2_se_2_conv_BiasAdd( const float x[1][224][1][1], const float w[896][224][1][1], const float bias[896], float y[1][896][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<224; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack3_block3_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack3_block3_deep_2_se_sigmoid_Sigmoid( const float X[1][896][1][1], float Y[1][896][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack3_block3_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack3_block3_deep_2_se_out_mul( const float A[1][896][14][14], const float B[1][896][1][1], float C[1][896][14][14] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block3_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block3_deep_3_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack3_block3_add/add
 */
LIB_HIDDEN void node_filtermodel_stack3_block3_add_add( const float A[1][896][14][14], const float B[1][896][14][14], float C[1][896][14][14] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block3_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block3_out_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block4_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block4_deep_1_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block4_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block4_deep_1_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block4_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block4_deep_2_GC_conv_Conv2D( const float x[1][896][14][14], const float w[896][56][3][3], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<16; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block4_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block4_deep_2_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_9/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_9_Mean( const float input[1][896][14][14], float output[1][896][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<896; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<14; d0++ ) {
		for( int32_t d1 = 0; d1<14; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 196;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block4_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block4_deep_2_se_1_conv_BiasAdd( const float x[1][896][1][1], const float w[224][896][1][1], const float bias[224], float y[1][224][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<224; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block4_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block4_deep_2_se_relu_Relu( const float X[1][224][1][1], float Y[1][224][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<224; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block4_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block4_deep_2_se_2_conv_BiasAdd( const float x[1][224][1][1], const float w[896][224][1][1], const float bias[896], float y[1][896][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<224; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack3_block4_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack3_block4_deep_2_se_sigmoid_Sigmoid( const float X[1][896][1][1], float Y[1][896][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack3_block4_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack3_block4_deep_2_se_out_mul( const float A[1][896][14][14], const float B[1][896][1][1], float C[1][896][14][14] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block4_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block4_deep_3_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack3_block4_add/add
 */
LIB_HIDDEN void node_filtermodel_stack3_block4_add_add( const float A[1][896][14][14], const float B[1][896][14][14], float C[1][896][14][14] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block4_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block4_out_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block5_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block5_deep_1_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block5_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block5_deep_1_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block5_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block5_deep_2_GC_conv_Conv2D( const float x[1][896][14][14], const float w[896][56][3][3], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<16; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block5_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block5_deep_2_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_10/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_10_Mean( const float input[1][896][14][14], float output[1][896][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<896; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<14; d0++ ) {
		for( int32_t d1 = 0; d1<14; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 196;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block5_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block5_deep_2_se_1_conv_BiasAdd( const float x[1][896][1][1], const float w[224][896][1][1], const float bias[224], float y[1][224][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<224; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block5_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block5_deep_2_se_relu_Relu( const float X[1][224][1][1], float Y[1][224][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<224; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block5_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block5_deep_2_se_2_conv_BiasAdd( const float x[1][224][1][1], const float w[896][224][1][1], const float bias[896], float y[1][896][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<224; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack3_block5_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack3_block5_deep_2_se_sigmoid_Sigmoid( const float X[1][896][1][1], float Y[1][896][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack3_block5_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack3_block5_deep_2_se_out_mul( const float A[1][896][14][14], const float B[1][896][1][1], float C[1][896][14][14] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block5_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block5_deep_3_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack3_block5_add/add
 */
LIB_HIDDEN void node_filtermodel_stack3_block5_add_add( const float A[1][896][14][14], const float B[1][896][14][14], float C[1][896][14][14] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block5_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block5_out_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block6_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block6_deep_1_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block6_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block6_deep_1_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block6_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block6_deep_2_GC_conv_Conv2D( const float x[1][896][14][14], const float w[896][56][3][3], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<16; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block6_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block6_deep_2_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_11/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_11_Mean( const float input[1][896][14][14], float output[1][896][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<896; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<14; d0++ ) {
		for( int32_t d1 = 0; d1<14; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 196;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block6_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block6_deep_2_se_1_conv_BiasAdd( const float x[1][896][1][1], const float w[224][896][1][1], const float bias[224], float y[1][224][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<224; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block6_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block6_deep_2_se_relu_Relu( const float X[1][224][1][1], float Y[1][224][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<224; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block6_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block6_deep_2_se_2_conv_BiasAdd( const float x[1][224][1][1], const float w[896][224][1][1], const float bias[896], float y[1][896][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<224; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack3_block6_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack3_block6_deep_2_se_sigmoid_Sigmoid( const float X[1][896][1][1], float Y[1][896][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack3_block6_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack3_block6_deep_2_se_out_mul( const float A[1][896][14][14], const float B[1][896][1][1], float C[1][896][14][14] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block6_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block6_deep_3_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack3_block6_add/add
 */
LIB_HIDDEN void node_filtermodel_stack3_block6_add_add( const float A[1][896][14][14], const float B[1][896][14][14], float C[1][896][14][14] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block6_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block6_out_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block7_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block7_deep_1_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block7_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block7_deep_1_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block7_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block7_deep_2_GC_conv_Conv2D( const float x[1][896][14][14], const float w[896][56][3][3], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<16; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block7_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block7_deep_2_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_12/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_12_Mean( const float input[1][896][14][14], float output[1][896][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<896; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<14; d0++ ) {
		for( int32_t d1 = 0; d1<14; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 196;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block7_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block7_deep_2_se_1_conv_BiasAdd( const float x[1][896][1][1], const float w[224][896][1][1], const float bias[224], float y[1][224][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<224; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block7_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block7_deep_2_se_relu_Relu( const float X[1][224][1][1], float Y[1][224][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<224; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block7_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block7_deep_2_se_2_conv_BiasAdd( const float x[1][224][1][1], const float w[896][224][1][1], const float bias[896], float y[1][896][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<224; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack3_block7_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack3_block7_deep_2_se_sigmoid_Sigmoid( const float X[1][896][1][1], float Y[1][896][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack3_block7_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack3_block7_deep_2_se_out_mul( const float A[1][896][14][14], const float B[1][896][1][1], float C[1][896][14][14] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block7_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block7_deep_3_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack3_block7_add/add
 */
LIB_HIDDEN void node_filtermodel_stack3_block7_add_add( const float A[1][896][14][14], const float B[1][896][14][14], float C[1][896][14][14] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block7_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block7_out_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block8_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block8_deep_1_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block8_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block8_deep_1_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block8_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block8_deep_2_GC_conv_Conv2D( const float x[1][896][14][14], const float w[896][56][3][3], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<16; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block8_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block8_deep_2_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_13/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_13_Mean( const float input[1][896][14][14], float output[1][896][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<896; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<14; d0++ ) {
		for( int32_t d1 = 0; d1<14; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 196;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block8_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block8_deep_2_se_1_conv_BiasAdd( const float x[1][896][1][1], const float w[224][896][1][1], const float bias[224], float y[1][224][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<224; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block8_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block8_deep_2_se_relu_Relu( const float X[1][224][1][1], float Y[1][224][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<224; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block8_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block8_deep_2_se_2_conv_BiasAdd( const float x[1][224][1][1], const float w[896][224][1][1], const float bias[896], float y[1][896][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<224; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack3_block8_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack3_block8_deep_2_se_sigmoid_Sigmoid( const float X[1][896][1][1], float Y[1][896][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack3_block8_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack3_block8_deep_2_se_out_mul( const float A[1][896][14][14], const float B[1][896][1][1], float C[1][896][14][14] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block8_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block8_deep_3_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack3_block8_add/add
 */
LIB_HIDDEN void node_filtermodel_stack3_block8_add_add( const float A[1][896][14][14], const float B[1][896][14][14], float C[1][896][14][14] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block8_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block8_out_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block9_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block9_deep_1_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block9_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block9_deep_1_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block9_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block9_deep_2_GC_conv_Conv2D( const float x[1][896][14][14], const float w[896][56][3][3], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<16; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block9_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block9_deep_2_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_14/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_14_Mean( const float input[1][896][14][14], float output[1][896][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<896; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<14; d0++ ) {
		for( int32_t d1 = 0; d1<14; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 196;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block9_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block9_deep_2_se_1_conv_BiasAdd( const float x[1][896][1][1], const float w[224][896][1][1], const float bias[224], float y[1][224][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<224; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block9_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block9_deep_2_se_relu_Relu( const float X[1][224][1][1], float Y[1][224][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<224; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block9_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block9_deep_2_se_2_conv_BiasAdd( const float x[1][224][1][1], const float w[896][224][1][1], const float bias[896], float y[1][896][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<224; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack3_block9_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack3_block9_deep_2_se_sigmoid_Sigmoid( const float X[1][896][1][1], float Y[1][896][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack3_block9_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack3_block9_deep_2_se_out_mul( const float A[1][896][14][14], const float B[1][896][1][1], float C[1][896][14][14] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block9_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block9_deep_3_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack3_block9_add/add
 */
LIB_HIDDEN void node_filtermodel_stack3_block9_add_add( const float A[1][896][14][14], const float B[1][896][14][14], float C[1][896][14][14] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block9_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block9_out_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block10_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block10_deep_1_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block10_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block10_deep_1_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block10_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block10_deep_2_GC_conv_Conv2D( const float x[1][896][14][14], const float w[896][56][3][3], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<16; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block10_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block10_deep_2_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_15/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_15_Mean( const float input[1][896][14][14], float output[1][896][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<896; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<14; d0++ ) {
		for( int32_t d1 = 0; d1<14; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 196;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block10_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block10_deep_2_se_1_conv_BiasAdd( const float x[1][896][1][1], const float w[224][896][1][1], const float bias[224], float y[1][224][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<224; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block10_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block10_deep_2_se_relu_Relu( const float X[1][224][1][1], float Y[1][224][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<224; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block10_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack3_block10_deep_2_se_2_conv_BiasAdd( const float x[1][224][1][1], const float w[896][224][1][1], const float bias[896], float y[1][896][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<224; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack3_block10_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack3_block10_deep_2_se_sigmoid_Sigmoid( const float X[1][896][1][1], float Y[1][896][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack3_block10_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack3_block10_deep_2_se_out_mul( const float A[1][896][14][14], const float B[1][896][1][1], float C[1][896][14][14] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack3_block10_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack3_block10_deep_3_conv_Conv2D( const float x[1][896][14][14], const float w[896][896][1][1], const float bias[896], float y[1][896][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<896; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack3_block10_add/add
 */
LIB_HIDDEN void node_filtermodel_stack3_block10_add_add( const float A[1][896][14][14], const float B[1][896][14][14], float C[1][896][14][14] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<896; i1++) {
	for (unsigned i2=0; i2<14; i2++) {
	for (unsigned i3=0; i3<14; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack3_block10_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack3_block10_out_relu_Relu( const float X[1][896][14][14], float Y[1][896][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<175616; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack4_block1_shortcut_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack4_block1_shortcut_conv_Conv2D( const float x[1][896][14][14], const float w[2016][896][1][1], const float bias[2016], float y[1][2016][7][7] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<2016; m++) {
		for( int32_t o0=0, i0=0; o0<7; o0++, i0+=2) {
		for( int32_t o1=0, i1=0; o1<7; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack4_block1_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack4_block1_deep_1_conv_Conv2D( const float x[1][896][14][14], const float w[2016][896][1][1], const float bias[2016], float y[1][2016][14][14] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<2016; m++) {
		for( int32_t o0=0, i0=0; o0<14; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<14; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<896; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack4_block1_deep_1_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack4_block1_deep_1_relu_Relu( const float X[1][2016][14][14], float Y[1][2016][14][14] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<395136; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack4_block1_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack4_block1_deep_2_GC_conv_Conv2D( const float x[1][2016][14][14], const float w[2016][56][3][3], const float bias[2016], float y[1][2016][7][7] )
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
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 56; // output group size, i.e. maps/group
	uint32_t gi = 56; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<36; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<7; o0++, i0+=2) {
		for( int32_t o1=0, i1=-1; o1<7; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=14) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=14) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c-(gi*g)][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
		} /* g */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack4_block1_deep_2_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack4_block1_deep_2_relu_Relu( const float X[1][2016][7][7], float Y[1][2016][7][7] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<98784; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/tf.math.reduce_mean_16/Mean
 */
LIB_HIDDEN void node_filtermodel_tf_math_reduce_mean_16_Mean( const float input[1][2016][7][7], float output[1][2016][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<2016; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<7; d0++ ) {
		for( int32_t d1 = 0; d1<7; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 49;
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack4_block1_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack4_block1_deep_2_se_1_conv_BiasAdd( const float x[1][2016][1][1], const float w[224][2016][1][1], const float bias[224], float y[1][224][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<224; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<2016; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack4_block1_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack4_block1_deep_2_se_relu_Relu( const float X[1][224][1][1], float Y[1][224][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<224; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: filtermodel/stack4_block1_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_stack4_block1_deep_2_se_2_conv_BiasAdd( const float x[1][224][1][1], const float w[2016][224][1][1], const float bias[2016], float y[1][2016][1][1] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<2016; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<224; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=1) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=1) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Sigmoid
 * Name: filtermodel/stack4_block1_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_filtermodel_stack4_block1_deep_2_se_sigmoid_Sigmoid( const float X[1][2016][1][1], float Y[1][2016][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<2016; i1++) {
	for (unsigned i2=0; i2<1; i2++) {
	for (unsigned i3=0; i3<1; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: filtermodel/stack4_block1_deep_2_se_out/mul
 */
LIB_HIDDEN void node_filtermodel_stack4_block1_deep_2_se_out_mul( const float A[1][2016][7][7], const float B[1][2016][1][1], float C[1][2016][7][7] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<2016; i1++) {
	for (unsigned i2=0; i2<7; i2++) {
	for (unsigned i3=0; i3<7; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: filtermodel/stack4_block1_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_filtermodel_stack4_block1_deep_3_conv_Conv2D( const float x[1][2016][7][7], const float w[2016][2016][1][1], const float bias[2016], float y[1][2016][7][7] )
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
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<2016; m++) {
		for( int32_t o0=0, i0=0; o0<7; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<7; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<2016; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=7) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=7) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

/*
 * Operand:           Add
 * Name: filtermodel/stack4_block1_add/add
 */
LIB_HIDDEN void node_filtermodel_stack4_block1_add_add( const float A[1][2016][7][7], const float B[1][2016][7][7], float C[1][2016][7][7] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<2016; i1++) {
	for (unsigned i2=0; i2<7; i2++) {
	for (unsigned i3=0; i3<7; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Relu
 * Name: filtermodel/stack4_block1_out_relu/Relu
 */
LIB_HIDDEN void node_filtermodel_stack4_block1_out_relu_Relu( const float X[1][2016][7][7], float Y[1][2016][7][7] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<98784; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           GlobalAveragePool
 * Name: filtermodel/avg_pool/Mean
 */
LIB_HIDDEN void node_filtermodel_avg_pool_Mean( const float input[1][2016][7][7], float output[1][2016][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<2016; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<7; d0++ ) {
		for( int32_t d1 = 0; d1<7; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 49;
	}
	}
}

/*
 * Operand:           Squeeze
 * Name: filtermodel/avg_pool/Mean_Squeeze__847
 */
LIB_HIDDEN void node_filtermodel_avg_pool_Mean_Squeeze__847( const float input[1][2016][1][1], const int64_t axes_tensor[2], float output[1][2016] )
{
	/*Squeeze*/
	float *data = (float*)input;
	float *squeezed= (float*)output;
	for( uint32_t i=0; i<2016; i++ )
		squeezed[i] = data[i];

}

/*
 * Operand:           MatMul
 * Name: filtermodel/predictions/MatMul
 */
LIB_HIDDEN void node_filtermodel_predictions_MatMul( const float A[1][2016], const float B[2016][3], float Y[1][3] )
{
	/* MatMul */
	for( uint32_t r=0; r<1; r++ )
		for( uint32_t c=0; c<3; c++ ) {
			Y[r][c] = 0;
			for( uint32_t i=0; i<2016; i++ )
				Y[r][c] += A[r][i] * B[i][c];
		}
}

/*
 * Operand:           Add
 * Name: filtermodel/predictions/BiasAdd
 */
LIB_HIDDEN void node_filtermodel_predictions_BiasAdd( const float A[1][3], const float B[3], float C[1][3] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<3; i1++) {
		C[i0][i1] = A[0][i1]+B[i1];;
	}
	}
}

/*
 * Operand:           Softmax
 * Name: filtermodel/predictions/Softmax
 */
LIB_HIDDEN void node_filtermodel_predictions_Softmax( const float input[1][3], float output[1][3] )
{
	/* Softmax 13 (TF, pytorch style)
	 * axis = -1
	 */
	for( uint32_t i0=0; i0<1; i0++ ) {
		float max = -INFINITY;
		for( uint32_t i1=0; i1<3; i1++ ) {
			max = max>input[i0][i1] ? max :input[i0][i1];
		};
		float sum = 0.0;
		for( uint32_t i1=0; i1<3; i1++ ) {
			sum += expf(input[i0][i1] - max);
		};
		for( uint32_t i1=0; i1<3; i1++ ) {
			output[i0][i1] = expf(input[i0][i1] - max)/sum;
		};
	}
}


