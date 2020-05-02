#include "Lote.h"

Lote::Lote(Producto* producto, int codigo, int dia, int mes, int anio, int cantidad, int costo)
{
	this->producto = producto;
	this->codigo = codigo;
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
	this->cantidad = cantidad;
	this->costo = costo;
}

Producto* Lote::getProducto() { return producto; }

int Lote::getCantidad() { return cantidad; }

int Lote::getCosto() { return costo; }

string Lote::toStringLote()
{
	stringstream s;

	s << "Producto: " << producto->getNombre() << endl;
	s << "Codigo: " << codigo << endl;
	s << "Fecha: " << dia << "-" << mes << "-" << anio << endl;
	s << "Cantidad: " << cantidad << endl;
	s << "Costo: " << costo << endl;
}
