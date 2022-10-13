#ifndef ERROR_H
#define ERROR_H

#ifdef _cplusplus
extern "C"{
#endif

void error_banner(const char *header, const char *text, uint8_t location_x, uint8_t location_y, uint8_t width, uint8_t height, uint8_t background_color);
void error_notification(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t color);

#ifdef _cplusplus
}
#endif
#endif