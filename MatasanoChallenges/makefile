CFLAGS=-Wall -march=corei7 -std=c99
CC=clang
VPATH = set1

all: detectSingleXOR.o breakSingleXOR.o fixedXOR.o hexto64.o utils.o

detectSingleXOR.o: detectSingleXOR.c utils.o
	$(CC) $(CFLAGS) $^ -o $@

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
	rm -rf *.dSYM
