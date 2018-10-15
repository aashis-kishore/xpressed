#include <stdio.h>

#include "tests.h"

#include "../../src/evaluation/stack/stack.h"


void test1(char*, char*, TestFlag);
void test2(char*, char*, TestFlag);

int main(void) {

    test1(
        "Test 1: createStack()",
        "Check whether stack creation is successful",
        NO_SKIP_TEST
    );

    test2(
        "Test 2: destroyStack()",
        "Check whether stack destruction is successful",
        NO_SKIP_TEST
    );

    return 0;
}

void test1(char* testName, char* testPurpose, TestFlag flag) {
    printTestName(testName);
    printTestPurpose(testPurpose);

    if((flag & NO_SKIP_TEST) == NO_SKIP_TEST) {

        Stack newStack = createStack();
        
        if(newStack) {
            puts("TEST 1 PASSED\n");
        } else {
            puts("TEST 1 FAILED\n");
        }

        destroyStack(newStack);
        
    } else {
        puts("SKIPPED\n");
    }
}

void test2(char* testName, char* testPurpose, TestFlag flag) {
    printTestName(testName);
    printTestPurpose(testPurpose);

    if((flag & NO_SKIP_TEST) == NO_SKIP_TEST) {

        Stack newStack = createStack();
        
        destroyStack(newStack);

        if(!newStack) {
            puts("TEST 2 PASSED\n");
        } else {
            puts("TEST 2 FAILED\n");
        }
        
    } else {
        puts("SKIPPED\n");
    }
}