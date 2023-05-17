#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num = 0, cnt = 0;

	printf("정수를 입력하시오: ");
	scanf("%d", &num);
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			cnt++;
	}

	if (cnt > 0)
		printf("소수가 아닙니다");
	else
		printf("소수입니다");
}
