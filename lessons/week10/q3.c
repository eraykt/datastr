// convert a BST into its mirror tree.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

typedef struct node BTREE;

void *mirror(BTREE *root)
{
    if (root == NULL)
        return;

    if (root->left == root->right)
        return;

    BTREE *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}
