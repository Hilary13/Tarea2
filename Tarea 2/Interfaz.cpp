#include "Interfaz.h"

//--------------------------VARIABLES GLOBALES-----------------------------

int contAux = 0;


//-------------------------------------------------------------------------

string Interfaz::read()
{
	char chain[100];

	cin.getline(chain, 99);

	stringstream s;

	s << chain;

	int size = s.str().length();

	return s.str();
}

string Interfaz::leerString()
{
	char chain[100];

	cin.getline(chain, 99);

	stringstream s;

	s << chain;

	int size = s.str().length();

	if (size == 0 || s.str()[0] == 32) {
		if (contAux > 0) {
			cout << "Texto incorrecto, por favor ingréselo nuevamente: ";
		}
		contAux++;
		return leerString();
	}
	contAux = 0;
	return s.str();
}

int Interfaz::leerInt()
{
	std::string numero;
	bool intValido = false;
	while (!intValido) {
		try
		{
			std::getline(std::cin, numero);
			intValido = validarInt(numero);

			if (!intValido) { throw numero; }
		}
		catch (string a) {
			std::cout << "\n\t\tNúmero: " << a << " inválido." << std::endl;
			std::cout << "\n\tIngrese un número válido: ";
		}
	}
	return std::stoi(numero);
}

void Interfaz::color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
