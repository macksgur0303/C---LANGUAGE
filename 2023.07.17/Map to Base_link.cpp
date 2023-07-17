#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

double map_base_link_a(double a, double base_link_a, double degree)
{
    double x = base_link_a * cos(degree * M_PI / 180) + base_link_a * -sin(degree * M_PI / 180);
    x = x + a;
    return x;
}

double map_base_link_b(double b, double base_link_b, double degree)
{
    double y = base_link_b * cos(degree * M_PI / 180) + base_link_b * sin(degree * M_PI / 180);
    y = y + b;;
    return y;
}
int main()
{
    double a = 4, b = 4;
    double base_link_a = 1, base_link_b = 1;
    double degree = 45;

    /*
    printf("xmap, ymap 값: ");
    scanf("%d %d", &a, &b);
    printf("xbase_link_a, ybase_link_b 값: ");
    scanf("%d %d", &base_link_a, &base_link_b);
    printf("degree 값: ");
    scanf("%d", &degree);
    */

    double ret1 = map_base_link_a(a, base_link_a, degree);
    double ret2 = map_base_link_b(b, base_link_b, degree);

    printf("(%lf,%lf)", ret1, ret2);
    
}