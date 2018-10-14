#include <string.h>

#include "reading.h"
#include "../errors/errors.h"
#include "../errors/readingErrors.h"

// currently, `bufferLen` is unused
int readDirtyExpression(char* buffer, unsigned bufferLen) {
    if(!buffer) {
        reportErrorAndExit(invalidBufferError);
    }

    int success = scanf("%[^\n]s%*c", buffer);

    if(!success) {
        reportErrorAndExit(readError);
    }

    return (int)strlen(buffer);
}


