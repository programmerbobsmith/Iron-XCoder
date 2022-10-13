#ifndef IO_H
#define IO_H

#ifdef _cplusplus
extern "C"{
#endif

void gfx_PrintDouble(double value, uint8_t number_of_decimal_places, uint8_t text_color);
int gfx_GetInteger(uint8_t x, uint8_t y, uint8_t text_color, uint8_t background_color);
double gfx_GetDouble(uint8_t x, uint8_t y, uint8_t text_color, uint8_t background_color);
int gfx_GetSlider(uint8_t start_x, uint8_t start_y, uint8_t step, uint8_t slider_color, uint8_t background_color, uint8_t max_entries);

#ifdef _cplusplus
}
#endif
#endif