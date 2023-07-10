#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student
{
	int number;
	char name[10];
	double grade;
};

int main(void) {
	struct student s[10];

	printf("학번, 이름, 학점을 입력하시오: ");
	scanf("%d %s %lf", &s[0].number, &s[0].name, &s[0].grade);

	printf("학번, 이름, 학점을 입력하시오: ");
	scanf("%d %s %lf", &s[1].number, &s[1].name, &s[1].grade);

	printf("학번: %d\n", s[0].number);
	printf("이름: %s\n", s[0].name);
	printf("학점: %.2lf\n\n", s[0].grade);

	printf("학번: %d\n", s[1].number);
	printf("이름: %s\n", s[1].name);
	printf("학점: %.2lf\n", s[1].grade);

	return 0;
}