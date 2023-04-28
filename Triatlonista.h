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
	Lista<Fecha>* fechasActTriatlonista;
public:
	Triatlonista();
	Triatlonista(string, string, string, Fecha*, int, int, Ciclista*, Corredor*, Nadador*);
	virtual ~Triatlonista();
	void setCantPartIronMan(int);
	void setCantTriGanados(int);
	void setCiclista(Ciclista*);
	void setCorredor(Corredor*);
	void setNadador(Nadador*);
	int getCantPartIronMan();
	int getCantTriGanados();
	Ciclista* getCiclista();
	Corredor* getCorredor();
	Nadador* getNadador();
	string getFechaActTriatlonista(int);
	string toString();
};

