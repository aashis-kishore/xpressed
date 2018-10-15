#include <string.h>

#include "../errors/errors.h"
#include "../errors/sanitizationErrors.h"
#include "sanitization.h"

#define END_CHAR ((char)'\0')
#define HTAB_CHAR ((char)'\t')
#define NEW_LINE_CHAR ((char)'\n')
#define VTAB_CHAR ((char)'\v')
#define FORM_FEED_CHAR ((char)'\f')
#define CARRIAGE_RETURN_CHAR ((char)'\r')
#define SPACE_CHAR ((char)' ')


static int charIsDirty(char character) {
    switch(character) {
    case HTAB_CHAR:
    case NEW_LINE_CHAR:
    case VTAB_CHAR:
    case FORM_FEED_CHAR:
    case CARRIAGE_RETURN_CHAR:
    case SPACE_CHAR:
        return 1;
    default:
        return 0;
    }
}

static int cleanExpression(char* expression) {
    int numDirtyChar = 0;
    int expLength = strlen(expression);

    char duplicateExp[expLength];

    strncpy(duplicateExp, expression, (size_t)expLength);

    duplicateExp[expLength] = END_CHAR;

    int j = 0;
    for(int i = 0; duplicateExp[i] != END_CHAR; i++) {
        if(!charIsDirty(duplicateExp[i])) {
            expression[j++] = duplicateExp[i];
            continue;
        }
        numDirtyChar++;
    }
    expression[j] = END_CHAR;

    return numDirtyChar;
}

int getCleanExpression(char* expression) {
    if(!expression) {
        reportErrorAndExit(invalidExpressionError);
    }

    return cleanExpression(expression);
}