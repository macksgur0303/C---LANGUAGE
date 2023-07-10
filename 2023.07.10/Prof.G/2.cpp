#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int arr[], int len)
{
	int i;

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void funa(int arr[][4], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}
}

int main()
{
	int array[3];
	int i;

	array[0] = 100;
	array[1] = 200;
	array[2] = 300;

	for (i = 0; i < 3; i++)
		printf("array[%d]의 값: %d\n", i, array[i]);
/////////////////////////////////////////////////////////	 
	char arr[5];

	scanf("%s", arr);
	printf("arr : %s\n", arr);
/////////////////////////////////////////////////////////
	printf("ABCDE\0FGHI");
	printf("0123456\0 7891011");
	printf("ㄱㄴㄷ\0ㄹㅁㅂ");
////////////////////////////////////////////////////////
	char string1[10] = "ABCDEF";
	char string2[] = "ABCDEF";
	char string3[] = { 'A', 'B', 'C', 'D', 'F' };
	char string4[] = { 'A', 'B', 'C', 'D', 'F', '\0' };

	printf("%s\n", string1);
	printf("%s\n", string2);
	printf("%s\n", string3);
	printf("%s\n", string4);
///////////////////////////////////////////////////////////
	int array2D[3][3] = { {1,1,1},{1,2,4},{1,3,9} };
	int i2, j;

	for (i2 = 0; i2 < 3; i2++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", array2D[i2][j]);
		}
	}
///////////////////////////////////////////////////////////
	int array3D[2][3][4] = { {{1,2,3,4},{4,5,6,7},{8,9,1,2}},{{4,5,6,7},{5,6,7,8},{9,1,2,3}} };

	int i1, j1, k;
	for (i1 = 0; i1 < 2; i1++) {
		for (j1 = 0; j1 < 3; j1++) {
			for (k = 0; k < 4; k++) {
				scanf("%d", array3D[i1][j1][k]);
			}
		}
	}
////////////////////////////////////////////////////////////
	int arr2[] = { 1, 2, 3, 4, 5, 6 };

	func(arr2, sizeof arr2 / sizeof(int));
/////////////////////////////////////////////////////////////////

	int arr1[2][4] = { {1, 2, 3, 4}, {5, 6, 7, 8} };

	funa(arr1, 2);
///////////////////////////////////////////////////////////////	/

	return 0;
}