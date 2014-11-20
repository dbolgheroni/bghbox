TARGET=lesson1

UPLOAD_RATE=57600
#UPLOAD_RATE=19200
PORT=/dev/cuaU0
PROGRAMMER=avrisp
MCU=m328p
#MCU=m8

F_CPU = 16000000

CC = avr-gcc
OBJCOPY = avr-objcopy
SIZE = avr-size
CDEFS = -DF_CPU=$(F_CPU)
#CFLAGS = -g -mmcu=atmega328p -Os
CFLAGS = -g -mmcu=atmega328p -Os

OBJCOPYFLAGS = -j .text -j .data -O ihex

.SUFFIXES: .c .o .hex

all: build size
build: obj hex

obj: $(TARGET).o
hex: $(TARGET).hex

.c.o:
	$(CC) -c $(CFLAGS) $(CDEFS) -o$@ $<

.o.hex:
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

size: build
	$(SIZE) $(TARGET).o

upload: build
	avrdude -b$(UPLOAD_RATE) -P$(PORT) -c$(PROGRAMMER) -p$(MCU) -U flash:w:$(TARGET).hex

clean:
	rm -f *.o *.hex
