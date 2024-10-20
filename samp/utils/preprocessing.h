#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <stdlib.h>
#include <math.h>
#include <string.h>

// StandardScaler
static inline double* transform_data(const double* data, const double* mean, const double* scale, int size) {
    double* transformed_data = (double*)malloc(size * sizeof(double));
    if (transformed_data == NULL) {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        transformed_data[i] = (data[i] - mean[i]) / scale[i];
    }

    return transformed_data;
}

// Remove elements from array and shift left
static inline void remove_and_shift_left(double* features, int size, int start_idx, int end_idx) {
    int num_elements_to_remove = end_idx - start_idx + 1;
	int new_size = size - num_elements_to_remove;
    for (int i = start_idx; i < new_size; i++) {
        features[i] = features[i + num_elements_to_remove];
    }
}

// Comparison function for qsort
static inline int compare(const void *a, const void *b) {
    double fa = *(const double*)a;
    double fb = *(const double*)b;
    return (fa > fb) - (fa < fb);
}

static inline double calculate_median(double* data, int size) {
    // Sort the array
    qsort(data, size, sizeof(double), compare);

    // Calculate median
    if (size % 2 == 0) {
        // If even number of elements, average the two middle elements
        return (data[size/2 - 1] + data[size/2]) / 2.0;
    } else {
        // If odd number of elements, return the middle element
        return data[size/2];
    }
}

static inline double calculate_percentile(double* data, int size, double percentile) {
    double* sorted_data = (double*)malloc(size * sizeof(double));
    memcpy(sorted_data, data, size * sizeof(double));
    qsort(sorted_data, size, sizeof(double), compare);

    double rank = percentile * (size - 1);
    int lower_index = (int)rank;
    int upper_index = lower_index + 1;
    double fraction = rank - lower_index;

    double result;
    if (upper_index < size) {
        result = sorted_data[lower_index] + fraction * (sorted_data[upper_index] - sorted_data[lower_index]);
    } else {
        result = sorted_data[lower_index];
    }

    free(sorted_data);
    return result;
}

static inline double calculate_skewness(double* data, int size, double mean, double std) {
    double skewness = 0.0;
    for (int i = 0; i < size; i++) {
        skewness += pow((data[i] - mean) / std, 3);
    }
    return skewness / size;
}

static inline double calculate_kurtosis(double* data, int size, double mean, double std) {
    double kurtosis = 0.0;
    for (int i = 0; i < size; i++) {
        kurtosis += pow((data[i] - mean) / std, 4);
    }
    return kurtosis / size - 3;
}

static inline double calculate_entropy(double* data, int size) {
    double entropy = 0.0;
    double sum = 0.0;

    // Calculate the sum of the data
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }

    // Calculate the entropy
    for (int i = 0; i < size; i++) {
        if (data[i] > 0) {
            double p = data[i] / sum;
            entropy -= p * log(p);
        }
    }

    return entropy;
}

static inline double calculate_energy(double* data, int size) {
    double energy = 0.0;
    for (int i = 0; i < size; i++) {
        energy += data[i] * data[i];
    }
    return energy;
}

static inline void polyfit(const double* x, const double* y, int n, int degree, double* coeffs) {
    int i, j, k;
    double* X = (double*)malloc((degree + 1) * (degree + 1) * sizeof(double));
    double* Y = (double*)malloc((degree + 1) * sizeof(double));
    double* B = (double*)malloc((degree + 1) * sizeof(double));

    for (i = 0; i <= degree; i++) {
        for (j = 0; j <= degree; j++) {
            X[i * (degree + 1) + j] = 0;
            for (k = 0; k < n; k++) {
                X[i * (degree + 1) + j] += pow(x[k], i + j);
            }
        }
    }

    for (i = 0; i <= degree; i++) {
        Y[i] = 0;
        for (k = 0; k < n; k++) {
            Y[i] += pow(x[k], i) * y[k];
        }
    }

    for (i = 0; i <= degree; i++) {
        B[i] = Y[i];
        for (j = 0; j < i; j++) {
            B[i] -= X[i * (degree + 1) + j] * coeffs[j];
        }
        coeffs[i] = B[i] / X[i * (degree + 1) + i];
    }

    free(X);
    free(Y);
    free(B);
}

static inline double calculate_slope(double* data, int size) {
	if (size < 2) {
        return 0.0;
    }
	
    double* x = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        x[i] = (double)i;
    }

    double coeffs[2];
    polyfit(x, data, size, 1, coeffs);

    free(x);
    return coeffs[1];
}

static inline void remove_invalid_values(double* data, int* size) {
    int valid_count = 0;
    for (int i = 0; i < *size; i++) {
        if (data[i] != -1) {
            data[valid_count++] = data[i];
        }
    }
    *size = valid_count;
}

static inline void remove_invalid_values_2d(double* data, int* size, int num_features) {
    int valid_count = 0;
    for (int i = 0; i < *size; i++) {
        int valid = 1;
        for (int j = 0; j < num_features; j++) {
            if (data[i * num_features + j] == -1) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            for (int j = 0; j < num_features; j++) {
                data[valid_count * num_features + j] = data[i * num_features + j];
            }
            valid_count++;
        }
    }
    *size = valid_count;
}

static inline double find_min(double* data, int size) {
    double min_value = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < min_value) {
            min_value = data[i];
        }
    }
    return min_value;
}

static inline double find_max(double* data, int size) {
    double max_value = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max_value) {
            max_value = data[i];
        }
    }
    return max_value;
}

#endif // PREPROCESSING_H