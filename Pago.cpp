#include "Pago.h"

Pago::Pago(int _dia, int _mes, int _annio, double _monto) : fechaPago{ new Fecha(_dia, _mes, _annio) }, monto{ _monto } {}

Pago::Pago(Fecha* _fecha, double _monto) : fechaPago{ _fecha }, monto{ _monto } {}

Pago::Pago() : fechaPago{ new Fecha() }, monto{ 0 } {}

Pago::~Pago() {
}

void Pago::setFecha(Fecha* _fecha) {
	fechaPago = _fecha;
}

void Pago::setMonto(double _monto) {
	monto = _monto;
}

Fecha* Pago::getFecha() {
	return fechaPago;
}

double Pago::getMonto() {
	return monto;
}

string Pago::toString() {
	stringstream s;
	s << fechaPago->toString() << "\t\t" << fechaPago->getMes() << "\t\t" << monto << endl;
	return s.str();
}

string Pago::toStringArchivo() {
	stringstream s;
	s << fechaPago->toStringArchivo();
	s << monto << DELIMITA_CAMPO;
	s << 'P' << DELIMITA_CAMPO << DELIMITA_REGISTRO;
	return s.str();
}
