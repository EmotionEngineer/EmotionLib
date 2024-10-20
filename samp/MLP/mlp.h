#ifndef MLP_H
#define MLP_H

#include <stdio.h>
#include <math.h>
#include <stdint.h>

#define NUM_CLASSES 2
#define CLASS_THRESHOLD 0.5
#define INPUT_SIZE 49
#define N_LAYERS 5

typedef struct {
    const double *coefs[N_LAYERS - 1];
    const double *intercepts[N_LAYERS - 1];
    const int8_t sizes[N_LAYERS];
} MLP;

static inline double activation_hidden(double x) {
    return 1.00000000 / (1.00000000 + expf(-x));
}

static inline double activation_output(double x) {
    return 1.00000000 / (1.00000000 + expf(-x));
}

static inline void forward_pass(const double *input, double *output, const double *coef, const double *intercept, int inputSize, int outputSize) {
    for (int j = 0; j < outputSize; j++) {
        double acc = 0.0;
        for (int k = 0; k < inputSize; k++) {
            acc += coef[j * inputSize + k] * input[k];
        }
        output[j] = acc + intercept[j];
    }
}

static inline double inference_mlp(const MLP *mlp, const double *input_data) {
    double buffer1[INPUT_SIZE];
    double buffer2[28]; // Maximum size needed for intermediate layers
    double *input = buffer1;
    double *output = buffer2;

    for (int i = 0; i < INPUT_SIZE; i++) {
        input[i] = input_data[i];
    }

    for (int i = 0; i < N_LAYERS - 1; i++) {
        forward_pass(input, output, mlp->coefs[i], mlp->intercepts[i], mlp->sizes[i], mlp->sizes[i + 1]);
        if (i < N_LAYERS - 2) {
            for (int j = 0; j < mlp->sizes[i + 1]; j++) {
                output[j] = activation_hidden(output[j]);
            }
            double *tmp = input;
            input = output;
            output = tmp;
        } else {
            for (int j = 0; j < mlp->sizes[i + 1]; j++) {
                output[j] = activation_output(output[j]);
            }
        }
    }

    return output[0];
}

#endif // MLP_H
