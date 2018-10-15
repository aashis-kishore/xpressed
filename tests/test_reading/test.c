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
    TEST_START(testName, testPurpose, flag)
        const int EXP_LENGTH = 1024;
        char buffer[EXP_LENGTH];

        int expLength = readDirtyExpression(buffer, EXP_LENGTH);

        TEST_VERDICT(expLength == (int)strlen(buffer))
    TEST_END
}

void test2(char* testName, char* testPurpose, TestFlag flag) {

    TEST_START(testName, testPurpose, flag)
        const int EXP_LENGTH = 1024;
        char* buffer = NULL;

        readDirtyExpression(buffer, EXP_LENGTH);
    TEST_END
}