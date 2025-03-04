#ifndef LSTM_FILTER_MODEL_H
#define LSTM_FILTER_MODEL_H

double predictSafeness(const double tensor_combined_input[50][1][4],
					   const double tensor_mlp_input[1][30]);

#endif