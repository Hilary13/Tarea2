#include "Interfaz.h"

//--------------------------VARIABLES GLOBALES-----------------------------

int contAux = 0;
Lista<Producto>* listproducto = new Lista<Producto>;
Lista<Lote>* listlote = new Lista<Lote>;

//-------------------------------------------------------------------------
bool Interfaz::validarInt(string n)
{
	int i;
	int inicio = 0;
	if (n.length() == 0) { return false; }
	if (n.length() > 9) { return false; }
	for (i = inicio; i < n.length(); i++)
	{
		if (!isdigit(n[i])) { return false; }
	}
	return true;
}

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

void Interfaz::ingresarProductos()
{
	std::cin.ignore();
	cout << " \n";
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |                 Ingresar Producto                 |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       |     Ingrese el código del producto:               |" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       Código:  ";
	int codigo = Interfaz::leerInt();
	while (!listproducto->verificarCodigoExiste(codigo)) {


		system("cls");
		cout << "       +---------------------------------------------------+" << endl;
		cout << "       |                 Ingresar Producto                 |" << endl;
		cout << "       +---------------------------------------------------+" << endl;
		cout << "       |                                                   |" << endl;
		cout << "       |     Ingrese el nombre del producto:               |" << endl;
		cout << "       |                                                   |" << endl;
		cout << "       +---------------------------------------------------+" << endl;
		cout << "       Producto:  ";
		string nombre = Interfaz::leerString();

		system("cls");
		cout << "       +---------------------------------------------------+" << endl;
		cout << "       |                 Ingresar Producto                 |" << endl;
		cout << "       +---------------------------------------------------+" << endl;
		cout << "       |                                                   |" << endl;
		cout << "       |     Ingrese el proveedor del producto:            |" << endl;
		cout << "       |                                                   |" << endl;
		cout << "       +---------------------------------------------------+" << endl;
		cout << "       Proveedor:  ";
		string proovedor = Interfaz::leerString();

		system("cls");
		cout << "       +---------------------------------------------------+" << endl;
		cout << "       |                 Ingresar Producto                 |" << endl;
		cout << "       +---------------------------------------------------+" << endl;
		cout << "       |                                                   |" << endl;
		cout << "       |     Ingrese el precio del producto:               |" << endl;
		cout << "       |                                                   |" << endl;
		cout << "       +---------------------------------------------------+" << endl;
		cout << "       Precio:  ";
		int precio = Interfaz::leerInt();

		system("cls");

		Producto* producto = new Producto(codigo, nombre, proovedor, precio);
		listproducto->insertarInicio(producto);
		cout << "\n\tProducto ingresado correctamente" << endl;
		std::cout << "\tProducto: " << std::endl;
		std::cout << producto->toStringProducto() << "\n\n" << std::endl;
		system("pause");
		system("cls");
		Controladora::menuPrincipal();
	}
	
	cout << "Error, este número de código ya existe" << endl;
	system("pause");
	system("cls");
	Interfaz::ingresarProductos();
}

void Interfaz::ingresarLotesProducto()
{
	Producto* produAux = new Producto;
	system("cls");
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |                   Ingresar Lote                   |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       |     Ingrese el código del producto:               |" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       Código:  ";
	int codigo_produ = Interfaz::leerInt();

	while (listproducto->verificarCodigoExiste(codigo_produ)) {

		codigo_produ = produAux->getCodigo();
		//cout << produAux->toStringProducto();

		system("cls");
		cout << "       +---------------------------------------------------+" << endl;
		cout << "       |                   Ingresar Lote                   |" << endl;
		cout << "       +---------------------------------------------------+" << endl;
		cout << "       |                                                   |" << endl;
		cout << "       |     Ingrese el código del producto:               |" << endl;
		cout << "       |                                                   |" << endl;
		cout << "       +---------------------------------------------------+" << endl;
		cout << "       Código:  ";
		int codigo_lote = Interfaz::leerInt();

		while (!listlote->verificarCodigoExiste(codigo_lote)) {




		}
		cout << "Código de lote ya existe";
		Interfaz::ingresarLotesProducto(); 
	}

	cout << "Codigo de producto inexistente. Ingrese un código válido" << endl;
	Interfaz::ingresarLotesProducto();

}

