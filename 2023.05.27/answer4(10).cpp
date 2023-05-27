#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void b_rand(int n)
{
    int result = rand() % 2 + 1;
    char ch = 0;
    if (result == n)
        printf("맞았습니다\n");
    else
        printf("틀렸습니다\n");

}

int main()
{
    int n = 0;
    char ch;
    srand((unsigned)time(NULL));
    while (1)
    {
        printf("앞면 = 1, 뒷면 = 2:");
        scanf("%d", &n);
        b_rand(n);
        printf("계속하시겠습니까?(y 또는 n):");
        ch = getchar();
        if (ch == 'n')
            break;
    }
}