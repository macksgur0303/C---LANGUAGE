#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int age = 0;
    int tall = 0;

    printf("나이를 입력하시오: ");
    scanf("%d", &age);
    printf("키를 입력하시오: ");
    scanf("%d", &tall);

    if (age >= 10 && tall >= 140)
        printf("타도 좋습니다\n");
    else
        printf("죄송합니다\n");

    return 0;

}