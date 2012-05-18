#include <exemplo.h>

void ViewHeader()
{
	emit_arquivo("exemplo/html/header.html");
	emit_arquivo("exemplo/css/style.css");
	emit_arquivo("exemplo/html/header2.html");
}

void ViewHeaderCompleto()
{
	emit_arquivo("exemplo/html/header.html");
	emit_arquivo("exemplo/css/style.css");
	emit_arquivo("exemplo/html/header2.html");
	emit_arquivo("exemplo/html/header_barra.html");
}

void ViewFooter()
{
	emit_arquivo("exemplo/html/footer.html");
}
