// printing the elements in the list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void PrintList(struct node *head)
{
    if (head == NULL)
        printf("list is empty.");

    else
    {
        while (head != NULL)
        {
            printf("%d", head->data);
            head = head->next;
        }
    }
}

// printing the elements in reverse order
void ReversePrintList(struct node *head)
{
    if (head == NULL)
        return;

    ReversePrintList(head->next);
    printf("%d", head->data);
}

void recursivePrintList(struct node *head)
{
    if (head == NULL)
        return;

    printf("%d", head->data);
    recursivePrintList(head->next);
}