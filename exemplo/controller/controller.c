/*
 * controller.c
 *
 * License: FreeBSD
 */
#include <exemplo.h>

void Controller(const struct http_request *request)
{
	printf(" URI: %s\r\n", request->uri);

	if (strcmp(request->uri, "/") == 0) {
		ViewIndex();
		return;
	}

	ViewNotFound();
}
