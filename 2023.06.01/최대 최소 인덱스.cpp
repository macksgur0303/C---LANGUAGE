#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main()
{
    srand((unsigned)time(NULL));
    int min = 100, max = 0, index_min, index_max;
    int price[SIZE] = { 0 };
    for (int i = 0; i < SIZE; i++)
    {
        price[i] = rand() % 100 + 1;
        printf("%d ", price[i]);
    }
    printf("\n\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (min >= price[i])
        {
            min = price[i];
            index_min = i;
        }
        if (max <= price[i])
        {
            max = price[i];
            index_max = i;
        }
    }

    printf("최솟값: %d, 최솟값 인덱스: %d, 최댓값: %d, 최댓값 인덱스: %d", min, index_min, max, index_max);
}