/*
 * controller.c
 *
 * License: FreeBSD
 */
#include <stdio.h>

void Controller(const struct http_request *request)
{
	fprintf(stdout, "Yeah, you hit me, bitch.\r\n");
}
