// dll'de halihazırda sıralı olan bir listeye veri eklediğimiz zaman sırası bozulmadan sıraya ekleyecek fonksiyonu yaz.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int employeeNo;
    char name[20];
    struct node *next;
    struct node *prev;
} node;

node *AddFront(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->employeeNo = data;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL)
        head->prev = temp;

    head = temp;
    return head;
}

node *AddEnd(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->employeeNo = data;
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

node *AddWithOrder(node *stk, int no)
{
    node *added = (node *)malloc(sizeof(node));
    added->employeeNo = no;

    node *temp = stk;

    if (no < stk->employeeNo)
    {
        added->prev = stk->prev;
        added->next = stk;
        stk = added;
        return stk;
    }

    while (temp->employeeNo < no && temp->next != NULL)
        temp = temp->next;

    if (temp->next == NULL)
    {
        added->next = NULL;
        added->prev = temp;
        temp->next = added;
    }

    else
    {
        node *prev = temp->prev;

        temp->prev = added;
        prev->next = added;
        added->next = temp;
        added->prev = prev;
    }

    return stk;
}

void printer(node *stk)
{
    if (stk == NULL)
        return;

    printf("%d ", stk->employeeNo);
    printer(stk->next);

    // while (stk != NULL)
    // {
    //     printf("%d ", stk->employeeNo);
    //     stk = stk->next;
    // }
}

int main(int argc, char const *argv[])
{
    node *stk = NULL;

    stk = AddFront(stk, 30);
    stk = AddFront(stk, 20);
    stk = AddFront(stk, 10);

    stk = AddWithOrder(stk, 5);
    stk = AddWithOrder(stk, 40);
    stk = AddWithOrder(stk, 25);
    stk = AddWithOrder(stk, 23);
    stk = AddWithOrder(stk, 46);
    printer(stk);

    return 0;
}
