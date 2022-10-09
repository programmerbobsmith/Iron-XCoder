#ifndef PROGRAM_H
#define PROGRAM_H

#ifdef _cplusplus
extern "C"{
#endif

void disp_ASMProg_Sprite(const char *prog_name, uint8_t x_loc, uint8_t y_loc)
void disp_TIProg(uint8_t x, uint8_t y, uint8_t program_text_color);
void disp_CProg(uint8_t x, uint8_t y, uint8_t program_text_color);
void run_TIProg(uint8_t x, uint8_t y, uint8_t slider_x, uint8_t slider_y, uint8_t slider_color, uint8_t background_color, uint8_t program_text_color, uint8_t error_mode);
void run_CProg(uint8_t x, uint8_t y, uint8_t slider_x, uint8_t slider_y, uint8_t slider_color, uint8_t background_color, uint8_t program_text_color, uint8_t error_mode);

#ifdef _cplusplus
}
#endif
#endif