#include "Cliente.h"

//Constructor y Destructor
Cliente::Cliente(string _cedula, string _nombre, string _telefono, int _cantPartIronMan, int _cantTriGanados, int _horasEntrenam, double _temPromedio,
	char _sexo, double _estatura, double _masaMuscular, double _peso, double _porcGrasaCorporal, int _dia, int _mes, int _annio, string _estado, int _cantCursos)
	: estado{ _estado }, cantCursMatri{ _cantCursos }, listPagos{ new Lista<Pago>() },
	triatlonista{ new Triatlonista(_cedula, _nombre, _telefono, _cantPartIronMan, _cantTriGanados, _horasEntrenam, _temPromedio, _sexo, _estatura, _masaMuscular, _peso, _porcGrasaCorporal, _dia, _mes, _annio) }
{}

Cliente::~Cliente() { delete listPagos; }

//Setters y Getters
string Cliente::getEstado() { return estado; }
void Cliente::setEstado(string _estado) { estado = _estado; }

int Cliente::getCantCursMatri() { return cantCursMatri; }
void Cliente::setCantCursMatri(int x) { cantCursMatri = x; }

string Cliente::getIdDeportista() { return triatlonista->getId(); }
Deportista* Cliente::getDeportista() { return triatlonista; }

Lista<Pago>* Cliente::getListPagos() { return listPagos; }

//Metodos Varios
void Cliente::agregarPago(Pago* pago) { //Agrega un nuevo pago al historial de pagos del cliente
	listPagos->insertarFinal(pago);
}

void Cliente::sumarRestarCantCursMatri(int cambia) { cantCursMatri += cambia; } //el parametro puede ser positivo o negativo para quitar o agregar cursos

void Cliente::determinaMorosidad() { //Determina si el cliente se encuentra en morosidad o no
	// Si el cliente ya ha realizado el primer pago se puede ejecutar esta funcion, de lo contrario no se hace nada, ni cambiarlo a inactivo.
	if (listPagos->obtenerUltimoElemento() != nullptr) {
		Fecha* ultimoPago = listPagos->obtenerUltimoElemento()->getFecha();
		Fecha* actual = new Fecha();
		actual->actualizarPorActual();

		//Si la fecha actual es 3 meses mayor que la del ultimo pago, y el cliente esta activo, entonces se encuentra en morosidad
		if (ultimoPago < actual && estado == "Activo") {
			estado = "Moroso";
		}
		else { //Si la fecha actual es menor a 3 en diferencia con el ultimo pago, entonces el cliente vuelve a estar activo.
			if (!(ultimoPago < actual) && estado == "Moroso") {
				estado = "Activo";
			}
		}
	}
}

//Metodos toString()
string Cliente::getToStringBasico() { return triatlonista->toStringBasico(); }

string Cliente::toString() {
	stringstream s;
	s << "---------INFORMACION DEL CLIENTE---------" << endl;
	s << triatlonista->toString() << endl;
	s << "Estado: " << estado << endl;
	s << "Cantidad de cursos matriculados: " << cantCursMatri << endl;
	s << "-----------------------------------------" << endl;
	return s.str();
}

string Cliente::toStringArchivo() {
	stringstream s;
	s << triatlonista->toStringArchivo();
	s << estado << DELIMITA_CAMPO;
	s << DELIMITA_REGISTRO;
	s << listPagos->guardarDatos();
	return s.str();
}