OBJETOS=init.o \
	controller/controller.o \
	view/index.o view/notfound.o view/header.o view/blog.o view/sobre.o \
	model/model.o model/post.o

CFLAGS=-Wall -I/usr/include/mysql
CC=clang

default: app

app: $(OBJETOS)
	ar -cq libexemplo.a $(OBJETOS)
	
model/model.o:
	$(CC) $(CFLAGS) -I.. -I. -c model/model.c -o model/model.o 

.c.o: $<
	$(CC) $(CFLAGS) -I.. -I. -c $< -o $@

clean:
	$(RM) *.o *.exe *.out *.a
	cd controller && $(RM) *.o *.exe *.out *.a
	cd model && $(RM) *.o *.exe *.out *.a
	cd view && $(RM) *.o *.exe *.out *.a
	