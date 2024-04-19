CC=cc
OPT=-O0 -ggdb3
CFLAGS=$(OPT) `pkg-config --cflags libmongoc-1.0`
LDFLAGS=`pkg-config --libs libmongoc-1.0`

example: main.c
	$(CC) -o example main.c $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f example
	rm -f *.o
