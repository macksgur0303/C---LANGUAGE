#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float old_average = 0;
float new_average = 0;
float data[5] = { 0,0,0,0,0 };


void average(float a, int K)
{
	new_average = (old_average + (a / K));
	old_average = new_average;
}

void move_average(float a) 
{
	for (int i = 0; i < 4; i++) 
	{
		data[i] = data[i + 1];
	}
	data[4] = a;
	new_average = old_average + (data[4] - data[0]) / 5;
	old_average = new_average;
}

int main(void) 
{
	float b = 0;

	for (int i = 0; i < 5; i++) 
	{

		printf("index = [%d]값을 넣으세요 : ", i);
		scanf("%f", &b);
		average(b, 5);
		printf("%f \n", new_average);
		data[i] = b;
	}
	while (1) 
	{
		printf("값을 넣으세요2 : ");
		scanf("%f", &b);
		move_average(b);
		printf("%f \n", new_average);
	}
}