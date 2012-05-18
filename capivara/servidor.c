#include "servidor.h"

void executar_servidor()
{
	int sock;
	struct sockaddr_in serv_addr;
	socklen_t serv_len = sizeof(serv_addr);

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		fatal("Erro ao criar socket.\n");
	}

	/* Definimos o socket com SO_REUSEADDR para que o bind não bloqueie
	 * o programa de ser executado ao reiniciar.
	 */
	int valor = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *) &valor,
			sizeof(valor)) < 0) {
		debug("Erro ao executar setsockopt.\r\n");
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(8080);

	if (bind(sock, (struct sockaddr *) &serv_addr, serv_len) < 0)
	fatal("Erro na função bind()\n");

	listen(sock, 5);

	while (1)
		escutar_nova_conexao(sock);

	close(sock);
}

