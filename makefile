CC=gcc
CFLAGS=-Wall -Wextra -std=c99
LDFLAGS=-lSDL -lSDL_image

all: prog

prog: entity.o main.o
	$(CC) entity.o main.o -o prog $(LDFLAGS)

entity.o: entity.c entity.h
	$(CC) -c entity.c -o entity.o $(CFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o prog
