#pragma once
#include "Gimnasio.h"
#include "Triatlonista.h"

class Interfaz {
private:
	Gimnasio* gym;
	Lista<Cliente>* listClientes;
	Lista<Curso>* listCursos;
public:
	Interfaz();
	void menuPrincipal();
	void menuAdmin();
	void menuDeportistas();
	void listadoDeportistas();
	void modificarDeportista();
	void menuCursos();
	void modificarCurso();
	void menuGrupos();
	void modificarGrupo();
	void menuPagos();

};