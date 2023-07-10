#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int score1[10] = { 100, 95, 85, 77, 66, 55, 67, 78, 89, 100 };
    int a1;
    for (a1 = 0; a1 < 10; a1++)
        printf(" %d\n", score1[a1]);

    /////////////////////////////////////////////////////////////////

    int score[6];
    int i, a,
        sum = 0;

    for (i = 0; i < 6; i++) {
        printf("학생 %d 성적을 입력입력하세요 : ", i + 1);
        scanf("%d", &score[i]);
    }

    for (i = 0; i < 6; i++)
        sum += score[i];

    printf("합계 : %d\n", sum);
    printf("평균 : %.2lf\n", (double)sum / 6);
    printf("\n score[6]에 저장되어있는 숫자: ");

    for (a = 0; a < 6; a++)
        printf(" %d", score[a]);
    printf("\n");
    //////////////////////////////////////////////////////////////

    char string1[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    char string2[6] = "world";
    char string3[10];

    printf("이름을 입력하세요: ");
    scanf("%s", &string3);

    printf("%s\n", string1);
    printf("%s\n", string2);
    printf("%s %s %s님 안녕하세요 \n", string1, string2, string3);
}