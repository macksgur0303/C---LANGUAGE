#include <stdio.h>
#define SIZE 5

void print_image(int image[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%03d ", image[i][j]);
        printf("\n");
    }
    printf("\n");
}

void brighten_image(int image[SIZE][SIZE])
{
    int* p;
    p = &image[0][0];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            *p += 10;
            p++;
        }
}

int main(void)
{
    int image[SIZE][SIZE] = {
        {10, 20, 30, 40, 50},
        {10, 20, 30, 40, 50},
        {10, 20, 30, 40, 50},
        {10, 20, 30, 40, 50},
        {10, 20, 30, 40, 50}, };

    print_image(image);
    brighten_image(image);
    print_image(image);

    return 0;
}