#include <exemplo.h>

void ViewIndex()
{
	ViewHeader();
	emit_arquivo("exemplo/html/index.html");
	emit_arquivo("exemplo/html/footer.html");
		build_view();
}
