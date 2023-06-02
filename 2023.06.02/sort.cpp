#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

int main()
{
    srand((unsigned)time(NULL));
    int list[SIZE] = { 0 };
    int temp;

    for (int i = 0; i < SIZE; i++)
    {
        list[i] = rand() % 100;
        printf("%d ", list[i]);
        if (i == 50)
            printf("\n");
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
        if (i == 50)
            printf("\n");
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
        if (i == 50)
            printf("\n");
    }

}
