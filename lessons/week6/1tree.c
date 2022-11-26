#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};
typedef struct node *BTREE;

BTREE newNode(int data)
{
    BTREE p;
    p = (BTREE)malloc(sizeof(struct node));
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

/*
        25              35 i insert ettik.
    10      40
          30
           35

*/

BTREE insert(BTREE root, int x)
{
    if (root == NULL)
    {
        root = newNode(x);
    }
    else
    {
        if (x < root->data)
            root->left = insert(root->left, x);

        else
            root->right = insert(root->right, x);
    }

    return root;
}

void inorder(BTREE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void preorder(BTREE root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BTREE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

// Get numbers from user till -1
int main(int argc, char const *argv[])
{
    BTREE myroot = NULL;
    int i;
    scanf("%d", &i);
    while (i != -1)
    {
        myroot = insert(myroot, i);
        scanf("%d", &i);
    }

    inorder(myroot);
    return 0;
}
