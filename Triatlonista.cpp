#include "Triatlonista.h"

Triatlonista::Triatlonista() {
	cantPartIronMan = 0;
	cantTriGanados = 0;
	ciclista = new Ciclista();
	corredor = new Corredor();
	nadador = new Nadador();

	fechasActTriatlonista = new Lista<Fecha>();
	fechasActTriatlonista->insertarFinal(new Fecha()); //Las fechas se encuentran en el mismo orden en el que se crean los atributos
	fechasActTriatlonista->insertarFinal(new Fecha());
	fechasActTriatlonista->actualizarTodasFechasAtributo();
}

Triatlonista::Triatlonista(string _cedula, string _nombre, string _telefono, Fecha* _fechaNac, int _cantPartIronMan, 
	int _cantTriGanados, int _horasEntrenam, double _temPromedio, char _sexo, double _estatura, double _masaMuscular, 
	double _peso, double _porcGrasaCorporal): cantPartIronMan{ _cantPartIronMan }, cantTriGanados{ _cantTriGanados }, 
	ciclista{ new Ciclista(_horasEntrenam, _temPromedio)}, corredor { new Corredor(_sexo, _estatura)}, 
	nadador{ new Nadador(_masaMuscular, _peso, _porcGrasaCorporal)}, Deportista(_cedula, _nombre, _telefono, _fechaNac)
{
	fechasActTriatlonista = new Lista<Fecha>();
	fechasActTriatlonista->insertarFinal(new Fecha()); //Las fechas se encuentran en el mismo orden en el que se crean los atributos
	fechasActTriatlonista->insertarFinal(new Fecha());
	fechasActTriatlonista->actualizarTodasFechasAtributo();
}

Triatlonista::~Triatlonista()
{
}

void Triatlonista::setCantPartIronMan(int _cantPartIronMan) {
	cantPartIronMan = _cantPartIronMan;
	fechasActTriatlonista->actualizarFechaAtributo(0);
}

void Triatlonista::setCantTriGanados(int _cantTriGanados) {
	cantTriGanados = _cantTriGanados;
	fechasActTriatlonista->actualizarFechaAtributo(1);
}

void Triatlonista::setCiclista(Ciclista* _ciclista) {
	ciclista = _ciclista;
}

void Triatlonista::setCorredor(Corredor* _corredor) {
	corredor = _corredor;
}

void Triatlonista::setNadador(Nadador* _nadador) {
	nadador = _nadador;
}

int Triatlonista::getCantPartIronMan() {
	return cantPartIronMan;
}

int Triatlonista::getCantTriGanados() {
	return cantTriGanados;
}

Ciclista* Triatlonista::getCiclista() {
	return ciclista;
}

Corredor* Triatlonista::getCorredor() {
	return corredor;
}

Nadador* Triatlonista::getNadador() {
	return nadador;
}

string Triatlonista::toString() {
	stringstream s;
	s << "Datos Generales" << endl;
	s << "ID: " << id << endl;
	s << "Nombre completo: " << nombre << endl;
	s << "Telefono: " << telefono << endl;
	s << "Fecha de nacimiento: " << fechaNac << endl;
	s << "Sexo: " << corredor->getSexo() << endl;
	s << "Horas de entrenamiento: " << ciclista->getHorasEntreno() << endl;
	s << "Cantidad de participaciones en IronMan: " << cantPartIronMan << endl;
	s << "Cantidad de triatlones ganados: " << cantTriGanados << endl << endl;
	s << "Datos biometricos basicos" << endl;
	s << "Estatura: " << corredor->getEstatura() << endl;
	s << "Peso: " << nadador->getPeso() << endl;
	s << "Grasa corporal: " << nadador->getPorcGrasaCorp() << " %" << endl;
	s << "Masa muscular: " << nadador->getMasaMuscular() << " %" << endl;
	return s.str();
}
