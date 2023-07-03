#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define wid 5
#define hei 20

int main()
{
    srand((unsigned)time(NULL));

    int grades[wid][hei] = { 0 };
    int tears[hei] = { 0 };
    int tmp, cnt, sss = 0;

    for (int i = 0; i < wid - 2; i++)
        for (int j = 0; j < hei; j++)
            grades[i][j] = rand() % 101;

    for (int i = 0; i < hei; i++)
    {
        grades[3][i] = grades[0][i] * 50 / 100 + grades[1][i] * 30 / 100 + grades[2][i] * 20 / 100;
        tears[i] = grades[3][i];
    }

    for (int i = 0; i < hei; i++)
    {
        for (int j = i + 1; j < hei; j++)
        {
            if (tears[i] < tears[j])
            {
                tmp = tears[i];
                tears[i] = tears[j];
                tears[j] = tmp;
            }
        }
    }

    for (int i = 0; i < hei; i++)
    {
        cnt = 0;
        for (int j = 0, sss = i + 1; j < hei; j++, sss++)
        {
            if (grades[wid - 2][j] == tears[i])
                grades[wid - 1][j] = i + 1;
            if (tears[i] == tears[sss])
                cnt++;
        }

        i += cnt;
    }

    printf("중간 기말 과제 총점 등수");
    printf("\n");

    for (int i = 0; i < hei; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            printf("%02d   ", grades[j][i]);

        }
        printf("\n");
    }

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
