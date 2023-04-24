#include "Triatlonista.h"

Triatlonista::Triatlonista() {
	cantPartIronMan = 0;
	cantTriGanados = 0;
	ciclista = new Ciclista();
	corredor = new Corredor();
	nadador = new Nadador();
}

Triatlonista::Triatlonista(string _cedula, string _nombre, string _telefono, Fecha* _fechaNac, int _cantPartIronMan, int _cantTriGanados, Ciclista* _ciclista, Corredor* _corredor, Nadador* _nadador) : Deportista(_cedula, _nombre, _telefono, _fechaNac) {
	cantPartIronMan = _cantPartIronMan;
	cantTriGanados = _cantTriGanados;
	ciclista = _ciclista;
	corredor = _corredor;
	nadador = _nadador;
}

Triatlonista::~Triatlonista()
{
}

void Triatlonista::setCantPartIronMan(int _cantPartIronMan) {
	cantPartIronMan = _cantPartIronMan;
}

void Triatlonista::setCantTriGanados(int _cantTriGanados) {
	cantTriGanados = _cantTriGanados;
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
