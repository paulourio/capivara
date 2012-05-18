/*
 * apps.h
 *
 * License: FreeBSD
 */

#ifndef _APPS_H_
#define _APPS_H_

#include <capivara.h>

struct app {
	char nome[155];
	capivara_callback callback;
	struct app *proximo;
};

extern struct app *lista_apps;

#endif /* _APPS_H_ */
