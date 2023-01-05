#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int pibonaci(int amount);
int combination(int amount1, int amount2);
int factorial(int amount);

int main()
{
	int choice, amount1, amount2, result;
	printf("파보니치 수열 = 1, 조합 = 2\n");
	scanf("%d", &choice);

	if (choice == 1)
	{
		printf("항의 개수: ");
		scanf("%d", &amount1);
		result = pibonaci(amount1);
	}

	else if (choice == 2)
	{
		printf("조합 n의값: ");
		scanf("%d", &amount1);
		printf("조합 r의값: ");
		scanf("%d", &amount2);
		result = combination(amount1, amount2);
	}

	else
		printf("잘못된 입력");

	printf("결과의 값: %d", result);


}

int pibonaci(int amount)
{
	int result = 0;

	if (amount == 0)
		return 0;

	else if (amount == 1)
	{
		return 1;
	}
	else
	{
		result = pibonaci(amount - 2) + pibonaci(amount - 1);
		return result;
	}

}
int factorial(int amount)
{
	int result = 0;

	if (amount == 0)
	{
		result++;
		return 1;
	}

	else if (amount == 1)
	{
		result++;
		return 1;
	}
	else
	{
		result = amount * factorial(amount - 1);
		return result;
	}
}

int combination(int amount1, int  amount2)
{
	int result;
	result = factorial(amount1) / (factorial(amount1 - amount2) * factorial(amount2));

	return result;
}