#ifndef _ERRORS_H
#define _ERRORS_H

#include <stdio.h>
#include <stdlib.h>

typedef enum errorcode {
    READ_ERROR = 1,
    INVALID_BUFFER_ERROR,
    INVALID_EXPRESSION_ERROR,
    STACK_CREAT_FAIL_ERROR,
    INVALID_STACK_ERROR
} ErrorCode;

typedef struct errors {
    ErrorCode code;
    char* errorMsg;
} Errors;

void reportError(Errors error) {
    printf("Error[%d]: %s\n", error.code, error.errorMsg);
}

void reportErrorAndExit(Errors error) {
    printf("Error[%d]: %s\n", error.code, error.errorMsg);
    exit(error.code);
}

#endif