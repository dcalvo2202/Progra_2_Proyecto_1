#include "Nadador.h"

//Constructores y Destructor
Nadador::Nadador() : masaMuscular{ 0 }, peso{ 0 }, porcGrasaCorp{ 0 } {}

Nadador::Nadador(double _masaMuscular, double _peso, double _porcGrasaCorp)
	: masaMuscular{ _masaMuscular }, peso{ _peso }, porcGrasaCorp{ _porcGrasaCorp } 
{}

Nadador::~Nadador(){}

//Setters y Getters
double Nadador::getMasaMuscular() { return masaMuscular; }
void Nadador::setMasaMuscular(double _masaMuscular) { masaMuscular = _masaMuscular; }

double Nadador::getPeso() { return peso; }
void Nadador::setPeso(double _peso) { peso = _peso; }

double Nadador::getPorcGrasaCorp() { return porcGrasaCorp; }
void Nadador::setPorcGrasaCorp(double _porcGrasaCorp) { porcGrasaCorp = _porcGrasaCorp; }

//Metodos toString

string Nadador::toString() {
	stringstream s;
	s << "Masa muscular del atleta: " << masaMuscular << endl;
	s << "Peso del atleta: " << peso << endl;
	s << "Porcentaje de grasa corporal del atleta: " << porcGrasaCorp  << " %" << endl;
	return s.str();
}

string Nadador::toStringArchivo() { //Para guardar los datos del nadador en el archivo
	stringstream s;
	s << masaMuscular << DELIMITA_CAMPO;
	s << peso << DELIMITA_CAMPO;
	s << porcGrasaCorp << DELIMITA_CAMPO;
	return s.str();
}