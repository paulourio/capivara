/*
 * sobre.c
 *
 * License: FreeBSD
 */
#include <exemplo.h>

void ViewSobre()
{
	ViewHeaderCompleto();
	emit("<div id=\"content\">  <h3>Página em construção!</h2> \r\n");
	emit("<div style=\"clear: both;\">&nbsp;</div>\r\n");
	emit("</div>\r\n");
	ViewFooter();
	build_view();
}
