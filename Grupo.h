#pragma once
#include "Instructor.h"
#include "Lista.h"
#include "Cliente.h"
#include "Fecha.h"

class Grupo {
private:
	Instructor* instructor;
	int cupo;
	Fecha* fechaInicio;
	int semanas;
	string horaI;
	string horaF;
	char dia;
	int numero;
	Lista<Cliente>* listClientes;
public:
	Grupo();
	Grupo(string, string, int, int, string, string, char, int, int, int, int);
	virtual ~Grupo();
	int getCupo();
	void setCupo(int);
	Fecha* getFechaInicio();
	void setFechaInicio(Fecha*);
	int getSemanas();
	void setSemanas(int);
	string getHoraI();
	void setHoraI(string);
	string getHoraF();
	void setHoraF(string);
	char getDia();
	void setDia(char);
	void setNumero(int);
	int getNumero();
	void setInstructor(Instructor*);
	Instructor* getInstructor();
	Lista<Cliente>* getListClientes();
	string reporteDepMatri();
	bool matricular(Cliente*);
	bool desmatricular(string);
	string toString();
	string toStringBasico();
	string toStringBasico2();
	string toStringArchivo();
};

