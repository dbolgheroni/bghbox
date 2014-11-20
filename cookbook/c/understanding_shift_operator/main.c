#include <stdio.h>

int main(void) {
    int x = 1;

    printf("int x = 1; sizeof(int) = %d\n", sizeof(int));
    printf("x << 1 = %d\n", x << 1);
    printf("x << 2 = %d\n", x << 2);
    printf("x << 3 = %d\n", x << 3);

    printf("x >> 1 = %d\n", x >> 1);
}
