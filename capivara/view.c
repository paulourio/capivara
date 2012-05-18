#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"

#define emit(...) offset += sprintf(msg+offset, __VA_ARGS__)

char *create_index_view(void)
{
	char *msg = malloc( 100000 * sizeof(char) );
	int offset = 0;
	
	if (msg == NULL) {
		fprintf(stderr, "Sem memório suficiente.");
	}
	
	memset(msg, 0, sizeof(char));
	
	emit("<!DOCTYPE html>\r\n");
	emit("<html>\r\n");
	emit("<head> <meta charset=\"UTF-8\"> <title>Bem-vindo</title> \r\n");
	emit("         <style type=\"text/css\">\r\n");
	offset += injetar_arquivo(msg+offset, "style.css");
	emit("         </style>\r\n");
	emit("</head>\r\n");
	emit("<body>\r\n");
	emit("<div id=\"wrapper\">\r\n");
	emit("	<div id=\"header-wrapper\">\r\n");
	emit("		<div id=\"header\">\r\n");
	emit("			<div id=\"logo\">\r\n");
	emit(" <h1><a href=\"#\">Paulo Urio Web Server</a></h1>\r\n");
	emit("<p>Because FUCK YOU. That's why.</p>\r\n");
	emit("	</div>\r\n");
	emit("			</div>\r\n");
	emit("</div>\r\n");
	emit("<!-- end #header -->\r\n");
	emit("<div id=\"menu\">\r\n");
	emit("			<ul>\r\n");
	emit("				<li class=\"current_page_item\"><a href=\"#\">Homepage</a></li>\r\n");
	emit("<li><a href=\"#\">Blog</a></li>\r\n");
	emit("<li><a href=\"#\">Photos</a></li>\r\n");
	emit("				<li><a href=\"#\">About</a></li>\r\n");
	emit("				<li><a href=\"#\">Links</a></li>\r\n");
	emit("				<li><a href=\"#\">Contact</a></li>\r\n");
	emit("			</ul>\r\n");
	emit("		</div>\r\n");
	emit("</body>\r\n");
	emit("</html>\r\n");
	
	return msg;
}
