#include <stdio.h>
#include <string.h>

#include "../tests.h"

#include "../../src/sanitization/sanitization.h"


void test1(char*, char*, TestFlag);
void test2(char*, char*, TestFlag);
void test3(char*, char*, TestFlag);
void test4(char*, char*, TestFlag);

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

    test3(
        "Test 3: charIsDirty() [Must be declared in the header for testing]",
        "Check whether function returns correctly for given input",
        NO_SKIP_TEST
    );

    test4(
        "Test 4: cleanExpression() [[Must be declared in the header for testing]]",
        "Check whether function returns correctly for given input",
        NO_SKIP_TEST
    );

    return 0;
}

void test1(char* testName, char* testPurpose, TestFlag flag) {
    printTestName(testName);
    printTestPurpose(testPurpose);

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
    printTestPurpose(testPurpose);

    if((flag & NO_SKIP_TEST) == NO_SKIP_TEST) {

        const int EXP_LENGTH = 1024;
        char expression[] = "2 + 3* 4\t-9";

        int numOfRemovedChars = getCleanExpression(expression);

        if(numOfRemovedChars == 4) {
            puts("TEST 2 PASSED\n");
        } else {
            puts("TEST 2 FAILED\n");
        }
        
    } else {
        puts("SKIPPED\n");
    }

}

void test3(char* testName, char* testPurpose, TestFlag flag) {
    printTestName(testName);
    printTestPurpose(testPurpose);

    if((flag & NO_SKIP_TEST) == NO_SKIP_TEST) {

        int status1 = charIsDirty(' ');
        int status2 = charIsDirty('\t');
        int status3 = charIsDirty('\f');
        int status4 = charIsDirty(' ');
        int status5 = charIsDirty('a');

        if(status1 == 1 && status2 == 1 && status3 == 1 && status4 == 1 && status5 == 0) {
            puts("TEST 3 PASSED\n");
        } else {
            puts("TEST 3 FAILED\n");
        }
        
    } else {
        puts("SKIPPED\n");
    }
}

void test4(char* testName, char* testPurpose, TestFlag flag) {
    printTestName(testName);
    printTestPurpose(testPurpose);

    if((flag & NO_SKIP_TEST) == NO_SKIP_TEST) {

        const int EXP_LENGTH = 1024;
        char expression[] = "2 + 3* 4\t-9";

        int numOfRemovedChars = cleanExpression(expression); 

        if(numOfRemovedChars == 4) {
            puts("TEST 4 PASSED\n");
        } else {
            puts("TEST 4 FAILED\n");
        }
        
    } else {
        puts("SKIPPED\n");
    }
}