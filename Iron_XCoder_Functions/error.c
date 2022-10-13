#include "error.h"
#include <graphx.h>
#include <sys/rtc.h>
#include <string.h>
#include <sys/timers.h>

void error_banner(const char *header, const char *text, uint8_t location_x, uint8_t location_y, uint8_t width, uint8_t height, uint8_t background_color)
{
	// allocate memory and grab background sprite of the specified location
	gfx_sprite_t *notification_background = gfx_MallocSprite(width+1,height);
	gfx_GetSprite(notification_background,location_x,location_y);
	// print the actuall notification with text
	error_notification(location_x,location_y,width,height,background_color);
	gfx_PrintStringXY(header,location_x+6,location_y+3);
	gfx_PrintStringXY(text,location_x+10,location_y+12);
	// pause for 2 seconds to allow for user attention
	msleep(2000);
	// removes the notification by drawing the background sprite
	gfx_Sprite(notification_background,180,20);
}

//don't use this on its own, it just draws a box
void error_notification(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t color)
{
	gfx_SetColor(color);
	gfx_Line(x,y+4,x,y+height-4);
	gfx_Line(x+1,y+2,x+1,y+height-2);
	gfx_Line(x+2,y+1,x+2,y+height-1);
	gfx_Line(x+3,y+1,x+3,y+height-1);
	gfx_FillRectangle(x+4,y,width-6,height);
	gfx_Line(x+width-3,y+1,x+width-3,y+height-1);
	gfx_Line(x+width-2,y+1,x+width-2,y+height-1);
	gfx_Line(x+width-1,y+2,x+width-1,y+height-2);
	gfx_Line(x+width,y+4,x+width,y+height-4);
}