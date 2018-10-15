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


int getStackLength(Stack stack) {
    if(!stack) {
        reportErrorAndExit(invalidStackError);
    }

    return stack->length;
}


static Node createNode(char data) {
    Node newNode = malloc(sizeof(struct node));

    if(!newNode) {
        reportErrorAndExit(stackCreatFailError);
    }

    newNode->data = data;
    newNode->next = NULL;
}

void pushStack(Stack stack, char data) {
    if(!stack) {
        reportErrorAndExit(invalidStackError);
    }

    Node newNode = createNode(data);
    newNode->next = stack->head;
    stack->head = newNode;

    stack->length++;
}

int emptyStack(Stack stack) {
    if(!stack) {
        reportErrorAndExit(invalidStackError);
    }

    return stack->length == 0;
}