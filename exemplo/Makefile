OBJETOS=init.o \
	controller/controller.o \
	view/index.o view/notfound.o view/header.o

default: app

app: $(OBJETOS)
	ar -cq libexemplo.a $(OBJETOS)

.c.o: $<
	$(CC) $(CFLAGS) -I.. -I. -c $< -o $@

clean:
	$(RM) *.o *.exe *.out *.a
