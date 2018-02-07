CC=gcc
CFLAGS=-O3 -march=native
LIBS=-lm
OBJS=test1.o test2.o

all: test1 test2

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

test1: test1.o
	$(CC) test1.o -o test1 $(LIBS)

test2: test2.o
	$(CC) test2.o -o test2 $(LIBS)

clean:
	rm $(OBJS) test1 test2
