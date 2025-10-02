#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils/preprocessing.h"
#include "utils/file_io.h"
#include "utils/scaler_weights.h"

#include "include/mlp_common.h"
#include "include/mlp_model1.h"
#include "include/mlp_model2.h"
#include "include/mlp_model3.h"
#include "include/mlp_model4.h"
#include "include/lstm_filter_model.h"
#include "include/mlp_mpaa_model.h"

#define NUM_EFP_FEATURES 3
#define NUM_FEATURES_SAFE 53
#define NUM_FEATURES_MPAA 45
#define TARGET_FRAMES_LENGTH 50

void extract_features(double* epp_data, double* efp_data, int framesCount, int frame_sec_interval, double* features) {
    // Count dark frames and remove -1 values
    int efp_dark_frames = 0;
	
    for (int i = 0; i < framesCount; i++) {
        if (efp_data[i * NUM_EFP_FEATURES] == -1) {
            efp_dark_frames++;
        }
    }
	
	// Remove -1 values only from EFP
    remove_invalid_values_2d(efp_data, &framesCount, NUM_EFP_FEATURES);
	
    // Calculate features
    double epp_sum = 0, epp_sum_sq = 0;
    double efp_sum[NUM_EFP_FEATURES] = {0}, efp_sum_sq[NUM_EFP_FEATURES] = {0};
	
    for (int i = 0; i < framesCount; i++) {
        epp_sum += epp_data[i];
        epp_sum_sq += epp_data[i] * epp_data[i];
    }
	
    for (int i = 0; i < framesCount; i++) {
        for (int j = 0; j < NUM_EFP_FEATURES; j++) {
            efp_sum[j] += efp_data[i * NUM_EFP_FEATURES + j];
            efp_sum_sq[j] += efp_data[i * NUM_EFP_FEATURES + j] * efp_data[i * NUM_EFP_FEATURES + j];
        }
    }
	
    double epp_mean = epp_sum / framesCount;
    double epp_std = sqrt(epp_sum_sq / framesCount - epp_mean * epp_mean);
    double epp_min = find_min(epp_data, framesCount);
    double epp_max = find_max(epp_data, framesCount);
    double epp_median = calculate_median(epp_data, framesCount);
    double epp_q1 = calculate_percentile(epp_data, framesCount, 0.25);
    double epp_q3 = calculate_percentile(epp_data, framesCount, 0.75);
    double epp_skewness = calculate_skewness(epp_data, framesCount, epp_mean, epp_std);
    double epp_kurtosis = calculate_kurtosis(epp_data, framesCount, epp_mean, epp_std);
    double epp_entropy = calculate_entropy(epp_data, framesCount);
    double epp_energy = calculate_energy(epp_data, framesCount);
    double epp_slope = calculate_slope(epp_data, framesCount);
	
    double efp_mean[NUM_EFP_FEATURES], efp_std[NUM_EFP_FEATURES];
    double efp_min[NUM_EFP_FEATURES], efp_max[NUM_EFP_FEATURES];
    double efp_median[NUM_EFP_FEATURES], efp_q1[NUM_EFP_FEATURES], efp_q3[NUM_EFP_FEATURES];
    double efp_skewness[NUM_EFP_FEATURES], efp_kurtosis[NUM_EFP_FEATURES];
    double efp_entropy[NUM_EFP_FEATURES], efp_energy[NUM_EFP_FEATURES];
    double efp_slope[NUM_EFP_FEATURES];
	
    for (int j = 0; j < NUM_EFP_FEATURES; j++) {
		// Create a temporary array to hold the j-th feature data
		double* feature_data = (double*)malloc(framesCount * sizeof(double));
		for (int i = 0; i < framesCount; i++) {
			feature_data[i] = efp_data[i * NUM_EFP_FEATURES + j];
		}
	
		efp_mean[j] = efp_sum[j] / framesCount;
		efp_std[j] = sqrt(efp_sum_sq[j] / framesCount - efp_mean[j] * efp_mean[j]);
		efp_min[j] = find_min(feature_data, framesCount);
		efp_max[j] = find_max(feature_data, framesCount);
		efp_median[j] = calculate_median(feature_data, framesCount);
		efp_q1[j] = calculate_percentile(feature_data, framesCount, 0.25);
		efp_q3[j] = calculate_percentile(feature_data, framesCount, 0.75);
		efp_skewness[j] = calculate_skewness(feature_data, framesCount, efp_mean[j], efp_std[j]);
		efp_kurtosis[j] = calculate_kurtosis(feature_data, framesCount, efp_mean[j], efp_std[j]);
		efp_entropy[j] = calculate_entropy(feature_data, framesCount);
		efp_energy[j] = calculate_energy(feature_data, framesCount);
		efp_slope[j] = calculate_slope(feature_data, framesCount);

		// Free the temporary array
		free(feature_data);
	}
	
    // Combine features
    features[0] = efp_dark_frames;	
    features[1] = epp_mean;
    features[2] = epp_std;
    features[3] = epp_min;
    features[4] = epp_max;
    features[5] = epp_median;
    features[6] = epp_q1;
    features[7] = epp_q3;
    features[8] = epp_skewness;
    features[9] = epp_kurtosis;
    features[10] = epp_entropy;
    features[11] = epp_energy;
    features[12] = epp_slope;
	
    memcpy(&features[13], efp_mean, 3 * sizeof(double));
    memcpy(&features[16], efp_std, 3 * sizeof(double));
    memcpy(&features[19], efp_min, 3 * sizeof(double));
    memcpy(&features[22], efp_max, 3 * sizeof(double));
    memcpy(&features[25], efp_median, 3 * sizeof(double));
    memcpy(&features[28], efp_q1, 3 * sizeof(double));
    memcpy(&features[31], efp_q3, 3 * sizeof(double));
    memcpy(&features[34], efp_skewness, 3 * sizeof(double));
    memcpy(&features[37], efp_kurtosis, 3 * sizeof(double));
    memcpy(&features[40], efp_entropy, 3 * sizeof(double));
    memcpy(&features[43], efp_energy, 3 * sizeof(double));
    memcpy(&features[46], efp_slope, 3 * sizeof(double));
	
	features[49] = features[1] - 2.0 * features[2]; // EPP mean with std penalty
    features[50] = features[13] - 2.0 * features[16]; // EFP_0 mean with std penalty
	
	features[51] = framesCount;
	features[52] = frame_sec_interval; // Frame capture interval
}

double inference(MLPModel* model, double* features, double* mean, double* scale, int featuresCount) {
    double* transformed_features = transform_data(features, mean, scale, featuresCount);
    double result = predict(model, transformed_features);
    free(transformed_features);
    return result;
}

void inference_intermediate(MLPModel* model, double* features, double* mean, double* scale, double* intermediate_output, int featuresCount) {
    double* transformed_features = transform_data(features, mean, scale, featuresCount);
    double* intermediate = predict_intermediate(model, transformed_features);
    memcpy(intermediate_output, intermediate, model->network_sizes[model->n_layers - 2] * sizeof(double));
    free(transformed_features);
}

#ifdef _WIN32
    #define DLLEXPORT __declspec(dllexport)
#else
    #define DLLEXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

DLLEXPORT double predictSAMP(const char* epp_path, const char* efp_path) {    
    int num_frames, frame_sec_interval;
    double *epp_data, *efp_data;
	
    // Read the EPP and EFP files
    read_epp_file(epp_path, &num_frames, &frame_sec_interval, &epp_data);
    read_efp_file(efp_path, &num_frames, &frame_sec_interval, &efp_data);
	
    // Process EFP and EPP data for LSTM
    double** efp_center = process_efp_series(efp_data, num_frames); // [3][50]
    double* epp_center = process_epp_series(epp_data, num_frames); // [50]
	
    // Extract features for safeness prediction
    double featuresSafeness[NUM_FEATURES_SAFE];
    extract_features(epp_data, efp_data, num_frames, frame_sec_interval, featuresSafeness);
	
	// Extract features for MPAA prediction
	double featuresMPAA[NUM_FEATURES_MPAA];
	int new_index = 0;

	for (int i = 0; i < 53; i++) {
	    // Skip energy and slope features
	    if (i == 11 || i == 12 || (i >= 43 && i <= 48)) {
	        continue;
	    }
	    // Select features for MPAA prediction model
	    featuresMPAA[new_index++] = featuresSafeness[i];
	}
	
    // Intermediate inference MLP models
    double intermediate_output1[9];
    double intermediate_output2[3];
    double intermediate_output3[18];
	double intermediate_output4[20];
    inference_intermediate(&model1, featuresSafeness, std_mean_mlp1, std_scale_mlp1, intermediate_output1, NUM_FEATURES_SAFE);
    inference_intermediate(&model2, featuresSafeness, std_mean_mlp2, std_scale_mlp2, intermediate_output2, NUM_FEATURES_SAFE);
    inference_intermediate(&model3, featuresSafeness, std_mean_mlp3, std_scale_mlp3, intermediate_output3, NUM_FEATURES_SAFE);
	// Last safeness MLP requires less features
	inference_intermediate(&model4, featuresMPAA, std_mean_mlp4, std_scale_mlp4, intermediate_output4, NUM_FEATURES_MPAA);

    // Copy results
	static double mlp_output[50]; // Intermediate for 4 different MLPs
    memcpy(mlp_output, intermediate_output1, sizeof(intermediate_output1));
    memcpy(mlp_output + 9, intermediate_output2, sizeof(intermediate_output2));
    memcpy(mlp_output + 12, intermediate_output3, sizeof(intermediate_output3));
	memcpy(mlp_output + 30, intermediate_output4, sizeof(intermediate_output4));
	
    // Allocate temporary arrays with proper sizes for LSTM function call
    double tensor_combined_input[50][1][4] = {0};
    double tensor_mlp_output[1][50] = {0};

    // Fill tensor_combined_input (concatenation of EFP and EPP)
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 3; j++) {
            tensor_combined_input[i][0][j] = efp_center[j][i];
        }
        tensor_combined_input[i][0][3] = epp_center[i];
    }

    // Fill tensor_mlp_output
    for (int i = 0; i < 50; i++) {
        tensor_mlp_output[0][i] = mlp_output[i];
    }

    // Predict safeness (binary classification: 0.0 - safe, 1.0 - unsafe)
    double safeness_score = predictSafeness(tensor_combined_input, tensor_mlp_output);

    // If the content is unsafe (safeness_score > 0.5), block it by returning 2.0
    if (safeness_score > 0.5) {
        return 2.0; // Special value indicating the content should be blocked
    }

    double mpaa_rating = inference(&mpaa_model, featuresMPAA, std_mean_mpaa, std_scale_mpaa, NUM_FEATURES_MPAA);
    return mpaa_rating; // Return the MPAA rating scale
}

#ifdef __cplusplus
}
#endif