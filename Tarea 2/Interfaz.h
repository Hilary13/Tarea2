#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include "Lista.h"
#include "Producto.h"
#include "Lote.h"

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


	//---------------Producto---------------------

	static void ingresarUsuario();

};

