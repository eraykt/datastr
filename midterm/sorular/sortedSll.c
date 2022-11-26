// sıralı bir sll ye sırasını bozmadan eleman ekleme
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

struct node *InitializeLinkedList(struct node *head, int x)
{
    struct node *alperen;

    if (head == NULL)
    {
        alperen = (struct node *)malloc(sizeof(struct node));
        alperen->data = x;
        alperen->next = NULL;
    }
    else
        printf("head zaten olusturulmus.\n");

    return alperen;
}

struct node *AddFrontOfALinkedList(struct node *head, int data)
{
    if (head == NULL)
        return InitializeLinkedList(head, data);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;

    return head;
}

void PrintAllLinkedList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

node *InsertInOrder(node *head, int data)
{
    node *added = (node *)malloc(sizeof(node));
    added->data = data;

    if (data < head->data)
    {
        added->next = head;
        head = added;
        return head;
    }

    node *temp = head->next;
    node *prev = head;

    while (temp->data < data && temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        added->next = NULL;
        temp->next = added;
    }

    else
    {
        added->next = temp;
        prev->next = added;
    }

    return head;
}

int main(int argc, char const *argv[])
{
    node *head = NULL;
    head = InitializeLinkedList(head, 50);
    head = AddFrontOfALinkedList(head, 40);
    head = AddFrontOfALinkedList(head, 30);
    head = AddFrontOfALinkedList(head, 20);
    head = AddFrontOfALinkedList(head, 10);

    head = InsertInOrder(head, 5);
    head = InsertInOrder(head, 25);
    head = InsertInOrder(head, 60);

    PrintAllLinkedList(head);
    return 0;
}
