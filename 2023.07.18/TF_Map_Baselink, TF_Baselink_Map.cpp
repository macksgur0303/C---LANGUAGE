#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RAD2DEG(x) (x * 180 / M_PI)
#define DEG2RAD(x) (x / 180 * M_PI)

typedef struct {
    double x;
    double y;
    double theta;
} Pose2D;

typedef struct {
    double x;
    double y;
} Point2D;

Pose2D    base_link_origin;
Point2D   base_link_Point2D, base_link_map_Point2D;

double angle_degree;
double angle_radian;
double Rotation_matrix[2][2];
double Rotation_matrix_inverse[2][2];

void set_rotation_matrix_inverse(double m_angle_degree)
{
    angle_radian = DEG2RAD(m_angle_degree);
    Rotation_matrix_inverse[0][0] = cos(angle_radian);    Rotation_matrix_inverse[0][1] = sin(angle_radian);
    Rotation_matrix_inverse[1][0] = -sin(angle_radian);   Rotation_matrix_inverse[1][1] = cos(angle_radian);
    //printf("%6.3lf  %6.3lf\n", Rotation_matrix_inverse[0][0], Rotation_matrix_inverse[0][1]);
    //printf("%6.3lf  %6.3lf\n", Rotation_matrix_inverse[1][0], Rotation_matrix_inverse[1][1]);
}

void set_rotation_matrix(double m_angle_degree) 
{
    angle_radian = DEG2RAD(m_angle_degree);
    Rotation_matrix[0][0] = cos(angle_radian);    Rotation_matrix[0][1] = -sin(angle_radian);
    Rotation_matrix[1][0] = sin(angle_radian);    Rotation_matrix[1][1] = cos(angle_radian);
    //printf("%6.3lf  %6.3lf\n", Rotation_matrix[0][0], Rotation_matrix[0][1]);
    //printf("%6.3lf  %6.3lf\n", Rotation_matrix[1][0], Rotation_matrix[1][1]);
}

void TF_base_link_base_link_map(Point2D base_link_point2d, Point2D* base_link_map_point2d, Pose2D base_link_origin) {
    printf("\n\n");
    printf("%6.3lf  %6.3lf\n", base_link_point2d.x, base_link_point2d.y);
    printf("%6.3lf  %6.3lf\n", base_link_map_point2d->x, base_link_map_point2d->y);
    printf("%6.3lf  %6.3lf  %6.3lf\n", base_link_origin.x, base_link_origin.y, base_link_origin.theta);
}

void TF_Change_base_link_to_map(double origin1, double origin2, double point1, double point2, double theta)
{
    set_rotation_matrix(theta);
    double answer1 = point1 * Rotation_matrix[0][0] + point2 * Rotation_matrix[0][1] + origin1;
    double answer2 = point1 * Rotation_matrix[1][0] + point2 * Rotation_matrix[1][1] + origin2;

    printf("%6.3lf  %6.3lf\n", answer1, answer2);
}

void TF_Change_map_to_base_link(double origin_x, double origin_y, double map_point_x, double map_point_y, double theta)
{
    set_rotation_matrix_inverse(theta);
    map_point_x -= origin_x;
    map_point_y -= origin_y;
    double answer1 = map_point_x * Rotation_matrix_inverse[0][0] + map_point_y * Rotation_matrix_inverse[0][1];
    double answer2 = map_point_x * Rotation_matrix_inverse[1][0] + map_point_y * Rotation_matrix_inverse[1][1];
    printf("%6.3lf  %6.3lf\n", answer1, answer2);
}

int main() {
    base_link_origin.x = 3.0;
    base_link_origin.y = 3.0;
    base_link_origin.theta = 90;

    base_link_Point2D.x = 4;
    base_link_Point2D.y = 2;

    base_link_map_Point2D.x = 1;
    base_link_map_Point2D.y = 7;

    TF_Change_base_link_to_map(base_link_origin.x, base_link_origin.y, base_link_Point2D.x, base_link_Point2D.y, base_link_origin.theta);
    //TF_base_link_base_link_map(base_link_Point2D, &base_link_map_Point2D, base_link_origin);

    printf("\n");

    TF_Change_map_to_base_link(base_link_origin.x, base_link_origin.y, base_link_map_Point2D.x, base_link_map_Point2D.y, base_link_origin.theta);
    //TF_base_link_base_link_map(base_link_Point2D, &base_link_map_Point2D, base_link_origin);

    return 0;
}