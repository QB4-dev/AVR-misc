#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <u8g2.h>
#include <u8x8-avr-LLdrv/u8x8_avr.h>
#include <u8x8_xprintf.h>

#define SSD1306_ADDR  0x78

u8g2_t u8g2;

int main (void)
{
	u8g2_Setup_ssd1306_i2c_128x32_univision_f(&u8g2, U8G2_R0, u8x8_byte_avr_hw_i2c, u8x8_avr_delay);
	u8g2_SetI2CAddress(&u8g2, SSD1306_ADDR);
	u8g2_InitDisplay(&u8g2);
	u8g2_SetPowerSave(&u8g2, 0);
	uint8_t x =0;

	while(1){
		u8g2_ClearBuffer(&u8g2);

		u8g2_SetFont(&u8g2, u8g2_font_smart_patrol_nbp_tr);
		u8g2_SetFontRefHeightText(&u8g2);
		u8g2_SetFontPosTop(&u8g2);
		u8g2_DrawStr(&u8g2, 0, 0, "u8g2 AVR HW I2C");

		u8g2_SetFont(&u8g2, u8g2_font_5x8_tf);
		XPRINTF(&u8g2,0,12,PSTR("xprintf test: dec %d"), x);
		XPRINTF(&u8g2,0,22,PSTR("hex %X lz %02d str %s"), x, x, "hello");

		u8g2_SendBuffer(&u8g2);

		_delay_ms(100);
		x++;
	}
}

