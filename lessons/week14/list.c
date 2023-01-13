#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} list;

list *Initialize(list *head, int vertex)
{
    head = (list *)malloc(sizeof(list));
    head->next = NULL;
    head->data = vertex;

    return head;
}

list *addLast(list *head, int vertex)
{
    list *iter = head;

    while (iter->next != NULL)
        iter = iter->next;

    list *new = (list *)malloc(sizeof(list));
    new->data = vertex;
    new->next = NULL;

    iter->next = new;
    return head;
}

void print(list *heads[])
{
    list *iter;
    for (int i = 0; i < 6; i++)
    {
        printf("%d-> ", heads[i]->data);

        iter = heads[i]->next;

        while (iter != NULL)
        {
            printf("%d ", iter->data);
            iter = iter->next;
        }

        printf("\n");
    }
}

int degree(list *head)
{
    int result = 0;

    list *iter = head;

    while (iter->next != NULL)
    {
        result++;
        iter = iter->next;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    list *heads[6] = {NULL};

    for (int i = 0; i < 6; i++)
        heads[i] = Initialize(heads[i], i + 1);

    heads[0] = addLast(heads[0], 2);

    heads[1] = addLast(heads[1], 3);
    heads[1] = addLast(heads[1], 4);

    heads[2] = addLast(heads[2], 4);
    heads[2] = addLast(heads[2], 6);

    heads[3] = addLast(heads[3], 5);

    heads[4] = addLast(heads[4], 1);
    heads[4] = addLast(heads[4], 3);

    heads[5] = addLast(heads[5], 5);

    for (int i = 0; i < 6; i++)
        printf("%d elemaninin derecesi=%d\n", i + 1, degree(heads[i]));

    print(heads);

    return 0;
}
