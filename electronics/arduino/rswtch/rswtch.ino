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
#include <EthernetUdp.h>

/* Ethernet Shield uses pins 10, 11, 12 and 13 */
#define SWITCH 9

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 253);

unsigned int localPort = 9000; /* port to listen */

char packetBuffer[UDP_TX_PACKET_MAX_SIZE];
char ReplyBuffer[] = "ack\n";

EthernetUDP Udp;

void setup(void) {
    /* relay uses complemented logic, HIGH is OFF */
    pinMode(SWITCH, OUTPUT);
    digitalWrite(SWITCH, HIGH);

    /* Ethernet shield */
    Ethernet.begin(mac, ip);
    Udp.begin(localPort);

    Serial.begin(115200);

    /* configure the IP of the board */
    Serial.println("Bolgh rswtch");

    return;
}

void loop(void) {
    /* if there's data available, read a packet */
    int packetSize = Udp.parsePacket();
    if(packetSize) {
        /* read the packet into packetBufffer */
        Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
        if (!strncmp(packetBuffer, "on\n", 3)) {
            digitalWrite(SWITCH, LOW);
        } else if (!strncmp(packetBuffer, "off\n", 3)) {
            digitalWrite(SWITCH, HIGH);
        }

        /* send a reply, to the IP address and port that sent us the
         * packet we received */
        Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
        Udp.write(ReplyBuffer);
        Udp.endPacket();
    }

    delay(10);
    return;
}

#ifdef __cplusplus
}
#endif
