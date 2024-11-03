#include <math.h>

#include "osentiment_activation.h"

LIB_HIDDEN void node_conv1( const float x[1][3][227][227], const float w[96][3][11][11], const float bias[96], float y[1][96][55][55] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 1
	 * kernel_shape: 11 11 
	 * pads: 0 0 0 0 
	 * strides: 4 4 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<96; m++) {
		for( int32_t o0=0, i0=0; o0<55; o0++, i0+=4) {
		for( int32_t o1=0, i1=0; o1<55; o1++, i1+=4) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<3; c++ ) {
			for( uint32_t k0=0; k0<11; k0++ ) {
			for( uint32_t k1=0; k1<11; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=227) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=227) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

LIB_HIDDEN void node_relu1( const float X[1][96][55][55], float Y[1][96][55][55] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<290400; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

LIB_HIDDEN void node_pool1( const float x[1][96][55][55], float y[1][96][27][27] )
{
	/* MaxPool
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 1
	 * kernel_shape: 3 3 
	 * pads: 0 0 0 0 
	 * strides: 2 2 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0, c=0; m<96; m++, c=m) {
		for( int32_t o0=0, i0=0; o0<27; o0++, i0+=2) {
		for( int32_t o1=0, i1=0; o1<27; o1++, i1+=2) {
			float curmax = -INFINITY;
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=55) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=55) continue;
				if( curmax < x[b][c][ii0][ii1]) {
				curmax = fmax( curmax, x[b][c][ii0][ii1]);
				}
			} /* k */
			} /* k */
			y[b][m][o0][o1]= curmax;
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

LIB_HIDDEN void node_norm1( const float X[1][96][27][27], float Y[1][96][27][27] )
{
	/* LRN */
	/* attributes:
	   alpha: 9.9999997473787516356e-05
	   beta:  0.75000000000000000000
	   bias:  1.0000000000000000000
	   size:  5
	*/
	int N = 1;
	int C = 96;
	float alpha = 9.9999997473787516356e-05;
	float beta = 0.75000000000000000000;
	float bias = 1.0000000000000000000;
	int size = 5;
	for (unsigned n=0; n<N; n++) {
	for (unsigned c=0; c<C; c++) {
	for (unsigned i2=0; i2<27; i2++) {
	for (unsigned i3=0; i3<27; i3++) {
		int start_i = fmax(0,   c-floor((size-1)/2));
		int end_i   = fmin(C-1, c+ceil((size-1)/2));
		float square_sum = 0;
		for (unsigned i=start_i; i<=end_i; i++) {
			square_sum += pow(X[n][i][i2][i3], 2);
		}
		Y[n][c][i2][i3]=X[n][c][i2][i3]/
		pow(bias + alpha/size * square_sum, beta);
	}
	}
	}
	}
}

LIB_HIDDEN void node_conv2( const float x[1][96][27][27], const float w[256][48][5][5], const float bias[256], float y[1][256][27][27] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 2
	 * kernel_shape: 5 5 
	 * pads: 2 2 2 2 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 128; // output group size, i.e. maps/group
	uint32_t gi = 48; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<2; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-2; o0<27; o0++, i0+=1) {
		for( int32_t o1=0, i1=-2; o1<27; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<5; k0++ ) {
			for( uint32_t k1=0; k1<5; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=27) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=27) continue;
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

LIB_HIDDEN void node_relu2( const float X[1][256][27][27], float Y[1][256][27][27] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<186624; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

LIB_HIDDEN void node_pool2( const float x[1][256][27][27], float y[1][256][13][13] )
{
	/* MaxPool
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 1
	 * kernel_shape: 3 3 
	 * pads: 0 0 0 0 
	 * strides: 2 2 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0, c=0; m<256; m++, c=m) {
		for( int32_t o0=0, i0=0; o0<13; o0++, i0+=2) {
		for( int32_t o1=0, i1=0; o1<13; o1++, i1+=2) {
			float curmax = -INFINITY;
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=27) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=27) continue;
				if( curmax < x[b][c][ii0][ii1]) {
				curmax = fmax( curmax, x[b][c][ii0][ii1]);
				}
			} /* k */
			} /* k */
			y[b][m][o0][o1]= curmax;
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

LIB_HIDDEN void node_norm2( const float X[1][256][13][13], float Y[1][256][13][13] )
{
	/* LRN */
	/* attributes:
	   alpha: 9.9999997473787516356e-05
	   beta:  0.75000000000000000000
	   bias:  1.0000000000000000000
	   size:  5
	*/
	int N = 1;
	int C = 256;
	float alpha = 9.9999997473787516356e-05;
	float beta = 0.75000000000000000000;
	float bias = 1.0000000000000000000;
	int size = 5;
	for (unsigned n=0; n<N; n++) {
	for (unsigned c=0; c<C; c++) {
	for (unsigned i2=0; i2<13; i2++) {
	for (unsigned i3=0; i3<13; i3++) {
		int start_i = fmax(0,   c-floor((size-1)/2));
		int end_i   = fmin(C-1, c+ceil((size-1)/2));
		float square_sum = 0;
		for (unsigned i=start_i; i<=end_i; i++) {
			square_sum += pow(X[n][i][i2][i3], 2);
		}
		Y[n][c][i2][i3]=X[n][c][i2][i3]/
		pow(bias + alpha/size * square_sum, beta);
	}
	}
	}
	}
}

LIB_HIDDEN void node_conv3( const float x[1][256][13][13], const float w[384][256][3][3], const float bias[384], float y[1][384][13][13] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 1
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0; m<384; m++) {
		for( int32_t o0=0, i0=-1; o0<13; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<13; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=0; c<256; c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=13) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=13) continue;
				y[b][m][o0][o1] += x[b][c][ii0][ii1] *w[m][c][k0][k1];
			} /* k */
			} /* k */
			} /* c */
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

LIB_HIDDEN void node_relu3( const float X[1][384][13][13], float Y[1][384][13][13] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<64896; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

LIB_HIDDEN void node_conv4( const float x[1][384][13][13], const float w[384][192][3][3], const float bias[384], float y[1][384][13][13] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 2
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 192; // output group size, i.e. maps/group
	uint32_t gi = 192; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<2; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<13; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<13; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=13) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=13) continue;
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

LIB_HIDDEN void node_relu4( const float X[1][384][13][13], float Y[1][384][13][13] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<64896; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

LIB_HIDDEN void node_conv5( const float x[1][384][13][13], const float w[256][192][3][3], const float bias[256], float y[1][256][13][13] )
{
	/* Conv
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 2
	 * kernel_shape: 3 3 
	 * pads: 1 1 1 1 
	 * strides: 1 1 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	uint32_t go = 128; // output group size, i.e. maps/group
	uint32_t gi = 192; // inptput group size, i.e. channels/group
	for( uint32_t g=0; g<2; g++) {
	for( uint32_t m=go*g; m<go*(g+1); m++) {
		for( int32_t o0=0, i0=-1; o0<13; o0++, i0+=1) {
		for( int32_t o1=0, i1=-1; o1<13; o1++, i1+=1) {
			y[b][m][o0][o1] = bias[m];
			for( int32_t c=gi*g; c<gi*(g+1); c++ ) {
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=13) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=13) continue;
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

LIB_HIDDEN void node_relu5( const float X[1][256][13][13], float Y[1][256][13][13] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<43264; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

LIB_HIDDEN void node_pool5( const float x[1][256][13][13], float y[1][256][6][6] )
{
	/* MaxPool
	 *
	 * auto_pad: NOTSET
	 * dilations: 1 1 
	 * group: 1
	 * kernel_shape: 3 3 
	 * pads: 0 0 0 0 
	 * strides: 2 2 
	 */
	for( uint32_t b=0; b<1; b++ ) {
	for( uint32_t m=0, c=0; m<256; m++, c=m) {
		for( int32_t o0=0, i0=0; o0<6; o0++, i0+=2) {
		for( int32_t o1=0, i1=0; o1<6; o1++, i1+=2) {
			float curmax = -INFINITY;
			for( uint32_t k0=0; k0<3; k0++ ) {
			for( uint32_t k1=0; k1<3; k1++ ) {
				int ii0 = i0+k0 * 1;
				if( ii0<0) continue;
				if( ii0>=13) continue;
				int ii1 = i1+k1 * 1;
				if( ii1<0) continue;
				if( ii1>=13) continue;
				if( curmax < x[b][c][ii0][ii1]) {
				curmax = fmax( curmax, x[b][c][ii0][ii1]);
				}
			} /* k */
			} /* k */
			y[b][m][o0][o1]= curmax;
		} /* o */
		} /* o */
	} /* m */
	} /* b */
}

LIB_HIDDEN void node_fc6_Reshape( const float data[1][256][6][6], const int64_t shape[2], float reshaped[1][9216] )
{
	/*Reshape*/
	float *data_ptr = (float*)data;
	float *reshaped_ptr = (float*)reshaped;
	for( uint32_t i=0; i<9216; i++ )
		reshaped_ptr[i] = data_ptr[i];

}

LIB_HIDDEN void node_fc6( const float A[1][9216], const float B[4096][9216], const float C[4096], float Y[1][4096] )
{
	/* Gemm */
	/* alpha   = 1.0000000000000000000
	   beta    = 1.0000000000000000000
	   transA  = 0
	   transB  = 1
	 */
	const int M = 1;
	const int K = 9216;
	const int N = 4096;
	float alpha = 1.0000000000000000000;
	float beta = 1.0000000000000000000;
	float (*C_)[4096]  = (float(*)[4096])C;
	for( uint32_t r=0; r<M; r++ )
		for( uint32_t c=0; c<N; c++ ) {
			float ABrc = 0;
			for( uint32_t i=0; i<K; i++ ) {
				float B_el = B[c][i];
				ABrc += A[r][i] * B_el;
			}
			float tmp = ABrc * alpha;
			tmp += C_[0][c] * beta;
			Y[r][c] = tmp;
	}
}

LIB_HIDDEN void node_relu6( const float X[1][4096], float Y[1][4096] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<4096; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

LIB_HIDDEN void node_fc7( const float A[1][4096], const float B[4096][4096], const float C[4096], float Y[1][4096] )
{
	/* Gemm */
	/* alpha   = 1.0000000000000000000
	   beta    = 1.0000000000000000000
	   transA  = 0
	   transB  = 1
	 */
	const int M = 1;
	const int K = 4096;
	const int N = 4096;
	float alpha = 1.0000000000000000000;
	float beta = 1.0000000000000000000;
	float (*C_)[4096]  = (float(*)[4096])C;
	for( uint32_t r=0; r<M; r++ )
		for( uint32_t c=0; c<N; c++ ) {
			float ABrc = 0;
			for( uint32_t i=0; i<K; i++ ) {
				float B_el = B[c][i];
				ABrc += A[r][i] * B_el;
			}
			float tmp = ABrc * alpha;
			tmp += C_[0][c] * beta;
			Y[r][c] = tmp;
	}
}

LIB_HIDDEN void node_relu7( const float X[1][4096], float Y[1][4096] )
{
	/*Relu*/
	float *X_ptr = (float*)X;
	float *Y_ptr = (float*)Y;
	for( uint32_t i=0; i<4096; i++ )
		Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;

}

LIB_HIDDEN void node_fc8( const float A[1][4096], const float B[2][4096], const float C[2], float Y[1][2] )
{
	/* Gemm */
	/* alpha   = 1.0000000000000000000
	   beta    = 1.0000000000000000000
	   transA  = 0
	   transB  = 1
	 */
	const int M = 1;
	const int K = 4096;
	const int N = 2;
	float alpha = 1.0000000000000000000;
	float beta = 1.0000000000000000000;
	float (*C_)[2]  = (float(*)[2])C;
	for( uint32_t r=0; r<M; r++ )
		for( uint32_t c=0; c<N; c++ ) {
			float ABrc = 0;
			for( uint32_t i=0; i<K; i++ ) {
				float B_el = B[c][i];
				ABrc += A[r][i] * B_el;
			}
			float tmp = ABrc * alpha;
			tmp += C_[0][c] * beta;
			Y[r][c] = tmp;
	}
}

LIB_HIDDEN void node_prob( const float input[1][2], float output[1][2] )
{
	/* Softmax
	 * axis = 1
	 */
	float sum = 0.0;
	float max = -INFINITY;

	for( uint32_t i0=0; i0<1; i0++ ) {
	for( uint32_t i1=0; i1<2; i1++ ) {
		max = max>input[i0][i1] ? max : input[i0][i1];
	}
	for( uint32_t i1=0; i1<2; i1++ ) {
		output[i0][i1] = expf(input[i0][i1]-max);
		sum += output[i0][i1];
	}
	for( uint32_t i1=0; i1<2; i1++ ) {
		output[i0][i1] /= sum;
	}
	sum = 0.0;
	max = -INFINITY;
	}
}