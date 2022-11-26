#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct q
{
    int cnt;
    node *front;
    node *rear;
} *queue;

void Initialize(queue q)
{
    q->cnt = 0;
    q->front = q->rear = NULL;
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
        node *temp = (node *)malloc(sizeof(temp));
        temp->data = data;
        temp->next = NULL;

        if (isEmpty(q))
            q->front = q->rear = temp;

        else
        {
            q->rear->next = temp;
            q->rear = temp;
        }

        q->cnt++;
    }
}

int Dequeue(queue q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -100;
    }

    node *temp = q->front;
    int x = temp->data;
    q->front = temp->next;
    free(temp);
    q->cnt--;
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
