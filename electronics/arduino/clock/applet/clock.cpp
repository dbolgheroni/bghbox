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
#include <Time.h>
#include <DS1307RTC.h>

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

void print2digits(int);

void setup(void) {
  Serial.begin(9600);
  while (!Serial); /* wait for serial */
  delay(200);
  Serial.println("Clock");
  Serial.println("-----");

  lcd.begin (16,2);

  /* backlight on */
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home();

  /* your code here */
  return;
}

void loop(void) {
  tmElements_t tm;

  if (RTC.read(tm)) {
    print2digits(tm.Hour);

    Serial.write(':');
    lcd.print(":");

    print2digits(tm.Minute);

    Serial.write(':');
    lcd.print(":");

    print2digits(tm.Second);

    Serial.println("");
    lcd.setCursor(0, 0);
  }

  delay(1000);

  /* more of your code here */
  return ;
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.print('0');
    lcd.print('0');
  }

  Serial.print(number);
  lcd.print(number);
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

