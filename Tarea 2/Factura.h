#pragma once
#include <iostream>
#include <sstream>
#include "Lista.h"

class Factura
{
	int nFactura;
	std::string nombreCliente;
	int cedula;
	int dia;
	int mes;
	int anio;
	Lista<Producto>* productos;
	float subtotal;
	float descuento;
	float total;
	bool cancelada;

public:
	Factura();
	Factura(int, std::string, int, int, int, int, Lista<Producto>*, float, float, float, bool);

	void setnFactura(int);
	void setProductos(Lista<Producto>*);
	void setSubtotal(float);
	void setDescuento(float);
	void setTotal(float);
	void setCancelada(bool);
	void setDia(int);
	void setMes(int);
	void setAnio(int);

	int getnFactura();
	Lista<Producto>* getProductos();
	float getSubtotal();
	float getDescuento();
	float getTotal();
	bool getCancelada();
	int getDia();
	int getMes();
	int getAnio();

	virtual std::string toString()const;

	bool operator==(const Factura&);
	bool operator!=(const Factura&);
};

std::ostream& operator<<(std::ostream&, const Factura&);