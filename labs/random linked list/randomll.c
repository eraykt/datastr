// single linked liste 100 adet random data ekle. sonra sırala.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define len 100

typedef struct node
{
    int data;
    struct node *next;
} node;

node *Initialize(node *head, int data)
{
    head = (node *)malloc(sizeof(node));
    head->data = data;
    head->next = NULL;
    return head;
}

node *Add(node *head, int data)
{
    if (head == NULL)
    {
        return Initialize(head, data);
    }

    node *added = (node *)malloc(sizeof(node));
    added->data = data;
    added->next = head;
    head = added;
    return head;
}

int RandomData()
{
    return rand() % 1000;
}

void PrintList(node *head)
{
    if (head == NULL)
        return;

    printf("%d ", head->data);
    PrintList(head->next);
}

/* Bubble sort the given linked list */
void bubbleSort(node *head)
{
    int swapped, i;
    node *ptr1;
    node *lptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                degis(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void degis(node *a, node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    node *list = NULL;

    for (int i = 0; i < 100; i++)
        list = Add(list, RandomData());

    bubbleSort(list);
    PrintList(list);

    return 0;
}
