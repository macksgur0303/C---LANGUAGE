#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 366;
    return 365;
}

int main()
{
    int year;
    printf("연도를 입력하시오: ");
    scanf("%d", &year);

    printf("%d은 %d일 입니다.\n", year, is_leap(year));
}