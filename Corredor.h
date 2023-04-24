#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Corredor {
private:
	char sexo;
	double estatura;
public:
	Corredor();
	Corredor(char, double);
	virtual ~Corredor();
	void setSexo(char);
	void setEstatura(double);
	char getSexo();
	double getEstatura();
	string toString();
};

