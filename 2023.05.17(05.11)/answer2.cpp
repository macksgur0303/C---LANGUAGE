#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	double num;
	int mod, cnt = 0;

	printf("실수를 입력하시오(m): ");
	scanf("%lf", &num);

	printf("모드를 입력하시오(cm == 1, mile == 2, yd == 3, inch == 4): ");
	scanf("%d", &mod);

	switch (mod)
	{
	case 1:
		num = num * 100;
		break;

	case 2:
		num = num * 0.000621371;
		break;

	case 3:
		num = num * 1.09361;
		break;

	case 4:
		num = num * 39.3701;
		break;

	default:
		printf("잘못된 입력 다시 입력하시오\n");
		cnt++;
		break;
	}

	if(cnt == 0)
		printf("변환된 값 %lf", num);
}
