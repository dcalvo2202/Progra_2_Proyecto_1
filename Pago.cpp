#include "Pago.h"

Pago::Pago(Fecha* _fecha, double _monto) {
	fechaPago = _fecha;
	monto = _monto;
}

Pago::Pago() {
	fechaPago = new Fecha();
	monto = 0;
}

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
	s << "Fecha de pago   " << "Mes   " << "Monto" << endl;
	s << fechaPago->toString() << "   " << fechaPago->getMes() << "   " << monto << endl;
	return s.str();
}
