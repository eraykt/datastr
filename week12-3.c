#include <stdio.h>
#include <stdlib.h>
#define len 10

int count; // listenin aktif uzunluğu.

void AddNumberInOrder(int dizi[], int num)
{
    int i, j;

    if (count + 1 == len)
    {
        printf("liste dolu");
        return;
    }

    for (i = 0; i < count + 1; i++)
    {
        if (num < dizi[i])
        {
            for (j = count + 1; j >= i; j--)
                dizi[j + 1] = dizi[j];

            dizi[i] = num;
            count++;
            return; // ilk for ile girilecek yeri tespit et, ikinci for ile elemanları sağa kaydır. return ise işlem bitince foknsiyonu sonlandırıyor.
        }
    }

    dizi[count++] = num; // eğer yukarıda yer bulamadıysa demek ki eleman en sona eklenecek. return ile fonksiyon bitmemişse en sona eleman ekler.
}

void main()
{
    int dizi[len] = {1, 2, 7, 10};
    count = 4; // listenin aktif uzunluğu.

    AddNumberInOrder(dizi, 3);
    AddNumberInOrder(dizi, -1);
    AddNumberInOrder(dizi, 0);
    AddNumberInOrder(dizi, 6);
    AddNumberInOrder(dizi, 8);

    for (int i = 0; i < count; i++)
    {
        printf("%d ", dizi[i]);
    }
}