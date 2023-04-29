#pragma once
#include "Curso.h"

class Gimnasio {
private:
	string nombre;
	double mensualidad;
	Lista<Cliente>* listClientes;
	Lista<Curso>* listCursos;
	Fecha* fechaActual;

public:
	Gimnasio();
	Gimnasio(string, double, Fecha* = nullptr);
	virtual ~Gimnasio();
	string getNombre();
	double getMensualidad();
	void setNombre(string);
	void setMensualidad(double);
	void setFechaActual(Fecha*);
	Fecha* getFechaActual();
	Lista<Cliente>* getListClientes();
	Lista<Curso>* getListCursos();
	string toString();




};