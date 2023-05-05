#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num1 = 0, num2 = 0, num3 = 0;
	printf("정수를 입력하시오: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	if (num1 >= num2 && num1 >= num3)
		printf("가장 큰 정수: %d", num1);
	else if (num2 >= num1 && num2 >= num3)
		printf("가장 큰 정수: %d", num2);
	else if (num3 >= num1 && num3 >= num2)
		printf("가장 큰 정수: %d", num3);
	else
		printf("잘못된 입력");
	return 0;
}