#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Ciclista {
private:
	int horasEntreno;
	double temPromedio;
public:
	Ciclista();
	Ciclista(int, double);
	virtual ~Ciclista();
	void setHorasEntreno(int);
	void setTemPromedio(double);
	int getHorasEntreno();
	double getTemPromedio();
	string toString();
};

