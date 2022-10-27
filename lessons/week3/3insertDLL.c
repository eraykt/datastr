// inserting a node in front of a DLL

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *addfront(node *head, int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;

    temp->next = head;
    temp->prev = NULL;

    if (head != NULL)
        head->prev = temp;

    head = temp;
    return head;
}

node *addlast(node *head, int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL)
        temp->prev = NULL;

    else
    {
        node *last = head;

        while (last->next != NULL)
            last = last->next;

        last->next = temp;
        temp->prev = last;
    }

    return head;
}