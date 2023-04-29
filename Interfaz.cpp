#include "Interfaz.h"

Interfaz::Interfaz() {
	gym = new Gimnasio();
	listClientes = new Lista<Cliente>();
	listCursos = new Lista<Curso>();
}

void Interfaz::menuPrincipal() {
	int dia, mes, annio;
	cout << "Bienvenido a Gimnasio UNA Fitness" << endl;
	cout << "Digite la fecha actual (DD/MM/AAAA)" << endl;
	cout << "Dia: " << endl;
	cin >> dia;
	cout << "Mes: " << endl;
	cin >> mes;
	cout << "Annio: " << endl;
	cin >> annio;
	Fecha* fecha = new Fecha(dia, mes, annio);
	gym->setFechaActual(fecha);
	system("cls");

	int opc;
	cout << "---------MENU PRINCIPAL---------" << endl;
	cout << "1. Administracion General" << endl;
	cout << "2. Control de Deportistas" << endl;
	cout << "3. Control de Cursos" << endl;
	cout << "4. Control de Grupos" << endl;
	cout << "5. Control de Pagos" << endl;
	cout << "6. Guardar en Archivos y Salir" << endl << endl;
	cout << "Digite una opcion del menu: " << endl;
	cin >> opc;
	system("cls");

	switch (opc) {
	case 1:
		menuAdmin();
		break;
	case 2:
		menuDeportistas();
		break;
	case 3:
		menuCursos();
		break;
	case 4:
	case 5:
	case 6:
	default:
		cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
		system("pause");
		system("cls");
		break;
	}
}

void Interfaz::menuAdmin() {
	bool salida = true;
	string nom;
	double mensualidad;
	int opc;
	cout << "---Administracion General---" << endl;
	cout << "1. Nombre del Gimnasio" << endl;
	cout << "2. Monto de Mensualidad" << endl;
	cout << "3. Volver al menu principal" << endl;
	cout << "Digite una opcion del menu: " << endl;
	cin >> opc;
	system("cls");

	while (!salida) {
		switch (opc) {
		case 1:
			cout << "Ingrese el nombre del gimnasio: " << endl;
			cin >> nom;
			gym->setNombre(nom);
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "Ingrese el monto de la mensualidad: " << endl;
			cin >> mensualidad;
			gym->setMensualidad(mensualidad);
			system("pause");
			system("cls");
			break;

		case 3:
			salida = false;
			break;

		default:
			cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Interfaz::menuDeportistas() {
	int opc;
	bool salida = true;
	string id, tel, nom;
	int dia, mes, annio, horasEntreno, cantPartIronMan, canTriGanados;
	char sexo;
	double estatura, peso, grasaCorp, masaMusc, temp;
	cout << "-------Control de Deportistas-------" << endl;
	cout << "1. Ingreso nuevo deportista" << endl;
	cout << "2. Modificacion de deportsita" << endl;
	cout << "3. Listado de deportistas" << endl;
	cout << "4. Detalle de deportista especifico" << endl;
	cout << "5. Devolverse al menu principal" << endl << endl;
	cout << "Digite una opcion: " << endl;
	cin >> opc;

	while (!salida) {
		switch (opc) {
		case 1:
			cout << "Datos generales: " << endl;
			cout << "ID: " << endl;
			cin >> id;
			cout << "Telefono: " << endl;
			cin >> tel;
			cout << "Nombre completo: " << endl;
			cin >> nom;
			cout << "Fecha de nacimiento (DD/MM/AAAA): " << endl;
			cout << "Dia: " << endl;
			cin >> dia;
			cout << "Mes: " << endl;
			cin >> mes;
			cout << "Annio: " << endl;
			cin >> annio;
			cout << "Sexo: " << endl;
			cin >> sexo;
			cout << "Horas de entrenamiento: " << endl;
			cin >> horasEntreno;
			cout << "Cantidad de participaciones en IronMan: " << endl;
			cin >> cantPartIronMan;
			cout << "Cantidad de triatlones ganados: " << endl;
			cin >> canTriGanados;
			cout << "Datos biometricos basicos: " << endl;
			cout << "Estatura: " << endl;
			cin >> estatura;
			cout << "Peso: " << endl;
			cin >> peso;
			cout << "Grasa corporal: " << endl;
			cin >> grasaCorp;
			cout << "Masa muscular: " << endl;
			cin >> masaMusc;
			cout << "Temperatura promedio: " << endl;
			cin >> temp;

			Fecha* f = new Fecha(dia, mes, annio);
			Ciclista* c = new Ciclista(horasEntreno, temp);
			Corredor* corre = new Corredor(sexo, estatura);
			Nadador* n = new Nadador(masaMusc, peso, grasaCorp);
			Triatlonista* t = new Triatlonista(id, nom, tel, f, cantPartIronMan, canTriGanados, c, corre, n);
			Cliente* client = new Cliente(t);

			listClientes->insertarFinal(client);
			system("pause");
			system("cls");
			break;

		case 2:
			modificarDeportista();
			break;

		case 3:
			listadoDeportistas();
			break;

		case 4:
			cout << "Digite el ID del deportista: " << endl;
			cin >> id;
			if (listClientes->clienteEncontrado(id)) {
				cout<<"Deportista encontrado!"<<endl;
			}
			cout << listClientes->mostrarCliente(id);
			system("pause");
			system("cls");
			break;

		case 5:
			salida = false;
			break;

		default:
			cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Interfaz::listadoDeportistas() {
	int opc;
	bool salida = true;
	cout << "1. Listado General" << endl;
	cout << "2. Listado de deportistas activos" << endl;
	cout << "3. Listado de deportistas inactivos" << endl;
	cout << "4. Listado de deportistas en morosidad" << endl;
	cout << "5. Devolverse" << endl << endl;
	cout << "Digite una opcion: " << endl;
	cin >> opc;

	while (!salida) {
		switch (opc) {
		case 1:
			cout << listClientes->toString();
			system("pause");
			system("cls");
			break;

		case 2:
			cout << listClientes->depActivos();
			system("pause");
			system("cls");
			break;

		case 3:
			cout << listClientes->depInactivos();
			system("pause");
			system("cls");
			break;

		case 4:
			break;

		case 5:
			salida = false;
			break;

		default:
			cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Interfaz::modificarDeportista() {
	int opc;
	bool salida = true;
	string id, tel, nom, estado;
	int dia, mes, annio, horasEntreno, cantPartIronMan, canTriGanados;
	char sexo;
	double estatura, peso, grasaCorp, masaMusc;
	cout << "Digite el id del deportista que desea modificar: " << endl;
	cin >> id;
	if (listClientes->clienteEncontrado(id) == true) {
		cout << "Deportista encontrado!" << endl;
	}
	cout << "Que dato desea modificar: " << endl;
	cout << "1. Nombre" << endl;
	cout << "2. Telefono" << endl;
	cout << "3. Fecha de nacimiento" << endl;
	cout << "4. Sexo" << endl;
	cout << "5. Estatura" << endl;
	cout << "6. Peso" << endl;
	cout << "7. Porc de grasa corporal" << endl;
	cout << "8. Porc de masa muscular" << endl;
	cout << "9. Estado" << endl;
	cout << "10. Horas entrenamiento" << endl;
	cout << "11. Cantidad de participaciones en IronMan" << endl;
	cout << "12. Cantidad de triatlones ganados" << endl;
	cout << "13. Devolverse" << endl << endl;
	cout << "Digite una opcion: " << endl;
	cin >> opc;
	while (!salida) {
		switch (opc) {
		case 1:
			cout << "Ingrese el nombre nuevo: " << endl;
			cin >> nom;
			listClientes->obtenerCliente(id)->getDeportista()->setNombre(nom);
			cout << "Nombre modificado con exito!" << endl;
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "Ingrese el numero de telefono nuevo: " << endl;
			cin >> tel;
			listClientes->obtenerCliente(id)->getDeportista()->setTelefono(tel);
			cout << "Telefono modificado con exito!" << endl;
			system("pause");
			system("cls");
			break;

		case 3:
			cout << "Ingrese la nueva fecha de nacimiento (DD/MM/AAAA): " << endl;
			cout << "Dia: " << endl;
			cin >> dia;
			cout << "Mes: " << endl;
			cin >> mes;
			cout << "Annio: " << endl;
			cin >> annio;
			Fecha* f = new Fecha(dia, mes, annio);
			listClientes->obtenerCliente(id)->getDeportista()->setFechaNac(f);
			cout << "Fecha de nacimiento modificada con exito!" << endl;
			system("pause");
			system("cls");
			break;

		case 4:
			cout << "Ingrese el sexo nuevo: " << endl;
			cin >> sexo;
			listClientes->obtenerCliente(id)->getDeportista()->getCorredor()->setSexo(sexo);
			cout << "Sexo modificado con exito!" << endl;
			system("pause");
			system("cls");
			break;

		case 5:
			cout << "Ingrese la nueva estatura: " << endl;
			cin >> estatura;
			listClientes->obtenerCliente(id)->getDeportista()->getCorredor()->setEstatura(estatura);
			cout << "Estatura modificada con exito!" << endl;
			system("pause");
			system("cls");
			break;

		case 6:
			cout << "Ingrese el peso nuevo: " << endl;
			cin >> peso;
			listClientes->obtenerCliente(id)->getDeportista()->getNadador()->setPeso(peso);
			cout << "Peso modificado con exito!" << endl;
			system("pause");
			system("cls");
			break;

		case 7:
			cout << "Ingrese el nuevo porcentaje de grasa corporal: " << endl;
			cin >> grasaCorp;
			listClientes->obtenerCliente(id)->getDeportista()->getNadador()->setPorcGrasaCorp(grasaCorp);
			cout << "Porcentaje modificado con exito!" << endl;
			system("pause");
			system("cls");
			break;

		case 8:
			cout << "Ingrese el nuevo porcentaje de masa muscular: " << endl;
			cin >> masaMusc;
			listClientes->obtenerCliente(id)->getDeportista()->getNadador()->setMasaMuscular(masaMusc);
			cout << "Porcentaje modificado con exito!" << endl;
			system("pause");
			system("cls");
			break;

		case 9:
			cout << "Ingrese el nuevo estado (Activo/Inactivo): " << endl;
			cin >> estado;
			listClientes->obtenerCliente(id)->setEstado(estado);
			cout << "Estado modificado con exito!" << endl;
			system("pause");
			system("cls");
			break;

		case 10:
			cout << "Ingrese la nueva cantidad de horas de entrenamiento: " << endl;
			cin >> horasEntreno;
			listClientes->obtenerCliente(id)->getDeportista()->getCiclista()->setHorasEntreno(horasEntreno);
			cout << "Horas de entrenamiento modificadas con exito!" << endl;
			system("pause");
			system("cls");
			break;

		case 11:
			cout << "Ingrese la nueva cantidad de participaciones en IronMan: " << endl;
			cin >> cantPartIronMan;
			listClientes->obtenerCliente(id)->getDeportista()->setCantPartIronMan(cantPartIronMan);
			cout << "Partcipaciones en IronMan modificadas con exito!" << endl;
			system("pause");
			system("cls");
			break;

		case 12:
			cout << "Ingrese la nueva cantidad de triatlones ganadas: " << endl;
			cin >> canTriGanados;
			listClientes->obtenerCliente(id)->getDeportista()->setCantTriGanados(canTriGanados);
			cout << "Triatlones ganados modificados con exito!" << endl;
			system("pause");
			system("cls");
			break;

		case 13:
			salida = false;
			break;

		default:
			cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

}
void Interfaz::menuCursos() {
	int opc;
	int cod, codAux, cantGrupos;
	char nivel;
	string nombre, descrip;
	bool salida = true;
	cout << "1. Ingreso nuevo curso" << endl;
	cout << "2. Reporte de curso especifico" << endl;
	cout << "3. Modificacion de curso especifico" << endl;
	cout << "4. Devolverse" << endl;
	cout << endl;
	cout << "Digite una opcion: ";
	cin >> opc;

	while (!salida) {
		switch (opc) {
		case 1:
			cout << "Digite el codigo del curso: ";
			cin >> cod;
			cout << "Digite el nombre del curso: ";
			cin >> nombre;
			cout << "Digite el nivel (P = Principiantes / I = Intermedio / A = Avanzado): ";
			cin >> nivel;
			cout << "Cantidad de grupos: ";
			cin >> cantGrupos;
			cout << "Descripcion del curso: ";
			cin >> descrip;
			Curso* c = new Curso(descrip, nombre, nivel, cod);
			c->getListGrupos()->setCan(cantGrupos);
			listCursos->insertarFinal(c);
			cout << "Curso registrado con exito!" << endl;
			system("pause");
			system("cls");
			break;

		case 2:
			cout << listCursos->mostrarCursosBasico();
			cout << endl;
			cout << "Digite el codigo del curso: ";
			cin >> codAux;
			if (listCursos->cursoEncontrado(codAux) == true) {
				cout << "Curso encontrado!" << endl;
			}
			else {
				cout << "No se encontro el curso" << endl;
			}
			cout << listCursos->mostrarInfoCurso(codAux);
			system("pause");
			system("cls");
			break;

		case 3:
			modificarCurso();
			break;

		default:
			cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
void Interfaz::modificarCurso() {
	int opc;
	int cod, codAux, cantGrupos;
	char nivel;
	string nombre, descrip;
	bool salida = true;
	cout << "Digite el codigo del curso especifico: ";
	cin >> codAux;
	if (listCursos->cursoEncontrado(codAux) == true) {
		cout << "Curso encontrado!" << endl;
	}
	else {
		cout << "No se encontro el curso" << endl;
	}
	cout << "Cual dato desea modificar" << endl;
	cout << "1. Codigo" << endl;
	cout << "2. Nombre" << endl;
	cout << "3. Nivel" << endl;
	cout << "4. Descripcion" << endl;
	cout << "5. Cantidad de grupos" << endl;
	cout << "6. Devolverse" << endl << endl;
	cout << "Digite una opcion: ";
	cin >> opc;

	while (!salida) {
		switch (opc) {
		case 1:
			cout << "Digite el nuevo codigo para el curso: ";
			cin >> cod;
			listCursos->obtenerCurso(codAux)->setCodigo(cod);
			system("cls");
			break;

		case 2:
			cout << "Ingrese el nuevo nombre del curso: ";
			cin >> nombre;
			listCursos->obtenerCurso(codAux)->setNombre(nombre);
			system("cls");
			break;

		case 3:
			cout << "Ingrese el nuevo nivel para el curso (P = Principiantes / I = Intermedio / A = Avanzado): ";
			cin >> nivel;
			listCursos->obtenerCurso(codAux)->setNivel(nivel);
			system("cls");
			break;

		case 4:
			cout << "Ingrese la nueva descripcion del curso: ";
			cin >> descrip;
			listCursos->obtenerCurso(codAux)->setDescrip(descrip);
			system("cls");
			break;

		case 5:
			cout << "Digite la nueva cantidad de grupos para el curso: ";
			cin >> cantGrupos;
			listCursos->obtenerCurso(codAux)->getListGrupos()->setCan(cantGrupos);
			system("cls");
			break;

		default:
			cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Interfaz::menuGrupos() {
	int opc, cod;
	string id, idAux, nombre, horaI, horaF;
	int cupo, dia, mes, annio, semanas, num, numAux;
	char d;
	bool salida = true;
	cout << "1. Ingreso de nuevo grupo" << endl;
	cout << "2. Modificacion de grupo en especifico" << endl;
	cout << "3. Matricula en grupo especifico" << endl;
	cout << "4. Reporte de un grupo especifico" << endl;
	cout << "5. Reporte de deportistas matriculados en un grupo" << endl;
	cout << "6. Cancelacion de matricula en grupo" << endl;
	cout << "7. Devolverse" << endl << endl;
	cout << "Digite una opcion: ";
	cin >> opc;

	while (!salida) {
		switch (opc) {
		case 1:
			cout << listCursos->mostrarCursosBasico();
			cout << "Digite el codigo del curso: ";
			cin >> cod;
			if (listCursos->cursoEncontrado(cod) == true) {
				cout << "Curso encontrado!" << endl;
			}
			else {
				cout << "El curso solicitado no existe" << endl;
			}
			cout << "Digite el ID del instructor: ";
			cin >> id;
			cout << "Digite el nombre del instructor: ";
			cin >> nombre;
			cout << "Digite el cupo maximo: ";
			cin >> cupo;
			cout << "Digite el numero de grupo: ";
			cin >> num;
			cout << "Fecha de inicio (DD/MM/AAAA): ";
			cout << "Dia: ";
			cin >> dia;
			cout << "Mes: ";
			cin >> mes;
			cout << "Annio: ";
			cin >> annio;
			cout << "Semanas de duracion: ";
			cin >> semanas;
			cout << "Horario: " << endl;
			cout << "Digite el dia de la semana (L-X-M-J-V-S-D): ";
			cin >> d;
			cout << "Digite la hora de inicio (hora militar): ";
			cin >> horaI;
			cout << "Digite la hora de finalizacion (hora militar): ";
			cin >> horaF;
			Instructor* i = new Instructor(nombre, id);
			Fecha* f = new Fecha(dia, mes, annio);
			Grupo* g = new Grupo(i, cupo, f, semanas, horaI, horaF, dia, num);
			listCursos->obtenerCurso(cod)->getListGrupos()->insertarFinal(g);
			system("pause");
			system("cls");
			break;

		case 2:
			modificarGrupo();
			break;

		case 3:
			cout << "Digite el ID del deportista: " << endl;
			cin >> idAux;
			if (listClientes->clienteEncontrado(idAux) == true) {
				cout << "Deportista encontrado!" << endl;
			}
			else {
				cout << "No se encontro ningun deportista con ese ID" << endl;
			}

			cout << "Digite el codigo del curso: " << endl;
			cin >> cod;
			if (listCursos->cursoEncontrado(cod) == true) {
				cout << "Curso encontrado" << endl;
			}
			else {
				cout << "No se encontro ningun curso con ese codigo" << endl;
			}

			cout << "Para el curso deseado existen los siguientes grupos disponibles: " << endl << endl;
			cout << "# Grupo   " << "Dia   " << "Horario   " << "Cupo   " << "Cantidad" << endl;
			cout << listCursos->obtenerCurso(cod)->getListGrupos()->mostrarInfoGrupos() << endl;
			cout << "Digite el numero de grupo deseado: " << endl;
			cin >> numAux;
			Cliente* c = listClientes->obtenerCliente(idAux);
			listCursos->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->matricular(c);
			system("pause");
			system("cls");
			break;

		case 4:
			cout << listCursos->mostrarCursosBasico();
			cout << "Digite el codigo del curso: ";
			cin >> cod;
			if (listCursos->cursoEncontrado(cod) == true) {
				cout << "Curso encontrado!" << endl;
			}
			else {
				cout << "El curso solicitado no existe" << endl;
			}
			cout << "Listado de grupos para el curso seleccionado: " << endl;
			cout << listCursos->obtenerCurso(cod)->getListGrupos()->mostrarNumerosGrupos() << endl;
			cout << "Digite el numero del grupo: " << endl;
			cin >> numAux;
			cout << listCursos->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->toString();
			system("pause");
			system("cls");
			break;

		case 5:
			cout << listCursos->mostrarCursosBasico();
			cout << "Digite el codigo del curso: ";
			cin >> cod;
			if (listCursos->cursoEncontrado(cod) == true) {
				cout << "Curso encontrado!" << endl;
			}
			else {
				cout << "El curso solicitado no existe" << endl;
			}
			cout << "Listado de grupos para el curso seleccionado: " << endl;
			cout << listCursos->obtenerCurso(cod)->getListGrupos()->mostrarNumerosGrupos() << endl;
			cout << "Digite el numero del grupo: " << endl;
			cin >> numAux;
			cout << listCursos->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->reporteDepMatri();
			system("pause");
			system("cls");
			break;
		}
	}
}

void Interfaz::modificarGrupo() {
	int opc, cod;
	string id, nombre, horaI, horaF;
	int cupo, dia, mes, annio, semanas, num, numAux;
	char d;
	bool salida = true;
	cout << listCursos->mostrarCursosBasico();
	cout << "Digite el codigo del curso: ";
	cin >> cod;
	if (listCursos->cursoEncontrado(cod) == true) {
		cout << "Curso encontrado!" << endl;
	}
	else {
		cout << "El curso solicitado no existe" << endl;
	}
	cout << "Digite el numero del curso que desea modificar: " << endl;
	cin >> numAux;
	cout << "Que desea modificar" << endl;
	cout << "1. ID del instructor" << endl;
	cout << "2. Nombre del instructor" << endl;
	cout << "3. Cupo maximo" << endl;
	cout << "4. Fecha de inicio" << endl;
	cout << "5. Semanas de duracion" << endl;
	cout << "6. Dia de la semana" << endl;
	cout << "7. Hora de inicio" << endl;
	cout << "8. Hora de finalizacion" << endl;
	cout << "9. Devolverse" << endl << endl;
	cout << "Digite una opcion: ";
	cin >> opc;
	
	while (!salida) {
		switch (opc) {
		case 1:
			cout << "Digite el nuevo ID del instructor: " << endl;
			cin >> id;
			listCursos->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->getInstructor()->setId(id);
			system("cls");
			break;

		case 2:
			cout << "Digite el nuevo nombre del instructor: " << endl;
			cin >> nombre;
			listCursos->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->getInstructor()->setNombre(nombre);
			system("cls");
			break;

		case 3:
			cout << "Digite el nuevo cupo del grupo: " << endl;
			cin >> cupo;
			listCursos->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->setCupo(cupo);
			system("cls");
			break;

		case 4:
			cout << "Digite la nueva fecha de inicio: " << endl;
			cout << "Dia: " << endl;
			cin >> dia;
			cout << "Mes: " << endl;
			cin >> mes;
			cout << "Annio: " << endl;
			cin >> annio;
			Fecha* f = new Fecha(dia, mes, annio);
			listCursos->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->setFechaInicio(f);
			system("cls");
			break;

		case 5:
			cout << "Digite la nueva cantidad de semanas de duracion: " << endl;
			cin >> semanas;
			listCursos->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->setSemanas(semanas);
			system("cls");
			break;

		case 6:
			cout << "Digite el nuevo dia de la semana para impartir el curso: " << endl;
			cin >> d;
			listCursos->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->setDia(d);
			system("cls");
			break;

		case 7:
			cout << "Digite la nueva hora de inicio: " << endl;
			cin >> horaI;
			listCursos->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->setHoraI(horaI);
			system("cls");
			break;

		case 8:
			cout << "Digite la nueva hora de finalizacion: " << endl;
			cin >> horaF;
			listCursos->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->setHoraF(horaF);
			system("cls");
			break;

		case 9:
			salida = false;
			break;

		default:
			cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
