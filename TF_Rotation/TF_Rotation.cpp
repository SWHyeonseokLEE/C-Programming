// TF_Rotation.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "math.h"

#define RAD2DEG(x)   x * (180/M_PI)
#define DEG2RAD(x)   x * (M_PI/180)

typedef struct
{
	double x;
	double y;
	double theta;
} Pose2D;

typedef struct
{
	double x;
	double y;
} Point2D;


Pose2D  base_link_origin;
Point2D base_link_Point2D, base_link_map_Point2D;
Point2D Transformed, Transformed_inverse;
Point2D Transformed2, Transformed_inverse2;

double	angle_degree;
double  angle_radian;
double  Rotation_matrix[2][2];
double  Rotation_matrix_inverse[2][2];


void set_rotation_matrix_inverse(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);

	Rotation_matrix_inverse[0][0] = cos(angle_radian);   Rotation_matrix_inverse[0][1] = sin(angle_radian);
	Rotation_matrix_inverse[1][0] = -sin(angle_radian);  Rotation_matrix_inverse[1][1] = cos(angle_radian);
}


void set_rotation_matrix(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);

	Rotation_matrix[0][0] = cos(angle_radian);  Rotation_matrix[0][1] = -sin(angle_radian);
	Rotation_matrix[1][0] = sin(angle_radian);  Rotation_matrix[1][1] = cos(angle_radian);
}

void TF_base_link_base_link_map(Point2D* base_link_point2d, Point2D* base_link_map_point2d, Pose2D base_link_origin)
{
	set_rotation_matrix_inverse(base_link_origin.theta);
	
	Transformed.x = (Rotation_matrix[0][0] * base_link_point2d->x) + (Rotation_matrix[0][1] * base_link_point2d->y);
	Transformed.y = (Rotation_matrix[1][0] * base_link_point2d->x) + (Rotation_matrix[1][1] * base_link_point2d->y);
}

void TF_base_link_map_map(Point2D* Transformed, Pose2D base_link_origin)
{
	TF_base_link_base_link_map(&base_link_Point2D, &base_link_map_Point2D, base_link_origin);
	Transformed2.x = Transformed->x + base_link_origin.x;
	Transformed2.y = Transformed->y + base_link_origin.y;

	printf("Base link to Base link map \n");
	printf("%6.3lf	%6.3lf \n\n", Transformed->x, Transformed->y);

	printf("Base link map to Map \n");
	printf("%6.3lf	%6.3lf \n\n", Transformed2.x, Transformed2.y);
	printf("--------------------------------------------- \n");
}

void TF_base_link_map(Point2D* base_link_point_2d, Point2D* base_link_map_point2d, Pose2D base_link_origin)
{
	set_rotation_matrix(base_link_origin.theta);
	TF_base_link_base_link_map(base_link_point_2d, base_link_map_point2d, base_link_origin);
	TF_base_link_map_map(&Transformed, base_link_origin);
}

void TF_map_base_link_map(Point2D* Transformed2, Pose2D base_link_origin)
{
	Transformed_inverse2.x = Transformed2->x - base_link_origin.x;
	Transformed_inverse2.y = Transformed2->y - base_link_origin.y;

	printf("--------------------------------------------- \n");
	printf("Map to Base link map \n");
	printf("% 6.3lf % 6.3lf \n\n", Transformed_inverse2.x, Transformed_inverse2.y);
}

void TF_base_link_map_base_link(Point2D* Transformed_inverse2, Point2D* base_link_map_point2d, Pose2D base_link_origin)
{
	set_rotation_matrix(base_link_origin.theta);

	Transformed_inverse.x = (Rotation_matrix_inverse[0][0] * base_link_map_point2d->x) + (Rotation_matrix_inverse[0][1] * base_link_map_point2d->y);
	Transformed_inverse.y = (Rotation_matrix_inverse[1][0] * base_link_map_point2d->x) + (Rotation_matrix_inverse[1][1] * base_link_map_point2d->y);

	printf("Base link map to Base link \n");
	printf("% 6.3lf % 6.3lf \n\n", Transformed_inverse.x, Transformed_inverse.y);
}

void TF_map_base_link(Point2D* base_link_point2d, Point2D* base_link_map_point2d, Pose2D base_link_origin)
{
	
	TF_map_base_link_map(&Transformed_inverse2, base_link_origin);
	TF_base_link_map_base_link(base_link_point2d, base_link_map_point2d, base_link_origin);

	printf("--------------------------------------------- \n");
}
int _tmain(int argc, _TCHAR* argv[])
{

	base_link_origin.x      = 5;
	base_link_origin.y      = 4;
	base_link_origin.theta  = -90;

	base_link_Point2D.x     = 1;
	base_link_Point2D.y     = -1;

	base_link_map_Point2D.x = 6;
	base_link_map_Point2D.y = 5;

	TF_map_base_link(&base_link_Point2D, &base_link_map_Point2D, base_link_origin);
	TF_base_link_map(&base_link_Point2D, &base_link_map_Point2D, base_link_origin);

	return 0;
}