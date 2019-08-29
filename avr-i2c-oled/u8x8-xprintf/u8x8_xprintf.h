#ifndef U8X8_XPRINTF_H_
#define U8X8_XPRINTF_H_

// Elm Chan xprintf implementation for u8g2
#include <u8g2.h>
#include <xprintf_asm.h>

// Don't use this functions below directly, use macros defined below
void oled_putc(uint8_t c);
void set_xprintf(u8g2_t *u8g2_obj, u8g2_uint_t x, u8g2_uint_t y);
void set_xprintfUTF8(u8g2_t *u8g2_obj, u8g2_uint_t x, u8g2_uint_t y);

#define XPRINTF(u8g2_,x,y,fmt, args...) do { \
	set_xprintf((u8g2_),(x),(y)); \
	xfprintf(oled_putc,fmt, ##args); \
} while(0)

#define XPRINTF_UTF8(u8g2_,x,y,fmt, args...) do { \
	set_xprintfUTF8((u8g2_),(x),(y)); \
	xfprintf(oled_putc,fmt, ##args); \
} while(0)

#endif /* U8X8_XPRINTF_H_ */
