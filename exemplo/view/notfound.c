#include <exemplo.h>

void ViewNotFound()
{
	set_codigo_resposta(440, "Not Found");
	ViewHeader();
	emit_arquivo("exemplo/html/404.html");
	build_view();
}
