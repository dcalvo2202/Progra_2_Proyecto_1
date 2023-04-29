#pragma once
#include "Fecha.h"
#include "Lista.h"

class Deportista {
protected:
	string id;
	string nombre;
	string telefono;
	Fecha* fechaNac;
	Lista<Fecha>* fechasActDeportista;
public:
	Deportista();
	Deportista(string, string, string, Fecha*);
	virtual ~Deportista();
	void setCedula(string);
	void setNombre(string);
	void setTelefono(string);
	void setFechaNac(Fecha*);
	string getId();
	string getNombre();
	string getTelefono();
	Fecha* getFechaNac();
	virtual string toString() = 0;
	string getFechaActDeportista(int);
	string toStringBasico();

};