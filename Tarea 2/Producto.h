#pragma once
#include <iostream>
#include <string>
#include <sstream>
//#include "Lote.h"


class Producto
{
private:

	int codigo;
	std::string nombre;
	std::string proveedor;
	int precio;
	//Lote* cantidad;

public:

	Producto(int, std::string, std::string, int);
	Producto();

	int getCodigo();
	std::string getNombre();
	std::string getProveedor();
	int getPrecio();

	void setCodigo(int);
	void setNombre(std::string);
	void setProveedor(std::string);
	void setPrecio(int);

	virtual std::string toStringProducto()const;

	bool operator==(const Producto&);
	bool operator!=(const Producto&);
};
std::ostream& operator<<(std::ostream&, const Producto&);