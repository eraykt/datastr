// counting the elements in a list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int CountList(struct node *head)
{
    int counter = 0;
    while (head != NULL)
    {
        counter++;
        head = head->next;
    }
}

int recursiveCountList(struct node *head)
{
    if (head == NULL)
        return 0;

    return 1 + recursiveCountList(head->next);
}