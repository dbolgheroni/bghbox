/*
 * no threads
 */

#include <stdio.h>

#define TASK 900000000

long int sum = 0;
long int *p;

void dosum() {
  long int lsum = 0;

  for (; lsum < TASK; )
    lsum += 1;

  *p += lsum;
}

int main() {
  p = &sum;

  dosum();

  printf("sum = %d\n", sum);
}
