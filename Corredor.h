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

public:
	Corredor();
	Corredor(char, double);
	virtual ~Corredor();
	char getSexo();
	void setSexo(char);
	double getEstatura();
	void setEstatura(double);
	string toString();
	string toStringArchivo();
};

