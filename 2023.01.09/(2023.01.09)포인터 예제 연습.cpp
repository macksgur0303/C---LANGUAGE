#include <stdio.h>

int main()
{
	int a = 10, b = 010, c = 0x10; // 10 = 10진수 표기 ,010 = 8진수 표기. 0x10 = 16진수 표기
	char d = 69; // 아스키코드 A = 65, a = 97
	double e = 1.36;

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("d = %c\n", d); // 아스키코드 69 = E
	printf("e = %lf\n\n", e);

	int x = 10, y = 20;
	int *px; // 포인터 변수 px 선언
	int* py; // =

	px = &x; // 포인터 px가 x의 주소를 가리킴
	printf("x = %d\n", x); // x의 값
	printf("x = %d\n", &x); // x의 주소
	printf("px = %d\n", px); // px의 주소(x의 주소)
	printf("*px = %d\n\n", *px); // px의 값(x의 값)

	*px = 20; // 포인터 px가 가르키는 곳에 20을 대입함
	printf("x = %d\n", x); //x의 값이 20으로 변경됨
	printf("x = %d\n", &x); 
	printf("px = %d\n", px);
	printf("*px = %d\n\n", *px); //px의 값이 20으로 변경됨

	// 위와 동일하니 설명하지 않음
	py = &y;
	printf("y = %d\n", y); 
	printf("y = %d\n", &y);
	printf("py = %d\n", py);
	printf("*py = %d\n\n", *py);

	*py = 10;
	printf("y = %d\n", y); 
	printf("y = %d\n", &y);
	printf("py = %d\n", py);
	printf("*py = %d\n\n", *py);
	return 0;
}