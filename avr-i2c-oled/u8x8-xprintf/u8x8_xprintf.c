#include "u8x8_xprintf.h"

static struct {
	 u8g2_uint_t c_x, c_y;
	 u8g2_t *ctx;
} xprintf_local;

static void oled_putc(uint8_t c)
{
	uint16_t e;
	u8g2_uint_t delta;

	e = xprintf_local.ctx->u8x8.next_cb(u8g2_GetU8x8(xprintf_local.ctx), c);
	if( e == 0x0ffff )
	  return;

	if( e != 0x0fffe ){
		delta = u8g2_DrawGlyph(xprintf_local.ctx, xprintf_local.c_x, xprintf_local.c_y, e);
		#ifdef U8G2_WITH_FONT_ROTATION
		switch(xprintf_local.ctx->font_decode.dir) {
			case 0: xprintf_local.c_x += delta; break;
			case 1: xprintf_local.c_y += delta; break;
			case 2: xprintf_local.c_x -= delta; break;
			case 3: xprintf_local.c_y -= delta; break;
			default: break;
		}
		#else
		xprintf_local.c_x += delta;
		#endif
	}
}

static void init_xprintf_common(u8g2_t *u8g2_obj, u8g2_uint_t x, u8g2_uint_t y)
{
	u8x8_utf8_init(u8g2_GetU8x8(u8g2_obj));
	xprintf_local.ctx = u8g2_obj;
	xprintf_local.c_x = x;
	xprintf_local.c_y = y;
	xdev_out(oled_putc);
}

void set_xprintf(u8g2_t *u8g2_obj, u8g2_uint_t x, u8g2_uint_t y)
{
	u8g2_obj->u8x8.next_cb = u8x8_ascii_next;
	init_xprintf_common(u8g2_obj,x,y);
}

void set_xprintfUTF8(u8g2_t *u8g2_obj, u8g2_uint_t x, u8g2_uint_t y)
{
	u8g2_obj->u8x8.next_cb = u8x8_utf8_next;
	init_xprintf_common(u8g2_obj,x,y);
}

