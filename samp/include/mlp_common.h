#ifndef MLP_COMMON_H
#define MLP_COMMON_H

#include <stdio.h>
#include <math.h>

typedef struct {
    int n_layers;
    int *network_sizes;
    double **biases;
    double **weights;
} MLPModel;

double *propagation(double *input, double *output, double *weights, double *bias, int input_size, int output_size, int n_layers, int layer_index);
double predict(MLPModel *model, double *sample);
double *predict_intermediate(MLPModel *model, double *sample);

#define ACTIVATION_LOGISTIC(x) (1.0000000000000000 / (1.0000000000000000 + exp(-(x))))

#endif
