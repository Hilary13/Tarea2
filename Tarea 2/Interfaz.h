#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include "Lista.h"
#include "Producto.h"
#include "Lote.h"
#include "Factura.h"
#include "Controladora.h"


class Interfaz
{

private:

	static std::string read();

public: 

	//----------------validar----------------------

	static std::string leerString();
	static int leerInt();
	static bool validarInt(std::string);
	static void color(int);
	static void verificarFecha(int, int, int);

	//---------------Producto---------------------

	static void ingresarProductos();
	static void ingresarLotesProducto();
	static void ingresarDescuentos();
	static void muestraProductosLotes();

	//---------------Factura---------------------

	static void factura();
	static void muestraFacturasPorCobrar();
	static void muestraFacturas();

};

