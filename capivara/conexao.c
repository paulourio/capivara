#include <errno.h>
#include "servidor.h"
#include <capivara.h>
#include "apps.h"

int conexao;

void escutar_nova_conexao(const int sock)
{
	struct sockaddr_in cli_addr;
	socklen_t cli_len = sizeof(cli_addr);

	conexao = accept(sock, (struct sockaddr *) &cli_addr, &cli_len);
	if (conexao < 0) {
		debug("Erro ao aceitar conexão.\r\n");
		goto fim_conexao;
	}

	int rec_size = 2046;
	char *recebido = malloc(rec_size * sizeof(char));
	int rec_total = 0;
	if (recebido == NULL) {
		fatal("Sem memória para receber dados.\r\n");
	}

	char buffer[1025] = { 0 };
	int n = 0;

	while ((n = read(conexao, buffer, sizeof(buffer))) > 0) {
		if (n < 0) {
			if (errno == EINTR)
				continue;
			debug("ERRO: Erro ao ler. Abandonando conexão.");
			goto fim_conexao;
		}
		if (rec_total + n > rec_size - 1) {
			int novo_tam = rec_total + n + 1024;
			if (realocar(&recebido, rec_size, novo_tam) == ERRO) {
				debug("Abandonando conexão.\r\n");
				goto fim_conexao;
			}
			rec_size += novo_tam;
		}
		memcpy(recebido + rec_total, buffer, n);
		rec_total += n;

		if (strstr(recebido, "\r\n\r\n") != NULL) {
			break;
		}
	}
	recebido[rec_total] = 0; /* Finalizar string */
	if (rec_total < 0)
		debug("Nada recebido da conexão.");

	struct http_request *hr;

	hr = analisar_cabecalho(recebido);
	init_view();
	despachar(hr);
	free_view();
	liberar_cabecalho(hr);

fim_conexao:
	free(recebido);
	close(conexao);
}
