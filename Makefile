CC=cc
STD=-std=c99
OPT=-O0 -ggdb3
WARN=-Wall -Wextra -Wpedantic
CFLAGS=$(OPT) $(STD) $(WARN) `pkg-config --cflags libmongoc-1.0`
LDFLAGS=`pkg-config --libs libmongoc-1.0`

example: main.c
	$(CC) -o example main.c $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f example
	rm -f *.o
