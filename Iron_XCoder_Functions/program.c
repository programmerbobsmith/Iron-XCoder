#include "program.h"
#include <graphx.h>
#include <ti/getcsc.h>
#include <stdbool.h>
#include <fileioc.h>
#include <string.h>
#include "error.h"
#include "io.h"

void disp_TIProg(unsigned int x, unsigned int y, unsigned int program_text_color)
{
	gfx_SetTextFGColor(program_text_color);
	char *var_name;
	void *vat_ptr = NULL;
	unsigned int x,y;
	x = 30;
	y = 10;
	char name[9];
	while(var_name = ti_DetectVar(&vat_ptr,NULL,OS_TYPE_PRGM))
	{
		strcpy(name,var_name);
		if (name[0] >= 'A' && name [0] <= 'Z' + 1)
		{
			gfx_PrintStringXY(var_name,x,y);
			y+=15;
		}
	}
	if (var_name == NULL && y == 10)
	{
		gfx_PrintStringXY("No TI-Basic Programs!",80,80);
		return;
	}
}

int launch_callbacks(void *data, int retval)
{
	return main();
}

void disp_CProg(unsigned int program_text_color, unsigned int error_mode)
{
	gfx_SetTextFGColor(program_text_color);
	char *var_name;
	void *vat_ptr = NULL;
	unsigned int x,y;
	x = 30;
	y = 10;
	while(var_name = ti_DetectVar(&vat_ptr,NULL,OS_TYPE_PROT_PRGM))
	{
		gfx_PrintStringXY(var_name,x,y);
		y+=15;
	}
	if (var_name == NULL && y == 10)
	{
		gfx_PrintStringXY("No C/ASM Programs!",80,80);
		return;
	}
}

void run_CProg(unsigned int x, unsigned int y, unsigned int slider_x, unsigned int slider_y, unsigned int slider_color, unsigned int background_color, unsigned int program_text_color, unsigned int error_mode)
{
	gfx_SetTextFGColor(program_text_color);
	char *var_name;
	void *vat_ptr = NULL;
	while(var_name = ti_DetectVar(&vat_ptr,NULL,OS_TYPE_PROT_PRGM))
	{
		gfx_PrintStringXY(var_name,x,y);
		y+=15;
	}
	if (var_name == NULL && y == 10)
	{
		gfx_PrintStringXY("No C/ASM Programs!",x,y);
		return;
	}
	unsigned int num_prog = (y-10)/15;
	unsigned int increment = gfx_Slider(slider_x,slider_y,15,slider_color,background_color,num_prog);
	if (increment == 0)
	{
		return;
	}
	vat_ptr = NULL;
	unsigned int i=0;
	while (i < increment)
	{
		var_name = ti_DetectVar(&vat_ptr,NULL,OS_TYPE_PROT_PRGM);
		i++;
	}
	int error = os_RunPrgm(var_name,NULL,0,launch_callbacks);
	if (error_mode == 1)
	{
		switch (error)
		{
			case -1:
				error_banner("Invalid","Program not found",180,20);
				break;
			case -2:
				error_banner("Memory","Not enough MEM",180,20);
				break;
		}
	}

}

void run_TIProg(unsigned int x, unsigned int y, unsigned int slider_x, unsigned int slider_y, unsigned int slider_color, unsigned int background_color, unsigned int program_text_color, unsigned int error_mode)
{
	gfx_SetTextFGColor(program_text_color);
	char *var_name;
	void *vat_ptr = NULL;
	char name[9];
	while(var_name = ti_DetectVar(&vat_ptr,NULL,OS_TYPE_PRGM))
	{
		strcpy(name,var_name);
		if (name[0] >= 'A' && name [0] <= 'Z' + 1)
		{
			gfx_PrintStringXY(var_name,x,y);
			y+=15;
		}
	}
	if (var_name == NULL && y == 10)
	{
		gfx_PrintStringXY("No TI-Basic Programs!",x,y);
		return;
	}
	unsigned int num_prog = (y-10)/15;
	unsigned int increment = gfx_Slider(slider_x,slider_y,15,slider_color,background_color,num_prog);
	if (increment == 0)
	{
		return;
	}
	vat_ptr = NULL;
	unsigned int i=0;
	while (i < increment)
	{
		var_name = ti_DetectVar(&vat_ptr,NULL,OS_TYPE_PRGM);
		i++;
	}
	gfx_End();
	int error = os_RunPrgm(var_name,NULL,0,launch_callbacks);
	gfx_Begin();
	if (error_mode == 1)
	{
		switch (error)
		{
			case -1:
				error_banner("Invalid","Program not found",180,20);
				break;
			case -2:
				error_banner("Memory","Not enough MEM",180,20);
				break;
		}
	}
}