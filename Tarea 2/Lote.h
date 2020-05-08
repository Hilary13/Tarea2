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
	int descuento;

public:

	Lote(Producto*, int, int, int, int, int, int, int);
	Lote();

	Producto* getProducto();
	int getCodigoProducto();
	int getCantidad();
	int getDia();
	int getMes();
	int getAnio();
	int getCosto();
	int getCodigo();
	int getDescuento();

	void setProducto(Producto*);
	void setCodigoProducto(int);
	void setCantidad(int);
	void setDia(int);
	void setMes(int);
	void setAnio(int);
	void setCosto(int);
	void setCodigo(int);
	void setDescuento(int);
	
	virtual std::string toStringLote()const;

	bool operator==(const Lote&);
	bool operator!=(const Lote&);

};

std::ostream& operator<<(std::ostream&, const Lote&);

#endif