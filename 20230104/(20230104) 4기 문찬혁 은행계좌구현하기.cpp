#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long balance = 0;
int money;

void in_money(int amount) // 돈 입금 시스템
{
	printf("***********************\n");
	printf("입금    출금    잔고\n");
	printf("***********************\n");
	printf("%d\t", amount);

	balance += amount;
	printf("\t%d\n", balance);
}

void out_money(int amount) // 돈 출금 시스템
{
	if (balance >= amount) // 계좌 잔액 부족 확인
	{
		printf("***********************\n");
		printf("입금    출금    잔고\n");
		printf("***********************\n");
		printf("\t%d", amount);
		balance += -amount;
		printf("\t%d\n", balance);
	}
	else
	{
		printf("오류!! 잔고보다 더 큰 출금액\n");
	}
}

int main()
{
	int choice = 0, i = 0;
	int inid, inpassword;
	int id = 12345;
	int password = 12345;

	while (i < 4) // 아이디랑 비밀번호 확인 총 시도횟수 3번까지 가능
	{
		printf("아이디를 입력하시오: ");
		scanf("%d", &inid);
		printf("비밀번호를 입력하시오: ");
		scanf("%d", &inpassword);
		if (i == 2)
		{
			printf("잘못된 아이디 또는 패스워드 시도 횟수 %d/3\n\n", i + 1);
			printf("잘못된 접근 프로그램을 종료합니다");
			goto skip;
		}
		if (id == inid && password == inpassword)
		{
			printf("로그인 성공!!\n");
			break;
		}
		else
		{
			printf("잘못된 아이디 또는 패스워드 시도 횟수 %d/3\n", i + 1);
			i++;
		}
	}
	while (choice <= 3) // 입금 출금 종료 선택
	{
		printf("입금 = 1, 출금 = 2 종료 = 3\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("얼마를 입금하시겠습니까? 금액 = ");
			scanf("%d", &money);
			in_money(money);
		}
		else if (choice == 2)
		{
			printf("얼마를 출금하시겠습니까? 금액 = ");
			scanf("%d", &money);
			out_money(money);
		}
		else if (choice == 3)
		{
			printf("은행계좌 잔액: %d\n", balance);
			break;
		}
		else
			printf("잘못된 입력 다시 시도하세요");
	}
	printf("***********************");

skip: // 잘못된 아이디 패스워드 3번 시도시 프로그램 종료


	return 0;
}