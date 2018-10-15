#ifndef _STACKERRORS_H
#define _STACKERRORS_H

// do notice the `s`
#include "errors.h"

Errors stackCreatFailError = {
    STACK_CREAT_FAIL_ERROR,
    "stack creation failed"
};

Errors invalidStackError = {
    INVALID_STACK_ERROR,
    "invalid stack as argument"
};

Errors nodeCreatFailError = {
    NODE_CREAT_FAIL_ERROR,
    "node creation failed"
};

Errors stackUnderflowError = {
    STACK_UNDERFLOW_ERROR,
    "stack underflow! ( there are no more data in the stack )"
};

#endif