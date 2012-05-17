#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define fatal(...) {fprintf(stderr, __VA_ARGS__); exit(1);}

int main(void)
{
	int sock, conexao;
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t serv_len = sizeof(serv_addr), cli_len = sizeof(cli_addr);

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
		fatal("erro ao criar scoket\n");
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(8083);

	if (bind(sock, (struct sockaddr *) &serv_addr, serv_len) < 0) 
		fatal("erro no bind\n");

	listen(sock, 5);
	conexao = accept(sock, (struct sockaddr *) &cli_addr, &cli_len);
	if (conexao < 0)
		fatal("erro ao aceitar");
	char buffer[301];
	memset(buffer, 0, sizeof(buffer));
	int n = read(conexao, buffer, sizeof(buffer)-1);
	if (n < 0)
		fatal("nada recebido");
	printf("Recebi: %s", buffer);

	char resposta[1024];
	char msg[1024];
	memset(resposta, 0, sizeof(resposta));
	memset(msg, 0, sizeof(msg));
	sprintf(msg, "<!DOCTYPE html> <html> <head> <title>Servidor</title> </head> <body> <h1>HAHA</h1></body></html>\r\n");
	sprintf(resposta, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s", strlen(msg), msg);
	write(conexao, resposta, strlen(resposta));	
	close(conexao);
	close(sock);

	return 0;
}

