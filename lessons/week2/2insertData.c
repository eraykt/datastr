// inserting element in a list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// inserting an element in front of a list
struct node *AddFront(struct node *head, int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}

// inserting an element at the end of the list
struct node *AddLast(struct node *head, int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    struct node *last = head;

    while (last->next != NULL)
        last = last->next;

    last->next = temp;

    return head;
}

void main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    head->next = NULL;

    head = AddFront(head, 2);
    printf("%d", head->data); // 2

    head = AddLast(head, 1);
    struct node *q = head;
    while (q->next != NULL)
        q = q->next;

    printf("\n%d", q->data); // 1
}
