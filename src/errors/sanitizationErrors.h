#ifndef _SANITIZATIONERRORS_H
#define _SANITIZATIONERRORS_H

// do notice the `s`
#include "errors.h"


Errors invalidExpressionError = {
    INVALID_EXPRESSION_ERROR,
    "getCleanExpression(): invalid expression"
};

#endif