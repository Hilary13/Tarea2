#include "Lote.h"
using namespace  std;
Lote::Lote(Producto* producto, int codigo, int dia, int mes, int anio, int cantidad, int costo, int descuento)
{
	this->producto = producto;
	this->codigo = codigo;
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
	this->cantidad = cantidad;
	this->costo = costo;
	this->descuento = descuento;
}

Lote::Lote()
{
}

Producto* Lote::getProducto() { return producto; }

int Lote::getCodigoProducto() { return producto->getCodigo(); }

int Lote::getCantidad() { return cantidad; }

int Lote::getDia() { return dia; }

int Lote::getMes() { return mes; }

int Lote::getAnio() { return anio; }

int Lote::getCosto() { return costo; }

int Lote::getCodigo() { return codigo; }

int Lote::getDescuento() { return descuento; }

void Lote::setProducto(Producto* producto) { this->producto = producto; }

void Lote::setCodigoProducto(int codigo_produ) 
{
	int aux = 0;
	this->producto->setCodigo(aux);
}

void Lote::setCantidad(int cantidad) { this->cantidad = cantidad; }

void Lote::setDia(int dia) { this->dia = dia; }

void Lote::setMes(int mes) { this->mes = mes; }

void Lote::setAnio(int anio) { this->anio = anio; }

void Lote::setCosto(int costo) { this->costo = costo; }

void Lote::setCodigo(int codigo) { this->codigo = codigo; }

void Lote::setDescuento(int descuento) { this->descuento = descuento; }

string Lote::toStringLote()const
{
	stringstream s;

	s << "Producto: " << endl << producto->toStringProducto() << endl << endl;
	s << "Codigo: " << codigo << endl;
	s << "Fecha: " << dia << "-" << mes << "-" << anio << endl;
	s << "Cantidad: " << cantidad << endl;
	s << "Costo: " << costo << endl;
	s << "Descuento: " << descuento << endl;

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