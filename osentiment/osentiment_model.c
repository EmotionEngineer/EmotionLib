#include "osentiment_activation.h"
#include "osentiment_model.h"
#include "osentiment_weights.h"

LIB_HIDDEN void
model_infer (struct tensors *ts,
             ModelInput const *image,
             ModelOut *result)
{
	node_conv1( image, tensor_conv1_W, tensor_conv1_b, ts->tu0.tensor_conv1);
	node_relu1( ts->tu0.tensor_conv1, ts->tu1.tensor_relu1);
	node_pool1( ts->tu1.tensor_relu1, ts->tu0.tensor_pool1);
	node_norm1( ts->tu0.tensor_pool1, ts->tu1.tensor_norm1);
	node_conv2( ts->tu1.tensor_norm1, tensor_conv2_W, tensor_conv2_b, ts->tu0.tensor_conv2);
	node_relu2( ts->tu0.tensor_conv2, ts->tu1.tensor_relu2);
	node_pool2( ts->tu1.tensor_relu2, ts->tu0.tensor_pool2);
	node_norm2( ts->tu0.tensor_pool2, ts->tu1.tensor_norm2);
	node_conv3( ts->tu1.tensor_norm2, tensor_conv3_W, tensor_conv3_b, ts->tu0.tensor_conv3);
	node_relu3( ts->tu0.tensor_conv3, ts->tu1.tensor_relu3);
	node_conv4( ts->tu1.tensor_relu3, tensor_conv4_W, tensor_conv4_b, ts->tu0.tensor_conv4);
	node_relu4( ts->tu0.tensor_conv4, ts->tu1.tensor_relu4);
	node_conv5( ts->tu1.tensor_relu4, tensor_conv5_W, tensor_conv5_b, ts->tu0.tensor_conv5);
	node_relu5( ts->tu0.tensor_conv5, ts->tu1.tensor_relu5);
	node_pool5( ts->tu1.tensor_relu5, ts->tu0.tensor_pool5);
	node_fc6_Reshape( ts->tu0.tensor_pool5, tensor_fc6_shape, ts->tu1.tensor_fc6_Reshape);
	node_fc6( ts->tu1.tensor_fc6_Reshape, tensor_fc6_W, tensor_fc6_B, ts->tu0.tensor_fc6);
	node_relu6( ts->tu0.tensor_fc6, ts->tu1.tensor_relu6);
	node_fc7( ts->tu1.tensor_relu6, tensor_fc7_W, tensor_fc7_B, ts->tu0.tensor_fc7);
	node_relu7( ts->tu0.tensor_fc7, ts->tu1.tensor_relu7);
	node_fc8( ts->tu1.tensor_relu7, tensor_fc8_W, tensor_fc8_B, ts->tu0.tensor_fc8);
	node_prob( ts->tu0.tensor_fc8, result);
}
