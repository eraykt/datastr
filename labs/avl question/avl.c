#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
};

typedef struct node AVLTREE;

int maxValue(int x, int y)
{
    return x >= y ? x : y;
}

AVLTREE *new_node(int data)
{
    AVLTREE *p = (AVLTREE *)malloc(sizeof(struct node));
    p->data = data;
    p->left = p->right = NULL;
    p->height = 0;
    return p;
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
    z->height = maxValue(z->left == NULL ? -1 : z->left->height, z->left == NULL ? -1 : z->right->height) + 1;
    temp->height = maxValue(z->left == NULL ? -1 : temp->left->height, z->left == NULL ? -1 : temp->right->height) + 1;
    return temp;
}

AVLTREE *leftRightRotate(AVLTREE *z)
{
    z->left = LeftRotate(z->left);
    return RightRotate(z);
}

AVLTREE *rightLeftRotate(AVLTREE *z)
{
    z->right = RightRotate(z->right);
    return LeftRotate(z);
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

AVLTREE *insertToAVL(int x, AVLTREE *tree)
{
    if (tree != NULL)
    {
        if (x < tree->data)
            tree->left = insertToAVL(x, tree->left);
        else
            tree->right = insertToAVL(x, tree->right);

        tree->height = maxValue(height(tree->left), height(tree->right)) + 1;
        if ((height(tree->left) - height(tree->right)) > 1 && x < tree->left->data)
            return RightRotate(tree);

        if ((height(tree->left) - height(tree->right)) > 1 && x > tree->left->data)
            return leftRightRotate(tree);

        if ((height(tree->left) - height(tree->right)) < -1 && x > tree->right->data)
            return LeftRotate(tree);

        if ((height(tree->left) - height(tree->right)) < -1 && x < tree->right->data)
            return rightLeftRotate(tree);
    }
    else
        tree = new_node(x);
    return tree;
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

    root = new_node(2);
    root = new_node(5);
    root = new_node(3);
    root = new_node(1);
    root = new_node(9);
    inorder(root);
    return 0;
}

// int main()
// {
//     AVLTREE *agac = NULL;
//     int key, secim;
//     printf("Veri giriniz... Cikis icin -1 basiniz..");
//     scanf("%d", &key);
//     while (key != -1)
//     {
//         agac = insertToAVL(key, agac);
//         scanf("%d", &key);
//     }
//     do
//     {
//         printf("\n1-Insert\n2-Height\n3 Inorder\n4-Exit\nSeciminiz..?");
//         scanf("%d", &secim);
//         switch (secim)
//         {
//         case 1:
//             printf("Veri giriniz..");
//             scanf("%d", &key);
//             agac = insertToAVL(key, agac);
//             printf("Veri Eklendi...");
//             break;
//         case 2:
//             // printf("Height=%d",height(agac));
//             printf("Height=%d", agac->height);
//             break;
//         case 3:
//             inorder(agac);
//             break;
//         case 4:
//             exit(1);
//         default:
//             printf("Hatali Secim...");
//             break;
//         }
//     } while (1);
//     return 0;
// }