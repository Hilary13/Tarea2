#include "Interfaz.h"
using namespace std;
//--------------------------VARIABLES GLOBALES-----------------------------

int contAux = 0;
static int nFactura = 0;
Lista<Producto>* listproducto = new Lista<Producto>;
Lista<Lote>* listlote = new Lista<Lote>;
Lista<Factura>* listfactura = new Lista<Factura>;

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
			cout << "       Cantidad:  ";
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
			cout << "       Costo:  ";
			int costo = Interfaz::leerInt();
			system("pause");


			int descuento = 0;
			Lote* lote = new Lote(productoAux, codigo_lote, dia, mes, anio, cantidad, costo, descuento);
			listlote->insertarInicio(lote);
			cout << "Lote ingresado correctamente" << endl;
			cout << endl << endl << endl;
			cout << lote->toStringLote() << endl;
			system("pause");
			system("cls");
			Controladora::menuPrincipal();

		}

		cout << "Código de lote ya existe" << endl;
		Interfaz::ingresarLotesProducto();
	}
	cout << "Número de código no encontrado en los registros" << endl;
	Interfaz::ingresarLotesProducto();
}

void Interfaz::ingresarDescuentos()
{
	
	cin.ignore();
	system("cls");
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |               Ingresar Descuentos                 |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       |     Ingrese el código del producto:               |" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       Código de producto:  ";
	int codigoProducto = Interfaz::leerInt(); 
	Lista<Lote>* listAux = listlote->retornaListCodigo(codigoProducto);
	cout << listAux->toString();

	cout << "Ingrese el código del lote al que desea aplicar el descuento: ";
	int codigoLote = Interfaz::leerInt(); cout << endl;
	cout << "Ingrese el descuento que desea aplicarle al lote: ";
	float descuento = 0;
	cin >> descuento;
	if (listAux->verificarCodigoExiste(codigoLote)) {

		listAux->cambiaDescuento(codigoLote, descuento);
		cout << listAux->toString();
		*listlote = *listAux;
	}
	else 
		cout << "Codigo no existe, por favor ingrese uno válido" << endl;
	
}

void Interfaz::muestraProductosLotes()
{
	cout << listlote->toString();
}

void Interfaz::factura()
{
	Producto* productoAux = new Producto();
	Lista<Producto>* listproductoFactura = new Lista<Producto>;
	bool cancelada = false;
	bool masProductos = true;
	Factura* factura = new Factura();
	float subtotal = 0;
	float descuento = 0;
	float total = 0;
	int op = 0;
	system("cls");
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |                     Factura                       |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       |     Ingrese el nombre del Cliente:                |" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       Nombre:  ";
	string nombre = Interfaz::leerString();


	system("cls");
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |                     Factura                       |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       |     Ingrese la cédula del Cliente:                |" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       Cédula:  ";
	int cedula = Interfaz::leerInt();


	system("cls");
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |                     Factura                       |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       |     Ingrese la fecha de compra:                   |" << endl;
	cout << "       |                                                   |" << endl;
	cout << "       +---------------------------------------------------+" << endl;
	cout << "       Día:  ";
	int dia = Interfaz::leerInt(); cout << " \n";
	cout << "       Mes:  ";
	int mes = Interfaz::leerInt(); cout << " \n";
	cout << "       Año:  ";
	int anio = Interfaz::leerInt(); cout << " \n";
	//Interfaz::verificarFecha(dia, mes, anio);

	while (masProductos)
	{
	
		while (masProductos) {
	
			system("cls");
			cout << "       +---------------------------------------------------+" << endl;
			cout << "       |                     Factura                       |" << endl;
			cout << "       +---------------------------------------------------+" << endl;
			cout << "       |                                                   |" << endl;
			cout << "       |     Ingrese el código del producto:               |" << endl;
			cout << "       |                                                   |" << endl;
			cout << "       +---------------------------------------------------+" << endl;
			cout << "       Código de producto:  ";
			int codigoProducto = Interfaz::leerInt();
			Lista<Lote>* listAux = listlote->retornaListCodigo(codigoProducto);
			cout << listAux->toString();
			cout << "Ingrese el código del lote del producto: ";
			int codigoLote = Interfaz::leerInt(); cout << endl;
			cout << "Ingrese la cantidad de productos: ";
			float nProductos = 0;
			cin >> nProductos;
			if (listAux->verificarCodigoExiste(codigoLote)) {
				if (listAux->verificaInventario(codigoLote, nProductos)) {
					subtotal = subtotal + (listAux->getPrecio(codigoLote) * nProductos);
					descuento = descuento + listAux->getDescuento(codigoLote);
					total = (subtotal - descuento) * 1.15;
					*productoAux = (listproducto->buscaCodigo(codigoLote, productoAux));
					listproductoFactura->insertarInicio(productoAux);
					cout << "\tDesea ingresar otro producto?\n ";
					cout << "\t1) Sí\n ";
					cout << "\t2) No\n ";
					op = Interfaz::leerInt();
					switch (op)
					{
					case 1:
						masProductos = true;
						break;
					case 2:
						masProductos = false;
						break;

					default:
						cout << "\tError\n";
						break;
					}
					if (masProductos) { break; }
				}
			}
			else { cout << "Codigo no existe, por favor ingrese uno válido" << endl; }
		
			cout << listAux->toString();
			*listlote = *listAux;
			system("cls");
			cout << "\tFactura Cancelada\n";
			cout << "\t1) Sí\n ";
			cout << "\t2) No\n ";
			op = Interfaz::leerInt();
			switch (op)
			{
			case 1:
				cancelada = true;
				break;
			case 2:
				cancelada = false;
				break;

			default:
				cout << "\tError\n";
				break;
			}
			nFactura++;
			cout << listlote->toString();
			*factura = Factura(nFactura, nombre, cedula, dia, mes, anio, listproductoFactura, subtotal, descuento, total, cancelada);
			listfactura->insertarInicio(factura);
			cout << factura->toString();
		}
		
	}

}

void Interfaz::muestraFacturasPorCobrar()
{
	cout << (listfactura->facturasPorCobrar())->toString();
}

void Interfaz::muestraFacturas()
{
	cout << listfactura->toString();
}

