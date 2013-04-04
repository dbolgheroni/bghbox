/*
 * Copyright (c) 2010, Daniel Bolgheroni.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR AND CONTRIBUTORS OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation
 * are those of the authors and should not be interpreted as representing
 * official policies, either expressed or implied, of Daniel Bolgheroni.
 */

/*
 * Sketch for interfacing Arduino with ELM327.
 * Trabalho de Conclusao de Curso - TCC
 *
 * ALUNOS:
 * Daniel Bolgheroni 11.106.584-3
 * Felipe Eduardo    11.105.037-
 * Ralph Ikejiri     11.
 *
 * SOME NOTES:
 * - Arduino buffer for serial is 64 bytes long;
 * - I'm trying to fully document all code;
 * - This code is licensed by the license described above, which is
 *   pretty, pretty permissive. 
 *
 * BUGS SO FAR:
 * - can't type unvalid unique character command
 */

#include <string.h>

/* if defined, need a change in BSDmakefile to:
MCU=atmega2560
AVRDUDE_PROGRAMMER = stk500v2
UPLOAD_RATE = 115200 */
// #define MEGA2560

#ifndef MEGA2560
#define ASERIAL elm327 /* Alternative SERIAL */
#include <NewSoftSerial.h>
#else
#define ASERIAL Serial1
#endif

#define NUL '\0'
#define CR '\r' /* Carriage Return */
#define PROMPT '>'

#define NCMD 10 /* number of commands */
#define BUFSIZE 16

#define READ_A 0
#define READ_AB 1

/* hint from http://www.arduino.cc/playground/OpenBSD/CLI */
extern "C" void __cxa_pure_virtual(void) {
  while(1);
}

/* +------+-----------+
 * | PID  | Modify    | (A and B are global variables set by some funcs,
 * +------+-----+-----+  e.g. read.)
 * | 0104 |  A  |     |
 * | 0105 |  A  |     |
 * | 010C |  A  |  B  |
 * | 010D |  A  |     |
 * | 011F |  A  |  B  |
 * | 0121 |  A  |  B  |
 * | 014D |  A  |  B  |
 * | 0152 |  A  |     |
 * +------+-----+-----+
 */

char cmdbuf[BUFSIZE];

int pflag; /* prompt flag */
int i, found;

char elmrx[BUFSIZE];
char *e, *p;

char Ah[3], Bh[3];
int Ad = 0, Bd = 0;

int hex2dec(char *);
int read(char *, int);
void sendc(char *); /* send commands, ATs or PIDs */

/* update NCMD if you add or remove functions */
int getload(void);    /* PID 0104, Calculated engine load value */
int gettemp(void);    /* PID 0105, Engine coolant temperature */
int getrpm(void);     /* PID 010C, Engine RPM */
int getspd(void);     /* PID 010D, Vehicle speed */
int getton(void);  /* PID 011F, Run time since engine start */
int getdmil(void);  /* PID 0121, Distance traveled with MIL on */
int gettmil(void); /* PID 014D, Time run with MIL on */
int geteperc(void); /* PID 0152, Ethanol fuel % */
int getvolt(void);    /* ATRV, from ELM327 */
int help(void);       /* internal function */

const struct cmd {
  const char *name;
  const char *sname; // short name
  int (*func)();
} cmds[] = {
  { "getload",    "gl",  getload    },
  { "gettemp",    "gt",  gettemp    },
  { "getrpm",     "gr",  getrpm     },
  { "getspd",     "gs",  getspd     },
  { "getton",     "gto", getton     },
  { "getdmil",    "gdm", getdmil    },
  { "gettmil",    "gtm", gettmil    },
  { "geteperc",   "gep", geteperc   },
  { "getvolt",    "gv",  getvolt    },
  { "help",       "h",   help       }
};

/* an entry in BSDmakefile was needed
                      +------> receive pin
                      |  +---> transmit pin
                      |  |                */
#ifndef MEGA2560
NewSoftSerial ASERIAL(3, 2);
#endif

void setup() {
  Serial.begin(38400);
  ASERIAL.begin(38400);

  Serial.flush();
  ASERIAL.flush();
    
  p = cmdbuf;
  e = elmrx;

  found = 1;
  pflag = 0;

  Serial.println("TCCino v0.1");
  Serial.print("Initializing ELM327...");
  ASERIAL.println("ATE0"); /* disable echo */
  ASERIAL.println("ATZ");
  delay(500);
  Serial.println(" done.");    
  ASERIAL.flush();
}

void loop() {
  if (!pflag) {
    Serial.print("> ");
    pflag = 1;
  }

  if (Serial.available() > 0) {
    *p = Serial.read();

    if (*p == '\r') {
      *p = NUL;
      Serial.print("\n\r");
   
      p = cmdbuf;
      pflag = 0;

      found = 1;
      for(i = 0; i <= NCMD; i++) {
	if(!strcmp(cmds[i].name, cmdbuf) ||
	   !strcmp(cmds[i].sname, cmdbuf)) {
	  found = (*cmds[i].func)();
	  break;
	}
      }
      
      Serial.flush();

      if (found == 1)
	Serial.println("command not found, try \"h\" for help");

    } else {
      Serial.print(*p); /* echo */
      p++;
      *p = NUL;
    }
  }
}

void sendc(char *lp) {
  ASERIAL.println(lp);
  delay(100);

  while ((*e = ASERIAL.read()) != PROMPT) {
    if (*e >= ' ')
      e++;
  }

  *e = NUL;
  e = elmrx;
  Serial.println(elmrx);

  ASERIAL.flush();
  Serial.flush();
}

/* to read A or (A & B)                                               */
/* return value: none (global vars Ah, Ad, Bh and Bh can be modified) */
/* (to avoid passing structures and simplify the code                 */
int read(char *lp, int what) {
  int rvalue;

  ASERIAL.println(lp);
  delay(100);

  while ((*e = ASERIAL.read()) != PROMPT) {
    if (*e >= ' ')
      e++;
  }

  *e = NUL;
  e = elmrx;

  if (*e == '4' || *e == '7') {
    if (what == READ_A) {
      Ah[0] = elmrx[6];
      Ah[1] = elmrx[7];
      Ah[2] = '\0';

      Ad = hex2dec(Ah);
    } else if (what == READ_AB) {
      Ah[0] = elmrx[6];
      Ah[1] = elmrx[7];
      Ah[2] = '\0';

      Bh[0] = elmrx[9];
      Bh[1] = elmrx[10];
      Bh[2] = '\0';

      Ad = hex2dec(Ah);
      Bd = hex2dec(Bh);
    }

    return 0;
  } else {
    return -1;
  }
}

/* no need of an external hexadecimal to decimal function */
int hex2dec(char *lp) {
  int i, sum = 0, mul;

  for (i = 1; i >= 0; i--, lp++) {
    mul = 16 * i;
    if (i == 0)
      mul = 1;

    switch(*lp) {
    case '0':
      sum += 0 * mul;
      break;
    case '1':
      sum += 1 * mul;      
      break;
    case '2':
      sum += 2 * mul;
      break;
    case '3':
      sum += 3 * mul;
      break;
    case '4':
      sum += 4 * mul;
      break;
    case '5':
      sum += 5 * mul;
      break;
    case '6':
      sum += 6 * mul;
      break;
    case '7':
      sum += 7 * mul;
      break;
    case '8':
      sum += 8 * mul;
      break;
    case '9':
      sum += 9 * mul;
      break;
    case 'A':
      sum += 10 * mul;
      break;
    case 'B':
      sum += 11 * mul;
      break;
    case 'C':
      sum += 12 * mul;
      break;
    case 'D':
      sum += 13 * mul;
      break;
    case 'E':
      sum += 14 * mul;
      break;
    case 'F':
      sum += 15 * mul;
      break;
    } /* switch */
  } /* for */ 

  return sum;
}

int getload() {
  float rvalue;

  if (read((char *)"0104", READ_A) < 0) {
    Serial.print("-");
  } else {
    rvalue = (Ad * 100) / 255;
    Serial.print(rvalue, 1);
  }
  Serial.println("%");

  return 0;
}

int getvolt() {
  sendc((char *)"ATRV");

  return 0;
}

int gettemp() {
  int rvalue; /* real value, after formula */

  /* "or" char cmd[] = "0105"; read(cmd, READ_A); */
  if (read((char *)"0105", READ_A) < 0) {
    Serial.print("-");
  } else {
    rvalue = Ad - 40;
    Serial.print(rvalue);
  }
  Serial.println("oC");

  return 0;
}

int getrpm() {
  int rvalue;

  if (read((char *)"010C", READ_AB) < 0) {
    Serial.print("-");
  } else {
    rvalue = ((Ad * 256) + Bd) / 4;
    Serial.print(rvalue);
  }
  Serial.println("rpm");

  return 0;
}

int getspd() {
  int rvalue;

  if (read((char *)"010D", READ_A) < 0) {
    Serial.print("-");
  } else {
    rvalue = Ad;
    Serial.print(rvalue);
  }
  Serial.println("km/h");

  return 0;
}

int getton() {
  float rvalue;

  if (read((char *)"011F", READ_AB) < 0) {
    Serial.print("-");
  } else {
    rvalue = ((Ad * 256) + Bd) / 60;
    Serial.print(rvalue, 1);
  }
  Serial.println("min");

  return 0;
}

int getdmil() {
  Serial.println("not implemented yet");

  return 0;
}

int gettmil() {
  Serial.println("not implemented yet");

  return 0;
}

int geteperc() {
  float rvalue;

  if (read((char *)"0152", READ_A) < 0) {
    Serial.print("-");
  } else {
    rvalue = (Ad * 100) / 255;
    Serial.print(rvalue, 1);
  }
  Serial.println("%");

  return 0;
}

int help() {
  Serial.println("+---------------------------------------------------+");
  Serial.println("| TCCino v0.1 HELP SECTION                          |");
  Serial.println("+------------------+--------------------------------+");
  Serial.println("| command (alias)  | description (what it shows)    |");
  Serial.println("+------------------+--------------------------------+");
  Serial.println("| getload (gl)     | calculated engine load value   |");
  Serial.println("| gettemp (gt)     | engine coolant temperature     |");
  Serial.println("| getrpm  (gr)     | engine RPM                     |");
  Serial.println("| getspd  (gs)     | vehicle speed                  |");
  Serial.println("| getton  (gto)    | run time since engine start    |");
  Serial.println("| getdmil (gdm)    | distance traveled with MIL* on |");
  Serial.println("| gettmil   (gtm)  | shows time run with MIL* on    |");
  Serial.println("| geteperc (gep)   | shows ethanol fuel %           |");
  Serial.println("| getvolt (gv)     | shows voltage                  |");
  Serial.println("| help (h)         | shows this help                |");
  Serial.println("+------------------+--------------------------------+");
  Serial.println("| Copyright (c) 2010, Daniel Bolgheroni.            |");
  Serial.println("+---------------------------------------------------+");

  return 0;
}
