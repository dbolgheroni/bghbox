/* compile this with -DTEST */

#include <stdio.h>

int main() {
  
#ifdef TEST
    printf("TEST defined at compile time\n");
#else
    printf("TEST *not* defined at compile time\n");
#endif

    return 0;
}
