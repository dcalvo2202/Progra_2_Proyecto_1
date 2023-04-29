#include "Gimnasio.h"

Gimnasio::Gimnasio() {
	this->nombre = "";
	this->mensualidad = 0;
	this->listClientes = new Lista<Cliente>();
	this->listCursos = new Lista<Curso>();
	this->fechaActual = new Fecha;
}

Gimnasio::Gimnasio(string nom, double men, Fecha* fAct) : nombre{ nom }, mensualidad{ men }, 
	fechaActual{ fAct }, listClientes{ new Lista<Cliente>() }, listCursos{ new Lista<Curso>() } {}

Gimnasio::~Gimnasio(){
	/*delete listClientes;
	delete listCursos;
	delete fechaActual;*/
}
string Gimnasio::getNombre() { return nombre; }
double Gimnasio::getMensualidad() { return mensualidad; }
void Gimnasio::setNombre(string nom) { nombre = nom; }
void Gimnasio::setMensualidad(double men) { mensualidad = men; }
void Gimnasio::setFechaActual(Fecha* fAct) { fechaActual = fAct; }
Fecha* Gimnasio::getFechaActual() { return fechaActual; }
Lista<Cliente>* Gimnasio::getListClientes() { return listClientes; }
Lista<Curso>* Gimnasio::getListCursos() { return listCursos; }
string Gimnasio::toString(){
	stringstream s;
	s << "Algo se escribe así";
	return s.str();
}