#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "uart/uart.h"
#include "xprintf_asm/xprintf_asm.h"

int main (void)
{
	uint8_t x=0;
	uint16_t milivolts = 4060;

	uart_init(UART_BAUD_SELECT_DOUBLE_SPEED(19200,F_CPU));
	xdev_out(uart_putc);
	xputs(PSTR("AVR: NO ELO\n"));
	sei();
	while(1){
		xprintf(PSTR("x=%d\n"),x);
		xprintf(PSTR("x[hex]=%X x[bin]=%b\n"),x);
		xprintf(PSTR("x > 10? %s\n"), (x>10)?"YES":"NO");
		xprintf(PSTR("milivolts %d.%03d\n\n"), milivolts/1000, milivolts%1000);
		_delay_ms(2000);
		x++;
	}
}

