#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int A = 1000, B = 1000, C = 1000; // 소지금액
	int AC , AM, BC, BM, CC, CM; // C = 선택 CHOICE, M = 돈 MONEY
	int roll, count;
	int result;
	int AW = 0, AL = 0, BW = 0, BL = 0, CW = 0, CL = 0; // W = 승리 WIN, L = 패배 LOSE
	int ACM = 0, BCM = 0, CCM = 0; // CM = 최종돈

	srand((unsigned)time(NULL));

	for (roll = 0; roll < 10; roll++)
	{
		AC = 1 + rand() % 6; // 배팅구간
		AM = 1 + rand() % 1000;
		BC = 1 + rand() % 6;
		BM = 1 + rand() % 1000;
		CC = 1 + rand() % 6;
		CM = 1 + rand() % 1000;

		count = 1 + rand() % 6; // 주사위 돌리기

		printf("[%d] %d번째 게임\n", roll + 1, roll + 1);

		printf("주사위의 눈 = %d\n", count);
		if (A > 0) // 자금 부족시 게임 참가 불가
		{
			printf("A 선택 = %d, 판돈 = %d\n", AC, AM);
			if (AC == count) // A보상구간
			{
				A = 2 * AM;
				AW++;
				ACM += 2 * AM;
				printf("win, %d\n", A);
			}
			else
			{
				A = A - AM;
				AL++;
				printf("lose, %d\n", A);
			}
		}

		else
		{
			printf("소유자금 부족으로 인한 [%d]번째 게임참가불가!!\n", roll+1);
		}

		if (B > 0) // 자금 부족시 게임 참가 불가
		{
			printf("B 선택 = %d, 판돈 = %d\n", BC, BM);
			if (BC == count) // B보상구간
			{
				B = 2 * BM;
				BW++;
				BCM += 2 * BM;
				printf("win, %d\n", B);
			}
			else
			{
				B = B - BM;
				BL++;
				printf("lose, %d\n", B);
			}
		}
		else
		{
			printf("소유자금 부족으로 인한 [%d]번째 게임참가불가!!\n", roll+1);
		}

		if (C > 0) // 자금 부족시 게임 참가 불가
		{
			printf("C 선택 = %d, 판돈 = %d\n", CC, CM);
			if (CC == count) // C보상구간
			{
				C = 2 * CM;
				CW++;
				CCM += 2 * CM;
				printf("win, %d\n", C);
			}
			else
			{
				C = C - CM;
				CL++;
				printf("lose, %d\n", C);
			}
		}

		else
		{
			printf("소유자금 부족으로 인한 [%d]번째 게임참가불가!!\n", roll+1);
		}
	}

	printf("최종 결과\n");
	if (A > 0)
	{
		printf("A = 번돈 %d원, %d회 승리\n", ACM, AW);
	}
	else
		printf("돈 전부 잃음, %d회 승리\n",AW);

	if (B > 0)
	{
		printf("B = 번돈 %d원, %d회 승리\n", BCM, BW);
	}
	else
		printf("돈 전부 잃음, %d회 승리\n", BW);

	if (C > 0)
	{
		printf("C = 번돈 %d원, %d회 승리\n", CCM, CW);
	}
	else
		printf("돈 전부 잃음, %d회 승리\n", CW);

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
