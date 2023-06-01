#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 20

int main()
{
    int seats[SIZE] = { 0 };
    int size = 0, choice1, choice2;
    printf("그룹 수를 입력하여 주십시오: ");
    scanf("%d", &size);

    while (size != 0)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (i == 10)
                printf("\n");
            if (seats[i] == 0)
                printf("%d ", i + 1);
            else
                printf("0 ");
            if (i == SIZE - 1)
                printf("\n");
        }
        printf("몇 번째 좌석을 예약하시겠습니까?\n");
        scanf("%d %d", &choice1, &choice2);
        if (seats[choice1 - 1] == 0 && seats[choice2 - 1] == 0)
        {
            seats[choice1 - 1]++;
            seats[choice2 - 1]++;
            size--;
        }

        else
            printf("잘못된 선택이 있습니다 다시 선택하여 주십시오\n");
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (i == 10)
            printf("\n");
        if (seats[i] == 0)
            printf("%d ", i + 1);
        else
            printf("0 ");
        if (i == SIZE - 1)
            printf("\n");
    }

    printf("예약된 좌석: (");
    for (int i = 0; i < SIZE; i++)
    {
        if (seats[i] > 0)
            printf(" %d", i + 1);
    }
    printf(" )입니다");

}