#pragma once
#include "Lista.h"
#include "Grupo.h"

class Curso {
private:
	string descrip;
	string nombre;
	char nivel;
	string codigo;
	Lista<Grupo>* listGrupos;

public:
	Curso();
	Curso(string, string, char, string);
	virtual ~Curso();
	string getDescrip();
	void setDescrip(string);
	string getNombre();
	void setNombre(string);
	char getNivel();
	void setNivel(char);
	void setCodigo(string);
	string getIdentificador();
	Lista<Grupo>* getListGrupos();
	string toString();
	string toStringBasico();
	string toStringArchivo();
};

