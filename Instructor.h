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
	void setNombre(string);
	void setId(string);
	string getNombre();
	string getId();
	string toString();
};

