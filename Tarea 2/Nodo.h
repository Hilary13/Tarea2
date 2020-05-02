#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <sstream>
#include <string>

template<class T>
class Nodo
{
	T* info;
	Nodo<T>* sig;

public:
	Nodo(T*);
	Nodo<T>* getSig();
	T* getInfo();
	void setSig(Nodo<T>* info);
};
//-----------------------------------------------------------------------------------
template<class T>
Nodo<T>::Nodo(T* info)
{
	this->info = info;
	sig = NULL;
}
//-----------------------------------------------------------------------------------
template<class T>
Nodo<T>* Nodo<T>::getSig()
{
	return sig;
}
//-----------------------------------------------------------------------------------
template<class T>
T* Nodo<T>::getInfo()
{
	return info;
}
//-----------------------------------------------------------------------------------
template<class T>
void Nodo<T>::setSig(Nodo<T>* info)
{
	sig = info;
}

#endif