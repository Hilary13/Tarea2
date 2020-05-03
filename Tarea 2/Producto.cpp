#include "Producto.h"
using namespace  std;

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

string Producto::toStringProducto()const
{
	stringstream s;

	s << "\tCódigo del producto: " << codigo << endl;
	s << "\tNombre del producto: " << nombre << endl;
	s << "\tProveedor: " << proveedor << endl;
	s << "\tPrecio: " << precio << endl;

	return s.str();
}
bool  Producto::operator==(const Producto& aux)
{
	if (codigo == aux.codigo && nombre == aux.nombre && proveedor == aux.proveedor && precio == aux.precio) { return true; }
	else { return  false; }
}

bool  Producto::operator!=(const Producto& aux)
{
	if (codigo != aux.codigo || nombre != aux.nombre || proveedor != aux.proveedor || precio != aux.precio) { return true; }
	else { return  false; }
}

std::ostream& operator<<(std::ostream& salida, const Producto& u)
{
	salida << u.toStringProducto();
	return salida;
}
