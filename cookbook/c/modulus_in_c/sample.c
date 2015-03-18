#include <stdio.h>

int main() {
    unsigned int r;

    // Diego Aranha (MO421) slide example
    r = 101 % 7; // should be 3
    printf("r = %d\n", r);

    r = -101 % 7; // should be 4 in some dialects
    printf("r = %d\n", r);

    return 0;
}
