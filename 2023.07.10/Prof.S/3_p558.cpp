#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 3

struct student
{
	int number;
	char name[10];
	double grade;
};

int main(void) {
	struct student s[SIZE];

	for (int i = 0; i < SIZE; i++) {
		printf("학번, 이름, 학점을 입력하시오:");
		scanf("%d %s %lf", &s[i].number, &s[i].name, &s[i].grade);
	}

	for (int i = 0; i < SIZE; i++) {
		printf("학번:%d 이름: %s 학점: %.2lf\n", s[i].number, s[i].name, s[i].grade);
	}

	return 0;
}