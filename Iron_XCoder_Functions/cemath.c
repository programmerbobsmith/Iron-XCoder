#include "cemath.h"
#include <stdint.h>
#include <math.h>

//finds the factorial of a number
unsigned long long int fact(unsigned int num)
{
	unsigned int i;
	unsigned long long int fact = 1;
	//this multiplies `fact` by every number from 1 to `fact`
	for(i = 1; i<=num; ++i)
	{
		fact*=i;
	}
	return (fact);
}

double pythag(double leg_1, double leg_2, double hyp)
{
	if (hyp == NULL)
	{
		return sqrt(leg_1*leg_1+leg_2*leg_2);
	}else if (leg_2 == NULL)
	{
		return sqrt(hyp*hyp - leg_1*leg_1);
	}else if (leg_1 == NULL)
	{
		return sqrt(hyp*hyp - leg_2*leg_2);
	}
}

void solve_triangle(triangle_t triangle)
{
	switch(mode)
	{
		case 1: //side-angle-side
			triangle.side_1 = sqrt(triangle.side_2*triangle.side_2+triangle.side_3*triangle.side_3-cos(pi/180*triangle.angle_1)*2*triangle.side_2*triangle.side_3);
			triangle.angle_2 = 180/pi*acos((triangle.side_1*triangle.side_1+triangle.side_3*triangle.side_3-triangle.side_2*triangle.side_2)/(2*triangle.side_1*triangle.side_3));
			triangle.angle_3 = 180/pi*acos((triangle.side_1*triangle.side_1+triangle.side_2*triangle.side_2-triangle.side_3*triangle.side_3)/(2*triangle.side_1*triangle.side_2));
			triangle.perimeter = (triangle.side_a+triangle.side_b+triangle.side_c);
			semip = triangle.perimeter/2;
			triangle.area = sqrt(semip*(semip-triangle.side_a)*(semip-triangle.side_b)*(semip-triangle.side_c));
		case 2: //side-side-side
			triangle.angle_1 = 180/pi*acos((triangle.side_2*triangle.side_2+triangle.side_3*triangle.side_3-triangle.side_1*triangle.side_1)/(2*triangle.side_2*triangle.side_3));
    		triangle.angle_2 = 180/pi*acos((triangle.side_1*triangle.side_1+triangle.side_3*triangle.side_3-triangle.side_2*triangle.side_2)/(2*triangle.side_1*triangle.side_3));
			triangle.angle_3 = 180/pi*acos((triangle.side_1*triangle.side_1+triangle.side_2*triangle.side_2-triangle.side_3*triangle.side_3)/(2*triangle.side_1*triangle.side_2));
    		triangle.perimeter = (side_a+side_b+side_c);
			semip = triangle.perimeter/2;
    		area = sqrt(semip*(semip-side_a)*(semip-side_b)*(semip-side_c));
			break;
		case 3: //angle-side-angle
			triangle.angle_3 = 180 - triangle.angle_1 - triangle.angle_2;
    		triangle.side_1 = (triangle.side_3*sin(pi/180*triangle.angle_1))/sin(pi/180*triangle.angle_3);
    		triangle.side_2 = (triangle.side_1*sin(pi/180*triangle.angle_2))/sin(pi/180*triangle.angle_1);
    		triangle.perimeter = (side_a+side_b+side_c);
			semip = triangle.perimeter/2;
    		triangle.area = sqrt(semip*(semip-triangle.side_1)*(semip-triangle.side_2)*(semip-triangle.side_3));
			break;
		case 4: //angle-angle-side
			triangle.angle_3 = 180-triangle.angle_2-triangle.angle_3;
    		triangle.side_2 = (triangle.side_1*sin(pi/180*triangle.angle_2))/sin(pi/180*triangle.angle_1);
    		triangle.side_3 = (triangle.side_2*sin(pi/180*triangle.angle_3))/sin(pi/180*triangle.angle_2);
    		triangle.perimeter = (triangle.side_a+triangle.side_b+triangle.side_c);
			semip = triangle.perimeter/2;
    		triangle.area = sqrt(semip*(semip-triangle.side_a)*(semip-triangle.side_b)*(semip-triangle.side_c));
			break;
	}
}