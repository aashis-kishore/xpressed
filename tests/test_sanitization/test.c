#include <stdio.h>
#include <string.h>

#include "../tests.h"

#include "../../src/sanitization/sanitization.h"


void test1(char*, char*, TestFlag);

int main(void) {

    test1(
        "Test 1: getCleanExpression()",
        "Check whether function reports error when 'NULL' is passed as argument",
        NO_SKIP_TEST
    );

    test2(
        "Test 2: getCleanExpression()",
        "Check whether function returns clean expression",
        NO_SKIP_TEST
    );

    return 0;
}

void test1(char* testName, char* testPurpose, TestFlag flag) {
    printTestName(testName);

    if((flag & NO_SKIP_TEST) == NO_SKIP_TEST) {

        const int EXP_LENGTH = 1024;
        char* expression = NULL;

        int expLength = getCleanExpression(expression);
        
    } else {
        puts("SKIPPED\n");
    }

}

void test2(char* testName, char* testPurpose, TestFlag flag) {
    printTestName(testName);

    if((flag & NO_SKIP_TEST) == NO_SKIP_TEST) {

        const int EXP_LENGTH = 1024;
        char* expression = "2 + 3* 4    -9";

        int expLength = strlen(expression);
        int numOfRemovedChars = getCleanExpression(expression);
        int newExpLength = strlen(expression);

        if((expLength-newExpLength) == numOfRemovedChars) {
            puts("TEST 1 PASSED\n");
        } else {
            puts("TEST 1 FAILED\n");
        }
        
    } else {
        puts("SKIPPED\n");
    }

}