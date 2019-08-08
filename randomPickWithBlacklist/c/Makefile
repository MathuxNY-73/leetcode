CC=gcc
CFLAGS=-W -Wall -pedantic -std=c11
LDFLAGS=
EXEC=main
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

main: main.o input.o
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
