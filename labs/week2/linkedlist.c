#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} list;

list *AddNodeToFront(list *head, int data);
list *AddNoteToEnd(list *head, int data);
void PrintList(list *head);
void PrintListReverse(list *head);
int CountingElementsRec(list *head);
int CountingElements(list *head);

void main()
{
    system("cls");

    list *head = NULL;

    PrintList(head);
    printf("\n--------\n");
    head = AddNodeToFront(head, 3);
    PrintList(head);
    printf("--------\n");
    head = AddNodeToFront(head, 5);
    PrintList(head);
    printf("--------\n");
    head = AddNoteToEnd(head, 7);
    PrintList(head);
    printf("--------\n");
    PrintListReverse(head);

    int count1 = CountingElements(head);
    int count2 = CountingElementsRec(head);
    printf("\n%d %d", count1, count2);
}

list *AddNodeToFront(list *head, int data)
{
    list *temp = (list *)malloc(sizeof(list));

    if (head == NULL)
    {
        temp->data = data;
        temp->next = NULL;
        head = temp;
    }

    else
    {
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    return head;
}

list *AddNoteToEnd(list *head, int data)
{
    if (head == NULL)
        return AddNodeToFront(head, data);

    list *temp = (list *)malloc(sizeof(list));
    list *q = head;

    temp->data = data;
    temp->next = NULL;

    while (q->next != NULL)
        q = q->next;

    q->next = temp;

    return head;
}

void PrintList(list *head)
{
    if (head == NULL)
    {
        printf("the list is empty");
        return;
    }

    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void PrintListReverse(list *head)
{
    if (head == NULL)
        return;

    PrintListReverse(head->next);
    printf("%d\n", head->data);
}

int CountingElementsRec(list *head)
{
    if (head == NULL)
        return 0;

    return 1 + CountingElementsRec(head->next);
}

int CountingElements(list *head)
{
    int count = 0;

    if (head == NULL)
    {
        printf("the list is empty.");
        return count;
    }

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}