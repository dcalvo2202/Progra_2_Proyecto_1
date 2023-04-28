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
	Lista<Fecha>* fechasActNadador; //Se guarda la fecha en la que se actualizo cada atributo

public:
	Nadador();
	Nadador(double, double, double);
	virtual ~Nadador();
	void setMasaMuscular(double);
	void setPeso(double);
	void setPorcGrasaCorp(double);
	double getMasaMuscular();
	double getPeso();
	double getPorcGrasaCorp();
	string getFechaActNadador(int); //Retorna la fecha en la que se actualizo el atributo
	string toString();
};

