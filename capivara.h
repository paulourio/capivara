/*
 * capivara.h
 *
 * License: FreeBSD
 */

#ifndef _CAPIVARA_H_
#define _CAPIVARA_H_

typedef void (*capivara_callback)(void);

/* registrar.c */
void registrar(char *app, capivara_callback app_metodo);



#endif /* _CAPIVARA_H_ */
