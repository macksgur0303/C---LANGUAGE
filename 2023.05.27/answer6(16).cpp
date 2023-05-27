#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double factorial(int n)
{
    if (n == 1)
        return 1;
    return n * (factorial(n - 1));
}

int main()
{
    int n; 
    double answer = 0;
    printf("어디까지 계산할까요: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        answer += 1 / factorial(i);
    printf("오일러의 수는 %lf입니다.", answer + 1);
}