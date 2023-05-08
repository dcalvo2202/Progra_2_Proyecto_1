#include "Deportista.h"

//Constructores y Destructor
Deportista::Deportista() : id{ " " }, nombre{ " " }, telefono{ " " }, fechaNac{ new Fecha() } {}

Deportista::Deportista(string _cedula, string _nombre, string _telefono, int _dia, int _mes, int _annio)
	: id{ _cedula }, nombre{ _nombre }, telefono{ _telefono }, fechaNac{ new Fecha(_dia, _mes, _annio) } 
{}

Deportista::~Deportista() { delete fechaNac; }

//Setters y Getters
string Deportista::getId() { return id; }
void Deportista::setCedula(string _cedula) { id = _cedula; }

string Deportista::getNombre() { return nombre; }
void Deportista::setNombre(string _nombre) { nombre = _nombre; }

string Deportista::getTelefono() { return telefono; }
void Deportista::setTelefono(string _telefono) { telefono = _telefono; }

Fecha* Deportista::getFechaNac() { return fechaNac; }
void Deportista::setFechaNac(Fecha* _fechaNac) { fechaNac = _fechaNac; }

//Metodos toString()
string Deportista::toStringBasico() {
	stringstream s;
	s << id << "  " << nombre << endl;
	return s.str();
}
