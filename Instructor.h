#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Instructor {
private:
	string nombre;
	string id;
public:
	Instructor();
	Instructor(string, string);
	virtual ~Instructor();
	string getNombre();
	void setNombre(string);
	string getId();
	void setId(string);
	string toString();
	string toStringArchivo();
};

