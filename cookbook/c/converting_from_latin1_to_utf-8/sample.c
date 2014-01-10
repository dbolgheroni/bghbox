#include <stdio.h>

int main() {
    char ch;
    char str[1024];
    unsigned char *in, *out;
    int i = 0;

    FILE *fp;
    fp = fopen("latin1.txt", "r");

    while ((ch = getc(fp)) != EOF) {
        printf("read \"%X\"\n", ch);
        str[i] = ch;
        i++;
    }
    str[i] = '\0';
    printf("str: %s\n", str);

    in = str;
    while (*in)
        if (*in<128) *out++=*in++;
        else *out++=0xc2+(*in>0xbf), *out++=(*in++&0x3f)+0x80;
}
