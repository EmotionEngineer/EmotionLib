#include "tree.h"

int main() {
    // Define the input features
    double inputFeatures[] = {
		-0.49769330,  2.03591969, -0.41805010,  0.87321824,  0.79609849,  2.01264499,  2.44650610, 
		 1.60218023, -2.58624994,  1.42784093,  0.92669288,  1.86046375, -0.05101488,  1.34253574, 
		-1.15881123, -1.37932499, -1.68511424, -1.36316336, -1.74492116, -0.14363037, -0.25140792, 
		-0.24468282,  0.26180806, -0.47589283, -0.13877340,  0.85855120, -0.79790587, -0.82979960, 
		 1.54819328, -0.48084667, -0.45246115,  0.48614068, -1.34948911, -1.51558038, -3.13602444, 
		 1.78075447,  4.73170026,  6.99723571,  1.58120914, 10.44501637,  0.84527403,  0.81661726, 
		 0.62081999,  0.61994107, -0.66572140, -0.75761952, -0.08185866,  0.02469186,  0.09771323, 
		-1.31738281,  1.29528839,  1.87981316
	};

    // Perform inference using the Tree model
    double rawPrediction = ApplyTreeModel(inputFeatures);

    // Apply a sigmoid function to convert logits to probability
    double probability = 1.0 / (1.0 + exp(-rawPrediction));

    // Determine the class
    int predictedClass = probability > 0.5 ? 1 : 0;

    // Output the result
    printf("Raw Prediction: %f\n", rawPrediction);
    printf("Probability: %f\n", probability);
    printf("Predicted Class: %d\n", predictedClass);

    return 0;
}