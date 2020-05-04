#include "Controladora.h"

void Controladora::menuPrincipal()
{
	char entrar;
	do {
		cout << " \n";
		cout << "       +-----------------------------------------------+" << endl;
		cout << "       |                      MENU                     |" << endl;
		cout << "       +-----------------------------------------------+" << endl;
		cout << "       |                                               |" << endl;
		cout << "       |  1. Ingresar Productos al inventario          |" << endl;
		cout << "       |  2. Ingresar lotes a un producto              |" << endl;
		cout << "       |  3. Ingresar Descuentos                       |" << endl;
		cout << "       |  4. Crear factura                             |" << endl;
		cout << "       |  5. Mostar todas las facturas creadas         |" << endl;
		cout << "       |  6. Mostrar facturas por cobrar               |" << endl;
		cout << "       |  7. Probar sobrecarga de operadores           |" << endl;
		cout << "       |  8. Salir                                     |" << endl;
		cout << "       |                                               |" << endl;
		cout << "       +-----------------------------------------------+" << endl;
		cout << "       Opcion: ";
		cin >> entrar;
		switch (entrar) {

		case '1':
			
			system("cls");
			Interfaz::ingresarProductos();
			system("pause");
			system("cls");
			break;

		case '2':
		
			system("cls");
			Interfaz::ingresarLotesProducto();
			system("pause");
			system("cls");
			break;

		case '3':

			system("cls");
			//ingresar descuentos
			system("pause");
			system("cls");
			break;

		case '4':

			system("cls");
			//crear factura
			system("pause");
			system("cls");
			break;

		case '5':

			system("cls");
			//mostrar todas las facturas creadas
			system("pause");
			system("cls");
			break;

		case '6':

			system("cls");
			//mostrar facturas por cobrar
			system("pause");
			system("cls");
			break;

		case '7':

			system("cls");
			//probar sobrecarga de operadores
			system("pause");
			system("cls");
			break;

		case '8':
			//----salir-----
			cout << " \n";
			cout << "       Saliendo del programa \n";
			cout << " \n";
			system("pause");
			exit(1);

			break;
		default:
			cout << " \n";
			cout << "       La opcion digitada es incoreccta: " << endl;
			cout << " \n";
			system("pause");
			system("cls");
			break;

		}
	} while (entrar > 8);
}
