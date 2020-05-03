#include "Lote.h"
using namespace  std;
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
int Lote::getCodigo() { return codigo; }

string Lote::toStringLote()const
{
	stringstream s;

	s << "Producto: " << producto->getNombre() << endl;
	s << "Codigo: " << codigo << endl;
	s << "Fecha: " << dia << "-" << mes << "-" << anio << endl;
	s << "Cantidad: " << cantidad << endl;
	s << "Costo: " << costo << endl;

	return s.str();
}

bool  Lote::operator==(const Lote& aux)
{
	if (producto == aux.producto && codigo == aux.codigo && dia == aux.dia && mes == aux.mes && anio == aux.anio && cantidad == aux.cantidad && costo == aux.costo) { return true; }
	else { return  false; }
}

bool  Lote::operator!=(const Lote& aux)
{
	if (producto != aux.producto || codigo != aux.codigo || dia != aux.dia || mes != aux.mes || anio != aux.anio || cantidad != aux.cantidad || costo != aux.costo) { return true; }
	else { return  false; }
}

std::ostream& operator<<(std::ostream& salida, const Lote& u)
{
	salida << u.toStringLote();
	return salida;
}