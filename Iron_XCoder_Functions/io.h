#ifndef IO_H
#define IO_H

#ifdef _cplusplus
extern "C"{
#endif

void gfx_PrintDouble(double value, int number_of_decimal_places, int text_color);
int gfx_GetInteger(int x, int y, int text_color, int background_color);
double gfx_GetDouble(int x, int y, int text_color, int background_color);
int gfx_GetSlider(int start_x, int start_y, int step, int slider_color, int background_color, int max_entries);

#ifdef _cplusplus
}
#endif
#endif