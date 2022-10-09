#include "program.h"
#include <graphx.h>
#include <ti/getcsc.h>
#include <stdbool.h>
#include <stdint.h>
#include <fileioc.h>
#include <string.h>
#include "error.h"
#include "io.h"

void disp_CProg_Sprite(const char *prog_name, int x_loc, int y_loc)
{
	gfx_SetDefaultPalette(gfx_8bpp);
	uint8_t handle = ti_OpenVar(prog_name,"r",OS_TYPE_PRGM);
	ti_SetArchiveStatus(false,handle);
	uint8_t data;
	ti_Seek(10,SEEK_SET,handle);
	for(int x = 0; x<256;x++)
	{
		ti_Read(&data,sizeof(uint8_t),1,handle);
		gfx_SetColor(data);
		if (x_loc == x_loc+15)
		{
			y++;
			x_loc;
		}
		gfx_SetPixel(x_loc++,y);
	}
	ti_SetArchiveStatus(true,handle);
	ti_Close(oiram);
}

void disp_TIProg(int x, int y, int program_text_color)
{
	gfx_SetTextFGColor(program_text_color);
	char *var_name;
	void *vat_ptr = NULL;
	int x,y;
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

void disp_CProg(int program_text_color, int error_mode)
{
	gfx_SetTextFGColor(program_text_color);
	char *var_name;
	void *vat_ptr = NULL;
	int x,y;
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

void run_CProg(int x, int y, int slider_x, int slider_y, int slider_color, int background_color, int program_text_color, int error_mode)
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
	int num_prog = (y-10)/15;
	int increment = gfx_Slider(slider_x,slider_y,15,slider_color,background_color,num_prog);
	if (increment == 0)
	{
		return;
	}
	vat_ptr = NULL;
	int i=0;
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

void run_TIProg(int x, int y, int slider_x, int slider_y, int slider_color, int background_color, int program_text_color, int error_mode)
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
	int num_prog = (y-10)/15;
	int increment = gfx_Slider(slider_x,slider_y,15,slider_color,background_color,num_prog);
	if (increment == 0)
	{
		return;
	}
	vat_ptr = NULL;
	int i=0;
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