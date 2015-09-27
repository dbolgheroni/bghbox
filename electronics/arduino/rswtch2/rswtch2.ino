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
#define BOARDLED 13
#define CH1 9
#define CH2 8
#define CH3 7

#define NCMD 32

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 253);

unsigned int localPort = 9000; /* port to listen */

char packetBuffer[UDP_TX_PACKET_MAX_SIZE];
String packetStr;
char okMsg[] = "ok\n";
char errorMsg[] = "error\n";

EthernetUDP Udp;

void up_channel(int ch) {
    digitalWrite(ch, HIGH);
}

void down_channel(int ch) {
    digitalWrite(ch, LOW);
}

void toggle_channel(int ch) {
    if (digitalRead(ch) == LOW)
        digitalWrite(ch, HIGH);
    else
        digitalWrite(ch, LOW);
}

void reset_channel(int ch) {
    digitalWrite(ch, LOW);

    /* wait 1.5 seconds to fully discharge */
    delay(1500);

    digitalWrite(ch, HIGH);
}

struct cmd {
    String name;
    int ch;
    void (*func)(int ch);
} cmdlist[] = {
    { "u1", CH1, up_channel     },
    { "u2", CH2, up_channel     },
    { "u3", CH3, up_channel     },
    { "d1", CH1, down_channel   },
    { "d2", CH2, down_channel   },
    { "d3", CH3, down_channel   },
    { "t1", CH1, toggle_channel },
    { "t2", CH2, toggle_channel },
    { "t3", CH3, toggle_channel },
    { "r1", CH1, reset_channel  },
    { "r2", CH2, reset_channel  },
    { "r3", CH3, reset_channel  }
};

int ncmd = sizeof(cmdlist)/sizeof(struct cmd);

void setup(void) {
    /* initialize pins */
    pinMode(BOARDLED, OUTPUT);
    pinMode(CH1, OUTPUT);
    pinMode(CH2, OUTPUT);
    pinMode(CH3, OUTPUT);

    /* turn off board led, use it to debug error */
    digitalWrite(BOARDLED, LOW);

    /* on by default */
    digitalWrite(CH1, HIGH);
    digitalWrite(CH2, HIGH);
    digitalWrite(CH3, HIGH);

    /* Ethernet shield */
    Ethernet.begin(mac, ip);
    Udp.begin(localPort);

    Serial.begin(115200);

    /* configure the IP of the board */
    Serial.println("Bolgh rswtch");

    return;
}

void loop(void) {
    boolean found = false;

    /* if there's data available, read a packet */
    int packetSize = Udp.parsePacket();
    if (packetSize) {
        /* read the packet into packetBufffer */
        Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);

        /* leverage String from Arduino */
        packetStr = packetBuffer;

        /* check if the command exists and call the appropriate func if
         * found, passing the channel number as argument */
        for (int i = 0; i < ncmd; i++) {
            if (cmdlist[i].name + '\n' == packetStr) {
                (*cmdlist[i].func)(cmdlist[i].ch);
                found = true;
                break;
            }
        }

        /* send a reply, to the IP address and port that sent us the
         * packet we received */
        Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
        if (found) {
            Udp.write(okMsg);
            found = false;
        } else {
            Udp.write(errorMsg);
        }
        Udp.endPacket();

    }

    delay(10);
    return;
}

#ifdef __cplusplus
}
#endif
