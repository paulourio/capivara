#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define fatal(...) { fprintf(stderr, __VA_ARGS__); exit(1); }
#define debug(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); }

#define OK 1
#define ERRO 0

/* memoria.c */
extern int realocar(char **ptr, int atual, int novo);
/* servidor.c */
extern void executar_servidor(void);
/* conexao.c */
extern void escutar_nova_conexao(const int sock);
/* header_parser.c */
extern struct http_request *analisar_cabecalho(char *entrada);
extern void liberar_cabecalho(struct http_request *ptr);
/* view_builder.c */
extern void init_view();
extern void free_view();
/* injetor.c */
extern int injetar_arquivo(char *buff, char *arq);

#endif
