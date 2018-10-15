#include <stdio.h>
#include <string.h>

#include "../tests.h"

#include "../../src/sanitization/sanitization.h"


void test1(char*, char*, TestFlag);
void test2(char*, char*, TestFlag);

int main(void) {

    test1(
        "Test 1: getCleanExpression()",
        "Check whether function reports error when 'NULL' is passed as argument",
        SKIP_TEST
    );

    test2(
        "Test 2: getCleanExpression()",
        "Check whether function returns clean expression",
        NO_SKIP_TEST
    );

    return 0;
}

void test1(char* testName, char* testPurpose, TestFlag flag) {

    TEST_START(testName, testPurpose, flag)
        const int EXP_LENGTH = 1024;
        char* expression = NULL;

        int expLength = getCleanExpression(expression);
    TEST_END
}

void test2(char* testName, char* testPurpose, TestFlag flag) {
    
    TEST_START(testName, testPurpose, flag)
        const int EXP_LENGTH = 1024;
        char expression[] = "2 + 3* 4\t-9";

        int numOfRemovedChars = getCleanExpression(expression);

        TEST_VERDICT(numOfRemovedChars == 4)
    TEST_END
}