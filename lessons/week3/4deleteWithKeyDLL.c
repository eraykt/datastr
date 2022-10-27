// delete a node with a given key in a DLL

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *delete (node *head, int x)
{
    if (head != NULL)
    {
        node *temp = head;

        if (head->data == x)
        {
            head = head->next;
            free(temp);
            head->prev = NULL;
        }

        else
        {
            while (temp->data != x && temp != NULL)
                temp = temp->next;

            if (temp == NULL)
                return head;

            temp->prev->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);
        }

        return head;
    }
}