// ConsoleApplication5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL));

    int hand = 2;
    int C_hand = rand() % 3 + 1;
    printf("(가위 = 1, 바위 = 2, 보 = 3) 입력: ");
    scanf("%d", &hand);

    switch (hand)
    {
    case 1:
        if (C_hand = 1)
            printf("비겼습니다\n");
        else if (C_hand = 2)
            printf("졌습니다\n");
        else
            printf("이겼습니다\n");

        break;
    case 2:
        if (C_hand = 2)
            printf("비겼습니다\n");
        else if (C_hand = 3)
            printf("졌습니다\n");
        else
            printf("이겼습니다\n");

        break;
    case 3:
        if (C_hand = 3)
            printf("비겼습니다\n");
        else if (C_hand = 1)
            printf("졌습니다\n");
        else
            printf("이겼습니다\n");

        break;

    default:
        printf("잘못된 입력입니다\n");
   
    }

    printf("컴퓨터가 낸 손: %d", C_hand);

    return 0;

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
