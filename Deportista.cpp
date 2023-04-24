#include "Deportista.h"

Deportista::Deportista() {
	id = " ";
	nombre = " ";
	telefono = " ";
	fechaNac = nullptr;
}

Deportista::Deportista(string _cedula, string _nombre, string _telefono, Fecha* _fechaNac) {
	id = _cedula;
	nombre = _nombre;
	telefono = _telefono;
	fechaNac = _fechaNac;
}

Deportista::~Deportista()
{
}

void Deportista::setCedula(string _cedula) {
	id = _cedula;
}

void Deportista::setNombre(string _nombre) {
	nombre = _nombre;
}

void Deportista::setTelefono(string _telefono) {
	telefono = _telefono;
}

void Deportista::setFechaNac(Fecha* _fechaNac) {
	fechaNac = _fechaNac;
}

string Deportista::getId() {
	return id;
}

string Deportista::getNombre() {
	return nombre;
}

string Deportista::getTelefono() {
	return telefono;
}

Fecha* Deportista::getFechaNac() {
	return fechaNac;
}

string Deportista::toStringBasico() {
	stringstream s;
	s << id << "  " << nombre << endl;
	return s.str();
}
