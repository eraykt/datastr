// write a function substractMin that substracts the smallest node value
// from all nodes (including itself) in the linked list. Suppose the list
// store the following elements = [8,4,7,2,9,4,5,3]
// if you made the call of substractMin(head), the list would then store the elements=
// [6,2,5,0,7,2,3,1]

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *SubstractMin(node *head)
{
    if (head == NULL)
        return NULL;

    node *iter = head->next;
    int min = head->data;

    while (iter != NULL)
    {
        if (iter->data < min)
            min = iter->data;

        iter = iter->next;
    }

    iter = head;

    while (iter != NULL)
    {
        iter->data = iter->data - min;
        iter = iter->next;
    }

    return head;
}