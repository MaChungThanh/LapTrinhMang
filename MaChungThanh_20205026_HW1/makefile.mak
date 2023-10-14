CC = gcc
CFLAGS = -Wall

all: main

main: main.c menu.o login.o log.o
	$(CC) $(CFLAGS) -o main main.c menu.o login.o log.o

menu.o: menu.c menu.h account.h
	$(CC) $(CFLAGS) -c menu.c

login.o: login.c account.h
	$(CC) $(CFLAGS) -c login.c

log.o: log.c account.h
	$(CC) $(CFLAGS) -c log.c

clean:
	rm -f main menu.o login.o log.o