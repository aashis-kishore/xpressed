#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../tests.h"

#include "../../src/reading/reading.h"

void test1(char*);
void test2(char*);

// expression length (arbitrary)
// #define EXP_LENGTH ((size_t)1024)

int main(void) {

    test1("Test 1: readDirtyExpression()");
    // test 2 -- Must be skipped to run further tests
    test2("Test 2: readDirtyExpression() [ pass no buffer, i.e NULL ]");
    
    return 0;
}

void test1(char* testName) {
    printTestName(testName);

    const int EXP_LENGTH = 1024;
    char buffer[EXP_LENGTH];

    int expLength = readDirtyExpression(buffer, EXP_LENGTH);

    if(expLength == (int)strlen(buffer)) {
        puts("TEST 1 PASSED\n");
    } else {
        puts("TEST 1 FAILED\n");
    }
}

void test2(char* testName) {
    printTestName(testName);

    const int EXP_LENGTH = 1024;
    char* buffer = NULL;

    readDirtyExpression(buffer, EXP_LENGTH);
}