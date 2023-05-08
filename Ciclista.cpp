#include "Ciclista.h"

//Constructores y Destructor
Ciclista::Ciclista() : horasEntreno{ 0 }, temPromedio{ 0 } {}

Ciclista::Ciclista(int _horasEntreno, double _temPromedio) : horasEntreno{ _horasEntreno }, temPromedio{ _temPromedio } {}

Ciclista::~Ciclista() {}

//Setters y Getters
int Ciclista::getHorasEntreno() { return horasEntreno; }
void Ciclista::setHorasEntreno(int _horasEntreno) { horasEntreno = _horasEntreno; }

double Ciclista::getTemPromedio() { return temPromedio; }
void Ciclista::setTemPromedio(double _temPromedio) { temPromedio = _temPromedio; }

//Metodos toString
string Ciclista::toString() {
	stringstream s;
	s << "Temperatura promedio del atleta: " << temPromedio << endl;
	s << "Horas de entrenamiento del atleta: " << horasEntreno << endl;
	return s.str();
}

string Ciclista::toStringArchivo() { //Devuelve un string con los datos del ciclista separados por DELIMITA_CAMPO para guardarlos en el archivo
	stringstream s;
	s << horasEntreno << DELIMITA_CAMPO;
	s << temPromedio << DELIMITA_CAMPO;
	return s.str();
}