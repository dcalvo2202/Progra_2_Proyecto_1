#include "Nadador.h"

Nadador::Nadador() : masaMuscular{ 0 }, peso{ 0 }, porcGrasaCorp{ 0 } {
	fechasActNadador = new Lista<Fecha>();
	fechasActNadador->insertarFinal(new Fecha()); //Las fechas se encuentran en el mismo orden en el que se crean los atributos
	fechasActNadador->insertarFinal(new Fecha());
	fechasActNadador->insertarFinal(new Fecha());
	fechasActNadador->actualizarTodasFechasAtributo();
}

Nadador::Nadador(double _masaMuscular, double _peso, double _porcGrasaCorp)
	: masaMuscular{ _masaMuscular }, peso{ _peso }, porcGrasaCorp{ _porcGrasaCorp } 
{
	fechasActNadador = new Lista<Fecha>();
	fechasActNadador->insertarFinal(new Fecha());
	fechasActNadador->insertarFinal(new Fecha());
	fechasActNadador->insertarFinal(new Fecha());
	fechasActNadador->actualizarTodasFechasAtributo();
}

Nadador::~Nadador()
{
}

void Nadador::setMasaMuscular(double _masaMuscular) {
	masaMuscular = _masaMuscular;
	fechasActNadador->actualizarFechaAtributo(0);
}

void Nadador::setPeso(double _peso) {
	peso = _peso;
	fechasActNadador->actualizarFechaAtributo(1);
}

void Nadador::setPorcGrasaCorp(double _porcGrasaCorp) {
	porcGrasaCorp = _porcGrasaCorp;
	fechasActNadador->actualizarFechaAtributo(2);
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

string Nadador::getFechaActNadador(int atr) {
	return fechasActNadador->obtenerElementoPos(atr)->toString();
}

string Nadador::toString() {
	stringstream s;
	s << "Masa muscular del atleta: " << masaMuscular << endl;
	s << "Peso del atleta: " << peso << endl;
	s << "Porcentaje de grasa corporal del atleta: " << porcGrasaCorp  << " %" << endl;
	return s.str();
}
