#include <math.h>

#include "positiveness_activation.h"

/*
 * Operand:           Conv
 * Name: positiveness/stem_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stem_conv_Conv2D( const float x[1][3][256][256], const float w[32][3][3][3], const float bias[32], float y[1][32][128][128] )
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
		for( int32_t o0=0, i0=-1; o0<128; o0++, i0+=2) {
		for( int32_t o1=0, i1=-1; o1<128; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<3; c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=256) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=256) continue;
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
 * Name: positiveness/stem_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stem_swish_Sigmoid( const float X[1][32][128][128], float Y[1][32][128][128] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<32; i1++) {
	for (unsigned i2=0; i2<128; i2++) {
	for (unsigned i3=0; i3<128; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stem_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stem_swish_mul_1( const float A[1][32][128][128], const float B[1][32][128][128], float C[1][32][128][128] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<32; i1++) {
	for (unsigned i2=0; i2<128; i2++) {
	for (unsigned i3=0; i3<128; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack1_block1_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack1_block1_deep_1_conv_Conv2D( const float x[1][32][128][128], const float w[128][32][1][1], const float bias[128], float y[1][128][128][128] )
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
	for( uint32_t m=0; m<128; m++) {
		for( int32_t o0=0, i0=0; o0<128; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<128; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<32; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=128) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=128) continue;
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
 * Name: positiveness/stack1_block1_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack1_block1_deep_1_swish_Sigmoid( const float X[1][128][128][128], float Y[1][128][128][128] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<128; i1++) {
	for (unsigned i2=0; i2<128; i2++) {
	for (unsigned i3=0; i3<128; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack1_block1_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack1_block1_deep_1_swish_mul_1( const float A[1][128][128][128], const float B[1][128][128][128], float C[1][128][128][128] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<128; i1++) {
	for (unsigned i2=0; i2<128; i2++) {
	for (unsigned i3=0; i3<128; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack1_block1_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack1_block1_deep_2_GC_conv_Conv2D( const float x[1][128][128][128], const float w[128][16][3][3], const float bias[128], float y[1][128][64][64] )
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
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<8; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<64; o0++, i0+=2) {
		for( int32_t o1=0, i1=-1; o1<64; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=128) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=128) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack1_block1_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack1_block1_deep_2_swish_Sigmoid( const float X[1][128][64][64], float Y[1][128][64][64] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<128; i1++) {
	for (unsigned i2=0; i2<64; i2++) {
	for (unsigned i3=0; i3<64; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack1_block1_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack1_block1_deep_2_swish_mul_1( const float A[1][128][64][64], const float B[1][128][64][64], float C[1][128][64][64] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<128; i1++) {
	for (unsigned i2=0; i2<64; i2++) {
	for (unsigned i3=0; i3<64; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_22/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_22_Mean( const float input[1][128][64][64], float output[1][128][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<128; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<64; d0++ ) {
		for( int32_t d1 = 0; d1<64; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 4096;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack1_block1_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack1_block1_deep_2_se_1_conv_BiasAdd( const float x[1][128][1][1], const float w[32][128][1][1], const float bias[32], float y[1][32][1][1] )
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
	for( uint32_t m=0; m<32; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<128; c++ ) {
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
 * Name: positiveness/stack1_block1_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack1_block1_deep_2_se_relu_Relu( const float X[1][32][1][1], float Y[1][32][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<32; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack1_block1_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack1_block1_deep_2_se_2_conv_BiasAdd( const float x[1][32][1][1], const float w[128][32][1][1], const float bias[128], float y[1][128][1][1] )
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
	for( uint32_t m=0; m<128; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<32; c++ ) {
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
 * Name: positiveness/stack1_block1_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack1_block1_deep_2_se_sigmoid_Sigmoid( const float X[1][128][1][1], float Y[1][128][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<128; i1++) {
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
 * Name: positiveness/stack1_block1_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack1_block1_deep_2_se_out_mul( const float A[1][128][64][64], const float B[1][128][1][1], float C[1][128][64][64] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<128; i1++) {
	for (unsigned i2=0; i2<64; i2++) {
	for (unsigned i3=0; i3<64; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack1_block1_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack1_block1_deep_3_conv_Conv2D( const float x[1][128][64][64], const float w[48][128][1][1], const float bias[48], float y[1][48][64][64] )
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
	for( uint32_t m=0; m<48; m++) {
		for( int32_t o0=0, i0=0; o0<64; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<64; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<128; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=64) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=64) continue;
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
 * Name: positiveness/stack1_block2_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack1_block2_deep_1_conv_Conv2D( const float x[1][48][64][64], const float w[192][48][1][1], float y[1][192][64][64] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<64; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<64; o1++, i1+=1) {
			y[b][m][o0][o1] = 0;
			for( int32_t c=0; c<48; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=64) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=64) continue;
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
 * Operand:           BatchNormalization
 * Name: positiveness/stack1_block2_deep_1_bn/FusedBatchNormV3
 */
LIB_HIDDEN void node_positiveness_stack1_block2_deep_1_bn_FusedBatchNormV3( const float X[1][192][64][64], const float scale[192], const float bias[192], const float mean[192], const float var[192], float output[1][192][64][64] )
{
	/* BatchNormalization
	 * epsilon = 1.0009999641624744982e-05
	 * momentum = 0.89999997615814208984
	 */

	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<192; c++ ) {
	for( uint32_t i2=0; i2<64; i2++ ) {
	for( uint32_t i3=0; i3<64; i3++ ) {
		float tmp_X = ( X[b][c][i2][i3] - mean[c] ) / ( var[c] );
		output[b][c][i2][i3] = tmp_X * scale[c] + bias[c];
	}
	}
	}
	}
}

/*
 * Operand:           Sigmoid
 * Name: positiveness/stack1_block2_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack1_block2_deep_1_swish_Sigmoid( const float X[1][192][64][64], float Y[1][192][64][64] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<64; i2++) {
	for (unsigned i3=0; i3<64; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack1_block2_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack1_block2_deep_1_swish_mul_1( const float A[1][192][64][64], const float B[1][192][64][64], float C[1][192][64][64] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<64; i2++) {
	for (unsigned i3=0; i3<64; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack1_block2_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack1_block2_deep_2_GC_conv_Conv2D( const float x[1][192][64][64], const float w[192][16][3][3], const float bias[192], float y[1][192][64][64] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 12
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<12; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<64; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<64; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=64) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=64) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack1_block2_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack1_block2_deep_2_swish_Sigmoid( const float X[1][192][64][64], float Y[1][192][64][64] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<64; i2++) {
	for (unsigned i3=0; i3<64; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack1_block2_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack1_block2_deep_2_swish_mul_1( const float A[1][192][64][64], const float B[1][192][64][64], float C[1][192][64][64] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<64; i2++) {
	for (unsigned i3=0; i3<64; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_23/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_23_Mean( const float input[1][192][64][64], float output[1][192][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<192; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<64; d0++ ) {
		for( int32_t d1 = 0; d1<64; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 4096;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack1_block2_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack1_block2_deep_2_se_1_conv_BiasAdd( const float x[1][192][1][1], const float w[48][192][1][1], const float bias[48], float y[1][48][1][1] )
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
	for( uint32_t m=0; m<48; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack1_block2_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack1_block2_deep_2_se_relu_Relu( const float X[1][48][1][1], float Y[1][48][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<48; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack1_block2_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack1_block2_deep_2_se_2_conv_BiasAdd( const float x[1][48][1][1], const float w[192][48][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<48; c++ ) {
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
 * Name: positiveness/stack1_block2_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack1_block2_deep_2_se_sigmoid_Sigmoid( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
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
 * Name: positiveness/stack1_block2_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack1_block2_deep_2_se_out_mul( const float A[1][192][64][64], const float B[1][192][1][1], float C[1][192][64][64] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<64; i2++) {
	for (unsigned i3=0; i3<64; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack1_block2_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack1_block2_deep_3_conv_Conv2D( const float x[1][192][64][64], const float w[48][192][1][1], const float bias[48], float y[1][48][64][64] )
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
	for( uint32_t m=0; m<48; m++) {
		for( int32_t o0=0, i0=0; o0<64; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<64; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=64) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=64) continue;
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
 * Name: positiveness/stack1_block2_add/add
 */
LIB_HIDDEN void node_positiveness_stack1_block2_add_add( const float A[1][48][64][64], const float B[1][48][64][64], float C[1][48][64][64] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<48; i1++) {
	for (unsigned i2=0; i2<64; i2++) {
	for (unsigned i3=0; i3<64; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block1_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block1_deep_1_conv_Conv2D( const float x[1][48][64][64], const float w[192][48][1][1], const float bias[192], float y[1][192][64][64] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<64; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<64; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<48; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=64) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=64) continue;
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
 * Name: positiveness/stack2_block1_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block1_deep_1_swish_Sigmoid( const float X[1][192][64][64], float Y[1][192][64][64] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<64; i2++) {
	for (unsigned i3=0; i3<64; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack2_block1_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack2_block1_deep_1_swish_mul_1( const float A[1][192][64][64], const float B[1][192][64][64], float C[1][192][64][64] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<64; i2++) {
	for (unsigned i3=0; i3<64; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block1_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block1_deep_2_GC_conv_Conv2D( const float x[1][192][64][64], const float w[192][16][3][3], const float bias[192], float y[1][192][32][32] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 12
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 2 2 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<12; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<32; o0++, i0+=2) {
		for( int32_t o1=0, i1=-1; o1<32; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=64) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=64) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack2_block1_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block1_deep_2_swish_Sigmoid( const float X[1][192][32][32], float Y[1][192][32][32] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack2_block1_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack2_block1_deep_2_swish_mul_1( const float A[1][192][32][32], const float B[1][192][32][32], float C[1][192][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_24/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_24_Mean( const float input[1][192][32][32], float output[1][192][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<192; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<32; d0++ ) {
		for( int32_t d1 = 0; d1<32; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 1024;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block1_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack2_block1_deep_2_se_1_conv_BiasAdd( const float x[1][192][1][1], const float w[48][192][1][1], const float bias[48], float y[1][48][1][1] )
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
	for( uint32_t m=0; m<48; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack2_block1_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack2_block1_deep_2_se_relu_Relu( const float X[1][48][1][1], float Y[1][48][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<48; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block1_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack2_block1_deep_2_se_2_conv_BiasAdd( const float x[1][48][1][1], const float w[192][48][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<48; c++ ) {
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
 * Name: positiveness/stack2_block1_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block1_deep_2_se_sigmoid_Sigmoid( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
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
 * Name: positiveness/stack2_block1_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack2_block1_deep_2_se_out_mul( const float A[1][192][32][32], const float B[1][192][1][1], float C[1][192][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block1_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block1_deep_3_conv_Conv2D( const float x[1][192][32][32], const float w[96][192][1][1], const float bias[96], float y[1][96][32][32] )
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
	for( uint32_t m=0; m<96; m++) {
		for( int32_t o0=0, i0=0; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Name: positiveness/stack2_block2_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block2_deep_1_conv_Conv2D( const float x[1][96][32][32], const float w[384][96][1][1], float y[1][384][32][32] )
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
	for( uint32_t m=0; m<384; m++) {
		for( int32_t o0=0, i0=0; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = 0;
			for( int32_t c=0; c<96; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Operand:           BatchNormalization
 * Name: positiveness/stack2_block2_deep_1_bn/FusedBatchNormV3
 */
LIB_HIDDEN void node_positiveness_stack2_block2_deep_1_bn_FusedBatchNormV3( const float X[1][384][32][32], const float scale[384], const float bias[384], const float mean[384], const float var[384], float output[1][384][32][32] )
{
	/* BatchNormalization
	 * epsilon = 1.0009999641624744982e-05
	 * momentum = 0.89999997615814208984
	 */

	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<384; c++ ) {
	for( uint32_t i2=0; i2<32; i2++ ) {
	for( uint32_t i3=0; i3<32; i3++ ) {
		float tmp_X = ( X[b][c][i2][i3] - mean[c] ) / ( var[c] );
		output[b][c][i2][i3] = tmp_X * scale[c] + bias[c];
	}
	}
	}
	}
}

/*
 * Operand:           Sigmoid
 * Name: positiveness/stack2_block2_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block2_deep_1_swish_Sigmoid( const float X[1][384][32][32], float Y[1][384][32][32] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack2_block2_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack2_block2_deep_1_swish_mul_1( const float A[1][384][32][32], const float B[1][384][32][32], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block2_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block2_deep_2_GC_conv_Conv2D( const float x[1][384][32][32], const float w[384][16][3][3], const float bias[384], float y[1][384][32][32] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 24
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<24; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack2_block2_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block2_deep_2_swish_Sigmoid( const float X[1][384][32][32], float Y[1][384][32][32] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack2_block2_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack2_block2_deep_2_swish_mul_1( const float A[1][384][32][32], const float B[1][384][32][32], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_25/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_25_Mean( const float input[1][384][32][32], float output[1][384][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<384; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<32; d0++ ) {
		for( int32_t d1 = 0; d1<32; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 1024;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block2_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack2_block2_deep_2_se_1_conv_BiasAdd( const float x[1][384][1][1], const float w[96][384][1][1], const float bias[96], float y[1][96][1][1] )
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
	for( uint32_t m=0; m<96; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<384; c++ ) {
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
 * Name: positiveness/stack2_block2_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack2_block2_deep_2_se_relu_Relu( const float X[1][96][1][1], float Y[1][96][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<96; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block2_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack2_block2_deep_2_se_2_conv_BiasAdd( const float x[1][96][1][1], const float w[384][96][1][1], const float bias[384], float y[1][384][1][1] )
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
	for( uint32_t m=0; m<384; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<96; c++ ) {
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
 * Name: positiveness/stack2_block2_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block2_deep_2_se_sigmoid_Sigmoid( const float X[1][384][1][1], float Y[1][384][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
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
 * Name: positiveness/stack2_block2_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack2_block2_deep_2_se_out_mul( const float A[1][384][32][32], const float B[1][384][1][1], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block2_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block2_deep_3_conv_Conv2D( const float x[1][384][32][32], const float w[96][384][1][1], const float bias[96], float y[1][96][32][32] )
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
	for( uint32_t m=0; m<96; m++) {
		for( int32_t o0=0, i0=0; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<384; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Name: positiveness/stack2_block2_add/add
 */
LIB_HIDDEN void node_positiveness_stack2_block2_add_add( const float A[1][96][32][32], const float B[1][96][32][32], float C[1][96][32][32] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<96; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block3_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block3_deep_1_conv_Conv2D( const float x[1][96][32][32], const float w[384][96][1][1], const float bias[384], float y[1][384][32][32] )
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
	for( uint32_t m=0; m<384; m++) {
		for( int32_t o0=0, i0=0; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<96; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Name: positiveness/stack2_block3_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block3_deep_1_swish_Sigmoid( const float X[1][384][32][32], float Y[1][384][32][32] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack2_block3_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack2_block3_deep_1_swish_mul_1( const float A[1][384][32][32], const float B[1][384][32][32], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block3_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block3_deep_2_GC_conv_Conv2D( const float x[1][384][32][32], const float w[384][16][3][3], const float bias[384], float y[1][384][32][32] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 24
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<24; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack2_block3_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block3_deep_2_swish_Sigmoid( const float X[1][384][32][32], float Y[1][384][32][32] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack2_block3_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack2_block3_deep_2_swish_mul_1( const float A[1][384][32][32], const float B[1][384][32][32], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_26/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_26_Mean( const float input[1][384][32][32], float output[1][384][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<384; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<32; d0++ ) {
		for( int32_t d1 = 0; d1<32; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 1024;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block3_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack2_block3_deep_2_se_1_conv_BiasAdd( const float x[1][384][1][1], const float w[96][384][1][1], const float bias[96], float y[1][96][1][1] )
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
	for( uint32_t m=0; m<96; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<384; c++ ) {
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
 * Name: positiveness/stack2_block3_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack2_block3_deep_2_se_relu_Relu( const float X[1][96][1][1], float Y[1][96][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<96; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block3_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack2_block3_deep_2_se_2_conv_BiasAdd( const float x[1][96][1][1], const float w[384][96][1][1], const float bias[384], float y[1][384][1][1] )
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
	for( uint32_t m=0; m<384; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<96; c++ ) {
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
 * Name: positiveness/stack2_block3_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block3_deep_2_se_sigmoid_Sigmoid( const float X[1][384][1][1], float Y[1][384][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
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
 * Name: positiveness/stack2_block3_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack2_block3_deep_2_se_out_mul( const float A[1][384][32][32], const float B[1][384][1][1], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block3_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block3_deep_3_conv_Conv2D( const float x[1][384][32][32], const float w[96][384][1][1], const float bias[96], float y[1][96][32][32] )
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
	for( uint32_t m=0; m<96; m++) {
		for( int32_t o0=0, i0=0; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<384; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Name: positiveness/stack2_block3_add/add
 */
LIB_HIDDEN void node_positiveness_stack2_block3_add_add( const float A[1][96][32][32], const float B[1][96][32][32], float C[1][96][32][32] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<96; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block4_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block4_deep_1_conv_Conv2D( const float x[1][96][32][32], const float w[384][96][1][1], const float bias[384], float y[1][384][32][32] )
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
	for( uint32_t m=0; m<384; m++) {
		for( int32_t o0=0, i0=0; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<96; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Name: positiveness/stack2_block4_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block4_deep_1_swish_Sigmoid( const float X[1][384][32][32], float Y[1][384][32][32] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack2_block4_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack2_block4_deep_1_swish_mul_1( const float A[1][384][32][32], const float B[1][384][32][32], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block4_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block4_deep_2_GC_conv_Conv2D( const float x[1][384][32][32], const float w[384][16][3][3], const float bias[384], float y[1][384][32][32] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 24
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<24; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack2_block4_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block4_deep_2_swish_Sigmoid( const float X[1][384][32][32], float Y[1][384][32][32] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack2_block4_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack2_block4_deep_2_swish_mul_1( const float A[1][384][32][32], const float B[1][384][32][32], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_27/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_27_Mean( const float input[1][384][32][32], float output[1][384][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<384; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<32; d0++ ) {
		for( int32_t d1 = 0; d1<32; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 1024;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block4_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack2_block4_deep_2_se_1_conv_BiasAdd( const float x[1][384][1][1], const float w[96][384][1][1], const float bias[96], float y[1][96][1][1] )
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
	for( uint32_t m=0; m<96; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<384; c++ ) {
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
 * Name: positiveness/stack2_block4_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack2_block4_deep_2_se_relu_Relu( const float X[1][96][1][1], float Y[1][96][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<96; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block4_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack2_block4_deep_2_se_2_conv_BiasAdd( const float x[1][96][1][1], const float w[384][96][1][1], const float bias[384], float y[1][384][1][1] )
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
	for( uint32_t m=0; m<384; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<96; c++ ) {
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
 * Name: positiveness/stack2_block4_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block4_deep_2_se_sigmoid_Sigmoid( const float X[1][384][1][1], float Y[1][384][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
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
 * Name: positiveness/stack2_block4_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack2_block4_deep_2_se_out_mul( const float A[1][384][32][32], const float B[1][384][1][1], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block4_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block4_deep_3_conv_Conv2D( const float x[1][384][32][32], const float w[96][384][1][1], const float bias[96], float y[1][96][32][32] )
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
	for( uint32_t m=0; m<96; m++) {
		for( int32_t o0=0, i0=0; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<384; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Name: positiveness/stack2_block4_add/add
 */
LIB_HIDDEN void node_positiveness_stack2_block4_add_add( const float A[1][96][32][32], const float B[1][96][32][32], float C[1][96][32][32] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<96; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block5_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block5_deep_1_conv_Conv2D( const float x[1][96][32][32], const float w[384][96][1][1], const float bias[384], float y[1][384][32][32] )
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
	for( uint32_t m=0; m<384; m++) {
		for( int32_t o0=0, i0=0; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<96; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Name: positiveness/stack2_block5_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block5_deep_1_swish_Sigmoid( const float X[1][384][32][32], float Y[1][384][32][32] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack2_block5_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack2_block5_deep_1_swish_mul_1( const float A[1][384][32][32], const float B[1][384][32][32], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block5_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block5_deep_2_GC_conv_Conv2D( const float x[1][384][32][32], const float w[384][16][3][3], const float bias[384], float y[1][384][32][32] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 24
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<24; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack2_block5_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block5_deep_2_swish_Sigmoid( const float X[1][384][32][32], float Y[1][384][32][32] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack2_block5_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack2_block5_deep_2_swish_mul_1( const float A[1][384][32][32], const float B[1][384][32][32], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_28/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_28_Mean( const float input[1][384][32][32], float output[1][384][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<384; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<32; d0++ ) {
		for( int32_t d1 = 0; d1<32; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 1024;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block5_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack2_block5_deep_2_se_1_conv_BiasAdd( const float x[1][384][1][1], const float w[96][384][1][1], const float bias[96], float y[1][96][1][1] )
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
	for( uint32_t m=0; m<96; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<384; c++ ) {
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
 * Name: positiveness/stack2_block5_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack2_block5_deep_2_se_relu_Relu( const float X[1][96][1][1], float Y[1][96][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<96; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block5_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack2_block5_deep_2_se_2_conv_BiasAdd( const float x[1][96][1][1], const float w[384][96][1][1], const float bias[384], float y[1][384][1][1] )
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
	for( uint32_t m=0; m<384; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<96; c++ ) {
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
 * Name: positiveness/stack2_block5_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block5_deep_2_se_sigmoid_Sigmoid( const float X[1][384][1][1], float Y[1][384][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
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
 * Name: positiveness/stack2_block5_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack2_block5_deep_2_se_out_mul( const float A[1][384][32][32], const float B[1][384][1][1], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block5_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block5_deep_3_conv_Conv2D( const float x[1][384][32][32], const float w[96][384][1][1], const float bias[96], float y[1][96][32][32] )
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
	for( uint32_t m=0; m<96; m++) {
		for( int32_t o0=0, i0=0; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<384; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Name: positiveness/stack2_block5_add/add
 */
LIB_HIDDEN void node_positiveness_stack2_block5_add_add( const float A[1][96][32][32], const float B[1][96][32][32], float C[1][96][32][32] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<96; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block6_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block6_deep_1_conv_Conv2D( const float x[1][96][32][32], const float w[384][96][1][1], const float bias[384], float y[1][384][32][32] )
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
	for( uint32_t m=0; m<384; m++) {
		for( int32_t o0=0, i0=0; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<96; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Name: positiveness/stack2_block6_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block6_deep_1_swish_Sigmoid( const float X[1][384][32][32], float Y[1][384][32][32] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack2_block6_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack2_block6_deep_1_swish_mul_1( const float A[1][384][32][32], const float B[1][384][32][32], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block6_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block6_deep_2_GC_conv_Conv2D( const float x[1][384][32][32], const float w[384][16][3][3], const float bias[384], float y[1][384][32][32] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 24
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<24; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack2_block6_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block6_deep_2_swish_Sigmoid( const float X[1][384][32][32], float Y[1][384][32][32] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack2_block6_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack2_block6_deep_2_swish_mul_1( const float A[1][384][32][32], const float B[1][384][32][32], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_29/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_29_Mean( const float input[1][384][32][32], float output[1][384][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<384; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<32; d0++ ) {
		for( int32_t d1 = 0; d1<32; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 1024;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block6_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack2_block6_deep_2_se_1_conv_BiasAdd( const float x[1][384][1][1], const float w[96][384][1][1], const float bias[96], float y[1][96][1][1] )
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
	for( uint32_t m=0; m<96; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<384; c++ ) {
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
 * Name: positiveness/stack2_block6_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack2_block6_deep_2_se_relu_Relu( const float X[1][96][1][1], float Y[1][96][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<96; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block6_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack2_block6_deep_2_se_2_conv_BiasAdd( const float x[1][96][1][1], const float w[384][96][1][1], const float bias[384], float y[1][384][1][1] )
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
	for( uint32_t m=0; m<384; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<96; c++ ) {
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
 * Name: positiveness/stack2_block6_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack2_block6_deep_2_se_sigmoid_Sigmoid( const float X[1][384][1][1], float Y[1][384][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
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
 * Name: positiveness/stack2_block6_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack2_block6_deep_2_se_out_mul( const float A[1][384][32][32], const float B[1][384][1][1], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack2_block6_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack2_block6_deep_3_conv_Conv2D( const float x[1][384][32][32], const float w[96][384][1][1], const float bias[96], float y[1][96][32][32] )
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
	for( uint32_t m=0; m<96; m++) {
		for( int32_t o0=0, i0=0; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<384; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Name: positiveness/stack2_block6_add/add
 */
LIB_HIDDEN void node_positiveness_stack2_block6_add_add( const float A[1][96][32][32], const float B[1][96][32][32], float C[1][96][32][32] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<96; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block1_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block1_deep_1_conv_Conv2D( const float x[1][96][32][32], const float w[384][96][1][1], const float bias[384], float y[1][384][32][32] )
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
	for( uint32_t m=0; m<384; m++) {
		for( int32_t o0=0, i0=0; o0<32; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<32; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<96; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Name: positiveness/stack3_block1_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block1_deep_1_swish_Sigmoid( const float X[1][384][32][32], float Y[1][384][32][32] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block1_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block1_deep_1_swish_mul_1( const float A[1][384][32][32], const float B[1][384][32][32], float C[1][384][32][32] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<32; i2++) {
	for (unsigned i3=0; i3<32; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block1_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block1_deep_2_GC_conv_Conv2D( const float x[1][384][32][32], const float w[384][16][3][3], const float bias[384], float y[1][384][16][16] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 24
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 2 2 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<24; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<16; o0++, i0+=2) {
		for( int32_t o1=0, i1=-1; o1<16; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=32) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=32) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack3_block1_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block1_deep_2_swish_Sigmoid( const float X[1][384][16][16], float Y[1][384][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block1_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block1_deep_2_swish_mul_1( const float A[1][384][16][16], const float B[1][384][16][16], float C[1][384][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_30/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_30_Mean( const float input[1][384][16][16], float output[1][384][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<384; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<16; d0++ ) {
		for( int32_t d1 = 0; d1<16; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 256;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block1_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block1_deep_2_se_1_conv_BiasAdd( const float x[1][384][1][1], const float w[96][384][1][1], const float bias[96], float y[1][96][1][1] )
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
	for( uint32_t m=0; m<96; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<384; c++ ) {
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
 * Name: positiveness/stack3_block1_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack3_block1_deep_2_se_relu_Relu( const float X[1][96][1][1], float Y[1][96][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<96; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block1_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block1_deep_2_se_2_conv_BiasAdd( const float x[1][96][1][1], const float w[384][96][1][1], const float bias[384], float y[1][384][1][1] )
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
	for( uint32_t m=0; m<384; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<96; c++ ) {
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
 * Name: positiveness/stack3_block1_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block1_deep_2_se_sigmoid_Sigmoid( const float X[1][384][1][1], float Y[1][384][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
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
 * Name: positiveness/stack3_block1_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack3_block1_deep_2_se_out_mul( const float A[1][384][16][16], const float B[1][384][1][1], float C[1][384][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<384; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block1_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block1_deep_3_conv_Conv2D( const float x[1][384][16][16], const float w[192][384][1][1], const float bias[192], float y[1][192][16][16] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<384; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block2_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block2_deep_1_conv_Conv2D( const float x[1][192][16][16], const float w[768][192][1][1], float y[1][768][16][16] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = 0;
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Operand:           BatchNormalization
 * Name: positiveness/stack3_block2_deep_1_bn/FusedBatchNormV3
 */
LIB_HIDDEN void node_positiveness_stack3_block2_deep_1_bn_FusedBatchNormV3( const float X[1][768][16][16], const float scale[768], const float bias[768], const float mean[768], const float var[768], float output[1][768][16][16] )
{
	/* BatchNormalization
	 * epsilon = 1.0009999641624744982e-05
	 * momentum = 0.89999997615814208984
	 */

	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<768; c++ ) {
	for( uint32_t i2=0; i2<16; i2++ ) {
	for( uint32_t i3=0; i3<16; i3++ ) {
		float tmp_X = ( X[b][c][i2][i3] - mean[c] ) / ( var[c] );
		output[b][c][i2][i3] = tmp_X * scale[c] + bias[c];
	}
	}
	}
	}
}

/*
 * Operand:           Sigmoid
 * Name: positiveness/stack3_block2_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block2_deep_1_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block2_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block2_deep_1_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block2_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block2_deep_2_GC_conv_Conv2D( const float x[1][768][16][16], const float w[768][16][3][3], const float bias[768], float y[1][768][16][16] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 48
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<48; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack3_block2_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block2_deep_2_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block2_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block2_deep_2_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_31/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_31_Mean( const float input[1][768][16][16], float output[1][768][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<768; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<16; d0++ ) {
		for( int32_t d1 = 0; d1<16; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 256;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block2_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block2_deep_2_se_1_conv_BiasAdd( const float x[1][768][1][1], const float w[192][768][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
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
 * Name: positiveness/stack3_block2_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack3_block2_deep_2_se_relu_Relu( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<192; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block2_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block2_deep_2_se_2_conv_BiasAdd( const float x[1][192][1][1], const float w[768][192][1][1], const float bias[768], float y[1][768][1][1] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack3_block2_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block2_deep_2_se_sigmoid_Sigmoid( const float X[1][768][1][1], float Y[1][768][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
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
 * Name: positiveness/stack3_block2_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack3_block2_deep_2_se_out_mul( const float A[1][768][16][16], const float B[1][768][1][1], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block2_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block2_deep_3_conv_Conv2D( const float x[1][768][16][16], const float w[192][768][1][1], const float bias[192], float y[1][192][16][16] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block2_add/add
 */
LIB_HIDDEN void node_positiveness_stack3_block2_add_add( const float A[1][192][16][16], const float B[1][192][16][16], float C[1][192][16][16] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block3_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block3_deep_1_conv_Conv2D( const float x[1][192][16][16], const float w[768][192][1][1], const float bias[768], float y[1][768][16][16] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block3_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block3_deep_1_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block3_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block3_deep_1_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block3_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block3_deep_2_GC_conv_Conv2D( const float x[1][768][16][16], const float w[768][16][3][3], const float bias[768], float y[1][768][16][16] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 48
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<48; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack3_block3_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block3_deep_2_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block3_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block3_deep_2_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_32/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_32_Mean( const float input[1][768][16][16], float output[1][768][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<768; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<16; d0++ ) {
		for( int32_t d1 = 0; d1<16; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 256;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block3_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block3_deep_2_se_1_conv_BiasAdd( const float x[1][768][1][1], const float w[192][768][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
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
 * Name: positiveness/stack3_block3_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack3_block3_deep_2_se_relu_Relu( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<192; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block3_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block3_deep_2_se_2_conv_BiasAdd( const float x[1][192][1][1], const float w[768][192][1][1], const float bias[768], float y[1][768][1][1] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack3_block3_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block3_deep_2_se_sigmoid_Sigmoid( const float X[1][768][1][1], float Y[1][768][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
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
 * Name: positiveness/stack3_block3_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack3_block3_deep_2_se_out_mul( const float A[1][768][16][16], const float B[1][768][1][1], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block3_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block3_deep_3_conv_Conv2D( const float x[1][768][16][16], const float w[192][768][1][1], const float bias[192], float y[1][192][16][16] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block3_add/add
 */
LIB_HIDDEN void node_positiveness_stack3_block3_add_add( const float A[1][192][16][16], const float B[1][192][16][16], float C[1][192][16][16] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block4_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block4_deep_1_conv_Conv2D( const float x[1][192][16][16], const float w[768][192][1][1], const float bias[768], float y[1][768][16][16] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block4_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block4_deep_1_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block4_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block4_deep_1_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block4_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block4_deep_2_GC_conv_Conv2D( const float x[1][768][16][16], const float w[768][16][3][3], const float bias[768], float y[1][768][16][16] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 48
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<48; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack3_block4_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block4_deep_2_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block4_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block4_deep_2_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_33/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_33_Mean( const float input[1][768][16][16], float output[1][768][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<768; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<16; d0++ ) {
		for( int32_t d1 = 0; d1<16; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 256;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block4_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block4_deep_2_se_1_conv_BiasAdd( const float x[1][768][1][1], const float w[192][768][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
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
 * Name: positiveness/stack3_block4_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack3_block4_deep_2_se_relu_Relu( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<192; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block4_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block4_deep_2_se_2_conv_BiasAdd( const float x[1][192][1][1], const float w[768][192][1][1], const float bias[768], float y[1][768][1][1] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack3_block4_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block4_deep_2_se_sigmoid_Sigmoid( const float X[1][768][1][1], float Y[1][768][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
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
 * Name: positiveness/stack3_block4_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack3_block4_deep_2_se_out_mul( const float A[1][768][16][16], const float B[1][768][1][1], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block4_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block4_deep_3_conv_Conv2D( const float x[1][768][16][16], const float w[192][768][1][1], const float bias[192], float y[1][192][16][16] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block4_add/add
 */
LIB_HIDDEN void node_positiveness_stack3_block4_add_add( const float A[1][192][16][16], const float B[1][192][16][16], float C[1][192][16][16] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block5_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block5_deep_1_conv_Conv2D( const float x[1][192][16][16], const float w[768][192][1][1], const float bias[768], float y[1][768][16][16] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block5_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block5_deep_1_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block5_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block5_deep_1_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block5_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block5_deep_2_GC_conv_Conv2D( const float x[1][768][16][16], const float w[768][16][3][3], const float bias[768], float y[1][768][16][16] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 48
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<48; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack3_block5_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block5_deep_2_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block5_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block5_deep_2_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_34/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_34_Mean( const float input[1][768][16][16], float output[1][768][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<768; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<16; d0++ ) {
		for( int32_t d1 = 0; d1<16; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 256;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block5_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block5_deep_2_se_1_conv_BiasAdd( const float x[1][768][1][1], const float w[192][768][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
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
 * Name: positiveness/stack3_block5_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack3_block5_deep_2_se_relu_Relu( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<192; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block5_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block5_deep_2_se_2_conv_BiasAdd( const float x[1][192][1][1], const float w[768][192][1][1], const float bias[768], float y[1][768][1][1] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack3_block5_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block5_deep_2_se_sigmoid_Sigmoid( const float X[1][768][1][1], float Y[1][768][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
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
 * Name: positiveness/stack3_block5_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack3_block5_deep_2_se_out_mul( const float A[1][768][16][16], const float B[1][768][1][1], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block5_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block5_deep_3_conv_Conv2D( const float x[1][768][16][16], const float w[192][768][1][1], const float bias[192], float y[1][192][16][16] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block5_add/add
 */
LIB_HIDDEN void node_positiveness_stack3_block5_add_add( const float A[1][192][16][16], const float B[1][192][16][16], float C[1][192][16][16] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block6_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block6_deep_1_conv_Conv2D( const float x[1][192][16][16], const float w[768][192][1][1], const float bias[768], float y[1][768][16][16] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block6_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block6_deep_1_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block6_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block6_deep_1_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block6_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block6_deep_2_GC_conv_Conv2D( const float x[1][768][16][16], const float w[768][16][3][3], const float bias[768], float y[1][768][16][16] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 48
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<48; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack3_block6_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block6_deep_2_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block6_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block6_deep_2_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_35/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_35_Mean( const float input[1][768][16][16], float output[1][768][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<768; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<16; d0++ ) {
		for( int32_t d1 = 0; d1<16; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 256;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block6_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block6_deep_2_se_1_conv_BiasAdd( const float x[1][768][1][1], const float w[192][768][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
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
 * Name: positiveness/stack3_block6_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack3_block6_deep_2_se_relu_Relu( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<192; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block6_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block6_deep_2_se_2_conv_BiasAdd( const float x[1][192][1][1], const float w[768][192][1][1], const float bias[768], float y[1][768][1][1] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack3_block6_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block6_deep_2_se_sigmoid_Sigmoid( const float X[1][768][1][1], float Y[1][768][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
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
 * Name: positiveness/stack3_block6_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack3_block6_deep_2_se_out_mul( const float A[1][768][16][16], const float B[1][768][1][1], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block6_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block6_deep_3_conv_Conv2D( const float x[1][768][16][16], const float w[192][768][1][1], const float bias[192], float y[1][192][16][16] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block6_add/add
 */
LIB_HIDDEN void node_positiveness_stack3_block6_add_add( const float A[1][192][16][16], const float B[1][192][16][16], float C[1][192][16][16] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block7_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block7_deep_1_conv_Conv2D( const float x[1][192][16][16], const float w[768][192][1][1], const float bias[768], float y[1][768][16][16] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block7_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block7_deep_1_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block7_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block7_deep_1_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block7_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block7_deep_2_GC_conv_Conv2D( const float x[1][768][16][16], const float w[768][16][3][3], const float bias[768], float y[1][768][16][16] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 48
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<48; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack3_block7_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block7_deep_2_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block7_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block7_deep_2_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_36/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_36_Mean( const float input[1][768][16][16], float output[1][768][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<768; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<16; d0++ ) {
		for( int32_t d1 = 0; d1<16; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 256;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block7_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block7_deep_2_se_1_conv_BiasAdd( const float x[1][768][1][1], const float w[192][768][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
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
 * Name: positiveness/stack3_block7_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack3_block7_deep_2_se_relu_Relu( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<192; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block7_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block7_deep_2_se_2_conv_BiasAdd( const float x[1][192][1][1], const float w[768][192][1][1], const float bias[768], float y[1][768][1][1] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack3_block7_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block7_deep_2_se_sigmoid_Sigmoid( const float X[1][768][1][1], float Y[1][768][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
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
 * Name: positiveness/stack3_block7_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack3_block7_deep_2_se_out_mul( const float A[1][768][16][16], const float B[1][768][1][1], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block7_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block7_deep_3_conv_Conv2D( const float x[1][768][16][16], const float w[192][768][1][1], const float bias[192], float y[1][192][16][16] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block7_add/add
 */
LIB_HIDDEN void node_positiveness_stack3_block7_add_add( const float A[1][192][16][16], const float B[1][192][16][16], float C[1][192][16][16] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block8_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block8_deep_1_conv_Conv2D( const float x[1][192][16][16], const float w[768][192][1][1], const float bias[768], float y[1][768][16][16] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block8_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block8_deep_1_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block8_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block8_deep_1_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block8_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block8_deep_2_GC_conv_Conv2D( const float x[1][768][16][16], const float w[768][16][3][3], const float bias[768], float y[1][768][16][16] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 48
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<48; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack3_block8_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block8_deep_2_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block8_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block8_deep_2_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_37/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_37_Mean( const float input[1][768][16][16], float output[1][768][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<768; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<16; d0++ ) {
		for( int32_t d1 = 0; d1<16; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 256;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block8_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block8_deep_2_se_1_conv_BiasAdd( const float x[1][768][1][1], const float w[192][768][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
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
 * Name: positiveness/stack3_block8_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack3_block8_deep_2_se_relu_Relu( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<192; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block8_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block8_deep_2_se_2_conv_BiasAdd( const float x[1][192][1][1], const float w[768][192][1][1], const float bias[768], float y[1][768][1][1] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack3_block8_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block8_deep_2_se_sigmoid_Sigmoid( const float X[1][768][1][1], float Y[1][768][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
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
 * Name: positiveness/stack3_block8_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack3_block8_deep_2_se_out_mul( const float A[1][768][16][16], const float B[1][768][1][1], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block8_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block8_deep_3_conv_Conv2D( const float x[1][768][16][16], const float w[192][768][1][1], const float bias[192], float y[1][192][16][16] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block8_add/add
 */
LIB_HIDDEN void node_positiveness_stack3_block8_add_add( const float A[1][192][16][16], const float B[1][192][16][16], float C[1][192][16][16] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block9_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block9_deep_1_conv_Conv2D( const float x[1][192][16][16], const float w[768][192][1][1], const float bias[768], float y[1][768][16][16] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block9_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block9_deep_1_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block9_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block9_deep_1_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block9_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block9_deep_2_GC_conv_Conv2D( const float x[1][768][16][16], const float w[768][16][3][3], const float bias[768], float y[1][768][16][16] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 48
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<48; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack3_block9_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block9_deep_2_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block9_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block9_deep_2_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_38/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_38_Mean( const float input[1][768][16][16], float output[1][768][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<768; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<16; d0++ ) {
		for( int32_t d1 = 0; d1<16; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 256;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block9_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block9_deep_2_se_1_conv_BiasAdd( const float x[1][768][1][1], const float w[192][768][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
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
 * Name: positiveness/stack3_block9_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack3_block9_deep_2_se_relu_Relu( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<192; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block9_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block9_deep_2_se_2_conv_BiasAdd( const float x[1][192][1][1], const float w[768][192][1][1], const float bias[768], float y[1][768][1][1] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack3_block9_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block9_deep_2_se_sigmoid_Sigmoid( const float X[1][768][1][1], float Y[1][768][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
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
 * Name: positiveness/stack3_block9_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack3_block9_deep_2_se_out_mul( const float A[1][768][16][16], const float B[1][768][1][1], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block9_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block9_deep_3_conv_Conv2D( const float x[1][768][16][16], const float w[192][768][1][1], const float bias[192], float y[1][192][16][16] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block9_add/add
 */
LIB_HIDDEN void node_positiveness_stack3_block9_add_add( const float A[1][192][16][16], const float B[1][192][16][16], float C[1][192][16][16] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block10_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block10_deep_1_conv_Conv2D( const float x[1][192][16][16], const float w[768][192][1][1], const float bias[768], float y[1][768][16][16] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block10_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block10_deep_1_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block10_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block10_deep_1_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block10_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block10_deep_2_GC_conv_Conv2D( const float x[1][768][16][16], const float w[768][16][3][3], const float bias[768], float y[1][768][16][16] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 48
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<48; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack3_block10_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block10_deep_2_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block10_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block10_deep_2_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_39/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_39_Mean( const float input[1][768][16][16], float output[1][768][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<768; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<16; d0++ ) {
		for( int32_t d1 = 0; d1<16; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 256;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block10_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block10_deep_2_se_1_conv_BiasAdd( const float x[1][768][1][1], const float w[192][768][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
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
 * Name: positiveness/stack3_block10_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack3_block10_deep_2_se_relu_Relu( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<192; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block10_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block10_deep_2_se_2_conv_BiasAdd( const float x[1][192][1][1], const float w[768][192][1][1], const float bias[768], float y[1][768][1][1] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack3_block10_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block10_deep_2_se_sigmoid_Sigmoid( const float X[1][768][1][1], float Y[1][768][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
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
 * Name: positiveness/stack3_block10_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack3_block10_deep_2_se_out_mul( const float A[1][768][16][16], const float B[1][768][1][1], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block10_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block10_deep_3_conv_Conv2D( const float x[1][768][16][16], const float w[192][768][1][1], const float bias[192], float y[1][192][16][16] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block10_add/add
 */
LIB_HIDDEN void node_positiveness_stack3_block10_add_add( const float A[1][192][16][16], const float B[1][192][16][16], float C[1][192][16][16] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block11_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block11_deep_1_conv_Conv2D( const float x[1][192][16][16], const float w[768][192][1][1], const float bias[768], float y[1][768][16][16] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block11_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block11_deep_1_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block11_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block11_deep_1_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block11_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block11_deep_2_GC_conv_Conv2D( const float x[1][768][16][16], const float w[768][16][3][3], const float bias[768], float y[1][768][16][16] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 48
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<48; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack3_block11_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block11_deep_2_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block11_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block11_deep_2_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_40/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_40_Mean( const float input[1][768][16][16], float output[1][768][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<768; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<16; d0++ ) {
		for( int32_t d1 = 0; d1<16; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 256;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block11_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block11_deep_2_se_1_conv_BiasAdd( const float x[1][768][1][1], const float w[192][768][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
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
 * Name: positiveness/stack3_block11_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack3_block11_deep_2_se_relu_Relu( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<192; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block11_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block11_deep_2_se_2_conv_BiasAdd( const float x[1][192][1][1], const float w[768][192][1][1], const float bias[768], float y[1][768][1][1] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack3_block11_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block11_deep_2_se_sigmoid_Sigmoid( const float X[1][768][1][1], float Y[1][768][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
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
 * Name: positiveness/stack3_block11_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack3_block11_deep_2_se_out_mul( const float A[1][768][16][16], const float B[1][768][1][1], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block11_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block11_deep_3_conv_Conv2D( const float x[1][768][16][16], const float w[192][768][1][1], const float bias[192], float y[1][192][16][16] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block11_add/add
 */
LIB_HIDDEN void node_positiveness_stack3_block11_add_add( const float A[1][192][16][16], const float B[1][192][16][16], float C[1][192][16][16] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block12_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block12_deep_1_conv_Conv2D( const float x[1][192][16][16], const float w[768][192][1][1], const float bias[768], float y[1][768][16][16] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block12_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block12_deep_1_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block12_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block12_deep_1_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block12_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block12_deep_2_GC_conv_Conv2D( const float x[1][768][16][16], const float w[768][16][3][3], const float bias[768], float y[1][768][16][16] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 48
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<48; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack3_block12_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block12_deep_2_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack3_block12_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack3_block12_deep_2_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_41/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_41_Mean( const float input[1][768][16][16], float output[1][768][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<768; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<16; d0++ ) {
		for( int32_t d1 = 0; d1<16; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 256;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block12_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block12_deep_2_se_1_conv_BiasAdd( const float x[1][768][1][1], const float w[192][768][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
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
 * Name: positiveness/stack3_block12_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack3_block12_deep_2_se_relu_Relu( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<192; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block12_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack3_block12_deep_2_se_2_conv_BiasAdd( const float x[1][192][1][1], const float w[768][192][1][1], const float bias[768], float y[1][768][1][1] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack3_block12_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack3_block12_deep_2_se_sigmoid_Sigmoid( const float X[1][768][1][1], float Y[1][768][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
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
 * Name: positiveness/stack3_block12_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack3_block12_deep_2_se_out_mul( const float A[1][768][16][16], const float B[1][768][1][1], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack3_block12_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack3_block12_deep_3_conv_Conv2D( const float x[1][768][16][16], const float w[192][768][1][1], const float bias[192], float y[1][192][16][16] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack3_block12_add/add
 */
LIB_HIDDEN void node_positiveness_stack3_block12_add_add( const float A[1][192][16][16], const float B[1][192][16][16], float C[1][192][16][16] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<192; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack4_block1_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack4_block1_deep_1_conv_Conv2D( const float x[1][192][16][16], const float w[768][192][1][1], const float bias[768], float y[1][768][16][16] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<16; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<16; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Name: positiveness/stack4_block1_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack4_block1_deep_1_swish_Sigmoid( const float X[1][768][16][16], float Y[1][768][16][16] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack4_block1_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack4_block1_deep_1_swish_mul_1( const float A[1][768][16][16], const float B[1][768][16][16], float C[1][768][16][16] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<16; i2++) {
	for (unsigned i3=0; i3<16; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack4_block1_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack4_block1_deep_2_GC_conv_Conv2D( const float x[1][768][16][16], const float w[768][16][3][3], const float bias[768], float y[1][768][8][8] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 48
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 2 2 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<48; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<8; o0++, i0+=2) {
		for( int32_t o1=0, i1=-1; o1<8; o1++, i1+=2) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=16) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=16) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack4_block1_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack4_block1_deep_2_swish_Sigmoid( const float X[1][768][8][8], float Y[1][768][8][8] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<8; i2++) {
	for (unsigned i3=0; i3<8; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack4_block1_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack4_block1_deep_2_swish_mul_1( const float A[1][768][8][8], const float B[1][768][8][8], float C[1][768][8][8] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<8; i2++) {
	for (unsigned i3=0; i3<8; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_42/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_42_Mean( const float input[1][768][8][8], float output[1][768][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<768; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<8; d0++ ) {
		for( int32_t d1 = 0; d1<8; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 64;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack4_block1_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack4_block1_deep_2_se_1_conv_BiasAdd( const float x[1][768][1][1], const float w[192][768][1][1], const float bias[192], float y[1][192][1][1] )
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
	for( uint32_t m=0; m<192; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
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
 * Name: positiveness/stack4_block1_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack4_block1_deep_2_se_relu_Relu( const float X[1][192][1][1], float Y[1][192][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<192; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack4_block1_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack4_block1_deep_2_se_2_conv_BiasAdd( const float x[1][192][1][1], const float w[768][192][1][1], const float bias[768], float y[1][768][1][1] )
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
	for( uint32_t m=0; m<768; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<192; c++ ) {
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
 * Name: positiveness/stack4_block1_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack4_block1_deep_2_se_sigmoid_Sigmoid( const float X[1][768][1][1], float Y[1][768][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
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
 * Name: positiveness/stack4_block1_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack4_block1_deep_2_se_out_mul( const float A[1][768][8][8], const float B[1][768][1][1], float C[1][768][8][8] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<768; i1++) {
	for (unsigned i2=0; i2<8; i2++) {
	for (unsigned i3=0; i3<8; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack4_block1_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack4_block1_deep_3_conv_Conv2D( const float x[1][768][8][8], const float w[288][768][1][1], const float bias[288], float y[1][288][8][8] )
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
	for( uint32_t m=0; m<288; m++) {
		for( int32_t o0=0, i0=0; o0<8; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<8; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<768; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=8) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=8) continue;
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
 * Name: positiveness/stack4_block2_deep_1_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack4_block2_deep_1_conv_Conv2D( const float x[1][288][8][8], const float w[1152][288][1][1], float y[1][1152][8][8] )
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
	for( uint32_t m=0; m<1152; m++) {
		for( int32_t o0=0, i0=0; o0<8; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<8; o1++, i1+=1) {
			y[b][m][o0][o1] = 0;
			for( int32_t c=0; c<288; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=8) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=8) continue;
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
 * Operand:           BatchNormalization
 * Name: positiveness/stack4_block2_deep_1_bn/FusedBatchNormV3
 */
LIB_HIDDEN void node_positiveness_stack4_block2_deep_1_bn_FusedBatchNormV3( const float X[1][1152][8][8], const float scale[1152], const float bias[1152], const float mean[1152], const float var[1152], float output[1][1152][8][8] )
{
	/* BatchNormalization
	 * epsilon = 1.0009999641624744982e-05
	 * momentum = 0.89999997615814208984
	 */

	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<1152; c++ ) {
	for( uint32_t i2=0; i2<8; i2++ ) {
	for( uint32_t i3=0; i3<8; i3++ ) {
		float tmp_X = ( X[b][c][i2][i3] - mean[c] ) / ( var[c] );
		output[b][c][i2][i3] = tmp_X * scale[c] + bias[c];
	}
	}
	}
	}
}

/*
 * Operand:           Sigmoid
 * Name: positiveness/stack4_block2_deep_1_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack4_block2_deep_1_swish_Sigmoid( const float X[1][1152][8][8], float Y[1][1152][8][8] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<1152; i1++) {
	for (unsigned i2=0; i2<8; i2++) {
	for (unsigned i3=0; i3<8; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack4_block2_deep_1_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack4_block2_deep_1_swish_mul_1( const float A[1][1152][8][8], const float B[1][1152][8][8], float C[1][1152][8][8] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<1152; i1++) {
	for (unsigned i2=0; i2<8; i2++) {
	for (unsigned i3=0; i3<8; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack4_block2_deep_2_GC_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack4_block2_deep_2_GC_conv_Conv2D( const float x[1][1152][8][8], const float w[1152][16][3][3], const float bias[1152], float y[1][1152][8][8] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 72
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 16; // output group size, i.e. maps/group
	uint32_t gi = 16; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<72; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<8; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<8; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=8) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=8) continue;
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
 * Operand:           Sigmoid
 * Name: positiveness/stack4_block2_deep_2_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack4_block2_deep_2_swish_Sigmoid( const float X[1][1152][8][8], float Y[1][1152][8][8] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<1152; i1++) {
	for (unsigned i2=0; i2<8; i2++) {
	for (unsigned i3=0; i3<8; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/stack4_block2_deep_2_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_stack4_block2_deep_2_swish_mul_1( const float A[1][1152][8][8], const float B[1][1152][8][8], float C[1][1152][8][8] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<1152; i1++) {
	for (unsigned i2=0; i2<8; i2++) {
	for (unsigned i3=0; i3<8; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/tf.math.reduce_mean_43/Mean
 */
LIB_HIDDEN void node_positiveness_tf_math_reduce_mean_43_Mean( const float input[1][1152][8][8], float output[1][1152][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<1152; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<8; d0++ ) {
		for( int32_t d1 = 0; d1<8; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 64;
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack4_block2_deep_2_se_1_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack4_block2_deep_2_se_1_conv_BiasAdd( const float x[1][1152][1][1], const float w[288][1152][1][1], const float bias[288], float y[1][288][1][1] )
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
	for( uint32_t m=0; m<288; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<1152; c++ ) {
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
 * Name: positiveness/stack4_block2_deep_2_se_relu/Relu
 */
LIB_HIDDEN void node_positiveness_stack4_block2_deep_2_se_relu_Relu( const float X[1][288][1][1], float Y[1][288][1][1] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<288; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

/*
 * Operand:           Conv
 * Name: positiveness/stack4_block2_deep_2_se_2_conv/BiasAdd
 */
LIB_HIDDEN void node_positiveness_stack4_block2_deep_2_se_2_conv_BiasAdd( const float x[1][288][1][1], const float w[1152][288][1][1], const float bias[1152], float y[1][1152][1][1] )
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
	for( uint32_t m=0; m<1152; m++) {
		for( int32_t o0=0, i0=0; o0<1; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<1; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<288; c++ ) {
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
 * Name: positiveness/stack4_block2_deep_2_se_sigmoid/Sigmoid
 */
LIB_HIDDEN void node_positiveness_stack4_block2_deep_2_se_sigmoid_Sigmoid( const float X[1][1152][1][1], float Y[1][1152][1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<1152; i1++) {
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
 * Name: positiveness/stack4_block2_deep_2_se_out/mul
 */
LIB_HIDDEN void node_positiveness_stack4_block2_deep_2_se_out_mul( const float A[1][1152][8][8], const float B[1][1152][1][1], float C[1][1152][8][8] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<1152; i1++) {
	for (unsigned i2=0; i2<8; i2++) {
	for (unsigned i3=0; i3<8; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][0][0];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/stack4_block2_deep_3_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_stack4_block2_deep_3_conv_Conv2D( const float x[1][1152][8][8], const float w[288][1152][1][1], const float bias[288], float y[1][288][8][8] )
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
	for( uint32_t m=0; m<288; m++) {
		for( int32_t o0=0, i0=0; o0<8; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<8; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<1152; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=8) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=8) continue;
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
 * Name: positiveness/stack4_block2_add/add
 */
LIB_HIDDEN void node_positiveness_stack4_block2_add_add( const float A[1][288][8][8], const float B[1][288][8][8], float C[1][288][8][8] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<288; i1++) {
	for (unsigned i2=0; i2<8; i2++) {
	for (unsigned i3=0; i3<8; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]+B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           Conv
 * Name: positiveness/features_conv/Conv2D
 */
LIB_HIDDEN void node_positiveness_features_conv_Conv2D( const float x[1][288][8][8], const float w[1536][288][1][1], const float bias[1536], float y[1][1536][8][8] )
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
	for( uint32_t m=0; m<1536; m++) {
		for( int32_t o0=0, i0=0; o0<8; o0++, i0+=1) {
		for( int32_t o1=0, i1=0; o1<8; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<288; c++ ) {
			for( uint32_t k0=0; k0<1; k0++ ) {
			for( uint32_t k1=0; k1<1; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=8) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=8) continue;
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
 * Name: positiveness/features_swish/Sigmoid
 */
LIB_HIDDEN void node_positiveness_features_swish_Sigmoid( const float X[1][1536][8][8], float Y[1][1536][8][8] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<1536; i1++) {
	for (unsigned i2=0; i2<8; i2++) {
	for (unsigned i3=0; i3<8; i3++) {
		Y[i0][i1][i2][i3] = 1/(1+exp(-X[i0][i1][i2][i3]));
	}
	}
	}
	}
}

/*
 * Operand:           Mul
 * Name: positiveness/features_swish/mul_1
 */
LIB_HIDDEN void node_positiveness_features_swish_mul_1( const float A[1][1536][8][8], const float B[1][1536][8][8], float C[1][1536][8][8] )
{
	/* Mul
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<1536; i1++) {
	for (unsigned i2=0; i2<8; i2++) {
	for (unsigned i3=0; i3<8; i3++) {
		C[i0][i1][i2][i3] = A[0][i1][i2][i3]*B[0][i1][i2][i3];;
	}
	}
	}
	}
}

/*
 * Operand:           GlobalAveragePool
 * Name: positiveness/avg_pool/Mean
 */
LIB_HIDDEN void node_positiveness_avg_pool_Mean( const float input[1][1536][8][8], float output[1][1536][1][1] )
{
	/* GlobalAveragePool */
	for( int32_t b=0; b<1; b++ ) {
	for( int32_t c=0; c<1536; c++ ) {
		float dimsum=0.0f;
		for( int32_t d0 = 0; d0<8; d0++ ) {
		for( int32_t d1 = 0; d1<8; d1++ ) {
			dimsum +=  input[b][c][d0][d1];
		}
		}
		output[b][c][0][0] = dimsum / 64;
	}
	}
}

/*
 * Operand:           Squeeze
 * Name: positiveness/avg_pool/Mean_Squeeze__1071
 */
LIB_HIDDEN void node_positiveness_avg_pool_Mean_Squeeze__1071( const float input[1][1536][1][1], const int64_t axes_tensor[2], float output[1][1536] )
{
	/*Squeeze*/
	float *data = (float*)input;
	float *squeezed= (float*)output;
	for( uint32_t i=0; i<1536; i++ )
		squeezed[i] = data[i];

}

/*
 * Operand:           MatMul
 * Name: positiveness/predictions/MatMul
 */
LIB_HIDDEN void node_positiveness_predictions_MatMul( const float A[1][1536], const float B[1536][1], float Y[1][1] )
{
	/* MatMul */
	for( uint32_t r=0; r<1; r++ )
		for( uint32_t c=0; c<1; c++ ) {
			Y[r][c] = 0;
			for( uint32_t i=0; i<1536; i++ )
				Y[r][c] += A[r][i] * B[i][c];
		}
}

/*
 * Operand:           Add
 * Name: positiveness/predictions/BiasAdd
 */
LIB_HIDDEN void node_positiveness_predictions_BiasAdd( const float A[1][1], const float B[1], float C[1][1] )
{
	/* Add
	   shift_dir: NOT_GIVEN
	   fmod: 0
	 */
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<1; i1++) {
		C[i0][i1] = A[0][0]+B[0];;
	}
	}
}

/*
 * Operand:           Sigmoid
 * Name: positiveness/predictions/Sigmoid
 */
LIB_HIDDEN void node_positiveness_predictions_Sigmoid( const float X[1][1], float Y[1][1] )
{
	/* Sigmoid
	   Implemented with Elementwise template.
	   alpha = 0.0000000000000000000
	   beta = 0.0000000000000000000
	*/
	for (unsigned i0=0; i0<1; i0++) {
	for (unsigned i1=0; i1<1; i1++) {
		Y[i0][i1] = 1/(1+exp(-X[i0][i1]));
	}
	}
}


