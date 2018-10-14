#ifndef _ERRORS_H
#define _ERRORS_H

typedef enum errorcode ErrorCode;

typedef struct errors {
    ErrorCode code;
    char* errorMsg;
} Errors;

void reportError(char* errorMsg);

void reportErrorAndExit(Errors);

#endif