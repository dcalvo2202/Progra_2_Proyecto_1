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

public:
	Ciclista();
	Ciclista(int, double);
	virtual ~Ciclista();
	int getHorasEntreno();
	void setHorasEntreno(int);
	double getTemPromedio();
	void setTemPromedio(double);
	string toString();
	string toStringArchivo();
};

