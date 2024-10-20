#ifndef MPAA_MLP_H
#define MPAA_MLP_H

#include <stdio.h>
#include <math.h>
#include <stdint.h>

#define MPAA_INPUT_SIZE 49
#define MPAA_N_LAYERS 5

typedef struct {
    const double *coefs[MPAA_N_LAYERS - 1];
    const double *intercepts[MPAA_N_LAYERS - 1];
    const int8_t sizes[MPAA_N_LAYERS];
} MPAA_MLP;

static inline double mpaa_activation_hidden(double x) {
    return fmax(0.00000000, x);
}

static inline void mpaa_softmax(double *output, int size) {
    double max_elem = output[0];
    for (int i = 1; i < size; i++) {
        if (output[i] > max_elem) {
            max_elem = output[i];
        }
    }

    double sum_exp = 0.0;
    for (int i = 0; i < size; i++) {
        output[i] = exp(output[i] - max_elem);
        sum_exp += output[i];
    }

    for (int i = 0; i < size; i++) {
        output[i] /= sum_exp;
    }
}

static inline void mpaa_forward_pass(const double *input, double *output, const double *coef, const double *intercept, int inputSize, int outputSize) {
    for (int j = 0; j < outputSize; j++) {
        double acc = 0.0;
        for (int k = 0; k < inputSize; k++) {
            acc += coef[j * inputSize + k] * input[k];
        }
        output[j] = acc + intercept[j];
    }
}

static inline double* mpaa_inference_mlp(const MPAA_MLP *mlp, const double *input_data) {
    static double buffer1[MPAA_INPUT_SIZE];
    static double buffer2[23]; // Maximum size needed for intermediate layers
    double *input = buffer1;
    double *output = buffer2;

    for (int i = 0; i < MPAA_INPUT_SIZE; i++) {
        input[i] = input_data[i];
    }

    for (int i = 0; i < MPAA_N_LAYERS - 1; i++) {
        mpaa_forward_pass(input, output, mlp->coefs[i], mlp->intercepts[i], mlp->sizes[i], mlp->sizes[i + 1]);
        if (i < MPAA_N_LAYERS - 2) {
            for (int j = 0; j < mlp->sizes[i + 1]; j++) {
                output[j] = mpaa_activation_hidden(output[j]);
            }
            double *tmp = input;
            input = output;
            output = tmp;
        } else {
			// Apply softmax activation for output layer
            mpaa_softmax(output, mlp->sizes[MPAA_N_LAYERS - 1]);
        }
    }
    return output;
}

#endif // MPAA_MLP_H
