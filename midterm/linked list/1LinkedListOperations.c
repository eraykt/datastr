#include <stdio.h>
#include <stdlib.h>

/*
1- initialize linked list
2- add front of a list
3- add end of a list
4- print all elements
5- print all elements with recursive
6- print reverse order
7- count of the list
8- count of the list with recursive
9- delete an element with key
10- destroy the list
11- destroy the list with recursive
*/

struct node
{
    int data;
    struct node *next;
};

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
        printf("\n%d\n", head->data);
        head = head->next;
    }
}

void PrintAllRecursive(struct node *head)
{
    if (head == NULL)
        return;

    printf("\n%d\n", head->data);
    return PrintAllRecursive(head->next);
}

void PrintReverse(struct node *head)
{
    if (head == NULL)
        return;

    PrintReverse(head->next);
    printf("\n%d\n", head->data);
}

int CountOfTheList(struct node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }

    return cnt;
}

int CountRecursive(struct node *head)
{
    if (head == NULL)
        return 0;

    return 1 + CountRecursive(head->next);
}

struct node *DeleteWithKey(struct node *head, int key)
{
    if (head != NULL)
    {
        struct node *n = head;

        if (n->data == key)
        {
            head = head->next;
            free(n);
        }

        else
        {
            while (n->next->data != key && n->next != NULL)
                n = n->next;

            if (n->next == NULL)
                return head;

            struct node *deleted = n->next;
            n->next = deleted->next;
            free(deleted);
        }
    }

    return head;
}

struct node *Destroy(struct node *head)
{
    struct node *temp = head;
    while (head != NULL)
    {
        head = head->next;
        free(temp);
        temp = head;
    }

    return NULL;
}

struct node *DestroyRecursive(struct node *head)
{
    if (head == NULL)
        return NULL;

    DestroyRecursive(head->next);
    free(head);
}

int main(int argc, char const *argv[])
{
    struct node *head = NULL;

    head = InitializeLinkedList(head, 5);
    // printf("head->data = %d\n", head->data);

    head = AddFrontOfALinkedList(head, 31);
    // printf("head->data = %d\n", head->data);

    head = AddEndOfALinkedList(head, 81);

    // PrintAllLinkedList(head);
    PrintAllRecursive(head);
    printf("\n");
    PrintReverse(head);
    printf("\n");

    printf("%d\n", CountRecursive(head));

    // deleting with key
    // head = DeleteWithKey(head, 5);
    // PrintAllRecursive(head);

    // printf("%d\n", CountRecursive(head));

    // head = DeleteWithKey(head, 31);

    // PrintAllLinkedList(head);
    return 0;
}
