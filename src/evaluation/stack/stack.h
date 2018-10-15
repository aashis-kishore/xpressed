#ifndef _STACK_H
#define _STACK_H

typedef struct stack* Stack;

Stack createStack(void);

void destroyStack(Stack);

int stackLength(Stack);

void pushStack(Stack, char);

int emptyStack(Stack);

char popStack(Stack);

char peekStack(Stack);

#endif