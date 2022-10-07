#include "cemath.h"
#include <stdint.h>
#include <math.h>

unsigned long long int fact(unsigned int num)
{
	unsigned int i;
	unsigned long long int fact = 1;
	for(i = 1; i<=num; ++i)
	{
		fact*=i;
	}
	return (fact);
}