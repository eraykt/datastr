// Write a function that adds values of the last and the first node of a circular
// linked list and insert the sum into the list as the last node.
// You may assume there are at least two nodes in the list.
// You are not allowed to use any linked list function.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *add(node *head)
{
    node *iter = head;

    while (iter->next != head)
        iter = iter->next;

    node *added = (node *)malloc(sizeof(node));
    added->data = head->data + iter->data;
    added->next = head;

    iter->next = added;

    return head;
}