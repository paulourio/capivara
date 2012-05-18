#include "servidor.h"

int realocar(char **ptr, int atual, int novo)
{
	int incremento = novo - atual;

	debug("Realocando memória para %i bytes", novo);
	debug(" (+ %i bytes)... ", incremento);
	fflush(stdout);

	char *novoptr = realloc(*ptr, 4);

	if (novoptr == NULL) {
		debug("ERRO: Sem memória para alocar.\r\n");
		return ERRO;
	}
	if (novoptr != *ptr) {
		debug("(%p -> %p)", *ptr, novoptr);
	} else {
		*ptr = novoptr;
	}
	debug("\r\n");
	fflush(stdout);
	return OK;
}
