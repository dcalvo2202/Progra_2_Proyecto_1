#pragma once
#include "Gimnasio.h"
#include "Triatlonista.h"
#include <string>

class Interfaz {
private:
	Gimnasio* gym;

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
	//void menuPagos();

	
};