#pragma once
#include "Deportista.h"
#include "Triatlonista.h"
#include "Pago.h"
#include "Lista.h"

class Cliente {
private:
	Deportista* triatlonista; 
	string estado;
	int cantCursMatri;
	Lista<Pago>* listPagos;

public:
	Cliente(string, string, string, int, int, int, double, char, double, double, double, double, int, int, int, string = "Activo", int = 0);
	virtual ~Cliente();
	string getEstado();
	void setEstado(string);
	int getCantCursMatri();
	void setCantCursMatri(int);
	Deportista* getDeportista();
	string getIdDeportista();
	Lista<Pago>* getListPagos();
	void agregarPago(Pago*);
	void sumarRestarCantCursMatri(int);
	void determinaMorosidad();
	
	string getToStringBasico();
	string toString();
	string toStringArchivo();
	
};

