#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void first_page(int a[][7], int b[][7]);
void print_page(int a[][7]);
void move_page(int a[][7], int b[][7]);

int main()
{
	int a[7][7] = { 0 };
	int b[7][7] = { 0 };

	first_page(a, b);
	print_page(a);
	move_page(a, b);
}

void first_page(int a[][7], int b[][7]) // 여기를 깔끔하게 못함
{
	int i, j;
	int n = 4;
	for (i = 0; i < 3; i++)
	{
		for (j = 4; j < n + 1; j++)
		{
			a[i][7 - j] = 777;
			a[i][j - 1] = 777;
		}
		n++;
	}

	for (i = 3; i < 7; i++)
	{
		for (j = 4; j < n + 1; j++)
		{
			a[i][7 - j] = 777;
			a[i][j - 1] = 777;
		}
		n--;
	}
	n = 7;

}

void print_page(int a[][7])
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			printf("\t%d", a[i][j]);
		}
		printf("\n");
	}
}

void move_page(int a[][7], int b[][7])
{
	int choice = 0;

	printf("이동 입력 오른쪽 = 1, 왼쪽 = 2, 위쪽 = 3, 아래쪽 = 4, 종료 = 5\n");
	scanf("%d", &choice);

	while (choice != 5)
	{
		if (choice == 1) // 오른쪽
		{
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					b[i][(j + 1) % 7] = a[i][j];
				}
			}

			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					a[i][j] = b[i][j];
				}
			}
			print_page(a);
		}

		else if (choice == 2) // 왼쪽
		{
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					b[i][j] = a[i][(j + 1) % 7];
				}
			}

			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					a[i][j] = b[i][j];
				}
			}
			print_page(a);
		}

		else if (choice == 3) // 위
		{
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					b[i][j] = a[(i+1) % 7][j];
				}
			}

			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					a[i][j] = b[i][j];
				}
			}
			print_page(a);
		}

		else if (choice == 4) // 아래
		{
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					b[(i + 1) % 7][j] = a[i][j];
				}
			}

			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					a[i][j] = b[i][j];
				}
			}
			print_page(a);
		}

		scanf("%d", &choice);
	}
}