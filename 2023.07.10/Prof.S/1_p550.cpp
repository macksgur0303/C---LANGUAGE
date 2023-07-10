#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct student
{
	int number;
	char name[10];
	double grade;
};

int main(void) {
	struct student s[10];
	s[0].number = 20190001;
	strcpy(s[0].name, "홍길동");
	s[0].grade = 4.3;

	s[1].number = 202032012;
	strcpy(s[1].name, "김태균");
	s[1].grade = 4.33;

	printf("학번: %d\n", s[0].number);
	printf("이름: %s\n", s[0].name);
	printf("학점: %.2lf\n\n", s[0].grade);

	printf("학번: %d\n", s[1].number);
	printf("이름: %s\n", s[1].name);
	printf("학점: %.2lf\n", s[1].grade);

	return 0;
}