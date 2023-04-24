#pragma once
#include <iostream>
template <class T>
class Nodo {
private:
	T* dato;
	Nodo* sig;
public:
	Nodo(T*, Nodo<T>*);
	virtual ~Nodo();
	void setDato(T*);
	void setSig(Nodo<T>*);
	T* getDato() const;
	Nodo<T>* getSig() const;
};