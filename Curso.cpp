#include "Curso.h"

Curso::Curso() {
	descrip = " ";
	nombre = " ";
	nivel = ' ';
	codigo = 0;
	listGrupos = new Lista<Grupo>();
}

Curso::Curso(string _descrip, string _nombre, char _nivel, int _codigo) {
	descrip = _descrip;
	nombre = _nombre;
	nivel = _nivel;
	codigo = _codigo;
	listGrupos = new Lista<Grupo>();
}

Curso::~Curso() {
}

void Curso::setDescrip(string _descrip) {
	descrip = _descrip;
}

void Curso::setNombre(string _nombre) {
	nombre = _nombre;
}

void Curso::setNivel(char _nivel) {
	nivel = _nivel;
}

void Curso::setCodigo(int _codigo) {
	codigo = _codigo;
}

string Curso::getDescrip() {
	return descrip;
}

string Curso::getNombre() {
	return nombre;
}

char Curso::getNivel() {
	return nivel;
}

int Curso::getCodigo() {
	return codigo;
}

Lista<Grupo>* Curso::getListGrupos() {
	return listGrupos;
}

string Curso::toString() {
	stringstream s;
	s << "Nombre del curso: " << nombre << endl;
	s << "Nivel del curso: " << nivel << endl;
	s << "Cantidad de grupos: " << listGrupos->getCan() << endl;
	s << "Descripcion del curso: " << descrip << endl;
	s << "Detalle de grupos abiertos para el curso: " << endl;
	s << "Grupo   " << "Cupo   " << "Cantidad" << endl;
	s << listGrupos->mostrarInfoGrupos();
	return s.str();
}

string Curso::toStringBasico() {
	stringstream s;
	s << codigo << "  " << nombre << endl;
	return s.str();
}
