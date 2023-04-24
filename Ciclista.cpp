#include "Ciclista.h"

Ciclista::Ciclista() {
	horasEntreno = 0;
	temPromedio = 0;
}

Ciclista::Ciclista(int _horasEntreno, double _temPromedio) {
	horasEntreno = _horasEntreno;
	temPromedio = _temPromedio;
}

Ciclista::~Ciclista() {
}

void Ciclista::setHorasEntreno(int _horasEntreno) {
	horasEntreno = _horasEntreno;
}

void Ciclista::setTemPromedio(double _temPromedio) {
	temPromedio = _temPromedio;
}

int Ciclista::getHorasEntreno() {
	return horasEntreno;
}

double Ciclista::getTemPromedio() {
	return temPromedio;
}

string Ciclista::toString() {
	stringstream s;
	s << "Temperatura promedio del atleta: " << temPromedio << endl;
	s << "Horas de entrenamiento del atleta: " << horasEntreno << endl;
	return s.str();
}
