/*
 * blog.c
 *
 * License: FreeBSD
 */
#include <exemplo.h>

void ViewBlog()
{
	ViewHeaderCompleto();
	emit("<div id=\"content\">");

	ModelConectar();
	MYSQL_RES *query = ModelPost_GetPosts();
	MYSQL_ROW row;


	while ((row = ProximaLinha(query)) != NULL) {
		fprintf(stderr, "Processando entrada \"%s\"...\n", row[1]);
		emit("<div class=\"post\">\r\n");
		emit("<h2 class=\"title\"><a href=\"#\">%s</a></h2>\r\n", row[1]);
		emit("<p class=\"meta\">Posted by <a href=\"#\">%s</a> on "
		"April 22, 2012&nbsp;&bull;&nbsp; <a href=\"#\" class=\""
		"comments\">You Shall Not Comment</a></p>\r\n", row[0]);
		emit("<div class=\"entry\">\r\n");
		emit("%s\r\n", row[2]);
		emit("</div>\r\n");
	}
	emit("<div style=\"clear: both;\">&nbsp;</div>\r\n");
	emit("</div>\r\n");
	ViewFooter();
	build_view();

	FinalizarQuery(query);
	ModelDesconectar();
}
