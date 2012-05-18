/*
 * registrar.c
 *
 * License: FreeBSD
 */
#include "servidor.h"
#include "apps.h"
#include <capivara.h>

struct app *lista_apps = NULL;

void registrar(char *app, capivara_callback app_metodo)
{
	struct app *novo = malloc(sizeof(struct app));

	if (novo == NULL) {
		fatal("Não foi possível registrar app %s.\r\n", app);
		/* Sai do programa. */
	}
	strcpy(novo->nome, app);
	novo->callback = app_metodo;
	novo->proximo = lista_apps;
	lista_apps = novo;
	debug("App registrada (nome=%s, entrada=%p, callback=%p).\r\n",
			app, novo, app_metodo);
}

