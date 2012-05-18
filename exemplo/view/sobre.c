/*
 * sobre.c
 *
 * License: FreeBSD
 */
#include <exemplo.h>

void ViewSobre()
{
	ViewHeaderCompleto();
	emit("<div id=\"content\">  <h2>Página em construção!</h2> </div>\r\n");
	ViewFooter();
	build_view();
}
