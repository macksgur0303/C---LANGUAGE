#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)

{

    int num, tot = 0;

    do {

        printf("정수 입력 :");

        scanf("%d", & num);

        tot += num;

    } while (num != 0);

    printf("total = % d\n" , tot);

}// 0이 나올때까지 받은 정수의 합을 산출하는 프로그램

