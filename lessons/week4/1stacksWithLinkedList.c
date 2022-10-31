#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10

typedef struct
{
    int cnt;
    struct node *top;
} stack;

struct node
{
    int data;
    struct node *next;
};

void initialize(stack *stk)
{
    stk->cnt = 0;
    stk->top = NULL;
}

void push(stack *stk, int c)
{
    if (stk->cnt == STACKSIZE)
        printf("stack is full.");
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = c;
        temp->next = stk->top;
        stk->top = temp;
        stk->cnt++;
    }
}

int pop(stack *stk)
{
    if (stk->cnt == 0)
    {
        printf("stack is empty");
        return -100;
    }
    else
    {
        int x = stk->top->data;
        struct node *deleted = stk->top;
        stk->top = deleted->next;
        stk->cnt--;
        free(deleted);
        return x;
    }
}