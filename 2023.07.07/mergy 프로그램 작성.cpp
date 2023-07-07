#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void rand_arry(int a[SIZE], int b[SIZE])
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }
}

void sort_arry(int a[SIZE], int b[SIZE])
{
    int tmp = 100;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i; j < SIZE; j++)
        {
            if (a[i] < a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }

            if (b[i] < b[j])
            {
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }

    }
}

void merge_arry(int a[], int b[], int c[])
{
    int cnt = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            if (a[i] == b[j])
            {
                c[cnt] = a[i];
                cnt++;
            }
    }

    printf("포인트 = %d\n", cnt);
}

void print_arry(int a[], int b[], int c[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%02d %02d %02d", a[i], b[i], c[i]);
        printf("\n");
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int a[10] = {0};
    int b[10] = { 0 };
    int c[10] = { 0 };
    
    rand_arry(a, b);
    sort_arry(a, b);
    merge_arry(a, b, c);
    print_arry(a, b, c);

}