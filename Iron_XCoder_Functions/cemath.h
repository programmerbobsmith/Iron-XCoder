#ifndef CEMATH_H
#define CEMATH_H

#ifdef __cplusplus
extern "C" {
#endif

extern global struct triangle
{
	double side_1;
	double side_2;
	double side_3;
	double angle_1;
	double angle_2;
	double angle_3;
	double perimeter;
	double area;
}
#typedef triangle_t struct triangle
unsigned long long int fact(unsigned int num)
double pythag(double leg_1, double leg_2, double hyp)
void solve_triangle(triangle_t triangle, uint8_t mode)

#ifdef __cplusplus
}
#endif
#endif