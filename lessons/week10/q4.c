// You are given a queue q1. Write a program that adds the values of q1
// into a new queue q2. if the value is even, or a new queue q3 otherwise.
// You can use queue methods such as enqueue, dequeue etc..

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

typedef struct q
{
    int cnt;
    int data[QUEUE_SIZE];
    int rear, front;
} *queue;

void func(queue q1)
{
    queue q2, q3;
    Initialize(q2);
    Initialize(q3);

    while (!isEmpty(q1))
    {
        int x = Dequeue(q1);

        if (x % 2 == 0)
            Enqueue(q2, x);

        else
            Enqueue(q3, x);
    }
}

void Initialize(queue q)
{
    q->cnt = 0;
    q->front = 0;
    q->rear = -1;
}

int isFull(queue q)
{
    if (q->cnt == QUEUE_SIZE)
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

        if (q->rear == QUEUE_SIZE)
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

    if (q->front == QUEUE_SIZE)
        q->front = 0;

    return x;
}
