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

void setup(void) {
    pinMode(2, INPUT_PULLUP);
    pinMode(12, OUTPUT);
    digitalWrite(12, LOW);

    return;
}

void loop(void) {
    if (digitalRead(2) == LOW) {
        digitalWrite(12, HIGH);
    }

    return;
}

#ifdef __cplusplus
}
#endif
