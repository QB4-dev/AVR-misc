/*
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stddef.h>

#include "avr_gpio.h"

static avr_gpio_t led_out = { &PORTB, PB1 };

int main(void)
{
	set_as_output(led_out);

    while(1) {
    	out_toggle(led_out);
    	_delay_ms(250);
    }
}


