#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10

typedef struct
{
    int A[QUEUE_SIZE + 1];
    int cnt;
} pqueue;

void Initialize(pqueue *p)
{
    p->cnt = 0;
}

void insert(pqueue *p, int key)
{
    if (p->cnt == QUEUE_SIZE)
        printf("queue is full");

    else
    {
        p->A[++p->cnt] = key;
        int iter = p->cnt;

        while (iter != 1 && p->A[iter] < p->A[iter / 2])
        {
            int temp = p->A[iter];
            p->A[iter] = p->A[iter / 2];
            p->A[iter / 2] = temp;
            iter /= 2;
        }
    }
}

int delete(pqueue *p)
{
    if (p->cnt == 0)
    {
        printf("queue is empty");
        return -100;
    }

    else
    {
        int x = p->A[1];
        p->A[1] = p->A[p->cnt];
        p->cnt--;
        int iter = 1;

        while (2 * iter <= p->cnt && (p->A[iter] > p->A[2 * iter] || p->A[iter] > p->A[2 * iter + 1]))
        {
            if (p->A[2 * iter] < p->A[2 * iter + 1])
            {
                int temp = p->A[iter];
                p->A[iter] = p->A[2 * iter];
                p->A[2 * iter] = temp;
                iter *= 2;
            }
            else
            {
                int temp = p->A[iter];
                p->A[iter] = p->A[2 * iter + 1];
                p->A[2 * iter + 1] = temp;
                iter = (iter * 2) + 1;
            }
        }
        return x;
    }
}

void print_heap(pqueue *p)
{
    if (p->cnt == 0)
        printf("Queue is empty");

    else
        for (int i = 1; i <= p->cnt; i++)
            printf("%d\t", p->A[i]);
}

int main(int argc, char const *argv[])
{
    system("cls");

    pqueue *p = (pqueue *)malloc(sizeof(pqueue));

    Initialize(p);

    insert(p, 5);
    insert(p, 3);
    insert(p, 10);
    insert(p, 7);
    insert(p, 8);
    insert(p, 1);
    insert(p, 0);
    insert(p, 2);
    insert(p, -1);
    insert(p, 4);
    int a = delete (p);

    print_heap(p);
    return 0;
}
