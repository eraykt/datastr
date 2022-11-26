// queue yu ve stack'i swaplayan fonksiyonu yaz.
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

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

typedef struct q
{
    int cnt;
    int data[STACK_SIZE];
    int rear, front;
} *queue;

void Initialize(queue q)
{
    q->cnt = 0;
    q->front = 0;
    q->rear = -1;
}

int isFull(queue q)
{
    if (q->cnt == STACK_SIZE)
        return 1;

    return 0;
}

int isEmpty(queue q)
{
    if (q->cnt == 0)
        return 1;

    return 0;
}

void Enqueue(queue q, int data)
{
    if (isFull(q))
        printf("Queue is full!\n");

    else
    {
        q->rear++;
        q->cnt++;

        if (q->rear == STACK_SIZE)
            q->rear = 0;

        q->data[q->rear] = data;
    }
}

int Dequeue(queue q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -100;
    }

    int x = q->data[q->front++];
    q->cnt--;

    if (q->front == STACK_SIZE)
        q->front = 0;

    return x;
}

void swapQueueAndStack(queue q, stack *stk)
{
    stack *stkTemp = (stack *)malloc(sizeof(stack));
    Reset(stkTemp);

    while (q->cnt != 0)
        Push(stkTemp, Dequeue(q));

    while (stk->top != -1)
        Enqueue(q, Pop(stk));

    while (stk->top != STACK_SIZE - 1)
        Push(stk, Pop(stkTemp));
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

    queue q = (queue)malloc(sizeof(struct q));
    Initialize(q);
    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);
    Enqueue(q, 40);
    Enqueue(q, 50);

    swapQueueAndStack(q, stk);
    printf("%d ", Pop(stk));
    printf("%d ", Pop(stk));
    printf("%d ", Pop(stk));
    printf("%d ", Pop(stk));
    printf("%d ", Pop(stk));
    printf("\n");
    printf("%d ", Dequeue(q));
    printf("%d ", Dequeue(q));
    printf("%d ", Dequeue(q));
    printf("%d ", Dequeue(q));
    printf("%d ", Dequeue(q));

    return 0;
}
