#include <stdlib.h>

#include "stack.h"
#include "../../errors/errors.h"
#include "../../errors/stackErrors.h"


struct node {
    char data;
    struct node* next;
};

typedef struct node* Node;

struct stack {
    int length;
    Node head;
};


Stack createStack(void) {
    Stack newStack = malloc(sizeof(struct stack));

    if(!newStack) {
        reportErrorAndExit(stackCreatFailError);
    }

    newStack->length = 0;
    newStack->head = NULL;

    return newStack;
}


static void removeStackContents(Stack stack) {
    Node temp = stack->head;

    while(temp) {
        stack->head = stack->head->next;
        free(temp);
        temp = stack->head;
    }
}

void destroyStack(Stack stack) {
    if(!stack) {
        reportErrorAndExit(invalidStackError);
    }

    removeStackContents(stack);

    free(stack);
}