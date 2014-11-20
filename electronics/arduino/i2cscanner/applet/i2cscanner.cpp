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

/*
 * based on
 * http://playground.arduino.cc/Main/I2cScanner
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <Wire.h>

void setup(void) {
    Wire.begin();

    Serial.begin(9600);
    Serial.println("\ni2cscanner");

    /* your code here */
    return;
}

void loop(void) {
    byte error, address;
    int nDevices;

    Serial.println("scanning...");

    nDevices = 0;
    for(address = 1; address < 127; address++) {
        /* i2cscanner uses the return value of the
         * Write.endTransmisstion to see if a device did acknowledge to
         * the address
         */
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
            Serial.print("I2C device found at address 0x");
            if (address < 16) 
                Serial.print("0");
            Serial.print(address, HEX);
            Serial.println();

            nDevices++;
        }
        else if (error == 4) 
        {
            Serial.print("unknow error at address 0x");
            if (address < 16) 
                Serial.print("0");
            Serial.println(address, HEX);
        }    
    }
    if (nDevices == 0)
        Serial.println("no I2C devices found\n");
    else
        Serial.println("done\n");

    delay(5000);

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

