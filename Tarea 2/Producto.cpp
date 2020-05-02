#include "Producto.h"

Producto::Producto(int codigo, string nombre, string proveedor, int precio)
{
	this->codigo = codigo;
	this->nombre = nombre;
	this->proveedor = proveedor;
	this->precio = precio;
}

Producto::Producto()
{
	codigo = 0;
	nombre = "";
	proveedor = "";
	precio = 0;
}

int Producto::getCodigo() { return codigo; }

string Producto::getNombre() { return nombre; }

string Producto::getProveedor() { return proveedor; }

int Producto::getPrecio() { return precio; }

void Producto::setCodigo(int codigo) { this->codigo = codigo; }

void Producto::setNombre(string nombre) { this->nombre = nombre; }

void Producto::setProveedor(string proveedor) { this->proveedor = proveedor; }

void Producto::setPrecio(int precio) { this->precio = precio; }

string Producto::toStringProducto()
{
	stringstream s;

	s << "Código del producto: " << codigo << endl;
	s << "Nombre del producto: " << nombre << endl;
	s << "Proveedor: " << proveedor << endl;
	s << "Precio: " << precio << endl;

	return s.str();
}
