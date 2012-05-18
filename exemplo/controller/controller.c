/*
 * controller.c
 *
 * License: FreeBSD
 */
#include <exemplo.h>

const struct http_request *current_request = NULL;

void Controller(const struct http_request *request)
{
	printf(" URI: %s\r\n", request->uri);
	current_request = request;

	if (strcmp(request->uri, "/") == 0) {
		ViewIndex();
		return;
	}

	if (strcmp(request->uri, "/blog") == 0) {
		ViewBlog();
		return;
	}

	if (strcmp(request->uri, "/sobre") == 0) {
		ViewSobre();
		return;
	}

	ViewNotFound();
}
