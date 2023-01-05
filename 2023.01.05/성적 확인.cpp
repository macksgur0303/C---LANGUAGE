#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int main()
{
	int prices[SIZE] = { 0 };
	int idex[SIZE] = { 0 };
	int i, minimum, maximum;
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0, ten = 0;

	srand((unsigned)time(NULL));

	for (i = 0; i < SIZE; i++)
	{
		prices[i] = rand() % 100 + 1;
		printf("%-3d\n", prices[i]);

	}
	printf("\n\n");



	minimum = prices[0];
	for (i = 0; i < SIZE; i++)
	{
		if (prices[i] < minimum)
			minimum = prices[i];
	}

	maximum = prices[0];
	for (i = 0; i < SIZE; i++)
	{
		if (prices[i] > maximum)
			maximum = prices[i];
	}

	printf("최솟값 = %d\n", minimum);
	printf("최댓값 = %d\n", maximum);

	for (i = 0; i < SIZE; i++)
	{
		if (prices[i] <= 9)
			one++;
		else if (prices[i] <= 19)
			two++;
		else if (prices[i] <= 29)
			three++;
		else if (prices[i] <= 39)
			four++;
		else if (prices[i] <= 49)
			five++;
		else if (prices[i] <= 59)
			six++;
		else if (prices[i] <= 69)
			seven++;
		else if (prices[i] <= 79)
			eight++;
		else if (prices[i] <= 89)
			nine++;
		else if (prices[i] <= 100)
			ten++;
	}
	printf("[0 ~ 9] : ");
	for (i = 0; i < one; i++)
	{
		printf("*");
	}
	printf("\n");

	printf("[10 ~ 19] : ");
	for (i = 0; i < two; i++)
	{
		printf("*");
	}
	printf("\n");

	printf("[20 ~ 29] : *");
	for (i = 0; i < three; i++)
	{
		printf("*");
	}
	printf("\n");

	printf("[30 ~ 39] : *");
	for (i = 0; i < four; i++)
	{
		printf("*");
	}
	printf("\n");

	printf("[40 ~ 49] : *");
	for (i = 0; i < five; i++)
	{
		printf("*");
	}
	printf("\n");

	printf("[50 ~ 59] : *");
	for (i = 0; i < six; i++)
	{
		printf("*");
	}
	printf("\n");

	printf("[60 ~ 69] : *");
	for (i = 0; i < seven; i++)
	{
		printf("*");
	}
	printf("\n");

	printf("[70 ~ 79] : *");
	for (i = 0; i < eight; i++)
	{
		printf("*");
	}
	printf("\n");

	printf("[80 ~ 89] : *");
	for (i = 0; i < nine; i++)
	{
		printf("*");
	}
	printf("\n");

	printf("[90 ~ 100] : *");
	for (i = 0; i < ten; i++)
	{
		printf("*");
	}
	printf("\n");

	printf("\n");

	return 0;
}