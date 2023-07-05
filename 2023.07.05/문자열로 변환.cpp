#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string, int k)
{
    int len = strlen(my_string);
    char* answer = (char*)malloc(sizeof(char) * (len * k));

    for (int i = 0; i < k; i++)
    {
        strcpy(answer + i * len, my_string);
    }

    return answer;
}

int main()
{
    const char* my_string1 = "string";
    const char* my_string2 = "love";
    int k1 = 3;
    int k2 = 10;

    char* answer1 = solution(my_string1, k1);
    printf("%s\n", answer1);
    free(answer1);

    char* answer2 = solution(my_string2, k2);
    printf("%s\n", answer2);
    free(answer2);

    return 0;
}