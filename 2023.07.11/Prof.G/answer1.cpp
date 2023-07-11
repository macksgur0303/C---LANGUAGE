#include <stdio.h>
#define SIZE 5

int main() 
{
    int arr[SIZE] = { 3, 6, 2, 8, 1 };
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < SIZE; i++) 
    {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    printf("max = %d\n", max);
    printf("min = %d\n", min);
}