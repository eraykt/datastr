#include <stdio.h>
#include <stdlib.h>

int check(int num)
{
    if (num < 10)
        return -1;

    int temp;

    while (num > 10)
    {
        temp = num % 10;
        num /= 10;

        if (num % 10 != temp)
            return 0;
    }

    return 1;
}

void main()
{
    int A[] = {233, 45, 777, 81, 99999, 36, 90, 88, 11, 61};

    for (int i = 0; i < 10; i++)
    {
        if (check(A[i]))
            printf("%d >> tum basamaklari esit\n", A[i]);

        else
            printf("%d >> tum basamaklari esit degil\n", A[i]);
    }
}