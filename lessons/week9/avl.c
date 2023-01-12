#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

typedef struct node AVLTREE;

AVLTREE *RightRotate(AVLTREE *z)
{
    AVLTREE *y = z->left;
    z->left = y->right;
    y->right = z;

    z->height = max(z->left, z->right) + 1;
    y->height = max(y->left, y->right) + 1;
    return y;
}