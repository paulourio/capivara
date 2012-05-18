/*
 * capivara.h
 *
 * License: FreeBSD
 */

#ifndef _CAPIVARA_H_
#define _CAPIVARA_H_

struct param {
	char *nome; /* Accept-*, etc */
	char *valor; /* só o primeiro valor é armazenado */
	struct param *proximo;
};

struct http_request {
	char *tipo; /* GET ou POST */
	char *uri; /* pedido */
	char *versao; /* versão do http */
	char *host; /* host sendo acessado */
	struct param *lista_param;
};

typedef void (*capivara_callback)(const struct http_request *);

/* registrar.c */
extern void registrar(char *app, capivara_callback app_metodo);

/* main.c */
extern void run_capivara(void);

/* view_builder.c */
extern void set_codigo_resposta(int codigo, char *descricao);
extern void set_tipo_conteudo(char *valor);
extern void emit(const char *format, ...);
extern void emit_arquivo(const char *arquivo);
extern void build_view(void);


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif /* _CAPIVARA_H_ */
