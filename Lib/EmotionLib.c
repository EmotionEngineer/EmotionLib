#include <stdio.h>
#include <string.h>

#include "model.h"

__attribute__((always_inline))
static inline struct tensors *
tensors_create_helper (char const *const caller)
{
	int             e = 0;
	struct tensors *t = tensors_create(&e);

	if (!t) {
		if (e)
			fprintf(stderr, "%s: tensors_create(): %s\n", caller, strerror(e));
		else
			fprintf(stderr, "%s: tensors_create() failed\n", caller);
	}

	return t;
}

LIB_EXPORT void
EmotionLib_imageSentiment (EmotionLibImage const *image,
                           EmotionLibPrediction  *result)
{
	struct tensors *ts = tensors_create_helper(__func__);

	if (ts) {
		model_infer(ts, image, result);
		tensors_destroy(&ts);
	}
}

LIB_EXPORT void
EmotionLib_videoSentiment (EmotionLibImage const *frames,
                           int                    num_frames,
                           EmotionLibPrediction  *results,
                           int                   *progress)
{
	struct tensors *ts = tensors_create_helper(__func__);

	if (ts) {
		for (int i = 0; i < num_frames; i++) {
			model_infer(ts, &frames[i], &results[i]);

			if (progress)
				(*progress)++;
		}

		tensors_destroy(&ts);
	}
}
