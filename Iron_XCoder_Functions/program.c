#include "program.h"
#include <graphx.h>
#include <ti/getcsc.h>
#include <stdbool.h>
#include <stdint.h>
#include <fileioc.h>
#include <string.h>
#include <ti/vars.h>
#include "error.h"
#include "io.h"

uint8_t disp_ASMProg_Description(const char *prog_name, uint8_t xloc, uint8_t y_loc, uint8_t text_color)
{
	gfx_SetDefaultPalette(gfx_8bpp);
	uint8_t handle = ti_OpenVar(prog_name,"r",OS_TYPE_PRGM);
	if(handle==0)
	{
		gfx_End();
		return 2;
	}
	uint8_t data;
	ti_Seek(2,SEEK_SET,handle);
	ti_Read(&data,sizeof(uint8_t),1,handle);
	ti_Rewind(handle);
	if(data==0x00)
	{
		ti_Seek(7,SEEK_SET,handle);
		ti_Read(&data,sizeof(uint8_t),1,handle);
		if(data==0x01 || data==0x02)
		{
			ti_Seek(8*(data==0x02)+266*(data==0x01),SEEK_SET,handle);
		}else
		{
			ti_Close(handle);
			return 1;
		}
		gfx_SetTextFGColor(text_color);
		gfx_SetTextXY(xloc,yloc);
		while(data!=0x00)
		{
			ti_Read(&data,sizeof(uint8_t),1,handle);
			gfx_PrintChar(data);
		}
	}else
	{
		ti_Close(handle);
		return 1;
	}
	ti_Close(handle);
	return 0;
}

uint8_t disp_ASMProg_Sprite(const char *prog_name, uint8_t x_loc, uint8_t y_loc)
{
	gfx_SetDefaultPalette(gfx_8bpp);
	uint8_t handle = ti_OpenVar(prog_name,"r",OS_TYPE_PRGM);
	if(handle==0)
	{
		return 2;
	}
	uint8_t data1,data2;
	ti_Seek(2,SEEK_SET,handle);
	ti_Read(&data1,sizeof(uint8_t),1,handle);
	ti_Rewind(handle);
	if(data1==0x00)
	{
		ti_Seek(8,SEEK_SET,handle);
		ti_Read(&data1,sizeof(uint8_t),1,handle);
		ti_Read(&data2,sizeof(uint8_t),1,handle);
		ti_Rewind(oiram);
		if (data1==0x10 && data2==0x10)
		{
			ti_Seek(10,SEEK_SET,handle);
		}else
		{
			return 1;
		}
	}else if(data1==0xc3)
	{
		ti_Seek(7,SEEK_SET,oiram);
		ti_Read(&data1,sizeof(uint8_t),1,handle);
		ti_Read(&data2,sizeof(uint8_t),1,handle);
		ti_Rewind(oiram);
		if (data1==0x10 && data2==0x10)
		{
			ti_Seek(9,SEEK_SET,handle);
		}else
		{
			return 1;
		}
	}else
	{
		return 1;
	}
	uint8_t original_xloc;
	for(uint8_t x = 0; x<256;x++)
	{
		ti_Read(&data1,sizeof(uint8_t),1,handle);
		gfx_SetColor(data1);
		if (x == original_xloc+15)
		{
			yloc++;
			xloc=original_xloc;
		}
		gfx_SetPixel(xloc++,yloc);
	}
	ti_Close(handle);
	return 0;
}

void disp_TIProg(uint8_t x, uint8_t y, uint8_t program_text_color)
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

void disp_CProg(uint8_t program_text_color, uint8_t error_mode)
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

void run_CProg(uint8_t x, uint8_t y, uint8_t slider_x, uint8_t slider_y, uint8_t slider_color, uint8_t background_color, uint8_t program_text_color, uint8_t error_mode)
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

void run_TIProg(uint8_t x, uint8_t y, uint8_t slider_x, uint8_t slider_y, uint8_t slider_color, uint8_t background_color, uint8_t program_text_color, uint8_t error_mode)
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