#pragma once
#include "Gimnasio.h"
#include "Triatlonista.h"
#include <string>
#include <fstream> //Librería de escritura y lectura de archivos

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
	void guardarDatos();
	void cargarDatos();
	void menuGrupos();
	void modificarGrupo();
	void menuPagos();

	
};