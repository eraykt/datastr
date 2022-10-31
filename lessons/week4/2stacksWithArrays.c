#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10

typedef struct
{
    int top;
    int data[STACKSIZE];
} stack;

void reset(stack *stk)
{
    stk->top = -1;
}

void push(stack *stk, int c)
{
    if (stk->top == STACKSIZE - 1)
        printf("\nStack is full");

    else
    {
        stk->data[++stk->top] = c;
    }
}

int pop(stack *stk)
{
    if (stk->top == -1)
    {
        printf("\nStack is empty");
        return -100;
    }

    return stk->data[stk->top--];
}
