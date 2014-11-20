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

#include <VirtualWire.h>

#ifdef __cplusplus
extern "C" {
#endif

void setup(void) {
    /* your code here */
    pinMode(13, OUTPUT);

    vw_set_ptt_inverted(true);
    vw_set_tx_pin(12);
    vw_setup(1024);

    return;
}

void loop(void) {
    /* more of your code here */
    char *controller;

    controller = (char *)"1";
    vw_send((uint8_t *)controller, strlen(controller));
    vw_wait_tx();
    digitalWrite(13, HIGH);
    delay(1000);

    controller = (char *)"0";
    vw_send((uint8_t *)controller, strlen(controller));
    vw_wait_tx();
    digitalWrite(13, LOW);
    delay(1000);

    return;
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

