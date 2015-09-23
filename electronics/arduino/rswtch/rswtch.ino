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

#define BOARDLED 13
#define PS1 12
#define PS2 11
#define PS3 10

#define NCMD 32

String inputStr = "";
boolean strComplete = false;

void serialEvent();

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

    /* wait 1,5 seconds to fully discharge */
    delay(1500);

    digitalWrite(ch, HIGH);
}

struct cmd {
    String name;
    int ch;
    void (*func)(int ch);
} cmdlist[] = {
    { "u1", PS1, up_channel     },
    { "u2", PS2, up_channel     },
    { "u3", PS3, up_channel     },
    { "d1", PS1, down_channel   },
    { "d2", PS2, down_channel   },
    { "d3", PS3, down_channel   },
    { "t1", PS1, toggle_channel },
    { "t2", PS2, toggle_channel },
    { "t3", PS3, toggle_channel },
    { "r1", PS1, reset_channel  },
    { "r2", PS2, reset_channel  },
    { "r3", PS3, reset_channel  }
};

void setup(void) {
    /* initialize pins */
    pinMode(BOARDLED, OUTPUT);
    pinMode(PS1, OUTPUT);
    pinMode(PS2, OUTPUT);

    /* turn off board led, use it to debug error */
    digitalWrite(BOARDLED, LOW);

    /* on by default */
    digitalWrite(PS1, HIGH);
    digitalWrite(PS2, HIGH);

    /* initialize serial code */
    Serial.begin(115200);

    /* wait for serial to initialize */
    delay(1000);

    /* present itself */
    Serial.println("rswtch");
    Serial.print("> ");

    inputStr.reserve(72);

    return;
}

void loop(void) {
    boolean found = 0;
    serialEvent();

    if (strComplete) {
        for (int i = 0; i <= NCMD; i++) {
            /* check if the command exists and call appropriate func if
             * found */
            if (cmdlist[i].name + '\r' == inputStr) {
                (*cmdlist[i].func)(cmdlist[i].ch);
                found = true;
                break;
            }
        }

        if (found) {
            Serial.println("ok");
            found = false;
        } else {
            Serial.println("error");
        }

        Serial.print("> ");

        inputStr = "";
        strComplete = false;
    }

    return;
}

void serialEvent() {
    while (Serial.available()) {
        char inChar = (char)Serial.read();
        inputStr += inChar;

        Serial.print(inChar);

        /* do not work with '\n' */
        if (inChar == '\r') {
            strComplete = true;
            Serial.println();
        }
    }
}

#ifdef __cplusplus
}
#endif
