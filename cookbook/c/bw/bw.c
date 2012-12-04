/* binary writer */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_LIMIT 32

#define YES 1
#define NO 0

int main()
{
  FILE *fd;
  char c, bak;
  int i, pair;

  printf("bw-0.1\n");

  fd = fopen("test.o", "w");

  i = 0;
  printf("=> ");


  for (pair = YES; (c = getchar()) != EOF; )
  {
    if (isalpha(c))
    {
      c = tolower(c);
      c = c - 87;
    } else if (isdigit(c))
      c = c - 48;

    if (pair == YES)
    {
      c = c << 4;
      bak = c;
      pair = NO;
    }
    else if (pair == NO)
    {
      pair = YES;
      bak = bak + c;
      fputc(bak, fd);
    }
  }
  
  /*
  Streams and FILE Objects
  - Unbuffered and buffered?
  - syscall() and stdio.h?

  int fd;

  fd = open("test.o", O_WRONLY | O_CREAT, 644);
  write(fd, "E 46\n0000", 6);
  */

  exit(0);
}
