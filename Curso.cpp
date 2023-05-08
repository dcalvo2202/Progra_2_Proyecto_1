#include "Curso.h"

//Constructores y Destructor
Curso::Curso() : descrip{ " " }, nombre{ " " }, nivel{ ' ' }, codigo{ " " }, listGrupos{ new Lista<Grupo>() } {}

Curso::Curso(string _descrip, string _nombre, char _nivel, string _codigo):
	descrip{ _descrip }, nombre{ _nombre }, nivel{ _nivel }, codigo{ _codigo }, listGrupos{ new Lista<Grupo>() } 
{}

Curso::~Curso() {}

//Setters y Getters
string Curso::getDescrip() { return descrip; }
void Curso::setDescrip(string _descrip) { descrip = _descrip; }

string Curso::getNombre() { return nombre; }
void Curso::setNombre(string _nombre) { nombre = _nombre; }

char Curso::getNivel() { return nivel; }
void Curso::setNivel(char _nivel) { nivel = _nivel; }

string Curso::getIdentificador() { return codigo; } //getCodigo()
void Curso::setCodigo(string _codigo) { codigo = _codigo; }

Lista<Grupo>* Curso::getListGrupos() { return listGrupos; }

//Metodos toString()
string Curso::toString() {
	stringstream s;
	s << "Nombre del curso: " << nombre << endl;
	s << "Nivel del curso: " << nivel << endl;
	s << "Cantidad de grupos: " << listGrupos->cantidadElementos() << endl;
	s << "Descripcion del curso: " << descrip << endl << endl;
	s << "Detalle de grupos abiertos para el curso: " << endl;
	s << "Grupo\t" << "Cupo\t" << endl;
	s << listGrupos->mostrarBasicoGrupos();
	return s.str();
}

string Curso::toStringBasico() {
	stringstream s;
	s << codigo << " " << nombre << endl;
	return s.str();
}

string Curso::toStringArchivo() { //Para guardar en el archivo
	stringstream s;
	s << descrip << DELIMITA_CAMPO;
	s << codigo << DELIMITA_CAMPO; 
	s << nombre << DELIMITA_CAMPO;
	s << nivel << DELIMITA_CAMPO; 
	s << DELIMITA_REGISTRO;

	int cantGrupos = listGrupos->cantidadElementos();
	for (int i = 0; i < cantGrupos;i++) {
		s << codigo << DELIMITA_CAMPO; //Se pone el codigo nuevamente para poder identificar al curso al que pertenece.
		s << listGrupos->obtenerElementoPos(i)->toStringArchivo();
	}
	return s.str();
}