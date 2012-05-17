CFLAGS=-Wall

default: all

all: server.exe

server.exe: servidor.o
	$(CC) servidor.o -o server.exe

servidor.o: servidor.c
	$(CC) $(CFLAGS) -c servidor.c

clean:
	$(RM) *.o *.exe *.out

