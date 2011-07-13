CC = gcc
CFLAGS = -Wall -g -O0 `pkg-config --cflags gtk+-3.0 gmodule-2.0`
LIBS = `pkg-config --libs gtk+-3.0 gmodule-2.0`
LDFLAGS = -g

SRCS = \
	baka.h baka.c \
	interface.h interface.c \
	menu.h menu.c

OBJS = \
	baka.o \
	interface.o \
	menu.o

all: baka

baka: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)

baka.o: baka.c baka.h interface.h
interface.o: interface.c interface.h baka.h
menu.o: menu.c menu.h baka.h

%.o:
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	-rm -f baka *.o

.PHONY: all clean
