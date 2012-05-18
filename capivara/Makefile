CC=clang
CFLAGS=-Wall -g
OBJETOS=run.o servidor.o conexao.o view.o injetor.o memoria.o \
	registrar.o header_parser.o dispatcher.o

default: libcapivara.a

libcapivara.a: $(OBJETOS)
	ar -cvq libcapivara.a $(OBJETOS)

.c.o: $<
	$(CC) $(CFLAGS) -I.. -c $< -o $@

clean:
	$(RM) *.o *.exe *.out *.a

