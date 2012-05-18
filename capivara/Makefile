CC=clang
CFLAGS=-Wall
OBJETOS=main.o servidor.o conexao.o view.o injetor.o memoria.o \
	registrar.o

default: all

all: server.exe
	./server.exe

valgrind: server.exe
	valgrind --leak-check=full ./server.exe

server.exe: $(OBJETOS)
	$(CC) $(OBJETOS) -o server.exe

.c.o: $<
	$(CC) $(CFLAGS) -I.. -c $< -o $@

clean:
	$(RM) *.o *.exe *.out

