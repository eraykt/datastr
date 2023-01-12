#include <stdio.h>
#include <stdlib.h>

void AlphabeticOrder(char str[])
{
    int i, j, len = 0;

    while (str[len] != '\0')
        len++;

    for (i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (str[j] == ' ')
                continue;

            else if (str[j] > str[j + 1])
            {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    printf("%s", str);
}

void main()
{
    char str[] = "eray";
    AlphabeticOrder(str);
}