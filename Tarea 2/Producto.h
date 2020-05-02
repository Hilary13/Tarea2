#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Lote.h"
using namespace  std;

class Producto
{
private:

	int codigo;
	string nombre;
	string proveedor;
	int precio;
	//Lote* cantidad;

public:

	Producto(int, string, string, int);
	Producto();

	int getCodigo();
	string getNombre();
	string getProveedor();
	int getPrecio();

	void setCodigo(int);
	void setNombre(string);
	void setProveedor(string);
	void setPrecio(int);

	string toStringProducto();


};

