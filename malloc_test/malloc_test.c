#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *f;

    /* runtime allocation */
    char *b = (char *)malloc(3072);

    f = fopen("loremipsum.txt", "r");

    if (!fread(b, 3073, 1, f)) {
        fprintf(stderr, "error reading loremipsum masterpiece\n");

        return 1;
    }

    return 0;
}
