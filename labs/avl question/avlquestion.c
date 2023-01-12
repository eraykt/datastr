#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} AVLTREE;

int maxValue(int x, int y)
{
    return x >= y ? x : y;
}

int height(AVLTREE *root)
{
    if (root == NULL)
        return -1;
    else
    {
        int lheight, rheight;
        rheight = height(root->right);
        lheight = height(root->left);
        if (rheight > lheight)
            return rheight + 1;
        else
            return lheight + 1;
    }
}

AVLTREE *NewNode(int data)
{
    AVLTREE *node = (AVLTREE *)malloc(sizeof(AVLTREE));

    node->data = data;
    node->left = node->right = NULL;
    node->height = 0;

    return node;
}

AVLTREE *RightRotate(AVLTREE *z)
{
    AVLTREE *temp = z->left;

    z->left = temp->right;
    temp->right = z;

    z->height = maxValue(height(z->left), height(z->right)) + 1;
    temp->height = maxValue(height(temp->left), height(temp->right)) + 1;

    return temp;
}

AVLTREE *LeftRotate(AVLTREE *z)
{
    AVLTREE *temp = z->right;
    z->right = temp->left;
    temp->left = z;

    z->height = maxValue(height(z->left), height(z->right)) + 1;
    temp->height = maxValue(height(temp->left), height(temp->right)) + 1;

    return temp;
}
// once sol sonra sag
AVLTREE *leftRightRotate(AVLTREE *z)
{
    z->left = LeftRotate(z->left);
    return RightRotate(z);
}

// once sag sonra sol
AVLTREE *rightLeftRotate(AVLTREE *z)
{
    z->right = RightRotate(z->right);
    return LeftRotate(z);
}

AVLTREE *insertToAVL(int x, AVLTREE *root)
{
    if (root != NULL)
    {
        if (x < root->data)
            root->left = insertToAVL(x, root->left);
        else
            root->right = insertToAVL(x, root->right);

        root->height = maxValue(height(root->left), height(root->right)) + 1;
        if ((height(root->left) - height(root->right)) > 1 && x < root->left->data)
            return RightRotate(root);

        if ((height(root->left) - height(root->right)) > 1 && x > root->left->data)
            return leftRightRotate(root);

        if ((height(root->left) - height(root->right)) < -1 && x > root->right->data)
            return LeftRotate(root);

        if ((height(root->left) - height(root->right)) < -1 && x < root->right->data)
            return rightLeftRotate(root);
    }
    else
        root = NewNode(x);

    return root;
}

void inorder(AVLTREE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int main(int argc, char const *argv[])
{
    AVLTREE *root = NULL;

    root = insertToAVL(3, root);
    root = insertToAVL(5, root);
    root = insertToAVL(7, root);
    root = insertToAVL(2, root);
    root = insertToAVL(9, root);

    inorder(root);

    return 0;
}
