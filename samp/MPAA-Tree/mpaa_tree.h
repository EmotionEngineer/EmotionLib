#ifndef MPAA_TREE_H
#define MPAA_TREE_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mpaa_tree_weights.h"

static inline void MPAA_ApplyTreeModelInplace(const double* floatFeatures, double* finalResults) {
    MPAATreeModel* model = &MPAATreeModelWeights;

    // Binarize features
    unsigned char binaryFeatures[MPAA_BINARY_FEATURE_COUNT] = {0};
    unsigned int binFeatureIndex = 0;

    for (unsigned int i = 0; i < model->FloatFeatureCount; ++i) {
        for (unsigned int j = 0; j < model->BorderCounts[i]; ++j) {
            binaryFeatures[binFeatureIndex] = (unsigned char)(floatFeatures[i] > model->Borders[binFeatureIndex]);
            ++binFeatureIndex;
        }
    }

    // Extract and sum values from trees
    double results[MPAA_OUT_COUNT] = {0.0, 0.0, 0.0};
    const unsigned int* treeSplitsPtr = model->TreeSplits;
    const double(*leafValuesForCurrentTreePtr)[MPAA_OUT_COUNT] = model->LeafValues;

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

static inline double* MPAA_ApplyTreeModel(const double* floatFeatures) {
    static double results[MPAA_OUT_COUNT];
    MPAA_ApplyTreeModelInplace(floatFeatures, results);
    return results;
}

#endif // MPAA_TREE_H