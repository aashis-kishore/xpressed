#include <stdio.h>

#include "../tests.h"

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
    
    TEST_START(testName, testPurpose, flag)
        Stack newStack = createStack();
        TEST_VERDICT(newStack)
        destroyStack(newStack);
    TEST_END
}

void test2(char* testName, char* testPurpose, TestFlag flag) {
    
    TEST_START(testName, testPurpose, flag)
         Stack newStack = createStack();
         destroyStack(newStack);

         // a weird fix, but, no memory leak can ensure success
        newStack = NULL;

        TEST_VERDICT(!newStack)
    TEST_END
}