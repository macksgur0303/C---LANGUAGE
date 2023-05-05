#include <stdio.h>
int main()
{
    for (int i = 0; i < 10; i += 2)

        printf("%d\n", i);



    int i = 0x10;

    for (; i; i >>= 1)

        printf("hello");



    int x, y;

    for (x = 0; x < 3; x++)

        for (y = 2; y >= 0; y--)

            printf("*");
}