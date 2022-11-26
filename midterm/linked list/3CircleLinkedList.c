#include <stdio.h>
#include <stdlib.h>
/*
1- cll başa ekleme
2- cll sona ekleme
*/
typedef struct node
{
    int data;
    struct node *next;
} node;

node *AddFront(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->data = data;

    if (head == NULL)
    {
        temp->next = temp;
        head = temp;

        return head;
    }

    else
    {
        node *last = head;

        while (last->next != head)
            last = last->next;

        temp->next = head;
        last->next = temp;
        head = temp;
    }

    return head;
}

node *AddLast(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;

    if (head == NULL)
    {
        temp->next = temp;
        head = temp;

        return head;
    }

    else
    {
        node *last = head;

        while (last->next != head)
            last = last->next;

        temp->next = head;
        last->next = temp;
    }

    return head;
}

void print(node *head)
{
    node *last = head;
    while (last->next != head)
    {
        printf("%d\n", last->data);
        last = last->next;
    }
    printf("%d\n", last->data);
}

int main(int argc, char const *argv[])
{
    node *head = NULL;

    head = AddFront(head, 5);

    head = AddFront(head, 31);

    head = AddLast(head, 2);

    print(head);

    return 0;
}
