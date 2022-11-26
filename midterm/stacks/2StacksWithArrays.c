#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

/*
1- Reset
2- push
3- pop
*/

typedef struct
{
    int top;
    int data[STACK_SIZE];
} stack;

void Reset(stack *stk)
{
    stk->top = -1;
}

void Push(stack *stk, int data)
{
    if (stk->top == STACK_SIZE - 1)
        printf("Stack is full!\n");

    else
        stk->data[++stk->top] = data;
}

int Pop(stack *stk)
{
    if (stk->top == -1)
    {
        printf("Stack is empty!\n");
        return -100;
    }

    return stk->data[stk->top--];
}

int main(int argc, char const *argv[])
{
    stack *stk = (stack *)malloc(sizeof(stack));

    Reset(stk);

    Push(stk, 1);
    Push(stk, 2);
    Push(stk, 3);
    Push(stk, 4);
    Push(stk, 5);
    Push(stk, 6);

    printf("%d\n", Pop(stk));
    printf("%d\n", Pop(stk));
    printf("%d\n", Pop(stk));
    printf("%d\n", Pop(stk));
    printf("%d\n", Pop(stk));
    printf("%d\n", Pop(stk));

    return 0;
}
