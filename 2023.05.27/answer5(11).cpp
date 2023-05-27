#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void f_rand()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; i++)
        printf("%lf", rand() / (double)RAND_MAX);
}

int main()
{
    f_rand();
}