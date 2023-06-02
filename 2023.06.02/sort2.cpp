#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

int main()
{
    srand((unsigned)time(NULL));
    int list[SIZE] = { 0 };
    int temp, a;

    for (int i = 0; i < SIZE; i++)
    {
        list[i] = rand() % 100;
        a = rand() % 2;
        if (a == 1)
            list[i] = -list[i];
        printf("%d ", list[i]);
    }

    printf("\n");

    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (list[j] < list[i])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }

        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", list[i]);
    }

    printf("\n");

    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (list[j] > list[i])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }

        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", list[i]);
    }

}
