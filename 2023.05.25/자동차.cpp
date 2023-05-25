#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tab = 5;

void drive(int i, int car, int dis)
{
	if (i == 0)
		printf("car#%d: ", car);
	for (int i = 0; i < dis; i++)
		printf("*");

	if (i != tab - 1)
		printf("|");
}

void car_num(int car, int dis)
{
	for (int i = 0; i < tab; i++)
	{
		dis = rand() % 10 + 1;
		drive(i, 1, dis);
	}

	printf("\n");
}

int main()
{
	srand((unsigned)time(NULL));
	int dis1 = 0, dis2 = 0, dis3 = 0;
	car_num(1, dis1);
	car_num(2, dis2);
	car_num(3, dis3);
}
