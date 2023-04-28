#include "Ciclista.h"

Ciclista::Ciclista() : horasEntreno{ 0 }, temPromedio{ 0 } {
	fechasActCiclista = new Lista<Fecha>();
	fechasActCiclista->insertarFinal(new Fecha()); //Las fechas se guardan en el mismo orden en el que se crean los atributos
	fechasActCiclista->insertarFinal(new Fecha());
	fechasActCiclista->actualizarTodasFechasAtributo();
}

Ciclista::Ciclista(int _horasEntreno, double _temPromedio) : horasEntreno{ _horasEntreno }, temPromedio{ _temPromedio } {
	fechasActCiclista = new Lista<Fecha>();
	fechasActCiclista->insertarFinal(new Fecha);
	fechasActCiclista->insertarFinal(new Fecha);
	fechasActCiclista->actualizarTodasFechasAtributo();
}

Ciclista::~Ciclista() {
}

void Ciclista::setHorasEntreno(int _horasEntreno) {
	horasEntreno = _horasEntreno;
	fechasActCiclista->actualizarFechaAtributo(0);
}

void Ciclista::setTemPromedio(double _temPromedio) {
	temPromedio = _temPromedio;
	fechasActCiclista->actualizarFechaAtributo(1);
}

int Ciclista::getHorasEntreno() {
	return horasEntreno;
}

double Ciclista::getTemPromedio() {
	return temPromedio;
}

string Ciclista::getFechaActCiclista(int atr) {
	return fechasActCiclista->obtenerElementoPos(atr)->toString();
}

string Ciclista::toString() {
	stringstream s;
	s << "Temperatura promedio del atleta: " << temPromedio << endl;
	s << "Horas de entrenamiento del atleta: " << horasEntreno << endl;
	return s.str();
}
