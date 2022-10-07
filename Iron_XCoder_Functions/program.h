#ifndef PROGRAM_H
#define PROGRAM_H

#ifdef _cplusplus
extern "C"{
#endif

void disp_TIProg(unsigned int x, unsigned int y, unsigned int program_text_color);
void disp_CProg(unsigned int x, unsigned int y, unsigned int program_text_color);
void run_TIProg(unsigned int x, unsigned int y, unsigned int slider_x, unsigned int slider_y, unsigned int slider_color, unsigned int background_color, unsigned int program_text_color, unsigned int error_mode);
void run_CProg(unsigned int x, unsigned int y, unsigned int slider_x, unsigned int slider_y, unsigned int slider_color, unsigned int background_color, unsigned int program_text_color, unsigned int error_mode);

#ifdef _cplusplus
}
#endif
#endif