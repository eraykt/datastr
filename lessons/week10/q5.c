// In a binary tree consisting of nodes which have student information
// such as name, surname, number and final, write a program that lists the students
// who have final grade above the average of the final grades in the classroom.
// Write the node structure. Note that you should calculate the average of the final grades.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    char name[20];
    char surname[20];
    double number;
    float final;
};
typedef struct node *BTREE;

void list(BTREE root, float avg)
{
    if (root == NULL)
        return;

    if (root->final > avg)
        printf("%s ", root->name);

    list(root->left, avg);
    list(root->right, avg);
}

float average(BTREE root)
{
    return sumnodes(root) / size(root);
}

float sumnodes(BTREE root)
{
    if (root == NULL)
        return 0;

    return root->final + sumnodes(root->left) + sumnodes(root->right);
}

float size(BTREE root)
{
    if (root == NULL)
        return 0;

    return 1 + size(root->left) + size(root->right);
}
