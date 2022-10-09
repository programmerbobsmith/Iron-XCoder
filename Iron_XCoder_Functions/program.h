#ifndef PROGRAM_H
#define PROGRAM_H

#ifdef _cplusplus
extern "C"{
#endif

void disp_TIProg(int x, int y, int program_text_color);
void disp_CProg(int x, int y, int program_text_color);
void run_TIProg(int x, int y, int slider_x, int slider_y, int slider_color, int background_color, int program_text_color, int error_mode);
void run_CProg(int x, int y, int slider_x, int slider_y, int slider_color, int background_color, int program_text_color, int error_mode);

#ifdef _cplusplus
}
#endif
#endif