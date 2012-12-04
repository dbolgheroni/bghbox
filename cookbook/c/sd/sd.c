/* structures dump */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
  char c;

  int i, *j;
  int i_def = 2;
  int *boo;
 
  puts("structures dump 0.01");

  j = &i;
  printf("address: %p\n", &i);

  boo = (void *)0xcfbd7684;
  printf("test: %p\n", boo);

  getc(stdin);
  exit(0);
}
