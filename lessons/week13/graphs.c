/* Write a function that returns the degree of a given vertex in an undirected graph which is represented by adjacency matrix.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int degree(int A[][2], int v, int n)
{
    int result = 0;

    for (int i = 0; i < n; i++)
        result += A[v][i];

    return result;
}

/* 2-outdegree, in a digraph, adjacency list */
int outdegree(struct node *heads[], int v)
{
    int result = 0;
    struct node *temp = heads[v];

    while (temp != NULL)
    {
        result++;
        temp = temp->next;
    }

    return result - 1;
}

/* 3- Write a function that returns the number of edges in an undirected graph which is represented by adjacecy matrix.*/

int edges(int A[][], int n)
{
    int result = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            // result += A[i][j];

            return result;
}

/* Homework: Write a function that returns true if there is a path between two given
vertices in a undirected graph which is represented by matrix.*/
