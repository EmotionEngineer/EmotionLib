#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils/preprocessing.h"
#include "utils/file_io.h"
#include "utils/scaler_weights.h"

#include "MLP/mlp.h"
#include "MLP/mlp_weights.h"
#include "Tree/tree.h"

#include "MPAA-MLP/mpaa_mlp.h"
#include "MPAA-MLP/mpaa_mlp_weights.h"
#include "MPAA-Tree/mpaa_tree.h"

#define NUM_EFP_FEATURES 3
#define NUM_FEATURES_MLP 49
#define NUM_FEATURES_TREE 52
#define NUM_FEATURES_MPAA_MLP 49
#define NUM_FEATURES_MPAA_TREE 54
#define NUM_MPAA_CLASSES 3

void extract_features(double* epp_data, int epp_size, double* efp_data, int efp_size, double* features) {
    // Count dark frames and remove -1 values
    int epp_dark_frames = 0;
	
    for (int i = 0; i < epp_size; i++) {
        if (epp_data[i] == -1) {
            epp_dark_frames++;
        }
    }
	
	// Remove -1 values
    remove_invalid_values(epp_data, &epp_size);
    remove_invalid_values_2d(efp_data, &efp_size, NUM_EFP_FEATURES);
	
    // Calculate features
    double epp_sum = 0, epp_sum_sq = 0;
    double efp_sum[NUM_EFP_FEATURES] = {0}, efp_sum_sq[NUM_EFP_FEATURES] = {0};
	
    for (int i = 0; i < epp_size; i++) {
        epp_sum += epp_data[i];
        epp_sum_sq += epp_data[i] * epp_data[i];
    }
	
    for (int i = 0; i < efp_size; i++) {
        for (int j = 0; j < NUM_EFP_FEATURES; j++) {
            efp_sum[j] += efp_data[i * NUM_EFP_FEATURES + j];
            efp_sum_sq[j] += efp_data[i * NUM_EFP_FEATURES + j] * efp_data[i * NUM_EFP_FEATURES + j];
        }
    }
	
    double epp_mean = epp_sum / epp_size;
    double epp_std = sqrt(epp_sum_sq / epp_size - epp_mean * epp_mean);
    double epp_min = find_min(epp_data, epp_size);
    double epp_max = find_max(epp_data, epp_size);
    double epp_median = calculate_median(epp_data, epp_size);
    double epp_q1 = calculate_percentile(epp_data, epp_size, 0.25);
    double epp_q3 = calculate_percentile(epp_data, epp_size, 0.75);
    double epp_skewness = calculate_skewness(epp_data, epp_size, epp_mean, epp_std);
    double epp_kurtosis = calculate_kurtosis(epp_data, epp_size, epp_mean, epp_std);
    double epp_entropy = calculate_entropy(epp_data, epp_size);
    double epp_energy = calculate_energy(epp_data, epp_size);
    double epp_slope = calculate_slope(epp_data, epp_size);
	
    double efp_mean[NUM_EFP_FEATURES], efp_std[NUM_EFP_FEATURES];
    double efp_min[NUM_EFP_FEATURES], efp_max[NUM_EFP_FEATURES];
    double efp_median[NUM_EFP_FEATURES], efp_q1[NUM_EFP_FEATURES], efp_q3[NUM_EFP_FEATURES];
    double efp_skewness[NUM_EFP_FEATURES], efp_kurtosis[NUM_EFP_FEATURES];
    double efp_entropy[NUM_EFP_FEATURES], efp_energy[NUM_EFP_FEATURES];
    double efp_slope[NUM_EFP_FEATURES];
	
    for (int j = 0; j < NUM_EFP_FEATURES; j++) {
		// Create a temporary array to hold the j-th feature data
		double* feature_data = (double*)malloc(efp_size * sizeof(double));
		for (int i = 0; i < efp_size; i++) {
			feature_data[i] = efp_data[i * NUM_EFP_FEATURES + j];
		}
	
		efp_mean[j] = efp_sum[j] / efp_size;
		efp_std[j] = sqrt(efp_sum_sq[j] / efp_size - efp_mean[j] * efp_mean[j]);
		efp_min[j] = find_min(feature_data, efp_size);
		efp_max[j] = find_max(feature_data, efp_size);
		efp_median[j] = calculate_median(feature_data, efp_size);
		efp_q1[j] = calculate_percentile(feature_data, efp_size, 0.25);
		efp_q3[j] = calculate_percentile(feature_data, efp_size, 0.75);
		efp_skewness[j] = calculate_skewness(feature_data, efp_size, efp_mean[j], efp_std[j]);
		efp_kurtosis[j] = calculate_kurtosis(feature_data, efp_size, efp_mean[j], efp_std[j]);
		efp_entropy[j] = calculate_entropy(feature_data, efp_size);
		efp_energy[j] = calculate_energy(feature_data, efp_size);
		efp_slope[j] = calculate_slope(feature_data, efp_size);

		// Free the temporary array
		free(feature_data);
	}
	
    // Combine features
    features[0] = epp_dark_frames;	
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
}

double process_mlp(double* features, double* std_mean_mlp, double* std_scale_mlp) {
    MLP mlp = {
        .coefs = {coefs_0, coefs_1, coefs_2, coefs_3},
        .intercepts = {intercepts_0, intercepts_1, intercepts_2, intercepts_3},
        .sizes = {NUM_FEATURES_MLP, 28, 16, 24, 1}
    };
	double* transformed_features = transform_data(features, std_mean_mlp, std_scale_mlp, NUM_FEATURES_MLP);
    double result = inference_mlp(&mlp, transformed_features);
	
	free(transformed_features);
    return result;
}

int process_tree(double* features, double* std_mean_tree, double* std_scale_tree, double mlp_result) {
    // Assigning the features for the tree model
    features[49] = mlp_result; // Use MLP prediction in Tree model
    features[50] = features[1] + 2.0 * features[2]; // EPP mean with std penalty
    features[51] = features[13] - 2.0 * features[16]; // EFP_0 mean with std penalty
	
    // Transform features after adding the new features
    double* transformed_features = transform_data(features, std_mean_tree, std_scale_tree, NUM_FEATURES_TREE);
	
    double rawPrediction = ApplyTreeModel(transformed_features);
    double probability = 1.0 / (1.0 + exp(-rawPrediction));
    int predictedClass = probability > 0.5 ? 1 : 0;
	
    free(transformed_features);
    return predictedClass;
}

double* process_mpaa_mlp(double* features, double* std_mean_mlp_mpaa, double* std_scale_mlp_mpaa) {
    MPAA_MLP mpaa_mlp = {
        .coefs = {mpaa_coefs_0, mpaa_coefs_1, mpaa_coefs_2, mpaa_coefs_3},
        .intercepts = {mpaa_intercepts_0, mpaa_intercepts_1, mpaa_intercepts_2, mpaa_intercepts_3},
        .sizes = {NUM_FEATURES_MPAA_MLP, 23, 22, 20, 3}
    };
	
	// Transform features
    double* transformed_features = transform_data(features, std_mean_mlp_mpaa, std_scale_mlp_mpaa, NUM_FEATURES_MPAA_MLP);
    double* results = mpaa_inference_mlp(&mpaa_mlp, transformed_features);
	
    free(transformed_features);
	
    return results;
}

int process_mpaa_tree(double* features, double* std_mean_tree_mpaa, double* std_scale_tree_mpaa, double* mpaa_results) {
    // Assigning the features for the tree model
    features[49] = mpaa_results[0];
    features[50] = mpaa_results[1];
    features[51] = mpaa_results[2];
    features[52] = features[1] + 2.0 * features[2];
    features[53] = features[13] - 2.0 * features[16];
	
	// Transform features after adding the new features
    double* transformed_features = transform_data(features, std_mean_tree_mpaa, std_scale_tree_mpaa, NUM_FEATURES_MPAA_TREE);
	double* mpaa_tree_results = MPAA_ApplyTreeModel(transformed_features);
	
    int classPrediction = 0;
    for (int i = 1; i < 3; ++i) {
        if (mpaa_tree_results[i] > mpaa_tree_results[classPrediction]) {
            classPrediction = i;
        }
    }
	
	free(transformed_features);
	return classPrediction;
}

#ifdef _WIN32
    #define DLLEXPORT __declspec(dllexport)
#else
    #define DLLEXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

DLLEXPORT double* PredictSafenessAndMPAA(const char* epp_path, const char* efp_path) {
    static double results[NUM_MPAA_CLASSES + 3]; // 1 MLP, 1 predictedClass, 3 MPAA MLP, 1 predictedClassMPAA
    
    int num_frames, frame_sec_interval;
    double *epp_data, *efp_data;
	
    // Read the EPP and EFP files
    read_epp_file(epp_path, &num_frames, &frame_sec_interval, &epp_data);
    read_efp_file(efp_path, &num_frames, &frame_sec_interval, &efp_data);
	
    // Extract features
    double features[NUM_FEATURES_MPAA_TREE];
    extract_features(epp_data, num_frames, efp_data, num_frames, features);
    
    // MLP processing
    double mlp_result = process_mlp(features, std_mean_mlp, std_scale_mlp);
    results[0] = mlp_result; // First element in array is MLP result
	
    // Tree processing
    int predictedClass = process_tree(features, std_mean_tree, std_scale_tree, mlp_result);
    results[1] = (double)predictedClass; // Second element in array is the predicted class (0 or 1)
	
    // Remove unused EFP features before MPAA processing
    // remove_and_shift_left(features, NUM_FEATURES_MPAA_TREE, 1, 3);
	
    // MPAA MLP processing
    double* mpaa_results = process_mpaa_mlp(features, std_mean_mlp_mpaa, std_scale_mlp_mpaa);
    for (int i = 0; i < NUM_MPAA_CLASSES; i++) {
        results[2 + i] = mpaa_results[i]; // Elements from 2 to 4 store MPAA MLP results
    }

    // MPAA tree processing
    int predictedClassMPAA = process_mpaa_tree(features, std_mean_tree_mpaa, std_scale_tree_mpaa, mpaa_results);
    results[5] = (double)predictedClassMPAA; // Last element is MPAA tree prediction

	// Free the allocated memory
	free(epp_data);
	free(efp_data);

    return results; // Return the array with results
}

#ifdef __cplusplus
}
#endif