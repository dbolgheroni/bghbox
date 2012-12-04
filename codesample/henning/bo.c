/*
 * trying to buffer overflow
 */

#include <string.h>
#include <stdio.h>

void func(char *str) {
  char buffer[16];
  strcpy(buffer, str);
}

int main() {
  char c;
  char *s = "short string";
  func(s);

  c = getchar();

  return 0;
}
