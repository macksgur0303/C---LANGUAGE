#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char name2[10][20] = { "찬혁", "찬혐", "찬호", "찬서", "찬희", "찬해", "찬황", "찬수", "찬훤", "찬학" };
struct student {
	int num;
	char name[20];
	int kor;
	int eng;
	int math;
	int sum;
	float avg;
};
void insert(student p[10]);
void print(student p[10]);
void average(student p[10]);

int main()
{
	struct student s_list[10];
	struct student* p = &s_list[10];
	insert(p);
}

void insert(student p[10])
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		strcpy(p[i].name, name2[rand() % 10]);
		p[i].num = i + 1;
		p[i].kor = rand() % 100 + 1;
		p[i].eng = rand() % 100 + 1;
		p[i].math = rand() % 100 + 1;
		p[i].sum = p[i].kor + p[i].eng + p[i].math;
		p[i].avg = p[i].sum / 3.0;
		average(p);
	}
	print(p);
}

void print(student p[10])
{
	printf("\t번호\t이름\t국어\t영어\t수학\t총점\t평균\n");
	printf("-------------------------------------------------------------------\n");
	for (int i = 0; i < 10; i++)
	{
		printf("\t%d\t%s\t%d\t%d\t%d\t%d\t%.1f\n", p[i].num, p[i].name, p[i].kor, p[i].eng, p[i].math, p[i].sum, p[i].avg);
		printf("-------------------------------------------------------------------\n");
	}
}

void average(student p[10])
{
	int j1;
	float j2;
	for (int i = 0; i < 10; i++)
	{
		j2 = p[i].avg * 10;
		j1 = j2;
		j2 = j1;
		p[i].avg = j2 / 10;
	}
}