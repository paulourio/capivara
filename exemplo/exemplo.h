/*
 * exemplo.h
 *
 * License: FreeBSD
 */

#ifndef _EXEMPLO_H_
#define _EXEMPLO_H_

#include <capivara.h>
#include <mysql.h>

/* Controllers */
extern void Controller();

/* Views */
extern void ViewIndex();
extern void ViewNotFound();
extern void ViewHeader();
extern void ViewHeaderCompleto();
extern void ViewFooter();
extern void ViewBlog();
extern void ViewSobre();

/* Model */
extern int ModelConectado();
extern int ModelConectar();
extern void ModelDesconectar();
extern MYSQL_RES *Query();
extern MYSQL_ROW ProximaLinha(MYSQL_RES  *query);
extern void FinalizarQuery(MYSQL_RES *query);

extern MYSQL_RES *ModelPost_GetPosts();

/* init.c */
extern void init_exemplo(void);

#endif /* _EXEMPLO_H_ */
