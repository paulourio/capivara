CC=clang
CFLAGS=-Wall -g
OBJETOS=run.o servidor.o conexao.o injetor.o memoria.o \
	registrar.o header_parser.o dispatcher.o view_builder.o

default: libcapivara.a

libcapivara.a: $(OBJETOS)
	ar -cq libcapivara.a $(OBJETOS)

.c.o: $<
	$(CC) $(CFLAGS) -I.. -c $< -o $@

clean:
	$(RM) *.o *.exe *.out *.a

