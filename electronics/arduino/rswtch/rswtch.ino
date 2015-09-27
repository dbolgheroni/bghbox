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
#define CH1 12
#define CH2 11
#define CH3 10

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

    /* initialize serial code */
    Serial.begin(115200);

    /* wait for serial to initialize */
    delay(1000);

    /* present itself */
    Serial.println("Bolgh rswtch");
    Serial.print("> ");

    inputStr.reserve(72);

    return;
}

void loop(void) {
    boolean found = false;
    serialEvent();

    if (strComplete) {
        /* check if the command exists and call the appropriate func if
         * found, passing the channel number as argument */
        for (int i = 0; i < ncmd; i++) {
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
