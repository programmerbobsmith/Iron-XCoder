#ifndef ERROR_H
#define ERROR_H

#ifdef _cplusplus
extern "C"{
#endif

void error_banner(const char *header, const char *text, unsigned int location_x, unsigned int location_y, unsigned int width, unsigned int height, unsigned int background_color);
void error_notification(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int color);

#ifdef _cplusplus
}
#endif
#endif