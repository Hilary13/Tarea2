#ifndef LOTE_H
#define LOTE_H
#include <iostream>
#include <sstream>
#include "Producto.h"

using namespace std;

class Lote
{
private:

	Producto* producto;
	int codigo;
	int dia;
	int mes;
	int anio;
	int cantidad;
	int costo;

public:

	Lote(Producto*, int, int, int, int, int, int);

	Producto* getProducto();
	int getCantidad();
	int getCosto();

	string toStringLote();

};

#endif 