/* p. 27, A Subtle Bug */

#include <stdio.h>

int array[] = { 23, 34, 12, 17, 204, 99, 16 };
#define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))

main() {
    // printf ("%d\n", sizeof(array));
    printf ("%d\n", TOTAL_ELEMENTS); 
 
    int d = -1, x;
    printf ("%d\n", d);

    if (d <= TOTAL_ELEMENTS - 2) {
        printf ("in if...\n");
    }
}
