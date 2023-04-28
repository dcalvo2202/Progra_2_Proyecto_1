#include "Corredor.h"

Corredor::Corredor() : sexo{ ' ' }, estatura{ 0 } {
	fechasActCorredor = new Lista<Fecha>();
	fechasActCorredor->insertarFinal(new Fecha()); //Las fechas se encuentran en el mismo orden en el que se crean los atributos
	fechasActCorredor->insertarFinal(new Fecha());
	fechasActCorredor->actualizarTodasFechasAtributo();
}

Corredor::Corredor(char _sexo, double _estatura) : sexo{ _sexo }, estatura{ _estatura } {
	fechasActCorredor = new Lista<Fecha>();
	fechasActCorredor->insertarFinal(new Fecha());
	fechasActCorredor->insertarFinal(new Fecha());
	fechasActCorredor->actualizarTodasFechasAtributo();
}

Corredor::~Corredor() {}

void Corredor::setSexo(char _sexo) {
	sexo = _sexo;
	fechasActCorredor->actualizarFechaAtributo(0);
}

void Corredor::setEstatura(double _estatura) {
	estatura = _estatura;
	fechasActCorredor->actualizarFechaAtributo(1);
}

char Corredor::getSexo() {
	return sexo;
}

double Corredor::getEstatura() {
	return estatura;
}

string Corredor::getFechaActCorredor(int atr) {
	return fechasActCorredor->obtenerElementoPos(atr)->toString();
}

string Corredor::toString() {
	stringstream s;
	s << "Sexo del atleta: " << sexo << endl;
	s << "Estatura del atleta: " << estatura << endl;
	return s.str();
}
