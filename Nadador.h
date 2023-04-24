#pragma once
#include <iostream>
#include <sstream>
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
	void setMasaMuscular(double);
	void setPeso(double);
	void setPorcGrasaCorp(double);
	double getMasaMuscular();
	double getPeso();
	double getPorcGrasaCorp();
	string toString();
};

