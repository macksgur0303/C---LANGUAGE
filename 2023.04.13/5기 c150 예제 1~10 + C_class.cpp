#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int q1()
{
	int x = 1;
	int y = 2;
	int z = x + y;

	return z;
}

double q2()
{
	int a = 1;
	double sum = a + M_PI;

	return sum;
}

int q3()
{
	int x = 10;

	return x - 5;
}

void q4()
{
	int x = 20;
	int y;

	printf("q3의 y값: ");
	scanf("%d", &y);

	if (x > y)
		printf("x의 값이 y의 값보다 큽니다\n");
	else if (x < y)
		printf("x의 값이 y의 값보다 작습니다\n");
	else
		printf("x의 값과 y의 값이 같습니다\n");

}

int q5()
{
	int sum = 0;
	for (int i = 0; i < 11; i++)
		sum += i;

	return sum;
}

void q6()
{
	int age;
	printf("q6의 age값: ");
	scanf("%d", &age);

	if (age < 20)
		printf("30% 할인\n");
	else
		printf("할인 없음\n");

}

void q7()
{
	int day, tem;

	printf("q7의 tem값: ");
	scanf("%d", &tem);

	printf("q7의 day값: ");
	scanf("%d", &day);

	if (day >= 2 && tem >= 33)
		printf("폭염주의보\n");
	else if (tem >= 35)
		printf("폭염경보\n");
	else
		printf("정상\n");
}

void q8()
{
	int money = 0;
	printf("q8의 money값: ");
	scanf("%d", &money);

	if (money >= 500)
		printf("음료수가 나왔습니다\n");
	else
		printf("%d원이 반환되었습니다\n", money);
}

int q9()
{
	int x = 0;
	printf("q9의 x값: ");
	scanf("%d", &x);

	if (x < 0)
		x = -x;
	else
		x = x;

	return x;
}

int q10()
{
	int score = 0;
	char grade;
	printf("q10의 score값: ");
	scanf("%d", &score);

	if (score >= 90)
		grade = 'A';
	else if (score >= 80)
		grade = 'B';
	else if (score >= 70)
		grade = 'C';
	else if (score >= 60)
		grade = 'D';
	else
		grade = 'F';

	return grade;
}

int C1()
{
	int x, y, tmp1, tmp2;
	int z = 0;

	printf("두개의 정수를 입력하시오 (큰수, 작은수): ");
	scanf("%d%d", &x, &y);

	for (int i = 1; i <= x; i++)
	{
		tmp1 = x % i;
		tmp2 = y % i;

		if (tmp1 == 0 && tmp2 == 0 && i > z)
		{
			z = i;
		}
	}

	return z;

 }

int C2()
{
	srand((unsigned)time(NULL));
	int answer = rand() % 100;
	int guess;
	int tries = 0;

	while (1)
	{
		printf("정답을 추측하여 보시오: ");
		scanf("%d", &guess);
		tries++;

		if (guess > answer)
			printf("high(guess가 더 큼)\n");
		else if (guess < answer)
			printf("low(guess가 더 작음)\n");
		else
			break;
	}

	printf("정답: %d\n", guess);

	return tries;
}

void C3()
{
	for (int i = 1; i =< 6; i++)
	{
		for (int j = 1; j =< 6; j++)
		{
			if (6 == i + j)
				printf("(%d, %d)", i, j);
		
		}
	}
	printf("\n");

	for (int i = 1; i =< 6; i++)
	{
		for (int j = 1; j =< 6; j++)
		{
			for (int k = 1; k =< 6; k++)
			{
				if (10 == i + j + k)
					printf("(%d, %d, %d)", i, j, k);
			}
		}
	}
	printf("\n");
}

void print()
{
	printf("q1 = %d\n", q1());
	printf("q2 = %lf\n", q2());
	printf("q3 = %d\n", q3());
	q4();
	printf("q5 = %d\n", q5());
	q6();
	q7();
	q8();
	printf("q9 = %d\n", q9());
	printf("q10 = %c\n", q10());
	printf("C1 = %d\n", C1());
	printf("C2 = %d\n", C2());
	C3();
}

int main()
{
	print();
	return 0;
}