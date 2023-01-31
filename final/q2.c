#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
    struct node *prev;
} node;

node *AddFront(node *head, char data)
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

node *AddEnd(node *head, char data)
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

void PrintList(node *head)
{
    node *iter = head;

    while (iter != NULL)
    {
        printf("%c", iter->data);
        iter = iter->next;
    }
}

int Palindrome(node *head)
{
    node *first = head;
    node *last = head;
    int cnt = 0;

    while (last->next != NULL)
    {
        last = last->next;
        cnt++;
    }

    cnt++;

    for (int i = 0; i < cnt / 2; i++)
    {
        if (first->data != last->data)
            return 0;

        first = first->next;
        last = last->prev;
    }

    return 1;
}

int main(int argc, char const *argv[])
{
    node *head = NULL;

    head = AddFront(head, 'k');
    head = AddEnd(head, 'a');
    head = AddEnd(head, 'y');
    head = AddEnd(head, 'a');
    head = AddEnd(head, 'k');

    PrintList(head);

    printf("\n%d", Palindrome(head));

    return 0;
}
