#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include "Lista.h"
#include "Producto.h"
#include "Lote.h"
#include "Controladora.h"

using namespace std;

class Interfaz
{

private:

	static string read();

public: 

	//----------------validar----------------------

	static string leerString();
	static int leerInt();
	static bool validarInt(std::string);
	static void color(int);
	static void verificarFecha(int, int, int);

	//---------------Producto---------------------

	static void ingresarProductos();
	static void ingresarLotesProducto();
	static void ingresarDescuentos();

};

