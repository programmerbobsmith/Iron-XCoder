#ifndef IO_H
#define IO_H

#ifdef _cplusplus
extern "C"{
#endif

void gfx_PrintDouble(double value, unsigned int number_of_decimal_places, unsigned int text_color);
int gfx_GetInteger(unsigned int x, unsigned int y, unsigned int text_color, unsigned int background_color);
double gfx_GetDouble(unsigned int x, unsigned int y, unsigned int text_color, unsigned int background_color);
int gfx_GetSlider(unsigned int start_x, unsigned int start_y, unsigned int step, unsigned int slider_color, unsigned int background_color, unsigned int max_entries);

#ifdef _cplusplus
}
#endif
#endif