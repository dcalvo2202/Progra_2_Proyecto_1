#pragma once
#include "Fecha.h"
#include "Lista.h"

class Deportista {
protected:
	string id;
	string nombre;
	string telefono;
	Fecha* fechaNac;

public:
	Deportista();
	Deportista(string, string, string, int, int, int);
	virtual ~Deportista();
	string getId();
	void setCedula(string);
	string getNombre();
	void setNombre(string);
	string getTelefono();
	void setTelefono(string);
	Fecha* getFechaNac();
	void setFechaNac(Fecha*);
	virtual string toString() = 0;
	string toStringBasico();
	virtual string toStringArchivo() = 0;

};