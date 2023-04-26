#include "Nadador.h"

Nadador::Nadador() : masaMuscular{ 0 }, peso{ 0 }, porcGrasaCorp{ 0 } {}

Nadador::Nadador(double _masaMuscular, double _peso, double _porcGrasaCorp)
	: masaMuscular{ _masaMuscular }, peso{ _peso }, porcGrasaCorp{ _porcGrasaCorp } {}

Nadador::~Nadador()
{
}

void Nadador::setMasaMuscular(double _masaMuscular) {
	masaMuscular = _masaMuscular;
}

void Nadador::setPeso(double _peso) {
	peso = _peso;
}

void Nadador::setPorcGrasaCorp(double _porcGrasaCorp) {
	porcGrasaCorp = _porcGrasaCorp;
}

double Nadador::getMasaMuscular() {
	return masaMuscular;
}

double Nadador::getPeso() {
	return peso;
}

double Nadador::getPorcGrasaCorp() {
	return porcGrasaCorp;
}

string Nadador::toString() {
	stringstream s;
	s << "Masa muscular del atleta: " << masaMuscular << endl;
	s << "Peso del atleta: " << peso << endl;
	s << "Porcentaje de grasa corporal del atleta: " << porcGrasaCorp  << " %" << endl;
	return s.str();
}
