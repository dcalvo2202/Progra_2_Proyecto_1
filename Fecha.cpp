#include "Fecha.h"

Fecha::Fecha() {
	dia = 0;
	mes = 0;
	annio = 0;
}

Fecha::Fecha(int _dia, int _mes, int _annio) {
	dia = _dia;
	mes = _mes;
	annio = _annio;
}

Fecha::~Fecha()
{
}

void Fecha::setDia(int _dia) {
	dia = _dia;
}

void Fecha::setMes(int _mes) {
	mes = _mes;
}

void Fecha::setAnnio(int _annio) {
	annio = _annio;

}

int Fecha::getDia() {
	return dia;
}

int Fecha::getMes() {
	return mes;
}

int Fecha::getAnnio() {
	return annio;
}

string Fecha::toString() {
	stringstream s;
	s << dia << "/" << mes << "/" << annio;
	return s.str();
}
