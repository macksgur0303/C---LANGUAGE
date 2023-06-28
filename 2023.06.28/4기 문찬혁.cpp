#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(int a, int b, const char c)
{
    if (c == '*')
        return a * b;

    if (c == '+')
        return a + b;

    if (c == '-')
        return a - b;

    if (c == '/')
        return a / b;

    if (c == '%')
        return a % b;
}

int main()
{
    char c;
    int a, b;
    printf("숫자를 입력하시오: ");
    scanf("%d", &a);

    printf("사칙연산 입력하시오 (/, *, +, -, 나머지 연산): ");
    getchar();
    scanf("%c", &c);

    printf("숫자를 입력하시오: ");
    scanf("%d", &b);

    while (1)
    {
        printf("%d %c %d = %d\n", a, c, b, solution(a, b, c));
        a = solution(a, b, c);
        printf("결과 = %d\n\n", a);

        printf("사칙연산 입력하시오 (종료= c): ");
        getchar();
        scanf("%c", &c);

        if (c == 'c')
        {
            printf("계산기 종료");
            break;
        }

        printf("숫자를 입력하시오: ");
        scanf("%d", &b);
    }
}
