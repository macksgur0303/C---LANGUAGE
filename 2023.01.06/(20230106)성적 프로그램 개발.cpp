#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 6

int score[ROWS][COLS];
void sum(void);
void avg(void);
void ascending(void);

int main()
{
	int i, j;
	srand((unsigned)time(NULL));

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS - 3; j++)
		{
			score[i][j] = rand() % 100 + 1;
		}
	}
	sum();
	avg();
	ascending();
	printf("-------------------성적테이블----------------------\n");
	printf("번호\tkor\teng\tmath\tsum\tavg\trank\n");

	for (i = 0; i < ROWS; i++)
	{
		printf("[%d]\t", i + 1);
		for (j = 0; j < COLS; j++)
		{
			printf("%d\t", score[i][j]);
		}
		printf("\n");
		printf("---------------------------------------------------\n");
	}
	printf("---------------------------------------------------\n");
}

void sum(void)
{
	int i, j, sum2 = 0;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS - 3; j++)
		{
			sum2 += score[i][j];
		}
		score[i][3] = sum2;
		sum2 = 0;
		score[i][4] = score[i][3] / 3;
	}
}

void avg(void)
{
	int i, j = 0;

	for (i = 0; i < ROWS; i++)
	{

		score[i][4] = score[i][3] / 3;
	}
}

void ascending(void)
{
	int i, j, tmp[10], temp;
	for (i = 0; i < ROWS; i++)
	{
		tmp[i] = score[i][4];
	}
	tmp[i] = score[i][4];
	for (i = 0; i < ROWS; i++)
	{
		for (j = i; j < ROWS; j++)
		{
			if (tmp[i] < tmp[j])
			{
				temp = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = temp;
			}
		}
	}

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < ROWS; j++)
		{
			if (tmp[i] == score[j][4])
				score[j][5] = i+1;
		}


	}
}