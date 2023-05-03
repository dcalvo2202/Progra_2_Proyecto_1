#pragma once
#include "Nodo.cpp"
#include <sstream>
using namespace std;

template <class T>

class Lista {
private:
	Nodo<T>* primero;
	Nodo<T>* actual;
	int can;
public:
	Lista();
	virtual ~Lista();
	void insertarFinal(T*);
	string toString();
	int getCan();
	bool clienteEncontrado(string);
	bool grupoEncontrado(int);
	bool cursoEncontrado(int);
	string depActivos();
	string depInactivos();
	string depMorosos();
	string mostrarCliente(string);
	string clientesMatriculados();
	string mostrarInfoCurso(int);
	string mostrarCursosBasico();
	string mostrarInfoGrupos();
	T* obtenerCliente(string);
	T* obtenerGrupo(int);
	T* obtenerCurso(int);
	bool cancelarMatricula(string);
	int cantidadElementos();
	//void rellenaGrupos(int);
	string mostrarBasicoGrupos();
	Nodo<T>* getPrimero();
	T* obtenerElementoPos(int);

	//Para utilizar con fecha
	void actualizarFechaAtributo(int);
	void actualizarTodasFechasAtributo();


};
template<class T>
Lista<T>::Lista() {
	primero = nullptr;
	actual = nullptr;
	can = 0;
}

template<class T>
Lista<T>::~Lista() {
	while (primero != nullptr) {
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}

template<class T>
void Lista<T>::insertarFinal(T* dato) {
	actual = primero;
	if (primero == nullptr) {
		primero = new Nodo<T>(dato, nullptr);
	}
	else {
		while (actual->getSig() != nullptr) {
			actual = actual->getSig();
		}
		actual->setSig(new Nodo<T>(dato, nullptr));
	}
	can++;
}

template<class T>
string Lista<T>::toString() {
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getDato()->toString() << endl;
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
int Lista<T>::getCan() {
	return can;
}

template<class T>
bool Lista<T>::clienteEncontrado(string _id) {
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getIdDeportista() == _id) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
bool Lista<T>::grupoEncontrado(int num) {
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getCodigo() == num) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
bool Lista<T>::cursoEncontrado(int cod) {
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getCodigo() == cod) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
string Lista<T>::depActivos() {
	stringstream s;
	bool existen = false;
	s << "---Listado de deportistas activos---" << endl;
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getEstado() == "Activo") {
			s << actual->getDato()->getToStringBasico();
			if(!existen) existen = true;
		}
		actual = actual->getSig();
	}
	if(!existen)
		return "No hay deportistas activos registrados.\n";
	return s.str();
}

template<class T>
string Lista<T>::depInactivos() {
	stringstream s;
	bool existen = false;
	s << "---Listado de deportistas inactivos---" << endl;
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getEstado() == "Inactivo") {
			s << actual->getDato()->getToStringBasico();
			if(!existen) existen = true;
		}
		actual = actual->getSig();
	}
	if(!existen)
		return "No hay deportistas inactivos registrados.\n";
	return s.str();
}

template<class T>
string Lista<T>::depMorosos(){
	stringstream s;
	bool existen = false;
	s << "---Listado de deportistas en morosidad---" << endl;
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getEstado() == "Moroso") {
			s << actual->getDato()->getToStringBasico();
			if (!existen) existen = true;
		}
		actual = actual->getSig();
	}
	if (!existen)
		return "No hay deportistas morosos registrados.\n";
	return s.str();
}

template<class T>
string Lista<T>::mostrarCliente(string id) {
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getIdDeportista() == id) {
			return actual->getDato()->toString();
		}
		actual = actual->getSig();
	}
	return "no definido el return"; //cambiar luego
}

template<class T>
string Lista<T>::clientesMatriculados() {
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getDato()->getToStringBasico();
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
string Lista<T>::mostrarInfoCurso(int cod) {
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getCodigo() == cod) {
			return actual->getDato()->toString();
		}
		actual = actual->getSig();
	}
	return "return no definido"; //cambiar luego
}

template<class T>
string Lista<T>::mostrarCursosBasico() {
	actual = primero;
	while (actual != nullptr) {
		return actual->getDato()->toStringBasico();
		actual = actual->getSig();
	}
	return "return no definido"; //cambiar luego
}

template<class T>
string Lista<T>::mostrarInfoGrupos() {
	actual = primero;
	while (actual != nullptr) {
		return actual->getDato()->toStringBasico();
		actual = actual->getSig();
	}
	return ""; //Revisar este metodo, parece que se quiere mostrar informacion de los grupos, pero el return evita eso.
}

template<class T>
T* Lista<T>::obtenerCliente(string id) {
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getIdDeportista() == id) {
			return actual->getDato();
		}
		actual = actual->getSig();
	}
	return nullptr;
}

template<class T>
T* Lista<T>::obtenerGrupo(int num) {
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getNumero() == num) {
			return actual->getDato();
		}
		actual = actual->getSig();
	}
	return nullptr;
}

template<class T>
T* Lista<T>::obtenerCurso(int cod) {
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getCodigo() == cod) {
			return actual->getDato();
		}
		actual = actual->getSig();
	}
	return nullptr;
}

template<class T>
bool Lista<T>::cancelarMatricula(string id) {
	Nodo<T>* aux = nullptr;
	actual = primero;
	if (primero == nullptr) {
		return false;
	}
	else {
		if (primero->getDato()->getIdDeportista() == id) {
			actual = actual->getSig();
			primero = actual;
			return true;
		}
	}
	while (actual != nullptr && actual->getDato()->getIdDeportista() != id) {
		aux = actual;
		actual = actual->getSig();
	}
	if (actual == nullptr) {
		return false;
	}
	else {
		aux->setSig(actual->getSig());
		return true;
	}
	return false;
}

template<class T>
int Lista<T>::cantidadElementos(){
	int cant = 0;
	actual = primero;
	while (actual != nullptr) {
		cant++;
		actual = actual->getSig();
	}
	return cant;
}

//template<class T>
//void Lista<T>::rellenaGrupos(int can){
//	can -= cantidadElementos();
//	for (int i = 0; i < can; i++) {
//		insertarFinal(new T());
//	}
//}

template<class T>
string Lista<T>::mostrarBasicoGrupos(){
stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getDato()->toStringBasico() << endl;
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
Nodo<T>* Lista<T>::getPrimero() { return primero; }

template<class T>
T* Lista<T>::obtenerElementoPos(int pos) {
	actual = primero;
	for (int i = 0; i < pos; i++) {
		actual = actual->getSig();
	}
	return actual->getDato();
}

//Para utilizar con fecha
template<class T>
void Lista<T>::actualizarFechaAtributo(int act) {
	actual = primero;
	for (int i = 0; i < act; i++) {
		actual = actual->getSig();
	}
	actual->getDato()->actualizarPorActual();
}

template<class T>
void Lista<T>::actualizarTodasFechasAtributo() {
	actual = primero;
	while (actual != nullptr) {
		actual->getDato()->actualizarPorActual();
		actual = actual->getSig();
	}
}