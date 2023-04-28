#pragma once
#include <iostream>
#include <sstream>
#include "Lista.h"
#include "Fecha.h"
using namespace std;

class Ciclista {
private:
	int horasEntreno;
	double temPromedio;
	Lista<Fecha>* fechasActCiclista; //Se guarda la fecha en la que se actualizo cada atributo

public:
	Ciclista();
	Ciclista(int, double);
	virtual ~Ciclista();
	void setHorasEntreno(int);
	void setTemPromedio(double);
	int getHorasEntreno();
	double getTemPromedio();
	string getFechaActCiclista(int); //Retorna la fecha en la que se actualizo el atributo
	string toString();
};

