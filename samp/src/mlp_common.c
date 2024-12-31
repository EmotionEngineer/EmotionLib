#include "../include/mlp_common.h"

// Perform forward propagation through a single layer
double *propagation(double *input, double *output, double *weights, double *bias, int input_size, int output_size, int n_layers, int layer_index) {
    for (int i = 0; i < output_size; i++) {
        output[i] = bias[i];
        for (int j = 0; j < input_size; j++) {
            output[i] += input[j] * weights[j * output_size + i];
        }
        // Apply activation function for hidden layers
        if (layer_index < n_layers - 2) {
            output[i] = ACTIVATION_LOGISTIC(output[i]);
        }
    }
    return output;
}

// Perform prediction using the MLP model
double predict(MLPModel *model, double *sample) {
    double buffer[256];
    double *input = sample;
    double *output = buffer;

    for (int i = 0; i < model->n_layers - 1; i++) {
        propagation(input, output, model->weights[i], model->biases[i], model->network_sizes[i], model->network_sizes[i + 1], model->n_layers, i);
        // Swap buffers
        double *temp = input;
        input = output;
        output = temp;
    }
    return input[0];
}

// Return the output of the penultimate layer
double *predict_intermediate(MLPModel *model, double *sample) {
    double buffer[256];
    double *intermediate = sample;
    double *output = buffer;

    for (int i = 0; i < model->n_layers - 2; i++) {
        propagation(intermediate, output, model->weights[i], model->biases[i], model->network_sizes[i], model->network_sizes[i + 1], model->n_layers, i);
        // Swap buffers
        double *temp = intermediate;
        intermediate = output;
        output = temp;
    }
    return intermediate;
}