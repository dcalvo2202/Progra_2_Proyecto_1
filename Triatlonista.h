#pragma once
#include "Deportista.h"
#include "Ciclista.h"
#include "Corredor.h"
#include "Nadador.h"


class Triatlonista : public Deportista {
private:
	int cantPartIronMan;
	int cantTriGanados;
	Ciclista* ciclista;
	Corredor* corredor;
	Nadador* nadador;

public:
	Triatlonista();
	Triatlonista(string, string, string, int, int, int, double, char, double, double, double, double, int, int, int);
	virtual ~Triatlonista();
	int getCantPartIronMan();
	void setCantPartIronMan(int);
	int getCantTriGanados();
	void setCantTriGanados(int);
	Ciclista* getCiclista();
	void setCiclista(Ciclista*);
	Corredor* getCorredor();
	void setCorredor(Corredor*);
	Nadador* getNadador();
	void setNadador(Nadador*);
	string toString();
	virtual string toStringArchivo();
};

