#include <stdio.h>
#include <wchar.h>

int main() {
    const char *t = "test";
    const wchar_t *u = "\xc3\xa7";

    printf("%s\n", t);
    //wprintf("%s\n", s);

    return 0;
}
