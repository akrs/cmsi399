CFLAGS=-Wall -march=corei7 -std=c99 -O3
CC=gcc
VPATH = set1

all: breakSingleXOR.o fixedXOR.o hexto64.o utils.o

breakSingleXOR.o: breakSingleXOR.c utils.o
	$(CC) $(CFLAGS) $^ -o $@

fixedXOR.o: fixedXOR.c utils.o
	$(CC) $(CFLAGS) $^ -o $@

hexto64.o: hexto64.c utils.o
	$(CC) $(CFLAGS) $^ -o $@

utils.o: utils.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf *.o
