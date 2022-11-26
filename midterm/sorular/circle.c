// 2 cll yi birleştiren fonksiyonu yaz.

#include <stdio.h>
#include <stdlib.h>

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
        printf("%d ", last->data);
        last = last->next;
    }
    printf("%d", last->data);
    printf(" %d", last->next->data);
}

node *CombineTwoCll(node *head1, node *head2)
{
    node *temp = head1;

    while (temp->next != head1)
        temp = temp->next;

    temp->next = head2;

    node *temp2 = head2;

    while (temp2->next != head2)
        temp2 = temp2->next;

    temp2->next = head1;

    return head1;
}

int main(int argc, char const *argv[])
{
    node *head1 = NULL;

    head1 = AddFront(head1, 30);
    head1 = AddFront(head1, 20);
    head1 = AddFront(head1, 10);

    // print(head1);

    node *head2 = NULL;
    head2 = AddFront(head2, 3);
    head2 = AddFront(head2, 2);
    head2 = AddFront(head2, 1);
    printf("\n");
    // print(head2);

    node *head3 = NULL;

    head3 = CombineTwoCll(head1, head2);
    print(head3);

    return 0;
}
