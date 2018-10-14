#ifndef _ERRORS_H
#define _ERRORS_H

#include <stdio.h>
#include <stdlib.h>

typedef enum errorcode ErrorCode;

typedef struct errors {
    ErrorCode code;
    char* errorMsg;
} Errors;

void reportError(char* errorMsg) {
    printf("%s\n", errorMsg);
}

void reportErrorAndExit(Errors error) {
    printf("%s\n", error.errorMsg);
    exit(error.code);
}

#endif