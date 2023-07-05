#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void print_image(int image[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%02d ", image[i][j]);
        printf("\n");
    }
    printf("\n");
}

void brighten_image(int image[SIZE][SIZE])
{
    int j = 4;
    for (int i = 0; i < SIZE; i++)
    {
        image[i][i] = 0;
        image[i][j] = 0;
        j--;
    }
}

void random_image(int image[SIZE][SIZE])
{
    int i = 0;
    int cnt = 0;
    while(1)
    {
        int r = rand() % 5;
        int c = rand() % 5;

        if (image[r][c] == 0)
        {
            image[r][c] = i;
            i++;
        }

        cnt++;
        if (i >= 25)
            break;
    }
    printf("시도 횟수 = %d\n", cnt);
}

int main(void)
{
    srand((unsigned)time(NULL));

    int image[SIZE][SIZE] = { 0 };

    print_image(image);
    random_image(image);
    print_image(image);

    return 0;
}