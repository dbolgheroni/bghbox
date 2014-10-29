#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/gpio.h>
#include <sys/ioctl.h>

int devfd = -1;

int main() {
    /* pin 3 of the P8 pinout is gpio1[6] according to
     * http://elinux.org/Beagleboard:Cape_Expansion_Headers */

    struct gpio_pin_op op;
    bzero(&op, sizeof(op));

    op.gp_pin = 6;
    op.gp_value = GPIO_PIN_LOW;

    /* open descriptor */
    if ((devfd = open("/dev/gpio1", O_RDWR)) == -1)
        err(1, "%s", "/dev/gpio1");

    for (;;) {
	if (ioctl(devfd, GPIOPINTOGGLE, &op) == -1)
	    err(1, "GPIOPINTOGGLE");

        sleep(1);
    }
}

