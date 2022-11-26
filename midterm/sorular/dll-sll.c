// sll verilen bir listeyi tersten dll ye çevirme
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

typedef struct dll
{
    int data;
    struct dll *next;
    struct dll *prev;
} dll;

dll *AddFront(dll *head, int data)
{
    dll *temp = (dll *)malloc(sizeof(dll));

    temp->data = data;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL)
        head->prev = temp;

    head = temp;
    return head;
}

dll *Reverse(node *head1)
{
    dll *head2 = NULL;

    while (head1 != NULL)
    {
        dll *temp = (dll *)malloc(sizeof(dll));
        temp->data = head1->data;
        temp->next = head2;

        if (temp->next != NULL)
            temp->next->prev = temp;

        head2 = temp;
        head1 = head1->next;
    }

    head2->prev = NULL;
    return head2;
}

void printDll(dll *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{
    struct node *head1 = NULL;
    head1 = InitializeLinkedList(head1, 20);
    head1 = AddFrontOfALinkedList(head1, 8);
    head1 = AddFrontOfALinkedList(head1, 12);
    head1 = AddFrontOfALinkedList(head1, 5);

    PrintAllLinkedList(head1);
    printf("\n");
    dll *head2 = Reverse(head1);
    printDll(head2);

    return 0;
}
