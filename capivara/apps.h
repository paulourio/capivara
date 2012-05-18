/*
 * apps.h
 *
 * License: FreeBSD
 */

#ifndef _APPS_H_
#define _APPS_H_

#include <capivara.h>

struct app {
	char host[155];
	capivara_callback callback;
	struct app *proximo;
};

extern struct app *lista_apps;

/* dispatcher.c */
extern void despachar(const struct http_request *request);

#endif /* _APPS_H_ */
