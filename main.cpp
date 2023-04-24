#include "Triatlonista.h"
#include "Cliente.h"
#include "Lista.h"

int main() {
    Ciclista* ciclista1 = new Ciclista(10, 25.0);
    Corredor* corredor1 = new Corredor('M', 1.8);
    Nadador* nadador1 = new Nadador(50.0, 70.0, 10.0);

    Ciclista* ciclista2 = new Ciclista(15, 23.5);
    Corredor* corredor2 = new Corredor('F', 1.6);
    Nadador* nadador2 = new Nadador(45.0, 60.0, 15.0);

    Ciclista* ciclista3 = new Ciclista(20, 22.0);
    Corredor* corredor3 = new Corredor('M', 1.9);
    Nadador* nadador3 = new Nadador(60.0, 80.0, 8.0);

    // Crear instancias de fechas
    Fecha* fecha1 = new Fecha(1, 1, 1990);
    Fecha* fecha2 = new Fecha(2, 2, 1995);
    Fecha* fecha3 = new Fecha(3, 3, 2000);

    // Crear instancias de triatletas
    Triatlonista* triatleta1 = new Triatlonista("12345678", "Juan Perez", "1111111", fecha1, 5, 2, ciclista1, corredor1, nadador1);
    Triatlonista* triatleta2 = new Triatlonista("23456789", "Maria Garcia", "2222222", fecha2, 3, 1, ciclista2, corredor2, nadador2);
    Triatlonista* triatleta3 = new Triatlonista("34567890", "Pedro Rodriguez", "3333333", fecha3, 7, 4, ciclista3, corredor3, nadador3);

    // Crear instancias de clientes
    Cliente* cliente1 = new Cliente(triatleta1);
    Cliente* cliente2 = new Cliente(triatleta2);
    Cliente* cliente3 = new Cliente(triatleta3);

	Lista<Cliente> *lista = new Lista<Cliente>();

	lista->insertarFinal(cliente1);
	lista->insertarFinal(cliente2);
	lista->insertarFinal(cliente3);

	cout << lista->toString();
	delete lista;
	system("pause");
	return 0;
}