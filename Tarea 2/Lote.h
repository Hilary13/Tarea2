#ifndef LOTE_H
#define LOTE_H
#include <iostream>
#include <sstream>
#include "Producto.h"

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
	int getCodigo();
	virtual std::string toStringLote()const;

	bool operator==(const Lote&);
	bool operator!=(const Lote&);

};

std::ostream& operator<<(std::ostream&, const Lote&);

#endif