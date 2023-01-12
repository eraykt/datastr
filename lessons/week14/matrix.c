/* Write a program that prints out the degree of each vertex in on undirected graph which is represented by adjacency matrix.*/

#include <stdio.h>
#include <stdlib.h>

// A - liste V - istenen eleman N - matrix uzunlugu
int degree(int A[6][6], int v, int n)
{
    int result = 0;

    for (int i = 0; i < n; i++)
        result += A[v][i];

    return result;
}

int edges(int A[6][6])
{
    int result = 0;

    for (int i = 0; i < 6; i++)
        for (int j = i + 1; j < 6; j++)
            result += A[i][j];

    return result;
}

int sumOfDegrees(int A[6][6])
{
    int res = 0;

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            res += A[i][j];

    return res;
}

int main(int argc, char const *argv[])
{

    /*   1 2 3 4 5 6
       1   1     1
       2 1   1 1
       3   1   1 1 1
       4   1 1   1
       5 1   1 1   1
       6     1   1
     */

    int adjacency[6][6] = {
        {0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 1},
        {0, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 0}};

    for (int i = 0; i < 6; i++)
        printf("%d elemaninin derecesi=%d\n", i + 1, degree(adjacency, i, 6));

    printf("\nmatrixin ayrit sayisi=%d\n", edges(adjacency));

    printf("\nelemanlarin derecelerinin toplami = %d", sumOfDegrees(adjacency));

    return 0;
}
