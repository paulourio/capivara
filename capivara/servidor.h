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
#define debug(...) fprintf(stderr, __VA_ARGS__)

#define OK 1
#define ERRO 0

/* memoria.c */
int realocar(char **ptr, int atual, int novo);
/* servidor.c */
void executar_servidor(void);
/* conexao.c */
void escutar_nova_conexao(const int sock);

#endif
