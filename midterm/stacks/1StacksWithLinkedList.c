#include <stdio.h>
#include <stdlib.h>

/*
1- initialize
2- push
3- pop
*/

#define STACK_SIZE 5

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct
{
    int cnt;
    node *top;
} stack;

void Initialize(stack *stk)
{
    stk->cnt = 0;
    stk->top = NULL;
}

void Push(stack *stk, int c)
{
    if (stk->cnt == STACK_SIZE)
        printf("stack is full");

    else
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = c;
        temp->next = stk->top;
        stk->top = temp;
        stk->cnt++;
    }
}

int Pop(stack *stk)
{
    if (stk->cnt == 0)
    {
        printf("stack is empty\n");
        return -100;
    }

    int x = stk->top->data;
    node *deleted = stk->top;
    stk->top = deleted->next;
    stk->cnt--;
    free(deleted);
    return x;
}

int main(int argc, char const *argv[])
{
    stack *st = (stack *)malloc(sizeof(stack));

    Initialize(st);

    Push(st, 1);
    Push(st, 2);
    Push(st, 3);
    Push(st, 4);
    Push(st, 5);
    Push(st, 6);

    printf("\n%d\n", Pop(st));
    printf("%d\n", Pop(st));
    printf("%d\n", Pop(st));
    printf("%d\n", Pop(st));
    printf("%d\n", Pop(st));
    printf("%d\n", Pop(st));

    /*stack st;

    Initialize(&st);

    Push(&st, 1);
    Push(&st, 2);
    Push(&st, 3);
    Push(&st, 4);
    Push(&st, 5);
    Push(&st, 6);

    printf("\n%d\n", Pop(&st));
    printf("%d\n", Pop(&st));
    printf("%d\n", Pop(&st));
    printf("%d\n", Pop(&st));
    printf("%d\n", Pop(&st));
    printf("%d\n", Pop(&st));*/

    return 0;
}
