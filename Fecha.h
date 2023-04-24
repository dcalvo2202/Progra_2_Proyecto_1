#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Fecha {
private:
	int dia;
	int mes;
	int annio;
public:
	Fecha();
	Fecha(int, int, int);
	virtual ~Fecha();
	void setDia(int);
	void setMes(int);
	void setAnnio(int);
	int getDia();
	int getMes();
	int getAnnio();
	string toString();
};

