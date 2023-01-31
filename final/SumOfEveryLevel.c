#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
} BTREE;

BTREE *NewNode(int data)
{
    BTREE *p = (BTREE *)malloc(sizeof(struct node));
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

BTREE *Insert(BTREE *root, int data)
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
int height(BTREE *root)
{
    // the root is null then the height of the tree will be Zero
    if (root == NULL)
        return 0;
    else
    {
        /* compute  height of each subtree */
        int lheight = height(root->left);
        int rheight = height(root->right);

        /* use the larger one */
        // height of both the sub trees is calcualted and which one is higher is used.
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void InOrder(BTREE *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d\t", root->data);
        InOrder(root->right);
    }
}

typedef struct
{
    int top;
    int data[STACK_SIZE];
} stack;

void Reset(stack *stk)
{
    stk->top = -1;
}

void Push(stack *stk, int data)
{
    if (stk->top == STACK_SIZE - 1)
        printf("Stack is full!\n");

    else
        stk->data[++stk->top] = data;
}

int Pop(stack *stk)
{
    if (stk->top == -1)
    {
        printf("Stack is empty!\n");
        return -100;
    }

    return stk->data[stk->top--];
}

int SumOfLevel(BTREE *root, int level)
{
    if (root == NULL)
        return 0;

    if (root->right == root->left && level != 0)
        return 0;

    if (level != 0)
        return SumOfLevel(root->left, level - 1) + SumOfLevel(root->right, level - 1);

    return root->data;
}

stack *AddToStack(BTREE *root)
{
    stack *stk = (stack *)malloc(sizeof(stack));
    Reset(stk);

    for (int i = 0; i < height(root); i++)
        Push(stk, SumOfLevel(root, i));

    return stk;
}

int main(int argc, char const *argv[])
{
    BTREE *root = NULL;
    root = Insert(root, 20);

    root = Insert(root, 15);
    root = Insert(root, 35);

    root = Insert(root, 7);
    root = Insert(root, 17);
    root = Insert(root, 25);
    root = Insert(root, 40);
    root = Insert(root, 2);
    root = Insert(root, 8);

    /* 20 50 89 10
                        20
                15            35
              7    17       25   40
            2  8
    */

    stack *stk = AddToStack(root);

    printf("%d ", Pop(stk));
    printf("%d ", Pop(stk));
    printf("%d ", Pop(stk));
    printf("%d ", Pop(stk));

    return 0;
}

void rec(BTREE *root, int x)
{
    if (root == NULL)
        return;

    if (root->left == root->right)
        return;

    if (root->data > x)
    {
        printf("right of the %d", root->data);
        rec(root->right, x);
    }

    else
    {
        printf("left of the %d", root->data);
        rec(root->left, x);
    }
}
