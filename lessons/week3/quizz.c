// write a function that returns 1 if a value exists in a SLL, 0 otherwise.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int search(struct node *head, int x)
{
    while (head != NULL)
    {
        if (head->data == x)
            return 1;

        head = head->next;
    }
    return 0;
}