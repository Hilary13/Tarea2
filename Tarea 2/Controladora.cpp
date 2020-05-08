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
		cout << "       |  4. Muestra productos y lotes                 |" << endl;
		cout << "       |  5. Crear factura                             |" << endl;
		cout << "       |  6. Mostar todas las facturas creadas         |" << endl;
		cout << "       |  7. Mostrar facturas por cobrar               |" << endl;
		cout << "       |  8. Probar sobrecarga de operadores           |" << endl;
		cout << "       |  9. Salir                                     |" << endl;
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
			Interfaz::ingresarDescuentos();
			system("pause");
			system("cls");
			break;

		case '4':

			system("cls");
			Interfaz::muestraProductosLotes();
			system("pause");
			system("cls");
			break;

		case '5':

			system("cls");
			Interfaz::factura();
			system("pause");
			system("cls");
			break;

		case '6':

			system("cls");
			Interfaz::muestraFacturas();
			system("pause");
			system("cls");
			break;

		case '7':

			system("cls");
			Interfaz::muestraFacturasPorCobrar();
			system("pause");
			system("cls");
			break;

		case '8':

			system("cls");
			//probar sobrecarga de operadores
			system("pause");
			system("cls");
			break;

		case '9':
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
