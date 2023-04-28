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

void Fecha::actualizarPorActual() {
	SYSTEMTIME st; //Systemtime contiene informacion detallada sobre la fecha actual
	GetLocalTime(&st); //GetLocalTime es una funcion de la API de windows.

	dia = st.wDay; //Devuelve el valor en numero entero, del dia del mes en el que se encuentra el sistema.
	mes = st.wMonth; // //Devuelve el valor en numero entero, del mes en el que se encuentra el sistema.
	annio = st.wYear; //Devuelve el valor en numero entero, del año en el que se encuentra el sistema.
}

string Fecha::toString() {
	stringstream s;
	s << dia << "/" << mes << "/" << annio;
	return s.str();
}
