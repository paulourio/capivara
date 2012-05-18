/*
 * exemplo.h
 *
 * License: FreeBSD
 */

#ifndef _EXEMPLO_H_
#define _EXEMPLO_H_

#include <capivara.h>

/* Controllers */
extern void Controller();

/* Views */
extern void ViewIndex();
extern void ViewNotFound();
extern void ViewHeader();


/* init.c */
extern void init_exemplo(void);

#endif /* _EXEMPLO_H_ */
