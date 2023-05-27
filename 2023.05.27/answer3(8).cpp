#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double sin_degree(double n)
{
    return sin(3.14 * n / 180);
}

int main()
{
    double n = 0;
    printf("종료 : -1\n");
    while (n != -1)
    {
        printf("sin(n)의 값: ");
        scanf("%lf", &n);
        printf("sin(%lf)의 값은 %lf\n", n, sin_degree(n));
    }
}