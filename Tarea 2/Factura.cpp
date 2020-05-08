#include "Factura.h"

using namespace std;
Factura::Factura()
{
	this->nFactura = 0;
	this->nombreCliente = "";
	this->cedula = 0;
	this->dia = 0;
	this->mes = 0;
	this->anio = 0;
	this->productos = NULL;
	this->subtotal = 0;
	this->descuento = 0;
	this->total = 0;
	this->cancelada = false;
}

Factura::Factura(int nFactura, std::string nombreCliente, int cedula, int dia, int mes, int anio, Lista<Producto>* productos, float subtotal, float descuento, float total, bool cancelada)

{
	this->nFactura = nFactura;
	this->nombreCliente = nombreCliente;
	this->cedula = cedula;
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
	this->productos = productos;
	this->subtotal = subtotal;
	this->descuento = descuento;
	this->total = total;
	this->cancelada = cancelada;
}


void Factura::setnFactura(int nFactura)
{
	this->nFactura = nFactura;
}

void Factura::setProductos(Lista<Producto>* productos)
{
	this->productos = productos;
}

void Factura::setSubtotal(float subtotal)
{
	this->subtotal = subtotal;
}

void Factura::setDescuento(float descuento)
{
	this->descuento = descuento;
}

void Factura::setTotal(float total)
{
	this->total = total;
}

void Factura::setCancelada(bool cancelada)
{
	this->cancelada = cancelada;
}

void Factura::setDia(int dia) { this->dia = dia; }

void Factura::setMes(int mes) { this->mes = mes; }

void Factura::setAnio(int anio) { this->anio = anio; }

int Factura::getnFactura()
{
	return nFactura;
}

Lista<Producto>* Factura::getProductos()
{
	return productos;
}

float Factura::getSubtotal()
{
	return subtotal;
}

float Factura::getDescuento()
{
	return descuento;
}

float Factura::getTotal()
{
	return total;
}

bool Factura::getCancelada()
{
	return cancelada;
}
int Factura::getDia() { return dia; }

int Factura::getMes() { return mes; }

int Factura::getAnio() { return anio; }

string Factura::toString()const
{
	stringstream s;
	s << "\tNúmero de factura: " << nFactura << endl;
	s << "\tNombre Cliente: " << nombreCliente << endl;
	s << "\tCédula: " << cedula << endl;
	s << "\tFecha: " << dia << "/" << mes << "/" << anio << endl;
	s << "\tProductos: " << productos->toString() << endl;
	s << "\tSubtotal: " << subtotal << endl;
	s << "\tDescuento: " << descuento << endl;
	s << "\tIVA: " << "15%" << endl;
	s << "\tTotal: " << total << endl;
	if (cancelada == true) {
		s << "\tCancelada: " << "Si" << endl;
	}else
	s << "\tCancelada: " << "No" << endl;


	return s.str();
}
bool  Factura::operator==(const Factura& aux)
{
	if (nFactura == aux.nFactura && productos == aux.productos && subtotal == aux.subtotal && descuento == aux.descuento && total == aux.total && cancelada == aux.cancelada) { return true; }
	else { return  false; }
}

bool  Factura::operator!=(const Factura& aux)
{
	if (nFactura != aux.nFactura || productos != aux.productos || subtotal != aux.subtotal || descuento != aux.descuento || total != aux.total || cancelada != aux.cancelada) { return true; }
	else { return  false; }
}

std::ostream& operator<<(std::ostream& salida, const Factura& f)
{
	salida << f.toString();
	return salida;
}
