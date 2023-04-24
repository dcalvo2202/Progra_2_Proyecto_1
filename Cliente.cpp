#include "Cliente.h"

Cliente::Cliente(Deportista* _deportista) {
	triatlonista = _deportista;
	estado = "Activo";
}

Cliente::~Cliente() {
}

void Cliente::setEstado(string _estado) {
	estado = _estado;
}

void Cliente::setCantCursMatri(int x) {
	cantCursMatri = x;
}

Deportista* Cliente::getDeportista() {
	return triatlonista;
}

string Cliente::getEstado() {
	return estado;
}

int Cliente::getCantCursMatri() {
	return cantCursMatri;
}

string Cliente::getIdDeportista() {
	return triatlonista->getId();
}

string Cliente::getToStringBasico() {
	return triatlonista->toStringBasico();
}

string Cliente::toString() {
	stringstream s;
	s << "---------INFORMACION DEL CLIENTE---------" << endl;
	s << triatlonista->toString() << endl;
	s << "Estado: " << estado << endl;
	s << "-----------------------------------------" << endl;
	return s.str();
}
