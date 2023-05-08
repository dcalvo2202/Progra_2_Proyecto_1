#include "Corredor.h"

//Constructores y Destructor
Corredor::Corredor() : sexo{ ' ' }, estatura{ 0 } {}

Corredor::Corredor(char _sexo, double _estatura) : sexo{ _sexo }, estatura{ _estatura } {}

Corredor::~Corredor() {}

//Setters y Getters
char Corredor::getSexo() { return sexo; }
void Corredor::setSexo(char _sexo) { sexo = _sexo; }

double Corredor::getEstatura() { return estatura; }
void Corredor::setEstatura(double _estatura) { estatura = _estatura; }

//Metodos toString
string Corredor::toString() {
	stringstream s;
	s << "Sexo del atleta: " << sexo << endl;
	s << "Estatura del atleta: " << estatura << endl;
	return s.str();
}

string Corredor::toStringArchivo() { //Para guardar los datos del corredor en el archivo
	stringstream s;
	s << sexo << DELIMITA_CAMPO;
	s << estatura << DELIMITA_CAMPO;
	return s.str();
}
