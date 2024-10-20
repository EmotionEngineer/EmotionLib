#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tree_weights.h"

static inline void ApplyTreeModelInplace(const double* floatFeatures, double* finalResults) {
    TreeModel* model = &TreeModelWeights;

    // Binarize features
    unsigned char binaryFeatures[BINARY_FEATURE_COUNT] = {0};
    unsigned int binFeatureIndex = 0;

    for (unsigned int i = 0; i < model->FloatFeatureCount; ++i) {
        for (unsigned int j = 0; j < model->BorderCounts[i]; ++j) {
            binaryFeatures[binFeatureIndex] = (unsigned char)(floatFeatures[i] > model->Borders[binFeatureIndex]);
            ++binFeatureIndex;
        }
    }

    // Extract and sum values from trees
    double results[OUT_COUNT] = {0.0};
    const unsigned int* treeSplitsPtr = model->TreeSplits;
    const double(*leafValuesForCurrentTreePtr)[OUT_COUNT] = model->LeafValues;

    for (unsigned int treeId = 0; treeId < model->TreeCount; ++treeId) {
        const unsigned int currentTreeDepth = model->TreeDepth[treeId];
        unsigned int index = 0;

        for (unsigned int depth = 0; depth < currentTreeDepth; ++depth) {
            index |= (binaryFeatures[treeSplitsPtr[depth]] << depth);
        }

        for (unsigned int resultIndex = 0; resultIndex < model->OutCount; resultIndex++) {
            results[resultIndex] += leafValuesForCurrentTreePtr[index][resultIndex];
        }

        treeSplitsPtr += currentTreeDepth;
        leafValuesForCurrentTreePtr += 1 << currentTreeDepth;
    }

    // Apply scale and biases
    for (unsigned int resultId = 0; resultId < model->OutCount; resultId++) {
        finalResults[resultId] = model->Scale * results[resultId] + model->Biases[resultId];
    }
}

static inline double ApplyTreeModel(const double* floatFeatures) {
    double result[OUT_COUNT];
    ApplyTreeModelInplace(floatFeatures, result);
    return result[0];
}

#endif // TREE_H