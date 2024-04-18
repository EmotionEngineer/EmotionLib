#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "positiveness_tensor.h"

LIB_HIDDEN struct tensors *
tensors_create (int *error)
{
    struct tensors *ts = calloc(1, sizeof *ts);
    if (!ts && error)
        *error = errno;
    return ts;
}

LIB_HIDDEN void
tensors_destroy (struct tensors **pp)
{
    if (pp && *pp) {
        memset(*pp, 0, sizeof **pp);
        free(*pp);
        *pp = NULL;
    }
}