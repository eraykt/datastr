#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

typedef struct q
{
    int cnt;
    int data[QUEUE_SIZE];
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

int main(int argc, char const *argv[])
{
    queue q = (queue)malloc(sizeof(struct q));

    Initialize(q);
    Enqueue(q, 1);
    Enqueue(q, 2);
    Enqueue(q, 3);
    Enqueue(q, 4);
    Enqueue(q, 5);
    Enqueue(q, 6);

    printf("%d\n", Dequeue(q));
    printf("%d\n", Dequeue(q));
    printf("%d\n", Dequeue(q));
    printf("%d\n", Dequeue(q));
    printf("%d\n", Dequeue(q));
    printf("%d\n", Dequeue(q));
    return 0;
}
