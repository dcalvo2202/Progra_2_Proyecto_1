#pragma once
#include "Nodo.cpp"
#include <sstream>
using namespace std;

template <class T>

class Lista {
private:
	Nodo<T>* primero;
	Nodo<T>* actual;

public:
	Lista();
	virtual ~Lista();

	//Metodos de Clientes
	string depActivos();
	string depInactivos();
	string depMorosos();
	string mostrarCliente(string);
	string clientesMatriculados();
	bool clienteEncontrado(string);
	T* obtenerCliente(string);
	bool cancelarMatricula(string);

	//Metodos de Cursos
	bool cursoEncontrado(string);
	string mostrarInfoCurso(string);
	string mostrarCursosBasico();
	T* obtenerCurso(string);

	//Metodos de Grupos
	bool grupoEncontrado(int);
	string mostrarBasicoGrupos();
	string mostrarInfoGrupos();
	T* obtenerGrupo(int);
	T* obtenerGrupoPorCliente(string);
	bool verificarMatriculaExistente(string);

	//Para utilizar con fecha
	void actualizarFechaAtributo(int); 
	void actualizarTodasFechasAtributo();

	//Metodos Generales
	void insertarFinal(T*);
	string toString();
	int cantidadElementos();
	Nodo<T>* getPrimero();
	T* obtenerElementoPos(int);
	string guardarDatos();
	string guardarIdentificador();
	T* obtenerUltimoElemento();
	
	//void rellenaGrupos(int);
	
};

//Constructor y Destructor
template<class T>
Lista<T>::Lista() {
	primero = nullptr;
	actual = nullptr;
}

template<class T>
Lista<T>::~Lista() {
	while (primero != nullptr) {
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}

//Metodos de Clientes
template<class T>
string Lista<T>::depActivos() { //Devuelve un string con los clientes activos
	stringstream s;
	bool existen = false;
	s << "---Listado de deportistas activos---" << endl;
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getEstado() == "Activo") {
			s << actual->getDato()->getToStringBasico();
			if (!existen) existen = true;
		}
		actual = actual->getSig();
	}
	if (!existen)
		return "No hay deportistas activos registrados.\n";
	return s.str();
}

template<class T>
string Lista<T>::depInactivos() { //Devuelve un string con los clientes inactivos
	stringstream s;
	bool existen = false;
	s << "---Listado de deportistas inactivos---" << endl;
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getEstado() == "Inactivo") {
			s << actual->getDato()->getToStringBasico();
			if (!existen) existen = true;
		}
		actual = actual->getSig();
	}
	if (!existen)
		return "No hay deportistas inactivos registrados.\n";
	return s.str();
}

template<class T>
string Lista<T>::depMorosos() {	//Devuelve un string con los clientes morosos
	stringstream s;
	bool existen = false;
	s << "---Listado de deportistas en morosidad---" << endl;
	actual = primero;
	while (actual != nullptr) {
		actual->getDato()->determinaMorosidad();
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
string Lista<T>::mostrarCliente(string id) { //Devuelve un string con la informacion de un cliente especifico
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getIdDeportista() == id) {
			return actual->getDato()->toString();
		}
		actual = actual->getSig();
	}
	return "El cliente indicado no existe.";
}

template<class T>
string Lista<T>::clientesMatriculados() { //Devuelve un string con los clientes matriculados en un grupo
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getDato()->getToStringBasico();
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
bool Lista<T>::clienteEncontrado(string _id) { //Devuelve true si el cliente existe
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
T* Lista<T>::obtenerCliente(string id) { //Devuelve un cliente especifico
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
bool Lista<T>::cancelarMatricula(string id) { //Elimina un cliente de la lista de matriculados de un grupo
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


//Metodos de Cursos
template<class T>
bool Lista<T>::cursoEncontrado(string cod) { //Devuelve true si el curso existe
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getIdentificador() == cod) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
string Lista<T>::mostrarInfoCurso(string cod) { //Devuelve un string con la informacion de un curso especifico
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getIdentificador() == cod) {
			return actual->getDato()->toString();
		}
		actual = actual->getSig();
	}
	return "El curso indicado no existe.";
}

template<class T>
string Lista<T>::mostrarCursosBasico() { //Devuelve un string con la informacion basica de los cursos
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getDato()->toStringBasico();
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
T* Lista<T>::obtenerCurso(string cod) { //Devuelve un curso especifico
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getIdentificador() == cod) {
			return actual->getDato();
		}
		actual = actual->getSig();
	}
	return nullptr;
}

//Metodos de Grupos
template<class T>
bool Lista<T>::grupoEncontrado(int num) { //Devuelve true si el grupo existe
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getNumero() == num) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
string Lista<T>::mostrarBasicoGrupos() { //Devuelve un string con la informacion basica de los grupos
	stringstream s;
	actual = primero;
	if (actual == nullptr) {
		s << " No hay grupos registrados para este curso." << endl;
	}
	while (actual != nullptr) {
		s << actual->getDato()->toStringBasico2();
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
string Lista<T>::mostrarInfoGrupos() { //Devuelve un string con informacion un poco mas completa de los grupos
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getDato()->toStringBasico();
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
T* Lista<T>::obtenerGrupo(int num) { //Devuelve un grupo especifico
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
T* Lista<T>::obtenerGrupoPorCliente(string id){ //Busca un cliente en todos los grupos que tenga un curso y devuelve ese grupo
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getListClientes()->clienteEncontrado(id)) {
			return actual->getDato();
		}
		actual = actual->getSig();
	}
	return nullptr;
}

template<class T>
bool Lista<T>::verificarMatriculaExistente(string id) { //Verifica si el cliente ya esta matriculado en algun grupo de un curso especifico
	actual = primero;
	while (actual != nullptr) {
		if (actual->getDato()->getListClientes()->clienteEncontrado(id)) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

//Para utilizar con fecha
template<class T>
void Lista<T>::actualizarFechaAtributo(int act) { //Actualiza los valores de un objeto fecha por los de la fecha actual del sistema
	actual = primero;
	for (int i = 0; i < act; i++) {
		actual = actual->getSig();
	}
	actual->getDato()->actualizarPorActual();
}

template<class T>
void Lista<T>::actualizarTodasFechasAtributo() { //Actualiza los valores de todos los objetos fecha en una lista por los de la fecha actual del sistema
	actual = primero;
	while (actual != nullptr) {
		actual->getDato()->actualizarPorActual();
		actual = actual->getSig();
	}
}

//Metodos Generales
template<class T>
void Lista<T>::insertarFinal(T* dato) { //Inserta un dato al final de la lista
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
}

template<class T>
string Lista<T>::toString() { //Devuelve un string con la informacion de todos los elementos de la lista
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getDato()->toString() << endl;
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
int Lista<T>::cantidadElementos(){ //Devuelve la cantidad de elementos en la lista
	int cant = 0;
	actual = primero;
	while (actual != nullptr) {
		cant++;
		actual = actual->getSig();
	}
	return cant;
}

template<class T>
Nodo<T>* Lista<T>::getPrimero() { return primero; } //Devuelve el primer nodo de la lista

template<class T>
T* Lista<T>::obtenerElementoPos(int pos) { //Devuelve un elemento especifico de la lista segun su posicion
	actual = primero;
	for (int i = 0; i < pos; i++) {
		actual = actual->getSig();
	}
	return actual->getDato();
}

template<class T>
string Lista<T>::guardarDatos(){ //Activa los metodos toStringArchivo() de los objetos para guardar los datos de cada uno en un archivo .txt
stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getDato()->toStringArchivo();
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
string Lista<T>::guardarIdentificador() { //Devuelve un string con los identificadores de los objetos en la lista
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s<<actual->getDato()->getIdentificador();
		actual = actual->getSig();
	}
}

template<class T>
T* Lista<T>::obtenerUltimoElemento(){ //Devuelve el ultimo elemento de la lista
	actual = primero;
	while (actual->getSig() != nullptr) {
		actual = actual->getSig();
	}
	return actual->getDato();
}