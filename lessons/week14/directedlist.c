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
    for (int i = 0; i < 4; i++)
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

int outdegree(list *heads[], int v)
{
    int result = 0;
    struct node *temp = heads[v];

    while (temp != NULL)
    {
        result++;
        temp = temp->next;
    }

    return result - 1;
}

int indegree(list *heads[], int v)
{
    int result = 0;
    list *temp;

    int indegree = v + 1;

    for (int i = 0; i < 4; i++)
    {
        temp = heads[i]->next;
        while (temp != NULL)
        {
            if (temp->data == indegree)
                result++;

            temp = temp->next;
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    list *heads[4] = {NULL};

    for (int i = 0; i < 4; i++)
        heads[i] = Initialize(heads[i], i + 1);

    heads[0] = addLast(heads[0], 2);
    heads[0] = addLast(heads[0], 3);

    heads[3] = addLast(heads[3], 1);

    printf("---THE ADJACENCY LIST---\n");
    print(heads);

    printf("---THE OUTDEGREE---\n");
    for (int i = 0; i < 4; i++)
        printf("outdegree of %d is %d\n", i + 1, outdegree(heads, i));

    printf("---THE INDEGREE---\n");
    for (int i = 0; i < 4; i++)
        printf("indegree of %d is %d\n", i + 1, indegree(heads, i));

    return 0;
}
