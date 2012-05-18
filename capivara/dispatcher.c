/*
 * dispatcher.c
 *
 * License: FreeBSD
 */
#include "servidor.h"
#include "apps.h"

void despachar(const struct http_request *request)
{
	struct app *curr = lista_apps;

	while (curr != NULL) {
		if (strcmp(curr->host, request->host) == 0) {
			debug("Chamando manipulador @ %p...\n", curr);
			curr->callback(request);
		}
		curr = curr->proximo;
	}
}
