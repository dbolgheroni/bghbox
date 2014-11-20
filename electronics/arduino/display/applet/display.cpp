#include "Arduino.h"
#ifdef __cplusplus
extern "C" void __cxa_pure_virtual(void) { while(1); }
#endif

/*
 * $OpenBSD: template.ino,v 1.1 2012/04/24 06:37:32 jasper Exp $
 *
 * Arduino projects run something like this:
 *	main() {
 *		init(); // arduino private setup
 *		setup(); // your setup goes here
 *		while(1) {
 *			loop(); // your main loop
 *		}
 *	}
 *
 * Arduino reference is at /usr/local/share/doc/arduino/reference/
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

LiquidCrystal_I2C lcd(I2C_ADDR,
                      En_pin,
                      Rw_pin,
                      Rs_pin,
                      D4_pin,
                      D5_pin,
                      D6_pin,
                      D7_pin);

void setup(void) {
    lcd.begin (16,2); /* 16x2 LCD */

    /* backlight on */
    lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
    lcd.setBacklight(HIGH);
    lcd.home();

    //lcd.print("Hello World"); 

    /* your code here */
    return;
}

void loop(void) {
    lcd.setCursor(0, 0);
    lcd.print("Hello");
    delay(500);
    lcd.setCursor(0, 0);
    lcd.print("World");
    delay(500);

    //lcd.setCursor(0, 1);
    //lcd.print(n++, DEC);
    //lcd.setBacklight(HIGH);

    /* more of your code here */
    return ;
}

#ifdef __cplusplus
}
#endif
#include <Arduino.h>

int main(void)
{
	init();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}

