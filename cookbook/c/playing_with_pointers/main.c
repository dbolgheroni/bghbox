#include <stdio.h>

int main(void) {
    int i = 888;
    int *pi;
    typedef struct data {
        int i;
    } data;

    data d;
    d.i = 666;
    printf("%d\n", d.i);

    data *p = &d;
    p->i = 777;
    printf("%d\n", p->i);

    pi = &i;
    printf("i = %d; *pi = %d\n", i, *pi);

    /* modifying i through pi */
    *pi = 999;
    printf("i = %d; *pi = %d\n", i, *pi);

    return 0;
}
