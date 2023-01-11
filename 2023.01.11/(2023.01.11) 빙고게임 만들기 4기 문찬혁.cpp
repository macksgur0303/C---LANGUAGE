#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SIZE = 5;
int number;
void insert_bingo(int a[][5], int b[][5]);
void init_bingo(int a[][5]);
void print_bingo(int a[][5]);

int main()
{
    int a[5][5] = { 0 };
    int b[5][5] = { 0 };

    init_bingo(a);
    insert_bingo(a, b);
    printf("\n\n");
    print_bingo(a);
    print_bingo(b);
    printf("빙고\n");
    return 0;
}

void insert_bingo(int a[][5], int b[][5])
{
    int number, xc, yc, i, j;
    int bingocnt = 0, sum = 0;
    srand((unsigned)time(NULL));

    while (bingocnt < 3)
    {
        int x = rand() % 5;
        int y = rand() % 5;
        xc = x;
        yc = y;
        bingocnt = 0;
        printf("(x , y) = (%d, %d)\n ", xc, yc);
        number = rand() % 25 + 1;
        printf("number = %d\n", number);


        for (i = 0; i < SIZE; i++) // 가로
        {

            for (j = 0; j < SIZE; j++)
            {
                if (b[i][j] == 0)
                {
                    if (a[i][j] == number)
                        b[i][j] = 1;
                }

                sum += b[i][j];
                if (sum >= 5)
                    bingocnt++;
            }
            sum = 0;
        }

        for (i = 0; i < SIZE; i++) // 세로
        {

            for (int j = 0; j < SIZE; j++)
            {
                sum += b[j][i];
                if (sum >= 5)
                    bingocnt++;

            }
            sum = 0;
        }

        for (i = 0; i < SIZE; i++) // 뢴쪽위 오른쪽 아래 대각선
        {
            sum += b[i][i];
            if (sum >= 5)
                bingocnt++;

            sum = 0;
        }

        for (i = 4; i > -1; i--) // 오른위 왼쪽 아래 대각선
        {
            sum += b[i][i];
            if (sum >= 5)
                bingocnt++;

            sum = 0;
        }
    }

}

void init_bingo(int a[][5])
{
    int count = 0;
    while (count < 25)
    {
        int x = rand() % 5;
        int y = rand() % 5;
        if (a[x][y] == 0)
        {
            a[x][y] = count + 1;
            count++;
        }
    }
}

void print_bingo(int a[][5])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%3d", a[i][j]);
        }

        printf("\n");
    }

    printf("\n\n");
}