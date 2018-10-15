#ifndef _TESTS_H
#define _TESTS_H

#include <stdio.h>


#define TEST_START(testName, testPurpose, flag) \
    printTestName(testName);    \
    printTestPurpose(testPurpose);  \
                                    \
    if((flag & NO_SKIP_TEST) == NO_SKIP_TEST) {

#define TEST_END    \
    } else {    \
        puts("SKIPPED\n");  \
    }

#define TEST_VERDICT(condition)    \
    if(condition) {  \
        puts("TEST 1 PASSED\n");    \
    } else {    \
        puts("TEST 1 FAILED\n");    \
    }


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