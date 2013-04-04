/*
    Main utility to communicate with Arduino.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <stdlib.h>

#define BUFSIZE 64
#define CMDSIZE 16
#define NUL '\0'
#define PROMPT '>'

void clrstr(char *);

int main(void) {
  int fd1, i, o, aux = 0, strsize, go, j;
  char ibuf[BUFSIZE], fibuf[BUFSIZE];

  const char teststring[CMDSIZE] = "gr\r";
  char processed[CMDSIZE];
  struct termios old;

  if ((fd1 = openport()) < 0) {
    printf("can't open port. check to see if it's being used.\n");
    exit(-1);
  } else {
    printf("port opened, descriptor no. = %d\n\n", fd1);

    /* save old config */
    tcgetattr(fd1, &old);    
    
    if (configport(fd1) < 0) {
      printf("can't configure port\n");
      exit(-1);
    }
  }

  while (1) {
    strsize = strlen(teststring);
    o = write(fd1, teststring, strsize);

    clrstr(ibuf);
    i = read(fd1, ibuf, BUFSIZE);

    printf("a-------------------------------\n");
    printf("i = %d, RECEIVED:\n", i);
    printf("%s", ibuf, i);
    
    /* "regex" */
    for (j = 4; j < BUFSIZE; j++) {
      if (ibuf[j] == 'V') {
	fibuf[j - 4] = NUL;
	break;
      } else {
	fibuf[j - 4] = ibuf[j];
      }
    }

    printf("\nprocessed: %s\n", fibuf);
    printf("\ne-------------------------------\n\n\n\n");

    sleep(1);
  }

  if (tcsetattr(fd1, TCSANOW, &old) < 0)
    printf("can't restore old port config\n");  

  close(fd1);
  exit(0);
}

void clrstr(char *str) {
  int i;

  for (i = 0; i < BUFSIZE; i++)
    str[i] = NUL;
}

int swrite(int fd, const char *str) {
  int len;
  int n;

  len = strlen(str);
  n = write(fd, str, len);

  if (n != len)
    return(-1);
  else
    return(n);
}

int sreaduntil(int fd, char *buf, char until) {
  char b[1];
  int i = 0, n;

  do {
    n = read(fd, b, 1);
    if (n < 0) {
      return(-1);
    } else if (n == 0) {
      usleep(10000);
      continue;
    }

    buf[i] = b[0];
    i++;
  } while (b[0] != until);

  buf[i] = NUL;
  return 0;
}

int openport() {
  int fd;

  fd = open("/dev/ttyU0", O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);

  if (fd < 0) {
    perror("openport: Unable to open /dev/ttyU0\n");
    return(-1);
  } else {
    fcntl(fd, F_SETFL, 0);
    return(fd);
  }
}


int configport(fd) {
  int i;
  struct termios new;

  /*
      When communicating using /dev/ttyU0, these new can be found
    running the following command:

    # stty -f /dev/ttyU0

      This is what you'll find if the utility here are running:

      $ sudo stty -f /dev/ttyU0
      speed 38400 baud;
      lflags: -icanon -isig -iexten -echo echoe echoke echoctl
      iflags: -icrnl ixoff
      oflags: -opost
      cflags: cs8 -parenb clocal
      min
      4
      $
  */
  
  i = fcntl(fd, F_GETFL);
  if (i == -1) {
    perror("fnctl");
  }
  i = fcntl(fd, F_SETFL, i & ~O_NONBLOCK);
  if (i == -1) {
    perror("fnctl");
  }

  tcgetattr(fd, &new);

  cfsetspeed(&new, B38400);

  /* from SerialPort.pm, an CPAN Perl module */
  new.c_cflag &= ~(PARENB | PARODD | CSIZE);
  new.c_cflag &= ~CSTOPB;
  new.c_cflag |= CS8;
  new.c_cflag &= ~CRTSCTS;
  new.c_cflag |= (CREAD | CLOCAL);

  new.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | IGNPAR | INPCK |
		   ISTRIP | INLCR | IGNCR | ICRNL| IXON);

  new.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);

  new.c_oflag &= ~OPOST;
  
  new.c_cc[VTIME] = 20;
  new.c_cc[VMIN] = 0;

  // tcflush(fd, TCIFLUSH);
  if (tcsetattr(fd, TCSANOW, &new) < 0)
    return(-1);

  return(fd);
}
