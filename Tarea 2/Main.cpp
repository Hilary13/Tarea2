//#include "Usuario.h"
#include "Lista.h"
#include "Controladora.h"
#include "Interfaz.h"

int main() {
	setlocale(LC_CTYPE, "Spanish");
	//::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	Controladora* c = new Controladora();
	//c->inicio();
	c->menuPrincipal();
	system("pause");
	return 0;
}