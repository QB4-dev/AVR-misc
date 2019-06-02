#ifndef U8X8_XPRINTF_H_
#define U8X8_XPRINTF_H_

// Elm Chan xprintf implementation for u8g2

#include <u8g2.h>
#include <xprintf_asm/xprintf_asm.h>

#define XPRINTF(u8g2_,x,y,fmt, args...) do { \
	set_xprintf((u8g2_),(x),(y)); \
	xprintf(fmt, ##args); \
} while(0)

#define XPUTS(u8g2_,x,y,str) do { \
	set_xprintf((u8g2_),(x),(y)); \
	xputs(str); \
} while(0)

void set_xprintf(u8g2_t *u8g2_obj, u8g2_uint_t x, u8g2_uint_t y);

#endif /* U8X8_XPRINTF_H_ */
