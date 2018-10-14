#ifndef _TESTS_H
#define _TESTS_H

#include <stdio.h>


typedef enum testFlag {
    SKIP_TEST,
    NO_SKIP_TEST,
} TestFlag;

void printTestName(const char* testName) {
    printf("%s\n\n", testName);
}

void printTestPurpose(const char* testPurpose) {
    printf("%s\n", testPurpose);
}

#endif