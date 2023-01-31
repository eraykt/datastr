// reverse a linked list first n elements.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *ReverseALinkedList(node *head, int n)
{
    if (n <= 1)
        return head;

    node *iter = head;

    for (int i = 0; i < n; i++)
    {
        iter = iter->next;

        if (iter == NULL)
            break;
    }

    node *current = head->next;
    node *next = NULL;

    for (int i = 0; i < n - 1; i++)
    {
        next = current->next;
        current->next = head;
        if (i == 0)
            head->next = iter;

        head = current;
        current = next;
    }
    return head;
}

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

struct node *AddEndOfALinkedList(struct node *head, int data)
{
    if (head == NULL)
        return InitializeLinkedList(head, data);

    struct node *last = head;

    while (last->next != NULL)
        last = last->next;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    last->next = temp;

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

int main(int argc, char const *argv[])
{
    node *head = NULL;

    head = AddEndOfALinkedList(head, 1);
    head = AddEndOfALinkedList(head, 2);
    head = AddEndOfALinkedList(head, 3);
    head = AddEndOfALinkedList(head, 4);
    head = AddEndOfALinkedList(head, 5);
    head = AddEndOfALinkedList(head, 6);
    head = AddEndOfALinkedList(head, 7);
    head = AddEndOfALinkedList(head, 8);
    head = AddEndOfALinkedList(head, 9);
    head = AddEndOfALinkedList(head, 10);

    PrintAllLinkedList(head);

    head = ReverseALinkedList(head, 5);
    printf("\n");
    PrintAllLinkedList(head);
    return 0;
}
