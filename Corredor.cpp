#include "Corredor.h"

Corredor::Corredor() : sexo{ ' ' }, estatura{ 0 } {}

Corredor::Corredor(char _sexo, double _estatura) : sexo{ _sexo }, estatura{ _estatura } {}

Corredor::~Corredor() {}

void Corredor::setSexo(char _sexo) {
	sexo = _sexo;
}

void Corredor::setEstatura(double _estatura) {
	estatura = _estatura;
}

char Corredor::getSexo() {
	return sexo;
}

double Corredor::getEstatura() {
	return estatura;
}

string Corredor::toString() {
	stringstream s;
	s << "Sexo del atleta: " << sexo << endl;
	s << "Estatura del atleta: " << estatura << endl;
	return s.str();
}
