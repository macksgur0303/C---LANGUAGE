#include <stdio.h>
#include <conio.h>
#include <string.h>
int main(void)
{
	char solution[100] = "meet at midnight";
	char answer[100] = "____ __ ________";
	char ch;
	int i;

	while (1) {
		printf("\n문자열을 입력하시오: %s\n", answer);
		printf("글자를 추측하시오: ");
		ch = _getch();

		for (i = 0; solution[i] != NULL; i++) {
			if (solution[i] == ch)
				answer[i] = ch;
		}
		if (strcmp(solution, answer) == 0) break;
	}
	return 0;
}