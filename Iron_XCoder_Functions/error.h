#ifndef ERROR_H
#define ERROR_H

#ifdef _cplusplus
extern "C"{
#endif

void error_banner(const char *header, const char *text, int location_x, int location_y, int width, int height, int background_color);
void error_notification(int x, int y, int width, int height, int color);

#ifdef _cplusplus
}
#endif
#endif