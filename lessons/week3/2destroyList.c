// Destroy an SLL

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *destroyRecursive(node *head)
{
    if (head == NULL)
        return NULL;

    return destroyRecursive(head->next);
    free(head);
}

node *destroy(node *head)
{
    node *temp = head;
    while (head != NULL)
    {
        head = head->next;
        free(temp);
        temp = head;
    }
    return NULL;
}