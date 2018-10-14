#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../tests.h"

#include "../../src/reading/reading.h"

// expression length (arbitrary)
#define EXP_LENGTH ((size_t)1024)

int main(void) {
    // Test 1
    printTestName("Test 1: readDirtyExpression()");

    char expression[EXP_LENGTH];
    int expLength = readDirtyExpression(expression, EXP_LENGTH);
    if(expLength == (int)strlen(expression)) {
        puts("TEST 1 PASSED\n");
    } else {
        puts("TEST 1 FAILED\n");
    }

    // Test 2 -- Must be skipped to run Tests after this.
    printTestName("Test 2: readDirtyExpression() [ pass no buffer, i.e NULL ]");
    
    char* buffer = NULL;
    readDirtyExpression(buffer, EXP_LENGTH);
    
    return 0;
}