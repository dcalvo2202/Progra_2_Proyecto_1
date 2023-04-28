#include "Deportista.h"

Deportista::Deportista() {
	id = " ";
	nombre = " ";
	telefono = " ";
	fechaNac = nullptr;

	fechasActDeportista = new Lista<Fecha>();
	fechasActDeportista->insertarFinal(new Fecha()); //Las fechas se encuentran en el mismo orden en el que se crean los atributos
	fechasActDeportista->insertarFinal(new Fecha());
	fechasActDeportista->insertarFinal(new Fecha());
	fechasActDeportista->insertarFinal(new Fecha());
	fechasActDeportista->actualizarTodasFechasAtributo();
}

Deportista::Deportista(string _cedula, string _nombre, string _telefono, Fecha* _fechaNac) {
	id = _cedula;
	nombre = _nombre;
	telefono = _telefono;
	fechaNac = _fechaNac;

	fechasActDeportista = new Lista<Fecha>();
	fechasActDeportista->insertarFinal(new Fecha()); //Las fechas se encuentran en el mismo orden en el que se crean los atributos
	fechasActDeportista->insertarFinal(new Fecha());
	fechasActDeportista->insertarFinal(new Fecha());
	fechasActDeportista->insertarFinal(new Fecha());
	fechasActDeportista->actualizarTodasFechasAtributo();
}

Deportista::~Deportista()
{
}

void Deportista::setCedula(string _cedula) {
	id = _cedula;
	fechasActDeportista->actualizarFechaAtributo(0);
}

void Deportista::setNombre(string _nombre) {
	nombre = _nombre;
	fechasActDeportista->actualizarFechaAtributo(1);
}

void Deportista::setTelefono(string _telefono) {
	telefono = _telefono;
	fechasActDeportista->actualizarFechaAtributo(2);
}

void Deportista::setFechaNac(Fecha* _fechaNac) {
	fechaNac = _fechaNac;
	fechasActDeportista->actualizarFechaAtributo(3);
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

string Deportista::getFechaActDeportista(int atr) {
	return fechasActDeportista->obtenerElementoPos(atr)->toString();
}

string Deportista::toStringBasico() {
	stringstream s;
	s << id << "  " << nombre << endl;
	return s.str();
}
