#include <exemplo.h>

void ViewHeader()
{
	emit_arquivo("exemplo/html/header.html");
	emit_arquivo("exemplo/css/style.css");
	emit_arquivo("exemplo/html/header2.html");
}

static void emit_button(const char *link, const char *label)
{
	if (strcmp(current_request->uri, link) == 0)
		emit("<li class=\"current_page_item\">");
	else
		emit("<li>");
	emit("\t<a href=\"%s\">%s</a></li>\r\n", link, label);
}

void ViewHeaderCompleto()
{
	ViewHeader();
	emit_arquivo("exemplo/html/header_barra.html");

	emit_button("/", "Início");
	emit_button("/blog", "Blog");
	emit_button("/fotos", "Fotos");
	emit_button("/sobre", "Sobre");
	emit_button("/links", "Links");
	emit_button("/contato", "contato");

	emit("\t</ul>\r\n</div>\r\n<div id=\"page\">");
}

void ViewFooter()
{
	emit_arquivo("exemplo/html/footer.html");
}
