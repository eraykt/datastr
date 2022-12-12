// write a function that returns the number of nodes in a given level.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

typedef struct node *BTREE;

int value(BTREE root, int level)
{
    if (root == NULL)
        return;

    if (level == 0)
        return 1;

    return value(root->left, level - 1) + value(root->right, level - 1);
}