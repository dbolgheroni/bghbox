/*
 * 3 instances of the same thread
 */

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define TASK 300000000

long int sum;
long int *p;

void *
u_thr() {
  long int lsum = 0;

  for (; lsum < TASK; ) {
    lsum += 1;
  }

  *p += lsum;
  printf("partial from thread with tid %d\n", pthread_self());
  printf("lsum = %d; *p = %d\n\n", lsum, *p);
  pthread_exit((void *)0);
}

int main() {
  char c;
  int err;
  pthread_t tid1, tid2, tid3;

  p = &sum;

  err = pthread_create(&tid1, NULL, u_thr, NULL);
  if (err != 0)
    printf("can't create thread 1: %s\n", strerror(err));

  err = pthread_create(&tid2, NULL, u_thr, NULL);
  if (err != 0)
    printf("can't create thread 2: %s\n", strerror(err));

  err = pthread_create(&tid3, NULL, u_thr, NULL);
  if (err != 0)
    printf("can't create thread 3: %s\n", strerror(err));

  c = getchar();

  printf("sum = %d\n", sum);
}
  
