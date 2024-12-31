#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include <stdlib.h>

#define NUM_EPP_FEATURES 2
#define NUM_EFP_FEATURES 3

static inline void read_epp_file(const char* file_path, int* num_frames, int* frame_sec_interval, double** tensor_predictions) {
    FILE* file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fread(num_frames, sizeof(int), 1, file);
    fread(frame_sec_interval, sizeof(int), 1, file);

    float* temp_predictions = (float*)malloc(*num_frames * NUM_EPP_FEATURES * sizeof(float));
    *tensor_predictions = (double*)malloc(*num_frames * sizeof(double));

    for (int i = 0; i < *num_frames; i++) {
        fread(&temp_predictions[i * NUM_EPP_FEATURES], sizeof(float), NUM_EPP_FEATURES, file);
        (*tensor_predictions)[i] = (double)temp_predictions[i * NUM_EPP_FEATURES + 1]; // Select only positiveness value
    }

    free(temp_predictions);
    fclose(file);
}

static inline void read_efp_file(const char* file_path, int* num_frames, int* frame_sec_interval, double** tensor_predictions) {
    FILE* file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fread(num_frames, sizeof(int), 1, file);
    fread(frame_sec_interval, sizeof(int), 1, file);

    float* temp_predictions = (float*)malloc(*num_frames * NUM_EFP_FEATURES * sizeof(float));
    *tensor_predictions = (double*)malloc(*num_frames * NUM_EFP_FEATURES * sizeof(double));

    for (int i = 0; i < *num_frames; i++) {
        fread(&temp_predictions[i * NUM_EFP_FEATURES], sizeof(float), NUM_EFP_FEATURES, file);
        for (int j = 0; j < NUM_EFP_FEATURES; j++) {
            (*tensor_predictions)[i * NUM_EFP_FEATURES + j] = (double)temp_predictions[i * NUM_EFP_FEATURES + j];
        }
    }

    free(temp_predictions);
    fclose(file);
}

#endif // FILE_IO_H