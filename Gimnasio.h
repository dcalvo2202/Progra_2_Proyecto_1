#pragma once
#include "Curso.h"

class Gimnasio {
private:
	string nombre;
	double mensualidad;
	Fecha* fechaActual;
	Lista<Cliente>* listClientes;
	Lista<Curso>* listCursos;

public:
	Gimnasio();
	Gimnasio(string, double, Fecha* = nullptr);
	virtual ~Gimnasio();
	string getNombre();
	void setNombre(string);
	double getMensualidad();
	void setMensualidad(double);
	Fecha* getFechaActual();
	void setFechaActual(Fecha*);
	Lista<Cliente>* getListClientes();
	Lista<Curso>* getListCursos();
	string guardarDatos();
	void cargarDatos(string guardar[20], int);
	string toString();
	



};