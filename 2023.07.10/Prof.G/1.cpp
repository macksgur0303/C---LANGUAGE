#include <stdio.h>

int main(void)
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int i = 0;



	for (i = 0; i < 5; i++)

		printf("%d\n", a[i]);

////////////////////////////////////////

	char str1[10] = "abc";

	char str2[10] = { 'a', 'b', 'c' };



	printf("%s\n", str1);

	printf("%s\n", str2);



////////////////////////////////////////

	int b[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int j, k;



	for (j = 0; j < 2; j++)

		for (k = 0; k < 3; k++)

			printf("%d\n", b[j][k]);
}