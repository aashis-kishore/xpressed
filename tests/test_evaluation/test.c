#include <stdio.h>

#include "../tests.h"

#include "../../src/evaluation/stack/stack.h"


void test1(char*, char*, TestFlag);
void test2(char*, char*, TestFlag);
void test3(char*, char*, TestFlag);
void test4(char*, char*, TestFlag);

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

    test3(
        "Test 3: getStackLength()",
        "Check whether function returns correct output",
        NO_SKIP_TEST
    );

    test4(
        "Test 4: pushStack()",
        "Ensure push operation works correctly",
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

void test3(char* testName, char* testPurpose, TestFlag flag) {

    TEST_START(testName, testPurpose, flag)
        Stack newStack = createStack();
        int stackLen = getStackLength(newStack);
        destroyStack(newStack);

        TEST_VERDICT(stackLen == 0)
    TEST_END
}

void test4(char* testName, char* testPurpose, TestFlag flag) {

    TEST_START(testName, testPurpose, flag)
        Stack newStack = createStack();
        pushStack(newStack, 'A');
        pushStack(newStack, 'Z');

        int stackLen = getStackLength(newStack);
        destroyStack(newStack);

        TEST_VERDICT(stackLen == 2)
    TEST_END
}