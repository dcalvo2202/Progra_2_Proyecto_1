#include "Instructor.h"

Instructor::Instructor() {
	nombre = " ";
	id = " ";
}

Instructor::Instructor(string _nombre, string _id) {
	nombre = _nombre;
	id = _id;
}

Instructor::~Instructor() {
}

void Instructor::setNombre(string _nombre) {
	nombre = _nombre;
}

void Instructor::setId(string _id) {
	id = _id;
}

string Instructor::getNombre() {
	return nombre;
}

string Instructor::getId() {
	return id;
}

string Instructor::toString() {
	stringstream s;
	s << "ID del instructor: " << id << endl;
	s << "Nombre del instructor: " << nombre << endl;
	return s.str();
}
