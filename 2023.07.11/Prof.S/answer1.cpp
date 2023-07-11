#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define wid 3
#define col 10

struct score {
    char name[wid];
    int mid;
    int last;
    int hw;
    int sum;
    int sum1;
    int grade;
}s1[col];

int main()
{
    srand((unsigned)time(NULL));
    int num, temp, cnt = 0;

    for (int i = 0; i < col; i++)
    {
        s1[i].mid = rand() % 101;
        s1[i].last = rand() % 101;
        s1[i].hw = rand() % 101;
        s1[i].sum = s1[i].mid + s1[i].hw + s1[i].last;
        s1[i].sum1 = s1[i].sum;
        for (int j = 0; j < wid; j++)
        {
            num = rand() % 2;
            if (num == 0)
                s1[i].name[j] = rand() % 24 + 65;
            else
                s1[i].name[j] = rand() % 24 + 97;
        }
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = i; j < col; j++)
        {
            if (s1[j].sum1 > s1[i].sum1)
            {
                temp = s1[i].sum1;
                s1[i].sum1 = s1[j].sum1;
                s1[j].sum1 = temp;
            }
        }
    }

    for (int i = 0; i < col; )
    {
        cnt = 0;
        for (int j = 0; j < col; j++)
        {
            if (s1[i].sum1 == s1[j].sum)
            {
                s1[j].grade = i + 1;
                cnt++;
            }
        }

        i += cnt;
    }

    printf("이름  중간 기말 과제 총점  등수");
    printf("\n");

    for (int i = 0; i < col; i++)
    {
        printf("%s    %02d   %02d   %02d   %03d   %02d\n", s1[i].name, s1[i].mid, s1[i].last, s1[i].hw, s1[i].sum, s1[i].grade);
    }

}
