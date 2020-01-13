/*
 * avr_gpio.h
 *
 *  Created on: 14 maj 2019
 *      Author: kuba
 */

#ifndef AVR_GPIO_H_
#define AVR_GPIO_H_

#include <avr/io.h>

typedef struct {
    volatile uint8_t *port;
    uint8_t pin;
} avr_gpio_t;

inline void set_as_output(avr_gpio_t io) {
    volatile uint8_t *ddr = io.port - 1;
    *ddr |= _BV(io.pin);
}

inline void set_high(avr_gpio_t io) {
    *io.port |= _BV(io.pin);
}

inline void set_low(avr_gpio_t io) {
    *io.port &= ~_BV(io.pin);
}

inline void out_toggle(avr_gpio_t io) {
    *io.port ^= _BV(io.pin);
}

inline void set_as_input(avr_gpio_t io, uint8_t pull_up) {
    volatile uint8_t *ddr = io.port - 1;
    *ddr &= ~_BV(io.pin);
    if(pull_up)
    	*io.port |= _BV(io.pin);
}

inline uint8_t get_input(avr_gpio_t io) {
    volatile uint8_t *pin = io.port - 2;
    return (*pin & _BV(io.pin));
}

#endif /* AVR_GPIO_H_ */
