#include <stdio.h>

int main() {
    unsigned char str[1024];
    unsigned char *p;
    unsigned char uch;

    int i = 0;
    char ch;

    FILE *in;
    in = fopen("in.txt", "r"); /* no checks */

    /* read file */
    p = str;
    while ((ch = getc(in)) != EOF) {
        printf("....char: %c\n..signed: %02x\n", ch, ch);
        uch = (unsigned)ch;
        printf("unsigned: %02x\n\n", uch);
        *p++ = uch;
    }
    *p = '\0';

    fclose(in);

    printf("str: %s", str);
}
