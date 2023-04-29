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
	void setCupo(int);
	void setFechaInicio(Fecha*);
	void setSemanas(int);
	void setHoraI(string);
	void setHoraF(string);
	void setDia(char);
	void setNumero(int);
	Instructor* getInstructor();
	int getCupo();
	Fecha* getFechaInicio();
	int getSemanas();
	string getHoraI();
	string getHoraF();
	char getDia();
	int getNumero();
	Lista<Cliente>* getListClientes();
	string toString();
	string toStringBasico();
	string reporteDepMatri();
	void matricular(Cliente*);
	void desmatricular(string);
};

