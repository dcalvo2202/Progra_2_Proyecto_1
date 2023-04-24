#include "Grupo.h"

Grupo::Grupo() {
	instructor = new Instructor();
	cupo = 0;
	fechaInicio = new Fecha();
	semanas = 0;
	horaI = " ";
	horaF = " ";
	dia = ' ';
	numero = 0;
	listClientes = new Lista<Cliente>();
}

Grupo::Grupo(Instructor* _inst, int _cupo, Fecha* _fechaI, int _semanas, string _horaI, string _horaF) {
	instructor = _inst;
	cupo = _cupo;
	fechaInicio = _fechaI;
	semanas = _semanas;
	horaI = _horaI;
	horaF = _horaF;
	listClientes = new Lista<Cliente>();
}

Grupo::~Grupo() {
}

void Grupo::setCupo(int _cupo) {
	cupo = _cupo;
}

void Grupo::setFechaInicio(Fecha* _fecha) {
	fechaInicio = _fecha;
}

void Grupo::setSemanas(int _semanas) {
	semanas = _semanas;
}

void Grupo::setHoraI(string _hora) {
	horaI = _hora;
}

void Grupo::setHoraF(string _hora) {
	horaF = _hora;
}

void Grupo::setDia(char _dia) {
	dia = _dia;
}

void Grupo::setNumero(int _num) {
	numero = _num;
}

Instructor* Grupo::getInstructor() {
	return instructor;
}

int Grupo::getCupo() {
	return cupo;
}

Fecha* Grupo::getFechaInicio() {
	return fechaInicio;
}

int Grupo::getSemanas() {
	return semanas;
}

string Grupo::getHoraI() {
	return horaI;
}

string Grupo::getHoraF() {
	return horaF;
}

char Grupo::getDia() {
	return dia;
}

int Grupo::getNumero() {
	return numero;
}

Lista<Cliente>* Grupo::getListClientes() {
	return listClientes;
}

string Grupo::toString() {
	stringstream s;
	s << "Numero de grupo: " << numero << endl;
	s << instructor->toString();
	s << "Cupo maximo: " << cupo << endl;
	s << "Cantidad de clientes matriculados: " << listClientes->getCan() << endl;
	s << "Semanas de duracion: " << semanas << endl;
	s << "Dia: " << dia << endl;
	s << "Horario: " << horaI << "-" << horaF << endl;
	return s.str();
}

string Grupo::toStringBasico() {
	stringstream s;
	s << numero << "   " << cupo << "   " << listClientes->getCan() << endl;
	return s.str();
}

string Grupo::reporteDepMatri() {
	stringstream s;
	s << "Lista de matriculados en el grupo # " << numero << endl;
	s << listClientes->clientesMatriculados();
	return s.str();
}

void Grupo::matricular(Cliente* client) {
	if (listClientes->getCan() < cupo) {
		listClientes->insertarFinal(client);
		cupo++;
		cout << "Deportista matriculado con exito!" << endl;
	}
	cout << "El grupo esta lleno" << endl;
}

void Grupo::desmatricular(string id) {
	if (listClientes->cancelarMatricula(id) == true) {
		cupo--;
		cout << "El deportista ha sido desmatriculado del grupo" << endl;
	}
}
