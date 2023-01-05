#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi_tower(int n, int from, int tmp, int to);

int main()
{
	hanoi_tower(4, 'A', 'B', 'C');
}

void hanoi_tower(int n, int from, int tmp, int to)
{
	if (n == 1)
		printf("���� 1�� %c���� %c���� �ű��. \n", from, to);
	else
	{
		hanoi_tower(n - 1, from, to, tmp);
		printf("���� 1�� %c���� %c���� �ű��. \n", from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}