/*
 * header_parser.c
 *
 * License: FreeBSD
 */
#include <capivara.h>
#include "servidor.h"

static struct http_request *pedido;

static struct param *novo_parametro(char *nome, char *valor)
{
	struct param *p = malloc(sizeof(struct param));
	if (p == NULL) {
		debug("Não é possível alocar um novo parâmetro.\r\n");
		return pedido->lista_param;
	}
	p->nome = nome;
	p->valor = valor;
	p->proximo = pedido->lista_param;
	return p;
}

static void processar_linha(char *linha)
{
	char *word;

	word = strtok(linha, " ");
	while (word != NULL) {
		if (strcmp(word, "GET") == 0 || strcmp(word, "POST") == 0) {
			pedido->tipo = word;
			word = strtok(NULL, " ");
			pedido->uri = word;
			word = strtok(NULL, " ");
			pedido->versao = word;
		} else if (strcmp(word, "Host:") == 0) {
			word = strtok(NULL, " ");
			pedido->host = word;
		} else {
			char *nome = word;
			word = strtok(NULL, " ");
			pedido->lista_param = novo_parametro(nome, word);
		}
		word = strtok(NULL, " ");
	}
}

struct http_request *analisar_cabecalho(char *entrada)
{
	char *offset;

	pedido = malloc(sizeof(struct http_request));
	if (pedido == NULL) {
		debug("ERRO: Sem memória para processar pedido.\r\n");
		return NULL;
	}
	pedido->lista_param = NULL;

	offset = strtok(entrada, "\r\n");
	while (offset != NULL) {
		char *nptr = offset;
		while (*nptr != 0) nptr++;
		while (*nptr == 0) nptr++;
		processar_linha(offset);
		offset = strtok(nptr, "\r\n");
	}
	return pedido;
}

void liberar_cabecalho(struct http_request *ptr)
{
	if (ptr == NULL)
		return;
	if (ptr->lista_param != NULL) {
		while (ptr->lista_param != NULL) {
			struct param *next = ptr->lista_param->proximo;
			free(ptr->lista_param);
			ptr->lista_param = next;
		}
	}
	free(ptr);
}
