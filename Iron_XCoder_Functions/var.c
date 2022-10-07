#include "var.h"
#include <ti/vars.h>
#include <stdint.h>
#include <ti/real.h>

void var_Sto(const char *var, float num_sto)
{
	real_t buffer;
	buffer = os_FloatToReal(num_sto);
	os_SetRealVar(var,&buffer);
}