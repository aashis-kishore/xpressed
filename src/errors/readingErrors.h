#ifndef _READINGERRORS_H
#define _READINGERRORS_H

// do notice the `s`
#include "errors.h"


Errors readError = {
    READ_ERROR,
    "unable to read"
};

Errors invalidBufferError = {
    INVALID_BUFFER_ERROR,
    "invalid buffer as argument"
};

#endif