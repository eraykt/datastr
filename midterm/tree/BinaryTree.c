#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
} *BTREE;

BTREE NewNode(int data)
{
    BTREE p = (BTREE)malloc(sizeof(struct node));
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

BTREE Insert(BTREE root, int data)
{
    if (root == NULL)
    {
        root = NewNode(data);
    }

    else
    {
        if (data < root->data)
            root->left = Insert(root->left, data);

        else
            root->right = Insert(root->right, data);
    }

    return root;
}

void InOrder(BTREE root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d\t", root->data);
        InOrder(root->right);
    }
}

void PreOrder(BTREE root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(BTREE root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d\t", root->data);
    }
}

BTREE InputTillMinusOne()
{
    BTREE myroot = NULL;
    int i;

    scanf("%d", &i);

    while (i != -1)
    {
        myroot = Insert(myroot, i);
        scanf("%d", &i);
    }

    return myroot;
}

int main(int argc, char const *argv[])
{
    BTREE minusOne = InputTillMinusOne();
    InOrder(minusOne);
    return 0;
}
