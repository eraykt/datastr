// creating a list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void main()
{
    system("cls");

    // creating head of the linked list
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));

    // assign a data
    head->data = 5;
    head->next = NULL;

    // insert another data
    head->next = (struct node *)malloc(sizeof(struct node));
    head->next->data = 3;
    head->next->next = NULL;
}