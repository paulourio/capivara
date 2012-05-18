#include <stdio.h>

int injetar_arquivo(char *buff, const char *arq)
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
	while ((read = fread(filebuff, sizeof(char), 1024, f)) > 0) {
		escrito += sprintf(buff + escrito, "%s", filebuff);
		/*printf("Escrito %d bytes...\n", escrito);*/
	}
	fclose(f);
	return escrito;
}
