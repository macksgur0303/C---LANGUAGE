#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define LEN 15
#define RAD2DEG(x) (x * 180 / M_PI)
#define DEG2RAD(x) (x / 180 * M_PI)

typedef struct
{
    double x;
    double y;
    double yaw;

} Pose2D;

typedef struct
{
    double x;
    double y;
    double z;
} Point3D;

typedef struct
{
    double x;
    double y;
} Point2D;

typedef struct
{
    double a;
    double b;
} Line_Equation;

Pose2D base_link_origin;                                     // baselink의 원점 pose
Pose2D utm_link_origin;                                      // utm     의 원점 pose
Pose2D odom_link_origin;                                     // odom    의 원점 pose

Point2D waypoint_utm[LEN];
Point2D waypoint_utm_relative[LEN];                          // 상대 좌표
Point2D waypoint_map_relative[LEN];                          // 상대 좌표
Point2D waypoint_odom_relative[LEN];
Point2D waypoint_odom_map_relative[LEN];

Point2D waypoint_utm_datum;                                  // utm 기준 좌표
Point2D base_link_point2D, base_link_map_point2D;

Line_Equation waypoint_line_equation_utm[LEN];               // utm 좌표 기존 waypoint의 line equation
Line_Equation waypoint_line_equation_map[LEN];               // map 좌표 기존 waypoint의 line equation

double waypoint_angle_utm[LEN] = { 0.0 };
double waypoint_angle_map[LEN] = { 0.0 };
double waypoint_distance[LEN] = { 0.0 };

double angle_degree;
double angle_radian;

double Rotation_Matrix_point[2][2];                         // 점을     회전하는 회전 행렬
double Rotation_Matrix_axis[2][2];                          // 좌표축을 회전하는 회전 행렬

int initialize_waypoint()                                   // waypoint 초기화 함수
{
    waypoint_utm[0] = { 403165.834539,  4129142.66722 };
    waypoint_utm[1] = { 403163.074411,  4129144.66310 };
    waypoint_utm[2] = { 403168.006126,  4129155.70202 };
    waypoint_utm[3] = { 403171.552590,  4129159.62227 };
    waypoint_utm[4] = { 403175.499272,  4129163.65995 };
    waypoint_utm[5] = { 403188.494255,  4129175.23815 };
    waypoint_utm[6] = { 403192.579036,  4129177.42123 };
    waypoint_utm[7] = { 403195.456870,  4129178.70838 };
    waypoint_utm[8] = { 403196.654117,  4129182.60031 };
    waypoint_utm[9] = { 403188.253848,  4129179.74587 };
    waypoint_utm[10] = { 403183.344647,  4129175.25328 };
    waypoint_utm[11] = { 403178.839622,  4129171.98767 };
    waypoint_utm[12] = { 403174.786097,  4129167.14121 };
    waypoint_utm[13] = { 403172.102604,  4129165.03072 };
    waypoint_utm[14] = { 403167.683418,  4129166.12481 };

    waypoint_utm_datum = waypoint_utm[0];

    for (int i = 0; i < LEN; i++)
    {
        waypoint_utm_relative[i].x = waypoint_utm[i].x - waypoint_utm_datum.x;
        waypoint_utm_relative[i].y = waypoint_utm[i].y - waypoint_utm_datum.y;

        printf(" %2d) X: %6.3lf, Y: %6.3lf \n", i, waypoint_utm[i].x, waypoint_utm[i].y);
    }
    printf("\n\n\n");
    for (int i = 0; i < LEN; i++)
    {
        printf(" %2d) X: %6.3lf, Y: %6.3lf \n", i, waypoint_utm_relative[i].x, waypoint_utm_relative[i].y);
    }

    utm_link_origin.x = 0.0;  utm_link_origin.y = 0.0;  utm_link_origin.yaw = -90.0;

    return 1;
}

void set_rotation_matrix_point(double m_angle_degree)
{
    angle_radian = DEG2RAD(m_angle_degree);
    Rotation_Matrix_point[0][0] = cos(angle_radian);   Rotation_Matrix_point[0][1] = -sin(angle_radian);
    Rotation_Matrix_point[1][0] = sin(angle_radian);   Rotation_Matrix_point[1][1] = cos(angle_radian);
    //printf("%6.3lf  %6.3lf\n", Rotation_matrix_inverse[0][0], Rotation_matrix_inverse[0][1]);
    //printf("%6.3lf  %6.3lf\n", Rotation_matrix_inverse[1][0], Rotation_matrix_inverse[1][1]);
}

void set_rotation_matrix_axis(double m_angle_degree)
{
    angle_radian = DEG2RAD(m_angle_degree);
    Rotation_Matrix_axis[0][0] = cos(angle_radian);    Rotation_Matrix_axis[0][1] = sin(angle_radian);
    Rotation_Matrix_axis[1][0] = -sin(angle_radian);   Rotation_Matrix_axis[1][1] = cos(angle_radian);
    //printf("%6.3lf  %6.3lf\n", Rotation_matrix_inverse[0][0], Rotation_matrix_inverse[0][1]);
    //printf("%6.3lf  %6.3lf\n", Rotation_matrix_inverse[1][0], Rotation_matrix_inverse[1][1]);
}

void TF_utm_map(Point2D utm_point2d, Point2D* map_point2d, Pose2D utm_origin)
{
    set_rotation_matrix_axis(-utm_origin.yaw); // 축의 변환 utm 좌표를 90도로 시계방향으로 회전하면 map 좌표계가 됨
    map_point2d->x = utm_point2d.x * Rotation_Matrix_axis[0][0] + utm_point2d.y * Rotation_Matrix_axis[0][1];
    map_point2d->y = utm_point2d.x * Rotation_Matrix_axis[1][0] + utm_point2d.y * Rotation_Matrix_axis[1][1];

    printf(" utm[%6.3lf,%6.3lf] ---> map[%6.3lf,%6.3lf]\n", utm_point2d.x, utm_point2d.y, map_point2d->x, map_point2d->y);
}

void TF_odom_map(Point2D odom_point2d, Point2D* map_point2d, Pose2D odom_origin)
{
    // 회전 변환 base_link -> base_link_map
    // 병행 변환 base_link_map -> map
    set_rotation_matrix_point(odom_origin.yaw);
    map_point2d->x = odom_point2d.x * Rotation_Matrix_point[0][0] + odom_point2d.y * Rotation_Matrix_point[0][1] + odom_origin.x;
    map_point2d->y = odom_point2d.x * Rotation_Matrix_point[1][0] + odom_point2d.y * Rotation_Matrix_point[1][1] + odom_origin.y;

    printf("Odom to Map: Odom[%6.3lf,%6.3lf] ---> Map[%6.3lf,%6.3lf]\n", odom_point2d.x, odom_point2d.y, map_point2d->x, map_point2d->y);
}

void caculate_waypoint_angle_utm()
{
    double dx, dy;  double angle;
    for (int i = 1; i < LEN; i++)
    {
        dx = waypoint_utm_relative[i].x - waypoint_utm_relative[i - 1].x;
        dy = waypoint_utm_relative[i].y - waypoint_utm_relative[i - 1].y;

        angle = atan2(dy, dx);
        printf("wp[%2d] line angle(utm) %6.3lf\n", i, RAD2DEG(angle));
    }
    printf("\n\n\n");
}

void caculate_waypoint_angle_map()
{
    double dx, dy;  double angle;
    for (int i = 1; i < LEN; i++)
    {
        dx = waypoint_map_relative[i].x - waypoint_map_relative[i - 1].x;
        dy = waypoint_map_relative[i].y - waypoint_map_relative[i - 1].y;

        angle = atan2(dy, dx);
        printf("wp[%2d] line angle(map) %6.3lf\n", i, RAD2DEG(angle));
    }
    printf("\n\n\n");
}

void caculate_waypoint_distance()
{
    double dx, dy; double distance;
    for (int i = 1; i < LEN; i++)
    {
        dx = waypoint_utm_relative[i].x - waypoint_utm_relative[i - 1].x;
        dy = waypoint_utm_relative[i].y - waypoint_utm_relative[i - 1].y;

        distance = sqrt(powf(dx, 2.0) + powf(dy, 2.0));
        waypoint_distance[i] = distance;
        printf("wp[%2d] waypoint distance %6.3lf [m]\n", i, waypoint_distance[i]);
    }
    printf("\n\n\n");
}

void caculate_waypoint_equation_utm()
{
    double dx, dy, a, b;
    for (int i = 1; i < LEN; i++)
    {
        dx = waypoint_utm_relative[i].x - waypoint_utm_relative[i - 1].x;
        dy = waypoint_utm_relative[i].y - waypoint_utm_relative[i - 1].y;

        a = dy / dx;
        b = waypoint_utm_relative[i].y - a * waypoint_utm_relative[i].x;               // b = y - ax
        waypoint_line_equation_utm[i].a = a;
        waypoint_line_equation_utm[i].b = b;
        printf("wp[%2d] waypoint equation(utm) y = %6.3lf * x + %6.3lf   [m]\n", i, waypoint_line_equation_utm[i].a, waypoint_line_equation_utm[i].b);
    }
    printf("\n\n\n");
}

void caculate_waypoint_equation_map()
{
    double dx, dy, a, b;
    for (int i = 1; i < LEN; i++)
    {
        dx = waypoint_map_relative[i].x - waypoint_map_relative[i - 1].x;
        dy = waypoint_map_relative[i].y - waypoint_map_relative[i - 1].y;

        a = dy / dx;
        b = waypoint_map_relative[i].y - a * waypoint_map_relative[i].x;               // b = y - ax
        waypoint_line_equation_map[i].a = a;
        waypoint_line_equation_map[i].b = b;
        printf("wp[%2d] waypoint equation(map) y = %6.3lf * x + %6.3lf   [m]\n", i, waypoint_line_equation_map[i].a, waypoint_line_equation_map[i].b);
    }
    printf("\n\n\n");
}

double calculation_distance_point_line_equation_utm(Point2D in_point2d, int waypoint_id)
{
    double distance = 0; // y = ax + b  ->  ax + b - y = 0
    distance = fabs(waypoint_line_equation_utm[waypoint_id].a * in_point2d.x + waypoint_line_equation_utm[waypoint_id].b - in_point2d.y)
        / sqrt(waypoint_line_equation_utm[waypoint_id].a * waypoint_line_equation_utm[waypoint_id].a + 1);

    return distance;
}

double calculation_distance_point_line_equation_map(Point2D in_point2d, int waypoint_id)
{
    double distance = 0; // y = ax + b  ->  ax + b - y = 0
    distance = fabs(waypoint_line_equation_map[waypoint_id].a * in_point2d.x + waypoint_line_equation_map[waypoint_id].b - in_point2d.y)
        / sqrt(waypoint_line_equation_map[waypoint_id].a * waypoint_line_equation_map[waypoint_id].a + 1);

    return distance;
}

void initialize_odom()
{
    waypoint_odom_relative[0] = { 0,1 };
    utm_link_origin = { 0, 0, 90 };
}
int main()
{
    initialize_waypoint();
    initialize_odom();
    for (int i = 0; i < LEN; i++)
        TF_utm_map(waypoint_utm_relative[i], &waypoint_map_relative[i], utm_link_origin);

    TF_odom_map(waypoint_odom_relative[0], &waypoint_odom_map_relative[0], utm_link_origin);
 
    printf("\n\n\n");
    printf("\n\n\n");

    caculate_waypoint_angle_utm();
    caculate_waypoint_angle_map();
    caculate_waypoint_distance();
    caculate_waypoint_equation_utm();
    caculate_waypoint_equation_map();

    Point2D test;
    test.x = 1.0;
    test.y = 1.0;
    printf("distance(utm) = %6.3lf\n", calculation_distance_point_line_equation_utm(test, 1.0));
    printf("distance(map) = %6.3lf\n", calculation_distance_point_line_equation_map(test, 1.0));
}
