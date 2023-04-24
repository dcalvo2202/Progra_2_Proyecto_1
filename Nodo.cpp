#include "Nodo.h"

template<class T>
Nodo<T>::Nodo(T* _dato, Nodo<T>* _sig) {
	dato = _dato;
	sig = _sig;
}

template<class T>
Nodo<T>::~Nodo() {
	delete dato;
}

template<class T>
void Nodo<T>::setDato(T* _dato) {
	dato = _dato;
}

template<class T>
void Nodo<T>::setSig(Nodo<T>* _sig) {
	sig = _sig;
}

template<class T>
T* Nodo<T>::getDato() const {
	return dato;
}

template<class T>
Nodo<T>* Nodo<T>::getSig() const {
	return sig;
}