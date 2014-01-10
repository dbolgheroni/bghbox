/* PiL 2, p. 259 */

#include <limits.h>
#include <stdio.h>

#define BITS_PER_WORD   (CHAR_BIT*sizeof(unsigned int))
#define I_WORD(i)       ((unsigned int)(i) / BITS_PER_WORD)
#define I_BIT(i)        (1 << ((unsigned int)(i) % BITS_PER_WORD))

int main() {
    typedef struct NumArray {
        int size;
        unsigned int values[1]; /* variable part */
    } NumArray;

    printf("CHAR_BIT = %d\n", CHAR_BIT);
    printf("sizeof(unsigned int) = %d\n", sizeof(unsigned int));
    printf("BITS_PER_WORD = %d\n", BITS_PER_WORD);

    /* size for an array with n elements */
    int n;
    size_t nbytes;

    printf("\nsizeof(NumArray) = %d\n", sizeof(NumArray));
    printf("sizeof(unsigned int) = %d\n", sizeof(unsigned int));
    printf("nbytes = sizeof(NumArray) + I_WORD(n - 1)*sizeof(unsigned int)\n");
    /* 33 (just to see the change */
    for (n=1; n <= 33; n++) {
        nbytes = sizeof(NumArray) + I_WORD(n - 1)*sizeof(unsigned int);
        printf("(n = %03d) I_WORD(n - 1) = %d; nbytes = %d\n",
                n, I_WORD(n - 1), nbytes);
    }
}
