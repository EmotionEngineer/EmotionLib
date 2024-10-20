#include "mpaa_mlp.h"
#include "mpaa_mlp_weights.h"
#include <stdio.h>

int main() {
    MPAA_MLP mlp = {
        .coefs = {mpaa_coefs_0, mpaa_coefs_1, mpaa_coefs_2, mpaa_coefs_3},
        .intercepts = {mpaa_intercepts_0, mpaa_intercepts_1, mpaa_intercepts_2, mpaa_intercepts_3},
        .sizes = {49, 23, 22, 20, 3}
    };

    double input_data[MPAA_INPUT_SIZE] = {
        -0.49568938, -0.88772260, -0.00893839, -0.48359357,  0.14156054, -0.93853339, 
        -0.77904923, -1.06370981,  1.31193263,  0.39773846, -0.09956940, -0.61980817, 
        -0.06375387,  0.26858655, -0.22833635, -0.27795817,  0.56918064,  0.40528608, 
         0.60658383, -0.17693375, -0.27274158, -0.25291931,  0.27097266,  0.12105529, 
        -0.03920200,  0.66302460, -0.47394343, -0.72374818, -0.28067079, -0.45232296, 
        -0.45396972,  0.47166057,  0.12722146,  0.36611386, -0.13830504,  0.20477747, 
         0.06705131, -0.41580487, -0.13951846, -0.31796535,  0.04668443,  0.00614106, 
        -0.03041886, -0.60879339, -0.62562187, -0.63367001, -0.10979735,  0.07000948, 
         0.10990227
    };

    double *result = mpaa_inference_mlp(&mlp, input_data);
    printf("MPAA proba by MLP:\n");
    for (int i = 0; i < 3; i++) {
        printf("%.8f\n", result[i]);
    }

    // Find the index of the maximum probability
    int max_index = 0;
    for (int i = 1; i < 3; i++) {
        if (result[i] > result[max_index]) {
            max_index = i;
        }
    }

    printf("Class with max probability: %d\n", max_index);

    return 0;
}