// insert a node in front of a CLL

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *addfront(node *head, int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
}