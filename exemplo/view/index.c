#include <exemplo.h>

void ViewIndex()
{
	ViewHeaderCompleto();
	emit("<div id=\"content\">  </div>\r\n");
	ViewFooter();
	build_view();
}
