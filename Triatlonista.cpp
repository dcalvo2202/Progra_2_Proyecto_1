#include "Triatlonista.h"

//Constructores y Destructor
Triatlonista::Triatlonista() 
	: cantPartIronMan{ 0 }, cantTriGanados{ 0 }, ciclista{ new Ciclista() }, corredor{ new Corredor() }, nadador{ new Nadador() } 
{}

Triatlonista::Triatlonista(string _cedula, string _nombre, string _telefono, int _cantPartIronMan, 
	int _cantTriGanados, int _horasEntrenam, double _temPromedio, char _sexo, double _estatura, double _masaMuscular, 
	double _peso, double _porcGrasaCorporal, int _dia, int _mes, int _annio): cantPartIronMan{ _cantPartIronMan }, cantTriGanados{ _cantTriGanados }, 
	ciclista{ new Ciclista(_horasEntrenam, _temPromedio)}, corredor { new Corredor(_sexo, _estatura)}, 
	nadador{ new Nadador(_masaMuscular, _peso, _porcGrasaCorporal)}, Deportista(_cedula, _nombre, _telefono, _dia, _mes, _annio)
{}

Triatlonista::~Triatlonista() {
	delete ciclista;
	delete corredor;
	delete nadador;
}

//Setters y Getters
int Triatlonista::getCantPartIronMan() { return cantPartIronMan; }
void Triatlonista::setCantPartIronMan(int _cantPartIronMan) { cantPartIronMan = _cantPartIronMan; }

int Triatlonista::getCantTriGanados() { return cantTriGanados; }
void Triatlonista::setCantTriGanados(int _cantTriGanados) { cantTriGanados = _cantTriGanados; }

Ciclista* Triatlonista::getCiclista() { return ciclista; }
void Triatlonista::setCiclista(Ciclista* _ciclista) { ciclista = _ciclista; }

Corredor* Triatlonista::getCorredor() { return corredor; }
void Triatlonista::setCorredor(Corredor* _corredor) { corredor = _corredor; }

Nadador* Triatlonista::getNadador() { return nadador; }
void Triatlonista::setNadador(Nadador* _nadador) { nadador = _nadador; }

//Metodos toString()
string Triatlonista::toString() {
	stringstream s;
	s << "--Datos Generales--" << endl;
	s << "ID: " << id << endl;
	s << "Nombre completo: " << nombre << endl;
	s << "Telefono: " << telefono << endl;
	s << "Fecha de nacimiento: " << fechaNac->toString() << endl;
	s << "Sexo: " << corredor->getSexo() << endl;
	s << "Horas de entrenamiento: " << ciclista->getHorasEntreno() << endl;
	s << "Cantidad de participaciones en IronMan: " << cantPartIronMan << endl;
	s << "Cantidad de triatlones ganados: " << cantTriGanados << endl << endl;

	s << "--Datos biometricos basicos--" << endl;
	s << "Estatura: " << corredor->getEstatura() << "M" <<endl;
	s << "Peso: " << nadador->getPeso() << "KG" << endl;
	s << "Grasa corporal: " << nadador->getPorcGrasaCorp() << " %" << endl;
	s << "Masa muscular: " << nadador->getMasaMuscular() << " %" << endl;
	return s.str();
}

string Triatlonista::toStringArchivo() {
	stringstream s;
	s << id << DELIMITA_CAMPO;
	s << nombre << DELIMITA_CAMPO;
	s << telefono << DELIMITA_CAMPO;
	s << cantPartIronMan << DELIMITA_CAMPO; 
	s << cantTriGanados << DELIMITA_CAMPO; 
	s << ciclista->toStringArchivo();
	s << corredor->toStringArchivo();
	s << nadador->toStringArchivo();
	s << fechaNac->toStringArchivo();
	return s.str();
}
