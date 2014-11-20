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

#include <UIPEthernet.h>

EthernetClient client;
signed long next;

void setup(void) {
    Serial.begin(57600);

    uint8_t mac[6] = {0xAD,0xDA,0x10,0x20,0x30,0x40};
    IPAddress ip(192,168,1,80);
    IPAddress dns(8,8,8,8);
    IPAddress gw(192,168,1,1);
    Ethernet.begin(mac, ip, dns, gw);

    Serial.print("localIP: ");
    Serial.println(Ethernet.localIP());
    Serial.print("subnetMask: ");
    Serial.println(Ethernet.subnetMask());
    Serial.print("gatewayIP: ");
    Serial.println(Ethernet.gatewayIP());
    Serial.print("dnsServerIP: ");
    Serial.println(Ethernet.dnsServerIP());

    next = 0;

    return;
}

void loop(void) {
    /*
    if (((signed long)(millis() - next)) > 0) {
        next = millis() + 5000;
        Serial.println("Client connect");
        // replace hostname with name of machine running tcpserver.pl
        //      if (client.connect("server.local",5000))
        if (client.connect(IPAddress(192,168,0,1),5000)) {
            Serial.println("Client connected");
            client.println("DATA from Client");
            while(client.available()==0) {
                if (next - millis() < 0)
                    goto close;
            }
            int size;
            while((size = client.available()) > 0) {
                uint8_t* msg = (uint8_t*)malloc(size);
                size = client.read(msg,size);
                Serial.write(msg,size);
                free(msg);
            }
close:
            //disconnect client
            Serial.println("Client disconnect");
            client.stop();
        }
        else
            Serial.println("Client connect failed");
    }
    */

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

