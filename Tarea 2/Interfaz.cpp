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

void Interfaz::verificarFecha(int dia, int mes, int anio)
{

	if (mes >= 1 && mes <= 12) {

		switch (mes) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (dia >= 1 && dia <= 31) {
				cout << "";
			}
			else
				cout << "Dia ingresado es incorrecto" << endl;
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			if (dia >= 1 && dia <= 30) {
				cout << "";
			}
			else
				cout << "Día ingresado es incorrecto" << endl;
			break;

		case 2:
			if (anio % 4 == 0 && anio % 100 != 0)
				if (dia >= 1 && dia <= 29);
				else { cout << "Día ingresado es inválido"; }
			else
				if (dia >= 1 && dia <= 28);
				else { cout << "Día ingresado es inválido"; }
			break;
		}
	}
	else
		cout << "El mes digitado es incorrecto, por favor ingréselo de nuevo" << endl;
	system("pause");
	system("cls");
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
	int codigo_produ = 0;
	string nombre = "";
	string proveedor = "";
	int precio = 0;

	Producto* productoAux = new Producto(codigo_produ, nombre, proveedor, precio);
	Producto* productoAux1 = new Producto(codigo_produ, nombre, proveedor, precio);

	system("cls");
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |                   Ingresar Lote                   |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       |     Ingrese el código del producto:               |" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       Código:  ";
	cin.ignore();
	codigo_produ = Interfaz::leerInt();
	*productoAux = (listproducto->buscaCodigo(codigo_produ, productoAux));
	if (*productoAux != *productoAux1) {
		/*cout << "todo bien";*/
		cout << "Producto: " << endl;
		cout << productoAux->toStringProducto();
		system("pause");
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
		system("pause");

		while (!listlote->verificarCodigoExiste(codigo_lote)) {

			system("cls");
			cout << "       +---------------------------------------------------+" << endl;
			cout << "       |                   Ingresar Lote                   |" << endl;
			cout << "       +---------------------------------------------------+" << endl;
			cout << "       |                                                   |" << endl;
			cout << "       |     Ingrese la fecha de ingreso:                  |" << endl;
			cout << "       |                                                   |" << endl;
			cout << "       +---------------------------------------------------+" << endl;
			cout << "       Día:  ";
			int dia = Interfaz::leerInt(); cout << " \n";
			cout << "       Mes:  ";
			int mes = Interfaz::leerInt(); cout << " \n";
			cout << "       Año:  ";
			int anio = Interfaz::leerInt(); cout << " \n";
			Interfaz::verificarFecha(dia, mes, anio);


			system("cls");
			cout << "       +---------------------------------------------------+" << endl;
			cout << "       |                   Ingresar Lote                   |" << endl;
			cout << "       +---------------------------------------------------+" << endl;
			cout << "       |                                                   |" << endl;
			cout << "       |     Ingrese la cantidad de productos:             |" << endl;
			cout << "       |                                                   |" << endl;
			cout << "       +---------------------------------------------------+" << endl;
			cout << "       Código:  ";
			int cantidad = Interfaz::leerInt();
			system("pause");


			system("cls");
			cout << "       +---------------------------------------------------+" << endl;
			cout << "       |                   Ingresar Lote                   |" << endl;
			cout << "       +---------------------------------------------------+" << endl;
			cout << "       |                                                   |" << endl;
			cout << "       |     Ingrese el costo:                             |" << endl;
			cout << "       |                                                   |" << endl;
			cout << "       +---------------------------------------------------+" << endl;
			cout << "       Código:  ";
			int costo = Interfaz::leerInt();
			system("pause");



			Lote* lote = new Lote(productoAux, codigo_lote, dia, mes, anio, cantidad, costo);
			listlote->insertarInicio(lote);
			cout << "Lote ingresado correctamente" << endl;
			cout << lote->toStringLote() << endl;
			system("pause");
			system("cls");

		}

		cout << "Código de lote ya existe" << endl;
		Interfaz::ingresarLotesProducto();
	}
	cout << "Número de código no encontrado en los registros" << endl;
	Interfaz::ingresarLotesProducto();
}

