CC = gcc
CFLAGS = -Wall -Wextra

all: lista_meu

lista_meu: main.o lista.o
	$(CC) $(CFLAGS) -o lista_meu main.o lista.o

main.o: main.c lista.h
	$(CC) $(CFLAGS) -c -o main.o main.c 

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c -o lista.o lista.c

clean:
	rm -f lista_meu main.o lista.o
