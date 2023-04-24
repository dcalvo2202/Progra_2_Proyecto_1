#pragma once
#include "Lista.h"
#include "Grupo.h"

class Curso {
private:
	string descrip;
	string nombre;
	char nivel;
	int codigo;
	Lista<Grupo>* listGrupos;
public:
	Curso();
	Curso(string, string, char, int);
	virtual ~Curso();
	void setDescrip(string);
	void setNombre(string);
	void setNivel(char);
	void setCodigo(int);
	string getDescrip();
	string getNombre();
	char getNivel();
	int getCodigo();
	Lista<Grupo>* getListGrupos();
	string toString();
	string toStringBasico();
};

