#include "Lista.h"
#include "Controladora.h"
#include "Interfaz.h"

int main() {
	setlocale(LC_CTYPE, "Spanish");
	Controladora* c = new Controladora();
	c->menuPrincipal();

	system("pause");
	return 0;
}