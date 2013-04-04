/* 
   Copyright (c) 2010 Daniel Bolgheroni.
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
   
   1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
   
   2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
   
   THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
   EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
   PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR AND CONTRIBUTORS OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
   
   The views and conclusions contained in the software and documentation
   are those of the authors and should not be interpreted as representing
   official policies, either expressed or implied, of Daniel Bolgheroni.
*/

/*
    Main utility to communicate with Arduino/TCCino.
 */

/* serial related includes */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <stdlib.h>

/* ncurses related includes */
#include <curses.h>

/* serial related defines */
#define BUFSIZE 64
#define STRSIZE 16
#define NUL '\0'

/* ncurses related defines */
#define WVSIZE 4
#define WHSIZE 24

#define COLUMN1 1
#define COLUMN2 26
#define COLUMN3 51

#define LINE1 7
#define LINE2 12
#define LINE3 17

#define XSTATUS 21
#define YSTATUS 14

/* serial related global variables */
int fd1; /* to simplify functions */
char ibuf[BUFSIZE];

char volt[BUFSIZE];
char load[BUFSIZE];
char rpm[BUFSIZE];
char temp[BUFSIZE];

/* ncurses related global variables */
static WINDOW *mainw;

/* 1st. line */
static WINDOW *tempw;
static WINDOW *voltw;
static WINDOW *ethpercw;

/* 2nd. line */
static WINDOW *timemilw;
static WINDOW *dstmilw;
static WINDOW *timeonw;

/* 3rd. line */
static WINDOW *loadw;
static WINDOW *rpmw;
static WINDOW *spdw;

/* serial related functions */
void clrstr(char *str) {
  int i;

  for (i = 0; i < BUFSIZE; i++)
    str[i] = NUL;
}

int openport() {
  int fd;

  fd = open("/dev/cuaU0", O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);

  if (fd < 0) {
    return(-1);
  } else {
    fcntl(fd, F_SETFL, 0);
    return(fd);
  }
}

int configport(fd) {
  int i;
  struct termios new;

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

  /* from SerialPort.pm, a CPAN Perl module */
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

void getvolt() {
  int i, o, j, cmdsize;
  char *cmd = "gv\r";

  cmdsize = strlen(cmd);
  o = write(fd1, cmd, cmdsize);

  clrstr(ibuf);
  i = read(fd1, ibuf, BUFSIZE);  

  /* "regex" */
  for (j = 4; j < BUFSIZE; j++) {
    if (ibuf[j] == 'V') {
      volt[j - 4] = NUL;
      break;
    } else {
      volt[j - 4] = ibuf[j];
    }
  }
}

void gettemp() {
  int i, o, j, cmdsize;
  char *cmd = "gt\r";

  cmdsize = strlen(cmd);
  o = write(fd1, cmd, cmdsize);

  clrstr(ibuf);
  i = read(fd1, ibuf, BUFSIZE);  

  /* "regex" */
  for (j = 4; j < BUFSIZE; j++) {
    if (ibuf[j] == 'o') {
      temp[j - 4] = NUL;
      break;
    } else {
      temp[j - 4] = ibuf[j];
    }
  }
}  

void getload() {
  int i, o, j, cmdsize;
  char *cmd = "gl\r";

  cmdsize = strlen(cmd);
  o = write(fd1, cmd, cmdsize);

  clrstr(ibuf);
  i = read(fd1, ibuf, BUFSIZE);  

  /* "regex" */
  for (j = 4; j < BUFSIZE; j++) {
    if (ibuf[j] == '%') {
      load[j - 4] = NUL;
      break;
    } else {
      load[j - 4] = ibuf[j];
    }
  }
}  

void getrpm() {
  int i, o, j, cmdsize;
  char *cmd = "gr\r";

  cmdsize = strlen(cmd);
  o = write(fd1, cmd, cmdsize);

  clrstr(ibuf);
  i = read(fd1, ibuf, BUFSIZE);  

  /* "regex" */
  for (j = 4; j < BUFSIZE; j++) {
    if (ibuf[j] == 'r') {
      rpm[j - 4] = NUL;
      break;
    } else {
      rpm[j - 4] = ibuf[j];
    }
  }
}  

/* ncurses related functions */
void initscreen(void) {
  mainw = initscr();
  noecho();
  cbreak();
  nodelay(mainw, TRUE);

  wrefresh(mainw);

  printw("*** nTCCino-20101209 (ncurses-based interface for TCCino) ***\n\n"

	 "FEI - Faculdade de Engenharia Industrial\n"
	 "Trabalho de Conclusão de Curso, Apresentação: 10/12/2010\n");
  hline(ACS_HLINE, 61);

  mvprintw(6, 1, "Monitoring");
  mvprintw(11, 1, "Malfunction Indication Lamp (MIL)");
  mvprintw(16, 1, "Run");

  mvprintw(21, 1, "LAST STATUS: ");
}

static void updatedisplay(void) {
  curs_set(0);

  /* Monitoring */
  tempw = newwin(WVSIZE, WHSIZE, LINE1, COLUMN1);
  box(tempw, ACS_VLINE, ACS_HLINE);
  mvwprintw(tempw, 1, 1, "Temperature (oC)");
  mvwprintw(tempw, 2, 1, "%s", temp);

  voltw = newwin(WVSIZE, WHSIZE, LINE1, COLUMN2);
  box(voltw, ACS_VLINE, ACS_HLINE);
  mvwprintw(voltw, 1, 1, "Battery Volt. (V)");
  mvwprintw(voltw, 2, 1, "%s", volt);

  ethpercw = newwin(WVSIZE, WHSIZE, LINE1, COLUMN3);
  box(ethpercw, ACS_VLINE, ACS_HLINE);
  mvwprintw(ethpercw, 1, 1, "Ethanol Perc. (%%)");

  /* Malfunction Indication Lamp (MIL) */
  timemilw = newwin(WVSIZE, WHSIZE, LINE2, COLUMN1);
  box(timemilw, ACS_VLINE, ACS_HLINE);
  mvwprintw(timemilw, 1, 1, "Time MIL On (min)");

  dstmilw = newwin(WVSIZE, WHSIZE, LINE2, COLUMN2);
  box(dstmilw, ACS_VLINE, ACS_HLINE);
  mvwprintw(dstmilw, 1, 1, "Distance MIL On (min)");

  timeonw = newwin(WVSIZE, WHSIZE, LINE2, COLUMN3);
  box(timeonw, ACS_VLINE, ACS_HLINE);
  mvwprintw(timeonw, 1, 1, "Time Run (min)");

  /* Run */
  loadw = newwin(WVSIZE, WHSIZE, LINE3, COLUMN1);
  box(loadw, ACS_VLINE, ACS_HLINE);
  mvwprintw(loadw, 1, 1, "Load (%%)");
  mvwprintw(loadw, 2, 1, "%s", load);

  rpmw = newwin(WVSIZE, WHSIZE, LINE3, COLUMN2);
  box(rpmw, ACS_VLINE, ACS_HLINE);
  mvwprintw(rpmw, 1, 1, "RPM (rpm)");
  mvwprintw(rpmw, 2, 1, "%s", rpm);

  spdw = newwin(WVSIZE, WHSIZE, LINE3, COLUMN3);
  box(spdw, ACS_VLINE, ACS_HLINE);
  mvwprintw(spdw, 1, 1, "Speed (km/h)");

  wrefresh(tempw);
  wrefresh(voltw);
  wrefresh(ethpercw);

  wrefresh(timeonw);
  wrefresh(timemilw);
  wrefresh(dstmilw);

  wrefresh(loadw);
  wrefresh(rpmw);
  wrefresh(spdw);

  refresh();
}

int main(void) {
  int cmd, quit = 0;

  initscreen();
  
  /* open port */
  if((fd1 = openport()) < 0) {
    mvprintw(XSTATUS, YSTATUS, "can't open port. Quit and try again.");
  } else {
    mvprintw(XSTATUS, YSTATUS, "port opened, descriptor no. = %d", fd1);

    if (configport(fd1) < 0)
      mvprintw(XSTATUS, YSTATUS, "can't configure port. Quit and try again.");
  }

  while (!quit) {
    cmd = getch();
    
    if ((cmd == 27) || (cmd == 'q')) { /* 27 = esc */
      quit = 1;
    }

    // getvolt();
    // gettemp();
    // getload();
    getrpm();

    updatedisplay();
    // sleep(1); /* update 1x/s */
    usleep(500 * 1000);
  }
  
  endwin();
  close(fd1);
  printf("Thank you for using nTCCino. Problems? dbolgheroni@gmail.com.\n");
  return(0);
}
