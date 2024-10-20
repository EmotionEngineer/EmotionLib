#include "mpaa_tree.h"

int main() {
    // Define the input features
    double inputFeatures[] = {
         0.74947379,  0.05627779,  1.30265974, -0.45640560,  0.75766942, -0.15322164,
        -0.37995870,  0.51452600, -0.11542020, -0.63681085,  1.21425278,  1.01399076,
        -0.18353213,  0.74725035, -0.86877237, -0.66309116,  0.61212810,  0.25990576,
         0.66559383, -0.86625010, -0.44141638, -0.40361897,  0.42499108,  0.01852620,
         1.59677586,  0.88986295, -0.95532398, -0.81295405,  0.21193463, -0.81706739,
        -0.82211102,  0.82039492, -0.76096192, -0.10202220, -0.64045952,  0.51364831,
         0.44291306, -0.69461392, -0.40447565, -0.61838415,  1.18064471,  1.10547360,
         1.11899370,  1.40600125,  0.93997228,  1.40587338,  0.07910105,  0.03086029,
        -0.16463579, -0.80690428,  0.81472098,  1.04584553,  0.69913082,  0.24927864
    };

    // Perform inference using the Tree model
	double *results = MPAA_ApplyTreeModel(inputFeatures);
	printf("MPAA proba by Tree:\n");
    for (int i = 0; i < 3; i++) {
        printf("%.8f\n", results[i]);
    }
	
	int classPrediction = 0;
    for (int i = 1; i < 3; ++i) {
        if (results[i] > results[classPrediction]) {
            classPrediction = i;
        }
    }

    printf("Predicted Class: %d\n", classPrediction);

    return 0;
}