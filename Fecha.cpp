#include "Fecha.h"

//Constructores y Destructor
Fecha::Fecha() : dia{ 0 }, mes{ 0 }, annio{ 0 } {}

Fecha::Fecha(int _dia, int _mes, int _annio) : dia{ _dia }, mes{ _mes }, annio{ _annio } {}

Fecha::~Fecha(){}

//Setters y Getters
int Fecha::getDia() { return dia; }
void Fecha::setDia(int _dia) { dia = _dia; }

int Fecha::getMes() { return mes; }
void Fecha::setMes(int _mes) { mes = _mes; }

int Fecha::getAnnio() { return annio; }
void Fecha::setAnnio(int _annio) { annio = _annio; }

//Metodos varios
void Fecha::actualizarPorActual() { //Actualiza la fecha por la fecha actual del sistema.
	SYSTEMTIME st; //Systemtime contiene informacion detallada sobre la fecha actual
	GetLocalTime(&st); //GetLocalTime es una funcion de la API de windows.

	dia = st.wDay; //Devuelve el valor en numero entero, del dia del mes en el que se encuentra el sistema.
	mes = st.wMonth; // //Devuelve el valor en numero entero, del mes en el que se encuentra el sistema.
	annio = st.wYear; //Devuelve el valor en numero entero, del año en el que se encuentra el sistema.
}

bool Fecha::operator < (const Fecha& f) { //Ayuda a determinar si un cliente es moroso o no.
	if (this->annio < f.annio) {
		return true;
	}
	else {
		if ((this->annio == f.annio) && (this->mes - f.mes <= -3)) { //Un cliente se determina como moroso tras 3 meses sin pagar
			return true;
		}
	}
	return false;
}

//Metodos toString()
string Fecha::toString() {
	stringstream s;
	s << dia << "/" << mes << "/" << annio;
	return s.str();
}

string Fecha::toStringArchivo() { //Para guardar los datos en el archivo
	stringstream s;
	s << dia << DELIMITA_CAMPO << mes << DELIMITA_CAMPO << annio << DELIMITA_CAMPO;
	return s.str();
}