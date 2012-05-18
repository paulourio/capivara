#include <stdio.h>
#include "view.h"

int injetar_arquivo(char *buff, char *arq)
{
	int escrito = 0;

	FILE *f = fopen(arq, "r");
	if (f == NULL) {
		fprintf(stderr, "Erro ao abrir arquivo %s.\r\n", arq);
		return escrito;
	}
	char filebuff[1025] = { 0 };
	int read;

	filebuff[sizeof(filebuff) - 1] = 0;
	while ((read = fread(filebuff, sizeof(char), 1024, f)))
		escrito += sprintf(buff + escrito, "%s", filebuff);
	fclose(f);
	return escrito;
}
