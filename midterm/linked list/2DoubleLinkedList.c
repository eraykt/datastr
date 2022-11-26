#include <stdio.h>
#include <stdlib.h>
/*
1- dll nin başına eleman ekleme
2- dll nin sonuna eleman ekleme
3- verilen bir eleman ile dllyi silme
*/

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *AddFront(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL)
        head->prev = temp;

    head = temp;
    return head;
}

node *AddEnd(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->data = data;
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

node *Delete(node *head, int key)
{
    if (head != NULL)
    {
        node *temp = head;

        if (head->data == key)
        {
            head = head->next;
            free(temp);

            head->prev = NULL;
        }

        else
        {
            while (temp->data != key && temp != NULL)
                temp = temp->next;

            if (temp == NULL)
            {
                printf("this element does not exist.");
                return head;
            }

            temp->prev->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);
        }

        return head;
    }
}