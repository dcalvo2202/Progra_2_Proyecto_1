#include "Instructor.h"

//Constructores y Destructor
Instructor::Instructor() : nombre{ " " }, id{ " " } {}

Instructor::Instructor(string _nombre, string _id) : nombre{ _nombre }, id{ _id } {}

Instructor::~Instructor() {}

//Setters y Getters
string Instructor::getNombre() { return nombre; }
void Instructor::setNombre(string _nombre) { nombre = _nombre; }

string Instructor::getId() { return id; }
void Instructor::setId(string _id) { id = _id; }

//Metodos toString()
string Instructor::toString() {
	stringstream s;
	s << "ID del instructor: " << id << endl;
	s << "Nombre del instructor: " << nombre << endl;
	return s.str();
}

string Instructor::toStringArchivo() { //Para guardar los datos del instructor en el archivo
	stringstream s;
	s << id << ';';
	s << nombre << ';';
	return s.str();
}
