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
    pinMode(11, OUTPUT); /* to relay, inverse logic */

    vw_set_ptt_inverted(true);
    vw_set_rx_pin(12);
    vw_setup(1024);

    vw_rx_start();

    return;
}

void loop(void) {
    /* more of your code here */
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if(vw_get_message(buf, &buflen)) {
        if (buf[0] == '1') {
            digitalWrite(13, HIGH);
            digitalWrite(11, LOW);
        } else if (buf[0] == '0') {
            digitalWrite(13, LOW);
            digitalWrite(11, HIGH);
        }
    }

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

