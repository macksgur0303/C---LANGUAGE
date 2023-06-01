#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main()
{
    srand((unsigned)time(NULL));
    int number[SIZE] = { 0 };
    int odd[SIZE] = { 0 };
    int even[SIZE] = { 0 };

    for (int i = 0; i < SIZE; i++)
    {
        number[i] = rand() % 100 + 1;
        printf("%d ", number[i]);

        if (number[i] % 2 == 0)
        {
            even[i] = number[i];
        }

        else
            odd[i] = number[i];
    }
    printf("\n\n");

    printf("홀수 배열: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", odd[i]);
    printf("\n");

    printf("짝수 배열: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", even[i]);
    printf("\n");
}