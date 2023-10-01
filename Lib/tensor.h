#ifndef EMOTIONLIB_TENSOR_H_
#define EMOTIONLIB_TENSOR_H_

#include "common.h"

struct tensors;

LIB_HIDDEN extern struct tensors *
tensors_create (int *error);

LIB_HIDDEN extern void
tensors_destroy (struct tensors **pp);

typedef float tensor_3_224_224[1][3][224][224];
typedef float tensor_4[1][4];
typedef float tensor_8_1_1[1][8][1][1];
typedef float tensor_32_112_112[1][32][112][112];
typedef float tensor_42_1_1[1][42][1][1];
typedef float tensor_112_1_1[1][112][1][1];
typedef float tensor_168_1_1[1][168][1][1];
typedef float tensor_168_56_56[1][168][56][56];
typedef float tensor_168_112_112[1][168][112][112];
typedef float tensor_224_1_1[1][224][1][1];
typedef float tensor_448_1_1[1][448][1][1];
typedef float tensor_448_28_28[1][448][28][28];
typedef float tensor_448_56_56[1][448][56][56];
typedef float tensor_896_1_1[1][896][1][1];
typedef float tensor_896_14_14[1][896][14][14];
typedef float tensor_896_28_28[1][896][28][28];
typedef float tensor_2016[1][2016];
typedef float tensor_2016_1_1[1][2016][1][1];
typedef float tensor_2016_7_7[1][2016][7][7];
typedef float tensor_2016_14_14[1][2016][14][14];

union tensor_union_0 {
	tensor_3_224_224   t_3_224_224;
	tensor_32_112_112  t_32_112_112;
	tensor_168_56_56   t_168_56_56;
	tensor_168_1_1     t_168_1_1;
	tensor_42_1_1      t_42_1_1;
	tensor_448_56_56   t_448_56_56;
	tensor_448_28_28   t_448_28_28;
	tensor_448_1_1     t_448_1_1;
	tensor_112_1_1     t_112_1_1;
	tensor_896_28_28   t_896_28_28;
	tensor_896_14_14   t_896_14_14;
	tensor_896_1_1     t_896_1_1;
	tensor_224_1_1     t_224_1_1;
	tensor_2016_14_14  t_2016_14_14;
	tensor_2016_7_7    t_2016_7_7;
	tensor_2016_1_1    t_2016_1_1;
	tensor_4           t_4;
};

union tensor_union_1 {
	tensor_32_112_112  t_32_112_112;
	tensor_168_112_112 t_168_112_112;
	tensor_168_56_56   t_168_56_56;
	tensor_448_28_28   t_448_28_28;
	tensor_448_1_1     t_448_1_1;
	tensor_112_1_1     t_112_1_1;
	tensor_896_14_14   t_896_14_14;
	tensor_896_1_1     t_896_1_1;
	tensor_224_1_1     t_224_1_1;
	tensor_2016_7_7    t_2016_7_7;
	tensor_2016        t_2016;
	tensor_4           t_4;
};

union tensor_union_2 {
	tensor_32_112_112  t_32_112_112;
	tensor_168_112_112 t_168_112_112;
	tensor_168_56_56   t_168_56_56;
	tensor_168_1_1     t_168_1_1;
	tensor_8_1_1       t_8_1_1;
	tensor_448_56_56   t_448_56_56;
	tensor_448_28_28   t_448_28_28;
	tensor_448_1_1     t_448_1_1;
	tensor_42_1_1      t_42_1_1;
	tensor_896_28_28   t_896_28_28;
	tensor_896_14_14   t_896_14_14;
	tensor_896_1_1     t_896_1_1;
	tensor_112_1_1     t_112_1_1;
	tensor_2016_14_14  t_2016_14_14;
	tensor_2016_7_7    t_2016_7_7;
	tensor_2016_1_1    t_2016_1_1;
	tensor_224_1_1     t_224_1_1;
};

union tensor_union_3 {
	tensor_168_112_112 t_168_112_112;
	tensor_168_56_56   t_168_56_56;
	tensor_8_1_1       t_8_1_1;
	tensor_168_1_1     t_168_1_1;
	tensor_42_1_1      t_42_1_1;
	tensor_448_56_56   t_448_56_56;
	tensor_448_28_28   t_448_28_28;
	tensor_448_1_1     t_448_1_1;
	tensor_112_1_1     t_112_1_1;
	tensor_896_28_28   t_896_28_28;
	tensor_896_14_14   t_896_14_14;
	tensor_896_1_1     t_896_1_1;
	tensor_224_1_1     t_224_1_1;
	tensor_2016_14_14  t_2016_14_14;
	tensor_2016_7_7    t_2016_7_7;
	tensor_2016_1_1    t_2016_1_1;
};

union tensor_union_4 {
	tensor_8_1_1       t_8_1_1;
	tensor_42_1_1      t_42_1_1;
	tensor_112_1_1     t_112_1_1;
	tensor_224_1_1     t_224_1_1;
};

struct tensors {
	union tensor_union_0 tu0;
	union tensor_union_1 tu1;
	union tensor_union_2 tu2;
	union tensor_union_3 tu3;
	union tensor_union_4 tu4;
};

#endif // EMOTIONLIB_TENSOR_H_
