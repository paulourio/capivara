#include <exemplo.h>
#include <mysql.h>

static MYSQL *conn = NULL;

static void print_mysql_erro(void)
{
	fprintf(stderr, "Erro no MySQL (%u): %s\n", mysql_errno(conn),
				mysql_error(conn));
}

int ModelConectado()
{
	return conn != NULL;
}

int ModelConectar()
{
	conn = mysql_init(NULL);

	if (conn == NULL) {
		print_mysql_erro();
		return 0;
	}

	if (mysql_real_connect(conn, "localhost", "capivara", "123", "exemplo", 0,
			NULL, 0) == NULL) {
		print_mysql_erro();
		return 0;
	}

	return 1;
}

void ModelDesconectar()
{
	mysql_close(conn);
	conn = NULL;
}

MYSQL_RES *Query(const char *sql)
{
	if (mysql_query(conn, sql)) {
		print_mysql_erro();
		return NULL;
	}
	return mysql_use_result(conn);
}

MYSQL_ROW ProximaLinha(MYSQL_RES  *query)
{
	if (query == NULL)
		fprintf(stderr, "Atenção: chamada ProximaLinha(NULL).\n");
	return mysql_fetch_row(query);
}

void FinalizarQuery(MYSQL_RES *query)
{
	if (query != NULL)
		mysql_free_result(query);
}

