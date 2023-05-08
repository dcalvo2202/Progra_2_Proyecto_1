#include "Gimnasio.h"

//Constructores y Destructor
Gimnasio::Gimnasio() 
	: nombre{ " " }, mensualidad{ 0.0 }, fechaActual{ new Fecha() }, listClientes { new Lista<Cliente>() }, listCursos{ new Lista<Curso>() } 
{}

Gimnasio::Gimnasio(string nom, double men, Fecha* fAct) : nombre{ nom }, mensualidad{ men }, 
	fechaActual{ fAct }, listClientes{ new Lista<Cliente>() }, listCursos{ new Lista<Curso>() } 
{}

Gimnasio::~Gimnasio(){
	delete listClientes;
	delete listCursos;
	delete fechaActual;
}

//Setters y Getters
string Gimnasio::getNombre() { return nombre; }
double Gimnasio::getMensualidad() { return mensualidad; }
void Gimnasio::setNombre(string nom) { nombre = nom; }
void Gimnasio::setMensualidad(double men) { mensualidad = men; }
void Gimnasio::setFechaActual(Fecha* fAct) { fechaActual = fAct; }
Fecha* Gimnasio::getFechaActual() { return fechaActual; }
Lista<Cliente>* Gimnasio::getListClientes() { return listClientes; }
Lista<Curso>* Gimnasio::getListCursos() { return listCursos; }

//Metodos varios
string Gimnasio::guardarDatos() {
	stringstream s;
	s << listClientes->guardarDatos();
	s << listCursos->guardarDatos();
	return s.str();
}

void Gimnasio::cargarDatos(string guardar[20], int cant) {
	if (cant == 16) { //Se verifica si la cantidad de datos es igual a la cantidad de datos que tiene un cliente.
		int _cantPartIronMan = stoi(guardar[3]); //Se convierte a int los datos del deportista que sean enteros.
		int _cantTriGanados = stoi(guardar[4]);
		int _horasEntreno = stoi(guardar[5]);
		int _dia = stoi(guardar[12]);
		int _mes = stoi(guardar[13]);
		int _annio = stoi(guardar[14]);
		//La cantidad de cursos matriculados se dejan en 0, pues los clientes se añadiran tras crear los grupos, devolviendo este dato al valor original
		int _cantCursosMatri = 0; 

		double _temPromedio = stod(guardar[6]); //Se convierte a double los datos del deportista que sean con decimales.
		double _estatura = stod(guardar[8]);
		double _masaMuscular = stod(guardar[9]);
		double _peso = stod(guardar[10]);
		double _porcGrasaCorp = stod(guardar[11]);

		const char* ext = guardar[7].c_str(); //Se convierte a char los datos del deportista que sean char.
		char _sexo = *ext;
		//Se ecesita crear un objeto de tipo cliente, colocando en el orden debido los atributos, para poder insertarlo en la lista de clientes.
		listClientes->insertarFinal(new Cliente(guardar[0], guardar[1], guardar[2], _cantPartIronMan, _cantTriGanados, _horasEntreno, _temPromedio, _sexo, _estatura, _masaMuscular, _peso, _porcGrasaCorp, _dia, _mes, _annio, guardar[15], _cantCursosMatri));
	}
	else {
		if (cant == 4) { //Se verifica si la cantidad de datos es igual a la cantidad de datos que tiene un curso.
			const char* niv = guardar[4].c_str(); //Se convierte a char los datos del curso que sean char.
			char _nivel = *niv;
			listCursos->insertarFinal(new Curso(guardar[0], guardar[2], _nivel, guardar[1]));
		}
		else {
			if (cant == 12) { //Se verifica si la cantidad de datos es igual a la cantidad de datos que tiene un grupo.
				int _cupo = stoi(guardar[3]); //Se convierte a int los datos del grupo que sean enteros.
				int _semanas = stoi(guardar[4]);
				int _numeroGrupo = stoi(guardar[8]);
				int _dia = stoi(guardar[9]);
				int _mes = stoi(guardar[10]);
				int _annio = stoi(guardar[11]);

				const char* day = guardar[7].c_str(); //Se convierte a char los datos del grupo que sean char.
				char _day = *day;

				listCursos->obtenerCurso(guardar[0])->getListGrupos()->insertarFinal(new Grupo(guardar[2], guardar[1], _cupo, _semanas, guardar[5], guardar[6], _day, _numeroGrupo, _dia, _mes, _annio));
			}
			else {
				if (cant == 1) {
					Cliente* agreg = listClientes->obtenerCliente(guardar[0]);
					listCursos->obtenerUltimoElemento()->getListGrupos()->obtenerUltimoElemento()->matricular(agreg);
					listClientes->obtenerCliente(guardar[0])->sumarRestarCantCursMatri(1);
					//Los grupos guardan el nombre del cliente inmediatamente, por lo que sabemos siempre que, un cliente que apareza en el archivo
					//de texto pertenece al ultimo grupo del ultimo curso creado.
				}
				else {
					if (cant == 5) {
						int _dia = stoi(guardar[0]); //Se convierte a int los datos del grupo que sean enteros.
						int _mes = stoi(guardar[1]);
						int _annio = stoi(guardar[2]);
						double _monto = stod(guardar[3]); //Y a double los que correspondan

						listClientes->obtenerUltimoElemento()->agregarPago(new Pago(_dia, _mes, _annio, _monto));
					}
				}
			}
		}
	}
}

//Metodo toString()
string Gimnasio::toString(){
	stringstream s;
	s << "Nombre del Gimnasio: " << nombre << endl;
	s << "Mensualidad: " << mensualidad << endl;
	s << "Fecha Actual: " << fechaActual->toString() << endl;
	return s.str();
}





