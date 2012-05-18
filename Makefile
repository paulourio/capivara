CC=clang
CFLAGS= -I/usr/include/mysql
LDFLAGS=`mysql_config --cflags --libs`

.PHONY=capivara exemplo

default: all

run: clean valgrind

lib:
	mkdir lib

libcapivara.a: lib
	@cd capivara && make
	cp capivara/libcapivara.a lib/

libexemplo.a: lib
	@cd exemplo && make
	cp exemplo/libexemplo.a lib/

all: libcapivara.a libexemplo.a main.o
	$(CC) $(CFLAGS) $(LDFLAGS) main.o -Llib -lexemplo -lcapivara -o server.exe
	
server.exe: all	
	
valgrind: server.exe
	valgrind --leak-check=full --show-reachable=yes ./server.exe

.c.o: $<
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@cd capivara && make clean
	@cd exemplo && make clean
	$(RM) *.o *.exe *.out *.a -R lib/

	
