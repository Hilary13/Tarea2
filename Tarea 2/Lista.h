#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "Lote.h"
#include "Producto.h"

template<class T>
class Lista
{
protected:
	Nodo<T>* primero;
	int tamanio;

public:
	Lista();
	Lista(Lista&);


	Producto buscaCodigo(int, T*);
	Lista<T>* retornaListCodigo(int);
	bool cambiaDescuento(int, float);
	bool verificaInventario(int, int);
	float getPrecio(int);
	float getDescuento(int);
	Lista<T>* facturasPorCobrar();
	void insertarInicio(T*);
	void insertarFinal(T*);
	void eliminarInicio();
	bool eliminarElemento(T*);
	bool buscar(T*);
	bool listaVacia();
	Nodo<T>* getPrimero();
	std::string toString();
	Lista& operator=(Lista&);
	~Lista();

	bool verificarCodigoExiste(int);
};


template<class T>
Producto Lista<T>::buscaCodigo(int i, T* aux)
{
	int codigo = 0;
	std::string nombre = "";
	std::string proveedor = "";
	int precio = 0;

	Nodo<Producto>* actual = primero;
	while (actual) {
		if (((*actual->getInfo()).getCodigo()) == i) {

			codigo = ((*actual->getInfo()).getCodigo());
			nombre = ((*actual->getInfo()).getNombre());
			proveedor = ((*actual->getInfo()).getProveedor());
			precio = ((*actual->getInfo()).getPrecio());
			aux->setCodigo(codigo);
			aux->setNombre(nombre);
			aux->setProveedor(proveedor);
			aux->setPrecio(precio);
			return *aux;
		}
		actual = actual->getSig();
	}
	aux->setCodigo(0);
	aux->setNombre("");
	aux->setProveedor("");
	aux->setPrecio(0);
	return *aux;

}

//-------------------------------------------------------------------------------------------------------------

template<class T>
Lista<T>* Lista<T>::retornaListCodigo(int i)
{
	Lista<T>* listAux = new Lista<T>;

	Nodo<T>* actual = primero;

	while (actual)
	{
		if (((actual->getInfo())->getCodigoProducto()) == i) {

			T* aux = actual->getInfo();
			listAux->insertarInicio(aux);

		}
		actual = actual->getSig();
	}
	return listAux;
}

template<class T>
bool Lista<T>::cambiaDescuento(int i, float des)
{
	Nodo<T>* actual = primero;
	while (actual) {
		if (((actual->getInfo())->getCodigo()) == i) {

			actual->getInfo()->setDescuento(des);
			return true;

		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
bool Lista<T>::verificaInventario(int i, int cantidad)
{
	Nodo<T>* actual = primero;
	while (actual) {
		if (((actual->getInfo())->getCodigo()) == i) {
			if (((actual->getInfo())->getCantidad()) >= cantidad) {
				(actual->getInfo())->setCantidad((actual->getInfo())->getCantidad() - cantidad);
				return true;
			}
			return false;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
inline float Lista<T>::getPrecio(int i)
{
	Nodo<T>* actual = primero;
	while (actual) {
		if (((actual->getInfo())->getCodigo()) == i) {

			return (((actual->getInfo())->getProducto())->getPrecio());
			
		}
		actual = actual->getSig();
	}
	return 0;
}

template<class T>
inline float Lista<T>::getDescuento(int i)
{
	Nodo<T>* actual = primero;
	while (actual) {
		if (((actual->getInfo())->getCodigo()) == i) {

			return ((actual->getInfo())->getDescuento());

		}
		actual = actual->getSig();
	}
	return 0;
}

template<class T>
inline Lista<T>* Lista<T>::facturasPorCobrar()
{
	Lista<T>* listAux = new Lista<T>;

	Nodo<T>* actual = primero;

	while (actual)
	{
		if (((actual->getInfo())->getCancelada()) == false){

			T* aux = actual->getInfo();
			listAux->insertarInicio(aux);

		}
		actual = actual->getSig();
	}
	return listAux;
}

//-------------------------------------------------------------------------------------------------------------
template<class T>
Lista<T>::Lista()
{
	primero = NULL;
	tamanio = 0;
}
//-------------------------------------------------------------------------------------------------------------
template <class T>
Lista<T>::Lista(Lista& aux)
{
	primero = NULL;
	tamanio = aux.tamanio;
	Nodo<T>* actual = aux.primero;
	while (actual)
	{
		insertarFinal(new T(*(actual->getInfo())));
		actual = actual->getSig();
	}
}
//-------------------------------------------------------------------------------------------------------------	
template<class T>
void Lista<T>::insertarInicio(T* dato)
{
	Nodo<T>* actual;
	actual = new Nodo<T>(dato);
	actual->setSig(primero);
	primero = actual;
	tamanio++;
}
//-------------------------------------------------------------------------------------------------------------
template <class T>
void Lista<T>::insertarFinal(T* dato)
{
	Nodo<T>* actual = primero;
	if (listaVacia()) {
		insertarInicio(dato);
	}
	else {
		while (actual->getSig() != NULL)
		{
			actual = actual->getSig();

		}
		actual->setSig(new Nodo<T>(dato));
		tamanio++;
	}
}
//-------------------------------------------------------------------------------------------------------------
template<class T>
void Lista<T>::eliminarInicio()
{
	Nodo<T>* actual = primero;
	if (primero == NULL)
	{
		std::cout << "La lista esta vacia" << std::endl;
	}
	else
	{
		actual = primero;
		primero = primero->getSig();
		delete actual;
		tamanio--;
	}
}
//-------------------------------------------------------------------------------------------------------------
template<class T>
bool Lista<T>::eliminarElemento(T* aux)
{
	Nodo<T>* punteroAnterior = NULL;
	Nodo<T>* actual = primero;
	actual = primero;
	if (primero == NULL)
	{
		return false;
	}

	if ((*primero->getInfo()) == (*aux))
	{
		actual = actual->getSig();
		delete (primero);
		primero = actual;
		return true;
	}

	while (actual != NULL && (*actual->getInfo()) != (*aux)) {
		punteroAnterior = actual;
		actual = actual->getSig();
	}

	if (actual == NULL) { return false; }
	else {
		punteroAnterior->setSig(actual->getSig());
		delete actual;
		return true;
	}
	return false;
}
//-------------------------------------------------------------------------------------------------------------
template<class T>
bool Lista<T>::buscar(T* aux)
{
	Nodo<T>* actual = primero;
	while (actual)
	{
		if ((*actual->getInfo()) == (*aux))
		{
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}
//-------------------------------------------------------------------------------------------------------------
template<class T>
bool Lista<T>::listaVacia()
{
	return (primero == NULL);
}
//-------------------------------------------------------------------------------------------------------------
template<class T>
std::string Lista<T>::toString()
{
	std::stringstream s;
	Nodo<T>* actual = primero;
	while (actual)
	{
		s << *actual->getInfo();
		actual = actual->getSig();
	}
	return s.str();
}
//-------------------------------------------------------------------------------------------------------------
template <class T>
Lista<T>& Lista<T>::operator=(Lista& aux)
{
	while (!listaVacia())
	{
		eliminarInicio();
	}
	primero = NULL;
	tamanio = aux.tamanio;
	Nodo<T>* actual = aux.primero;
	while (actual)
	{
		insertarFinal(new T(*(actual->getInfo())));
		actual = actual->getSig();
	}
	return *this;
}
//-------------------------------------------------------------------------------------------------------------
template<class T>
Lista<T>::~Lista()
{
	while (!listaVacia())
		eliminarInicio();
	tamanio = 0;
}
//-------------------------------------------------------------------------------------------------------------
template<class T>
Nodo<T>* Lista<T>::getPrimero() { return primero; }

template<class T>
bool Lista<T>::verificarCodigoExiste(int codigoAUX)
{
	Nodo<T>* actual = primero;
	while (actual)
	{
		if (((*actual->getInfo()).getCodigo()) == codigoAUX)
		{
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}


#endif

