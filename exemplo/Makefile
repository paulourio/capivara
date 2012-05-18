OBJETOS=init.o controller/controller.o

default: app

app: $(OBJETOS)
	ar -cvq libexemplo.a $(OBJETOS)

.c.o: $<
	$(CC) $(CFLAGS) -I.. -c $< -o $@

clean:
	$(RM) *.o *.exe *.out *.a
