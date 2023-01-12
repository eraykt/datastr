#include <stdio.h>
#include <stdlib.h>

void FindBiggestTwoNumbers(int dizi[])
{
    int max1 = dizi[0];
    int max2 = dizi[0];
    int i;

    for (i = 0; i < 10; i++)
    {
        if (max1 < dizi[i])
        {
            max2 = max1;
            max1 = dizi[i];
        }

        else if (max2 < dizi[i])
        {
            max2 = dizi[i];
        }
    }

    printf("en buyuk=%d\ten buyuk ikinci=%d", max1, max2);
}

void main()
{
    int dizi[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int i;

    printf("---10 eleman gir---\n");

    for (i = 0; i < 10; i++)
    {
        printf("%d. eleman..:", i + 1);
        scanf("%d", &dizi[i]);
    }

    FindBiggestTwoNumbers(dizi);
}