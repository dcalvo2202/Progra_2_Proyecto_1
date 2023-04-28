#pragma once
#include <iostream>
#include <sstream>
#include "Lista.h"
#include "Fecha.h"
using namespace std;

class Corredor {
private:
	char sexo;
	double estatura;
	Lista<Fecha>* fechasActCorredor; //Se guarda la fecha en la que se actualizo cada atributo

public:
	Corredor();
	Corredor(char, double);
	virtual ~Corredor();
	void setSexo(char);
	void setEstatura(double);
	char getSexo();
	double getEstatura();
	string getFechaActCorredor(int); //Retorna la fecha en la que se actualizo el atributo
	string toString();
};

