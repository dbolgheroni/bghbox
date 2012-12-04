#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/* how fork(2) works, run together with top(1) */

int
main() {
  char c;
  pid_t fork();

  printf("new process? (n)o, (y)es: ");
  c = getchar();
  switch(c) {
  case 'n':
    break;
  case 'y':
    fork();
    wait();
    break;
  default:
    printf("error! invalid option.\n");
    break;
  }

  c = getchar();
  c = getchar();
}
