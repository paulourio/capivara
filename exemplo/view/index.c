#include <exemplo.h>

void ViewIndex()
{
	ViewHeaderCompleto();
	emit("Teste");
	ViewFooter();
	build_view();
}
