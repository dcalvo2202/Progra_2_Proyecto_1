#pragma once
#include "Fecha.h"

class Pago {
private:
	Fecha* fechaPago;
	double monto;
public:
	Pago(int, int, int, double);
	Pago(Fecha*, double);
	Pago();
	virtual ~Pago();
	void setFecha(Fecha*);
	void setMonto(double);
	Fecha* getFecha();
	double getMonto();
	string toString();
	string toStringArchivo();
};

