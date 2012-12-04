/*
 * 3 different threads
 */

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define TASK 300000000

long int sum = 0;
long int *p;

void *
first_thr() {
  long int lsum = 0;

  for (; lsum < TASK; ) {
    lsum += 1;
  }

  *p += lsum;
  printf("partial from thread 1\n");
  printf("lsum = %d; *p = %d\n\n", lsum, *p);
  pthread_exit((void *)0);
}

void *
second_thr() {
  long int lsum = 0;

  for (; lsum < TASK; ) {
    lsum += 1;
  }

  *p += lsum;
  printf("partial from thread 2\n");
  printf("lsum = %d; *p = %d\n\n", lsum, *p);
  pthread_exit((void *)0);
}

void *
third_thr() {
  long int lsum = 0;

  for (; lsum < TASK; ) {
    lsum += 1;
  }

  *p += lsum;
  printf("partial from thread 3\n");
  printf("lsum = %d; *p = %d\n\n", lsum, *p);
  pthread_exit((void *)0);
}

int main() {
  char c;
  int err;
  pthread_t tid1, tid2, tid3;

  p = &sum;

  err = pthread_create(&tid1, NULL, first_thr, NULL);
  if (err != 0)
    printf("can't create thread 1: %s\n", strerror(err));
  else
    printf("thread 1 created\n");

  err = pthread_create(&tid2, NULL, first_thr, NULL);
  if (err != 0)
    printf("can't create thread 2: %s\n", strerror(err));
  else
    printf("thread 2 created\n");

  err = pthread_create(&tid3, NULL, first_thr, NULL);
  if (err != 0)
    printf("can't create thread 2: %s\n", strerror(err));
  else
    printf("thread 3 created\n");


  printf("sum = %d\n", sum);
}
  
