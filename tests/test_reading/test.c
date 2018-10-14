#include <stdio.h>
#include <string.h>

#include "../tests.h"

#include "../../src/reading/reading.h"


void test1(char*, char*, TestFlag);
void test2(char*, char*, TestFlag);

int main(void) {

    test1(
        "Test 1: readDirtyExpression()",
        "Check whether reading is successful",
        NO_SKIP_TEST
    );
    // test 2 -- Must be skipped to run further tests
    test2(
        "Test 2: readDirtyExpression()",
        "Check whether function reports error when 'NULL' is passed as argument",
        SKIP_TEST
    );
    
    return 0;
}

void test1(char* testName, char* testPurpose, TestFlag flag) {
    printTestName(testName);
    printTestPurpose(testPurpose);

    if((flag & NO_SKIP_TEST) == NO_SKIP_TEST) {

        const int EXP_LENGTH = 1024;
        char buffer[EXP_LENGTH];

        int expLength = readDirtyExpression(buffer, EXP_LENGTH);

        if(expLength == (int)strlen(buffer)) {
            puts("TEST 1 PASSED\n");
        } else {
            puts("TEST 1 FAILED\n");
        }

    } else {
        puts("SKIPPED\n");
    }
}

void test2(char* testName, char* testPurpose, TestFlag flag) {
    printTestName(testName);
    printTestPurpose(testPurpose);

    if((flag & NO_SKIP_TEST) == NO_SKIP_TEST) {

        const int EXP_LENGTH = 1024;
        char* buffer = NULL;

        readDirtyExpression(buffer, EXP_LENGTH);
    } else {
        puts("SKIPPED\n");
    }
}