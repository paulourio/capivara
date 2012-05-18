/*
 * view_builder.c
 *
 * License: FreeBSD
 */
#include <stdarg.h>
#include <sys/stat.h>
#include "servidor.h"
#include <capivara.h>

struct view {
	int http_cod;
	char *http_cod_msg;
	char *tipo_conteudo;
	char *conteudo;
	int tamanho, capacidade;
};

struct view view;

void init_view()
{
	set_codigo_resposta(200, "OK");
	set_tipo_conteudo("text/html");
	view.conteudo = NULL;
	view.tamanho = 0;
	view.capacidade = 0;
}

void free_view()
{
	if (view.conteudo != NULL) {
		free(view.conteudo);
		view.conteudo = NULL;
	}
	view.tamanho = 0;
}

void set_codigo_resposta(int codigo, char *descricao)
{
	view.http_cod = codigo;
	view.http_cod_msg = descricao;
}

void set_tipo_conteudo(char *valor)
{
	view.tipo_conteudo = valor;
}

static void realocar_buffer_view(int necessario)
{
	if (view.conteudo == NULL) {
		int tam = necessario + 1024;
		view.conteudo = malloc(tam);
		if (view.conteudo == NULL) {
			debug("Sem memória para alocar buffer da view.\r\n");
		}
		debug("Alocado %d bytes em %p para o buffer.\n", tam, view.conteudo);
		view.capacidade = tam;
	} else {
		int novo = view.capacidade + necessario + 1024;
		if (realocar(&view.conteudo, view.capacidade, novo) == 0) {
			debug("Erro ao realocar buffer de emissão!\r\n");
		}
		view.capacidade = novo;
	}
}

void emit(const char *format, ...)
{
	va_list arglist;
	char buffer[40000] = "";
	int buffer_len = 0;

	va_start(arglist, format);
	buffer_len = vsprintf(buffer, format, arglist);
	va_end(arglist);

	if (view.tamanho + buffer_len > view.capacidade - 1)
		realocar_buffer_view(buffer_len);
	memcpy(view.conteudo + view.tamanho, buffer, buffer_len);
	view.tamanho += buffer_len;
	view.conteudo[view.tamanho] = 0;
}

void emit_arquivo(const char *arquivo)
{
	struct stat st;

	stat(arquivo, &st);
	int bytes = st.st_size;
	if (view.tamanho + bytes > view.capacidade - 1)
		realocar_buffer_view(bytes);
	view.tamanho += injetar_arquivo(view.conteudo + view.tamanho, arquivo);
}

extern int conexao; /* socket de conexao em conexao.c */
void build_view(void)
{
	char *resposta = malloc(view.tamanho + 1024);

	if (resposta == NULL) {
		debug("Não é possível montar a resposta da view.");
		return;
	}

	sprintf(resposta, "HTTP/1.1 %d %s\r\nContent-Type: %s\r\n"
			"Content-Length: %d\r\n\r\n%s", view.http_cod,
			view.http_cod_msg, view.tipo_conteudo, view.tamanho,
			view.conteudo);

	write(conexao, resposta, strlen(resposta));

	free(resposta);
}

