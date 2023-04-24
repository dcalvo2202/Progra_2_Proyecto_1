#pragma once
#include "Deportista.h"
#include "Pago.h"
#include "Lista.h"

class Cliente {
private:
	Deportista* triatlonista;
	string estado;
	int cantCursMatri;
	Lista<Pago>* listPagos;
public:
	Cliente(Deportista*);
	virtual ~Cliente();
	void setEstado(string);
	void setCantCursMatri(int);
	Deportista* getDeportista();
	string getEstado();
	int getCantCursMatri();
	string getIdDeportista();
	string getToStringBasico();
	string toString();
};

