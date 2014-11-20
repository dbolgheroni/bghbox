#include "Arduino.h"
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

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

//IPAddress ip(192, 168, 1, 160);
IPAddress server(173, 194, 33, 104);

EthernetClient client;

void setup(void) {
    Serial.begin(57600);

    /* wait for serial port to connect */
    while (!Serial) {
        Serial.print(".");
    }
    Serial.println();

    /* start Ethernet connection */
    //Ethernet.begin(mac, ip);

    /* DHCP */
    if (Ethernet.begin(mac) == 0) {
        Serial.println("failed to configure Ethernet using DHCP");

        for (;;);
    }

    delay(1000);
    Serial.print("IP address: "); Serial.println(Ethernet.localIP());
    Serial.println("connecting...");

    if (client.connect(server, 80)) {
        Serial.println("connected");

        client.println("GET /search?q=arduino HTTP/1.0");
        client.println();
    } else {
        Serial.println("connection failed");
    }

    return;
}

void loop(void) {
    if (client.available()) {
        char c = client.read();
        Serial.print(c);
    }

    if (!client.connected()) {
        Serial.println();
        Serial.println("disconnecting.");
        client.stop();

        for(;;);
    }

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

