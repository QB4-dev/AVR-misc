# AVR-misc
This is space for various AVR templates

## avr-digispark
Template project for Digispark - mini USB board

## avr-i2c-oled
AVR-libc implemantation of u8g2 library with hardware I2C and with [Elm-Chan xprintf library](http://elm-chan.org/fsw/strf/xprintf.html)

xprintf functions provide basic printf-like expirience to small embedded microcontrollers. 

- You can print int variables just using `DISP_PRINTF(&u8g2,0,12,PSTR("xprintf test: dec %d"), x);`
- You can easily print as hex, print with leading zeroes or add strings with:<br>
`DISP_PRINTF(&u8g2,0,22,PSTR("hex %X lz %02d str %s"), x, x%10, "hello");`
- This xprintf implemantation also supports text rotation
- Supports UTF8 too

![AVR OLED](/avr-i2c-oled/avr-oled.JPG)

## avr-xprintf-asm

Basic example of [Elm-Chan xprintf library](http://elm-chan.org/fsw/strf/xprintf.html) [AVR asm version] integration on AVR
