#include "io.h"
#include <graphx.h>
#include <string.h>
#include <ti/getcsc.h>
#include <math.h>
#include <keypadc.h>

void print_Double(double value, uint8_t number_of_decimal_places, uint8_t text_color)
{
	gfx_SetTextFGColor(text_color);
	gfx_PrintInt((int)value,1);
	gfx_PrintChar('.');
	double answer = (int)((value - (int)value)*(pow(10,number_of_decimal_places)));
	if (answer < 0)
	{
		answer*=-1;
	}
	gfx_PrintInt(answer,number_of_decimal_places);
}

int get_Integer(uint8_t x, uint8_t y, uint8_t  text_color, uint8_tbackground_color)
{
	gfx_SetTextFGColor(text_color);
	unsigned int key;
	unsigned int increment = 0;
	char user_input[21];
	char key_pad[] = { [sk_0] = '0', [sk_1] = '1', [sk_2] = '2', [sk_3] = '3', [sk_4] = '4', [sk_5] = '5', [sk_6] = '6', [sk_7] = '7', [sk_8] = '8', [sk_9] = '9', [sk_Chs] = '-'};
	gfx_SetColor(text_color);
	gfx_Line(x,y+7,x+8,y+7);
	gfx_Line(x,y+8,x+8,y+8);
	while(key = os_GetCSC(), key != sk_Enter)
	{
		if (key == sk_Del && increment != 0)	// user deletes char
		{
			increment--;
			gfx_SetColor(background_color);
			gfx_Line(x,y+7,x+8,y+7);
			gfx_Line(x,y+8,x+8,y+8);
			x-=8;
			gfx_FillRectangle(x,y,8,8);
			gfx_SetColor(text_color);
			gfx_Line(x,y+7,x+8,y+7);
			gfx_Line(x,y+8,x+8,y+8);
		}else if (key == sk_Enter)
		{
			break;
		}else if (key == sk_Clear)
		{
			gfx_End();
			exit(0);
		}else if (key < 17 || key > 36 || key == 21 || key == 22 || key == 23 || key == 24 || key == 25|| key == 29 || key == 30 || key == 31 || key == 32)
		{
		}else if (key != 0 && key != sk_Enter && key != sk_Del && key != sk_Clear)
		{
			gfx_SetColor(background_color);
			gfx_Line(x,y+7,x+8,y+7);
			gfx_Line(x,y+8,x+8,y+8);
			gfx_SetTextFGColor(text_color);
			gfx_SetTextXY(x,y);
			gfx_PrintChar(key_pad[key]);
			x += 8;
			gfx_SetColor(text_color);
			gfx_Line(x,y+7,x+8,y+7);
			gfx_Line(x,y+8,x+8,y+8);
			user_input[increment++] = key_pad[key];
		}
	}
	user_input[increment] = '\0';		// terminates string at last position
	long int user_input_converted = strtol(user_input,NULL,0);
	gfx_SetColor(background_color);
	gfx_Line(x,y+7,x+8,y+7);
	gfx_Line(x,y+8,x+8,y+8);
	return (user_input_converted);
}

double get_Double(uint8_t x, uint8_ty, uint8_t text_color, uint8_t background_color)
{
	gfx_SetTextFGColor(text_color);
	unsigned int key;
	unsigned int increment = 0;
	char user_input[21];
	char key_pad[] = { [sk_0] = '0', [sk_1] = '1', [sk_2] = '2', [sk_3] = '3', [sk_4] = '4', [sk_5] = '5', [sk_6] = '6', [sk_7] = '7', [sk_8] = '8', [sk_9] = '9', [sk_DecPnt] = '.', [sk_Chs] = '-'};
	gfx_SetColor(background_color);
	gfx_Line(x,y+7,x+8,y+7);
	gfx_Line(x,y+8,x+8,y+8);
	while(key = os_GetCSC(), key != sk_Enter)
	{
		if (key == sk_Del && increment != 0)	// user deletes char
		{
			increment--;
			gfx_SetColor(background_color);
			gfx_Line(x,y+7,x+8,y+7);
			gfx_Line(x,y+8,x+8,y+8);
			x -= 8;
			gfx_FillRectangle(x,y,8,8);
			gfx_SetColor(text_color);
			gfx_Line(x,y+7,x+8,y+7);
			gfx_Line(x,y+8,x+8,y+8);
		}else if (key == sk_Enter)
		{
			break;
		}else if (key == sk_Clear)
		{
			gfx_End();
			exit(0);
		}else if (key < 17 || key > 36 || key == 21 || key == 22 || key == 23 || key == 24 || key == 29 || key == 30 || key == 31 || key == 32)
		{
		}else if (key != 0 && key != sk_Enter && key != sk_Del && key != sk_Clear)
		{
			gfx_SetColor(background_color);
			gfx_Line(x,y+7,x+8,y+7);
			gfx_Line(x,y+8,x+8,y+8);
			gfx_SetTextFGColor(text_color);
			gfx_SetTextXY(x,y);
			gfx_PrintChar(key_pad[key]);
			x += 8;
			gfx_SetColor(text_color);
			gfx_Line(x,y+7,x+8,y+7);
			gfx_Line(x,y+8,x+8,y+8);
			user_input[increment++] = key_pad[key];
		}
	}
	user_input[increment] = '\0';		// terminates string at last position
	double user_input_converted = strtod(user_input,NULL);
	gfx_SetColor(background_color);
	gfx_Line(x,y+7,x+8,y+7);
	gfx_Line(x,y+8,x+8,y+8);
	return (user_input_converted);
}

int get_Slider(uint8_t start_x, uint8_t start_y, uint8_t step, uint8_t slider_color, uint8_t background_color, uint8_t max_entries)
{
	unsigned int increment = 1;
	unsigned int key;
	start_y -= 2;
	gfx_SetColor(slider_color);
	gfx_FillTriangle( start_x-18, start_y+(step*(increment-1)), start_x-10, start_y+4+(step*(increment-1)), start_x-18, start_y+8+(step*(increment-1)));
	while(key = os_GetCSC(), key != sk_Enter)
	{
		if (key == sk_Clear)
		{
			gfx_End();
			exit(0);
		}else if (key == sk_Up && increment != 1)
		{
			gfx_SetColor(background_color);
			gfx_FillTriangle( start_x-18, start_y+(step*(increment-1)), start_x-10, start_y+4+(step*(increment-1)), start_x-18, start_y+8+(step*(increment-1)));
			increment--;
			gfx_SetColor(slider_color);
			gfx_FillTriangle( start_x-18, start_y+(step*(increment-1)), start_x-10, start_y+4+(step*(increment-1)), start_x-18, start_y+8+(step*(increment-1)));
		}else if (key == sk_Down && increment != max_entries)
		{
			gfx_SetColor(background_color);
			gfx_FillTriangle( start_x-18, start_y+(step*(increment-1)), start_x-10, start_y+4+(step*(increment-1)), start_x-18, start_y+8+(step*(increment-1)));
			increment++;
			gfx_SetColor(slider_color);
			gfx_FillTriangle( start_x-18, start_y+(step*(increment-1)), start_x-10, start_y+4+(step*(increment-1)), start_x-18, start_y+8+(step*(increment-1)));
		}
	}
	return (increment);
}
