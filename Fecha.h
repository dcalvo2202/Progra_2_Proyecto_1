#pragma once
#include <iostream>
#include <sstream>
#include <Windows.h>
#define DELIMITA_CAMPO ';' 
#define DELIMITA_REGISTRO '\n'
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
	int getDia();
	void setDia(int);
	int getMes();
	void setMes(int);
	int getAnnio();
	void setAnnio(int);
	void actualizarPorActual();
	bool operator < (const Fecha&);
	string toString();
	string toStringArchivo();
	
};

