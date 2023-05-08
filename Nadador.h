#pragma once
#include <iostream>
#include <sstream>
#include "Lista.h"
#include "Fecha.h"
using namespace std;

class Nadador {
private:
	double masaMuscular;
	double peso;
	double porcGrasaCorp;

public:
	Nadador();
	Nadador(double, double, double);
	virtual ~Nadador();
	double getMasaMuscular();
	void setMasaMuscular(double);
	double getPeso();
	void setPeso(double);
	double getPorcGrasaCorp();
	void setPorcGrasaCorp(double);
	string toString();
	string toStringArchivo();
};

