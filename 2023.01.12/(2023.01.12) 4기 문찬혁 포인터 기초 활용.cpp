#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void convert(double* grades, double* scores, int size);
void insert(double *grades);
void print1(double* scores, int size);
void print2(int* c, int size);
void merge(int* a, int* b, int* c, int size);

int main()
{
	int size = 10;
	double grades[10];
	double scores[10];

	int a[] = { 4, 6, 8, 13, 15 };
	int b[] = { 1, 3, 5, 7, 10 };
	int c[10] = { 0 };

	insert(grades);
	convert(grades, scores, size);
	print1(scores, size);
	merge(a, b, c, size);
	print2(c, size);
}

void insert(double *grades)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		grades[i] = rand() % 101;
	}
}

void convert(double* grades, double* scores, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		scores[i] = grades[i] * 4.3 / 100;
	}
}

void print1(double* scores, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("학생 성적 = %lf\n", scores[i]);
	}
}

void print2(int* c, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("merge = %d\n", c[i]);
	}
}
void merge(int* a, int* b, int* c, int size)
{
	int i = 0, j = 0, z = 0;

	while (c[9] > 0);
	{
		if (a[i] > b[j])
		{
			c[z] = b[j];
			z++;
			j++;
		}

		if (a[i] < b[j])
		{
			c[z] = a[i];
			z++;
			i++;
		}

		if (a[4] != 0)
		{
			for (j; j < 5; j++)
			{
				c[z] = b[j];
				z++;
			}
		}

		if (b[4] != 0)
		{
			for (i; i < 5; i++)
			{
				c[z] = a[i];
				z++;
			}
		}

	}
	
}