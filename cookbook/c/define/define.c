#include "header.h"

int main() {
  
#ifdef TEST
  printf("TEST defined.\n");
#else
  printf("TEST not defined.\n");
#endif

  return 0;
}
