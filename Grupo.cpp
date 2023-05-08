#include "Grupo.h"

//Constructores y Destructor
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

Grupo::Grupo(string _nomInst, string _idInst, int _cupo, int _semanas, string _horaI, string _horaF, char _dia, int _numero, int _diaF, int _mesF, int _annioF) {
	instructor = new Instructor(_nomInst, _idInst);
	cupo = _cupo;
	fechaInicio = new Fecha(_diaF, _mesF, _annioF);
	semanas = _semanas;
	horaI = _horaI;
	horaF = _horaF;
	dia = _dia;
	numero = _numero;
	listClientes = new Lista<Cliente>();
}

Grupo::~Grupo() {
	delete instructor;
	delete fechaInicio;
	delete listClientes;
}

//Setters y Getters
int Grupo::getCupo() { return cupo; }
void Grupo::setCupo(int _cupo) { cupo = _cupo; }

Fecha* Grupo::getFechaInicio() { return fechaInicio; }
void Grupo::setFechaInicio(Fecha* _fecha) { fechaInicio = _fecha; }

int Grupo::getSemanas() { return semanas; }
void Grupo::setSemanas(int _semanas) { semanas = _semanas; }

string Grupo::getHoraI() { return horaI; }
void Grupo::setHoraI(string _hora) { horaI = _hora; }

string Grupo::getHoraF() { return horaF; }
void Grupo::setHoraF(string _hora) { horaF = _hora; }

char Grupo::getDia() { return dia; }
void Grupo::setDia(char _dia) { dia = _dia; }

int Grupo::getNumero() { return numero; }
void Grupo::setNumero(int _num) { numero = _num; }

Instructor* Grupo::getInstructor() { return instructor; }
void Grupo::setInstructor(Instructor* _instructor) { instructor = _instructor; }

Lista<Cliente>* Grupo::getListClientes() { return listClientes; }

//Metodos varios
string Grupo::reporteDepMatri() {
	stringstream s;
	if (listClientes->cantidadElementos() == 0) {
		s << "No hay clientes matriculados en el grupo # " << numero << endl;
	}
	else {
		s << "Lista de matriculados en el grupo # " << numero << endl;
		s << listClientes->clientesMatriculados();
	}
	return s.str();
}

bool Grupo::matricular(Cliente* client) {
	if (listClientes->cantidadElementos() < cupo) {
		listClientes->insertarFinal(client);
		cupo--;
		return true;
	}
	return false;
}

bool Grupo::desmatricular(string id) {
	if (listClientes->cancelarMatricula(id)) {
		cupo++;
		return true;
	}
	return false;
}

//Metodos toString()
string Grupo::toString() {
	stringstream s;
	s << "---------INFORMACION DE GRUPO---------\n";
	s << "Numero de grupo: " << numero << endl;
	s << instructor->toString();
	s << "Cupo maximo: " << cupo << endl;
	s << "Cantidad de clientes matriculados: " << listClientes->cantidadElementos() << endl;
	s << "Semanas de duracion: " << semanas << endl;
	s << "Dia: " << dia << endl;
	s << "Horario: " << horaI << "-" << horaF << endl;
	s << "---------------------------------------";
	return s.str();
}

string Grupo::toStringBasico2() {
	stringstream s;
	s << numero << "\t" << cupo << endl;
	return s.str();
}

string Grupo::toStringBasico() {
	stringstream s;
	s << numero << "\t\t" << dia << "\t\t" << horaI << "-" << horaF << "\t\t" << cupo << "\t\t" << listClientes->cantidadElementos() << endl;
	return s.str();
}

string Grupo::toStringArchivo() {
	stringstream s;
	s << instructor->toStringArchivo();
	s << cupo + listClientes->cantidadElementos() << DELIMITA_CAMPO; //Se restaura el valor original de cupos, así al matricular los clientes este regresa al valor que tenia al guardar datos.
	s << semanas << DELIMITA_CAMPO;
	s << horaI << DELIMITA_CAMPO;
	s << horaF << DELIMITA_CAMPO;
	s << dia << DELIMITA_CAMPO;
	s << numero << DELIMITA_CAMPO;
	s << fechaInicio->toStringArchivo() << DELIMITA_REGISTRO;
	int cantClientes = listClientes->cantidadElementos();
	for (int i = 0; i < cantClientes; i++) {
		s << listClientes->obtenerElementoPos(i)->getIdDeportista() << DELIMITA_CAMPO << DELIMITA_REGISTRO; //Delimita registro para que cuando se cargue, haya vectores de un elemento.
	}
	return s.str();
}