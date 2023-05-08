#include "Interfaz2.h"

Interfaz::Interfaz() {
	gym = new Gimnasio();
}

void Interfaz::menuPrincipal() {
	int dia, mes, annio, opc;
	//do{
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

	//} while ((dia >= 1 && dia<=31) && (mes >= 1 && mes <=12) && (annio >= 2023));
	
	do {
		cout << "---------MENU PRINCIPAL---------" << endl;
		cout << "1. Administracion General" << endl;
		cout << "2. Control de Deportistas" << endl;
		cout << "3. Control de Cursos" << endl;
		cout << "4. Control de Grupos" << endl;
		cout << "5. Control de Pagos" << endl;
		cout << "6. Guardar en Archivos y Salir" << endl << endl;
		cout << "Digite una opcion del menu: ";
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
			menuGrupos(); 
			break;
		case 5:
			menuPagos();
			break;
		case 6:
			guardarDatos();
			cout << "Datos guardados!\n";
			break;
		case 7:
			cargarDatos();
			break;
		default:
			cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
			break;
		}
		//system("Pause");
		system("cls");
	} while (opc != 6);
}

void Interfaz::menuAdmin() {
	bool salida = true;
	string nom;
	double mensualidad;
	int opc;

	do{
		cout << "---Administracion General---" << endl;
		cout << "1. Nombre del Gimnasio" << endl;
		cout << "2. Monto de Mensualidad" << endl;
		cout << "3. Volver al menu principal" << endl;
		cout << "Digite una opcion del menu: ";
		cin >> opc;
		cin.ignore();
		system("cls");

		if (opc == 1) {
			cout << "Ingrese el nombre del gimnasio: " << endl;
			getline(cin, nom);
			gym->setNombre(nom);
			cout << "Nombre modificado con exito" << endl;
			system("pause");
		}
		else {
			if (opc == 2) {
				cout << "Ingrese el monto de la mensualidad: " << endl;
				cin >> mensualidad;
				gym->setMensualidad(mensualidad);
				cout << "Mensualidad modificada con exito" << endl;
				system("pause");
			}
			else {
				if (opc == 3) {
					salida = false;
				}
				else {
					cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
					system("pause");
				}
			}
		}
		system("cls");
	} while (salida);
}

void Interfaz::menuDeportistas() {
	bool salida = true;
	string id, tel, nom;
	int dia, mes, annio, horasEntreno, cantPartIronMan, canTriGanados, opc;
	char sexo;
	double estatura, peso, grasaCorp, masaMusc, temp;

	while (salida) {
		cout << "-------Control de Deportistas-------" << endl;
		cout << "1. Ingreso nuevo deportista" << endl;
		cout << "2. Modificacion de deportista" << endl;
		cout << "3. Listado de deportistas" << endl;
		cout << "4. Detalle de deportista especifico" << endl;
		cout << "5. Devolverse al menu principal" << endl << endl;
		cout << "Digite una opcion: ";
		cin >> opc;
		system("cls");

		if (opc == 1) {
			cout << "------Ingrese los datos del deportista nuevo------" << endl;
			cout << "ID: ";
			cin >> id;
			cout << "\nTelefono: ";
			cin >> tel;
			cin.ignore();
			cout << "\nNombre completo: ";
			getline(cin, nom);
			cout << "\nFecha de nacimiento (DD/MM/AAAA): ";
			cout << "\nDia: ";
			cin >> dia;
			cout << "\nMes: ";
			cin >> mes;
			cout << "\nAnnio: ";
			cin >> annio;
			cout << "\nSexo: ";
			cin >> sexo;
			cout << "\nHoras de entrenamiento: ";
			cin >> horasEntreno;
			cout << "\nCantidad de participaciones en IronMan: ";
			cin >> cantPartIronMan;
			cout << "\nCantidad de triatlones ganados: ";
			cin >> canTriGanados;
			cout << "\n\n-----Datos biometricos basicos----- \n";
			cout << "\nEstatura en metros: ";
			cin >> estatura;
			cout << "\nPeso en Kg: ";
			cin >> peso;
			cout << "\nPorcentaje Grasa corporal: ";
			cin >> grasaCorp;
			cout << "\nPorcentaje Masa muscular: ";
			cin >> masaMusc;
			cout << "\nTemperatura promedio en grados celsius: ";
			cin >> temp;

			gym->getListClientes()->insertarFinal(new Cliente(id, nom, tel, cantPartIronMan, canTriGanados, horasEntreno, temp, sexo, estatura, masaMusc, peso, grasaCorp, dia, mes, annio));
			/*Triatlonista* t = new Triatlonista(id, nom, tel, cantPartIronMan, canTriGanados, horasEntreno, temp, sexo, estatura, masaMusc, peso, grasaCorp, dia, mes, annio);
			gym->getListClientes()->insertarFinal(new Cliente(t));*/
			cout << "Cliente añadido exitosamente!\n";
			system("pause");
			system("cls");
		}
		else {
			if (opc == 2) {
				modificarDeportista();
			}
			else {
				if (opc == 3) {
					listadoDeportistas();
				}
				else {
					if (opc == 4) {
						cout << "Digite el ID del deportista: ";
						cin >> id;
						if (gym->getListClientes()->clienteEncontrado(id)) {
							cout << "Deportista encontrado!" << endl << endl;
							cout << gym->getListClientes()->mostrarCliente(id);
						}
						else {
							cout << "El deportista no existe.\n";
						}
						system("pause");
						system("cls");
					}
					else {
						if (opc == 5) {
							salida = false;
						}
						else {
							cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
							system("pause");
							system("cls");
						}
					}
				}
			}
		}
		system("cls");
	}
}

void Interfaz::listadoDeportistas() {
	int opc;
	bool salida = true;
	
	while (salida) {
		cout << "1. Listado General" << endl;
		cout << "2. Listado de deportistas activos" << endl;
		cout << "3. Listado de deportistas inactivos" << endl;
		cout << "4. Listado de deportistas en morosidad" << endl;
		cout << "5. Devolverse" << endl << endl;
		cout << "Digite una opcion: ";
		cin >> opc;
		system("cls");
		switch (opc) {
		case 1:
			if (gym->getListClientes()->cantidadElementos() >= 1) {
				cout << gym->getListClientes()->toString() << endl;
			}
			else {
				cout << "No hay deportistas registrados.\n\n";
			}
			system("pause");
			break;

		case 2:
			cout << gym->getListClientes()->depActivos() << endl;
			system("pause");
			break;

		case 3:
			cout << gym->getListClientes()->depInactivos() << endl; 
			system("pause");
			break;

		case 4:
			cout << gym->getListClientes()->depMorosos() << endl;
			system("pause");
			break;

		case 5:
			salida = false;
			break;

		default:
			cout << "La opcion indicada no existe, por favor vuelva a intentarlo presionando Enter" << endl;
			system("pause");
			break;
		}
		system("cls");
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

	if (gym->getListClientes()->clienteEncontrado(id) == true) {
		cout << "Deportista encontrado!" << endl << endl;

		while (salida) {
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
			system("cls");
			if (opc == 1){
				cout << "Ingrese el nombre nuevo: " << endl;
				cin.ignore();
				getline(cin, nom);
				gym->getListClientes()->obtenerCliente(id)->getDeportista()->setNombre(nom);
				cout << "Nombre modificado con exito!" << endl;
				system("pause");
				system("cls");
			}
			else {
				if (opc == 2) {
					cout << "Ingrese el numero de telefono nuevo: " << endl;
					cin >> tel;
					gym->getListClientes()->obtenerCliente(id)->getDeportista()->setTelefono(tel);
					cout << "Telefono modificado con exito!" << endl;
					system("pause");
					system("cls");
				}
				else {
					if (opc == 3) {
						cout << "Ingrese la nueva fecha de nacimiento (DD/MM/AAAA): " << endl;
						cout << "Dia: ";
						cin >> dia;
						cout << "Mes: ";
						cin >> mes;
						cout << "Annio: ";
						cin >> annio;
						Fecha* f = new Fecha(dia, mes, annio);
						gym->getListClientes()->obtenerCliente(id)->getDeportista()->setFechaNac(f);
						cout << "Fecha de nacimiento modificada con exito!" << endl;
						system("pause");
						system("cls");
					}
					else {
						if (opc == 4) {
							cout << "Ingrese el nuevo sexo: ";
							cin >> sexo;
							dynamic_cast<Triatlonista*>(gym->getListClientes()->obtenerCliente(id)->getDeportista())->getCorredor()->setSexo(sexo);
							cout << "Sexo modificado con exito!" << endl;
							system("pause");
							system("cls");
						}
						else {
							if (opc == 5) {
								cout << "Ingrese la nueva estatura en metros: ";
								cin >> estatura;
								dynamic_cast<Triatlonista*>(gym->getListClientes()->obtenerCliente(id)->getDeportista())->getCorredor()->setEstatura(estatura);
								cout << "Estatura modificada con exito!" << endl;
								system("pause");
								system("cls");
							}
							else {
								if (opc == 6) {
									cout << "Ingrese el nuevo peso en kilogramos: ";
									cin >> peso;
									dynamic_cast<Triatlonista*>(gym->getListClientes()->obtenerCliente(id)->getDeportista())->getNadador()->setPeso(peso);
									cout << "Peso modificado con exito!" << endl;
									system("pause");
									system("cls");
								}
								else {
									if (opc == 7) {
										cout << "Ingrese el nuevo porcentaje de grasa corporal: ";
										cin >> grasaCorp;
										dynamic_cast<Triatlonista*>(gym->getListClientes()->obtenerCliente(id)->getDeportista())->getNadador()->setPorcGrasaCorp(grasaCorp);
										cout << "Porcentaje modificado con exito!" << endl;
										system("pause");
										system("cls");
									}
									else {
										if (opc == 8) {
											cout << "Ingrese el nuevo porcentaje de masa muscular: ";
											cin >> masaMusc;
											dynamic_cast<Triatlonista*>(gym->getListClientes()->obtenerCliente(id)->getDeportista())->getNadador()->setMasaMuscular(masaMusc);
											cout << "Porcentaje modificado con exito!" << endl;
											system("pause");
											system("cls");
										}
										else {
											if (opc == 9) {
												cout << "Ingrese el nuevo estado (Activo/Inactivo): ";
												cin >> estado;
												gym->getListClientes()->obtenerCliente(id)->setEstado(estado);
												cout << "Estado modificado con exito!" << endl;
												system("pause");
												system("cls");
											}
											else {
												if (opc == 10) {
													cout << "Ingrese la nueva cantidad de horas de entrenamiento: ";
													cin >> horasEntreno;
													dynamic_cast<Triatlonista*>(gym->getListClientes()->obtenerCliente(id)->getDeportista())->getCiclista()->setHorasEntreno(horasEntreno);
													cout << "Horas de entrenamiento modificadas con exito!" << endl;
													system("pause");
													system("cls");
												}
												else {
													if (opc == 11) {
														cout << "Ingrese la nueva cantidad de participaciones en IronMan: ";
														cin >> cantPartIronMan;
														dynamic_cast<Triatlonista*>(gym->getListClientes()->obtenerCliente(id)->getDeportista())->setCantPartIronMan(cantPartIronMan);
														cout << "Partcipaciones en IronMan modificadas con exito!" << endl;
														system("pause");
														system("cls");
													}
													else {
														if (opc == 12) {
															cout << "Ingrese la nueva cantidad de triatlones ganadas: ";
															cin >> canTriGanados;
															dynamic_cast<Triatlonista*>(gym->getListClientes()->obtenerCliente(id)->getDeportista())->setCantTriGanados(canTriGanados);
															cout << "Triatlones ganados modificados con exito!" << endl;
															system("pause");
															system("cls");
														}
														else {
															if (opc == 13) {
																salida = false;
															}
															else {
																cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
																system("pause");
																system("cls");
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else {
		cout << "El cliente no existe." << endl;
		system("pause");
		system("cls");
	}
}

void Interfaz::menuCursos() {
	int opc;
	char nivel;
	string nombre, descrip, cod, codAux;
	bool salida = true;
	

	while (salida) {
		cout << "1. Ingreso nuevo curso" << endl;
		cout << "2. Reporte de curso especifico" << endl;
		cout << "3. Modificacion de curso especifico" << endl;
		cout << "4. Devolverse" << endl << endl;
		cout << "Digite una opcion: ";
		cin >> opc;
		system("cls");

		if (opc == 1) {
			cout << "Digite el codigo del curso: ";
			cin >> cod;
			cin.ignore();
			cout << "Digite el nombre del curso: ";
			getline(cin, nombre);
			cout << "Digite el nivel (P = Principiantes / I = Intermedio / A = Avanzado): ";
			cin >> nivel;
			cin.ignore();
			cout << "Descripcion del curso: ";
			getline(cin, descrip);
			gym->getListCursos()->insertarFinal(new Curso(descrip, nombre, nivel, cod));
			cout << "Curso registrado con exito!" << endl << endl;
			cout<<"Recuerda que si quieres agregar nuevos grupos a este curso, debes ir a la opcion de '4.Control de Grupos' en el menu principal\ny dentro a '1. Ingreso de nuevos grupos.\n"; 
			system("pause");
			system("cls");
		}
		else {
			if (opc == 2) {
				cout << gym->getListCursos()->mostrarCursosBasico();
				cout << endl;
				cout << "Digite el codigo del curso: ";
				cin >> codAux;
				if (gym->getListCursos()->cursoEncontrado(codAux) == true) {
					system("cls");
					cout << "Curso encontrado!" << endl << endl;
					cout << gym->getListCursos()->mostrarInfoCurso(codAux);
				}
				else {
					cout << "No se encontro el curso" << endl;
				}
				system("pause");
			}
			else {
				if (opc == 3) {
					modificarCurso();
				}
				else {
					if (opc == 4) {
						salida = false;
					}
					else {
						cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
						system("pause");
					}
				}
			}
		}
		system("cls");
	}
}

void Interfaz::modificarCurso() {
	int opc;
	int cantGrupos;
	char nivel;
	string nombre, descrip, codAux, cod;
	bool salida = true;
	cout << gym->getListCursos()->mostrarCursosBasico() << endl;
	cout << "Digite el codigo del curso especifico: ";
	cin >> codAux;
	system("cls");
	if (gym->getListCursos()->cursoEncontrado(codAux) == true) {
		cout << "Curso encontrado!" << endl << endl;

		while (salida) {
			cout << "Cual dato desea modificar" << endl;
			cout << "1. Codigo" << endl;
			cout << "2. Nombre" << endl;
			cout << "3. Nivel" << endl;
			cout << "4. Descripcion" << endl;
			cout << "5. Cantidad de grupos" << endl;
			cout << "6. Devolverse" << endl << endl;
			cout << "Digite una opcion: ";
			cin >> opc;
			system("cls");
			switch (opc) {
			case 1:
				cout << "Digite el nuevo codigo para el curso: ";
				cin >> cod;
				gym->getListCursos()->obtenerCurso(codAux)->setCodigo(cod);
				cout << "Codigo modificado con exito!\n";
				system("pause");
				system("cls");
				break;

			case 2:
				cout << "Ingrese el nuevo nombre del curso: ";
				cin.ignore();
				getline(cin, nombre);
				gym->getListCursos()->obtenerCurso(codAux)->setNombre(nombre);
				cout<<"Nombre modificado con exito!\n";
				system("pause");
				system("cls");
				break;

			case 3:
				cout << "Ingrese el nuevo nivel para el curso (P = Principiantes / I = Intermedio / A = Avanzado): ";
				cin >> nivel;
				gym->getListCursos()->obtenerCurso(codAux)->setNivel(nivel);
				cout << "Nivel modificado con exito!\n";
				system("pause");
				system("cls");
				break;

			case 4:
				cout << "Ingrese la nueva descripcion del curso: \n";
				cin.ignore();
				getline(cin, descrip);
				gym->getListCursos()->obtenerCurso(codAux)->setDescrip(descrip);
				cout << "Descripcion modificada con exito!\n";
				system("pause");
				system("cls");
				break;

			case 5: //VERIFICAR
				cout << "Digite la nueva cantidad de grupos para el curso: ";
				cin >> cantGrupos;
				//gym->getListCursos()->obtenerCurso(codAux)->getListGrupos()->rellenaGrupos(cantGrupos);
				cout<<"Cantidad de grupos del curso modificada con exito!\n";
				system("pause");
				system("cls");
				break;

			case 6:
				salida = false;
				break;
			default:
				cout << "Opcion incorrecta, por favor vuelva a intentarlo presionando Enter" << endl;
				system("pause");
				break;
			}
			system("cls");
		}
	}
	else {
		cout << "No se encontro el curso" << endl;
	}
}

void Interfaz::guardarDatos() {
	std::ofstream file; //ofstream abre el archivo para escritura

	file.open("guardadoArchivo.txt", std::ios::out); //Se abre el archivo y se usa la flag ios::out para sobreescribir.
	if (!file.is_open()) { //Si el archivo no está abierto (is_open() == false).
		std::cout << "Error al abrir el archivo...\n";
		system("PAUSE");
	}
	else {
		file << gym->guardarDatos();
	}
	file.close();
}

void Interfaz::cargarDatos() {
	ifstream file; //ifstream permite abrir el archivo para lectura
	string buffer;
	string guardar[20];
	int cant = 0;
	system("CLS");

	file.open("guardadoArchivo.txt", std::ios::in); //Abre el archivo para lectura
	if (!file.is_open()) { //Si el archivo no está abierto (is_open() == false).
		std::cout << "\nError al abrir el archivo... Es posible que hayas ingresado mal el nombre...\n";
		system("PAUSE");
	}
	else {
		size_t posicion = 0; //Se utiliza un size_t para guardar la posición del punto y coma.
		while (std::getline(file, buffer)) { //Se guarda en "buffer" la linea correspondiente hasta encontrar un salto de linea.
			while ((posicion = buffer.find(DELIMITA_CAMPO)) != string::npos) {
				guardar[cant++]= buffer.substr(0, posicion); //Se guarda en el arreglo "guardar" la cadena de caracteres hasta el punto y coma.
				buffer.erase(0, posicion + 1); //Se borra la cadena de caracteres hasta el punto y coma.
			}
			gym->cargarDatos(guardar, cant);
			cant = 0;
		}
	}
	file.close(); //Se cierra el archivo.
}

void Interfaz::menuGrupos() {
	int opc;
	string id, idAux, nombre, horaI, horaF, cod;
	int cupo, dia, mes, annio, semanas, num, numAux;
	char d;
	bool salida = true;

	while (salida) {
		cout << "1. Ingreso de nuevo grupo" << endl;
		cout << "2. Modificacion de grupo en especifico" << endl;
		cout << "3. Matricula en grupo especifico" << endl;
		cout << "4. Reporte de un grupo especifico" << endl;
		cout << "5. Reporte de deportistas matriculados en un grupo" << endl;
		cout << "6. Cancelacion de matricula en grupo" << endl;
		cout << "7. Devolverse" << endl << endl;
		cout << "Digite una opcion: ";
		cin >> opc;
		system("cls");

		switch (opc) {
		case 1:
			cout<<"Lista de cursos abiertos: \n";
			cout << gym->getListCursos()->mostrarCursosBasico() << endl;
			cout << "Digite el codigo del curso: ";
			cin >> cod;
			if (gym->getListCursos()->cursoEncontrado(cod) == true) {
				cout << "Curso encontrado!" << endl;

				cout << "Digite el ID del instructor: ";
				cin >> id;
				cin.ignore();
				cout << "Digite el nombre del instructor: ";
				getline(cin, nombre);
				cout << "Digite el cupo maximo: ";
				cin >> cupo;
				cout << "Digite el numero de grupo: "; //Realmente se deberia mantener un orden secuencial de los cursos, pero esto se mantiene por sus varios usos que puede tener.
				cin >> num;
				cout << "Fecha de inicio (DD/MM/AAAA): \n";
				cout << "Dia: ";
				cin >> dia;
				cout << "Mes: ";
				cin >> mes;
				cout << "Annio: ";
				cin >> annio;
				cout << "Semanas de duracion: ";
				cin >> semanas;
				cout << "\n-----Horario----- " << endl;
				cout << "Digite el dia de la semana (L-X-M-J-V-S-D): ";
				cin >> d;
				cout << "Digite la hora de inicio (hora militar): ";
				cin >> horaI;
				cout << "Digite la hora de finalizacion (hora militar): ";
				cin >> horaF;
				Grupo* g = new Grupo(nombre, id, cupo, semanas, horaI, horaF, d, num, dia, mes, annio);
				gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->insertarFinal(g);
				cout<<"\nGrupo creado con exito!" << endl;
			}
			else {
				cout << "El curso solicitado no existe" << endl;
			}
			system("pause");
			break;

		case 2:
			modificarGrupo();
			break;

		case 3:
			cout << "Digite el ID del deportista: " << endl;
			cin >> idAux;
			if (gym->getListClientes()->clienteEncontrado(idAux)) {
				cout << "Deportista encontrado!" << endl << endl;
				cout << "Lista de cursos abiertos: \n";
				cout << gym->getListCursos()->mostrarCursosBasico() << endl;
				cout << "Digite el codigo del curso: " << endl;
				cin >> cod;
				if (gym->getListCursos()->cursoEncontrado(cod)) {
					if (gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->verificarMatriculaExistente(idAux)) {
						cout << "El cliente ya se encuentra matriculado en un grupo de este curso." << endl;
					}
					else {
						system("cls");
						cout << "Curso encontrado!" << endl << endl;

						cout << "Para el curso deseado existen los siguientes grupos disponibles: " << endl;
						cout << "# Grupo\t\t" << "Dia\t\t" << "Horario\t\t" << "Cupo\t\t" << "Cantidad" << endl;
						cout << gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->mostrarInfoGrupos() << endl;
						cout << "Digite el numero de grupo deseado: ";
						cin >> numAux;
						Cliente* c = gym->getListClientes()->obtenerCliente(idAux);

						//IF interno
						if (gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->matricular(c)) {
							gym->getListClientes()->obtenerCliente(idAux)->sumarRestarCantCursMatri(1);
							cout << "Matricula realizada con exito!" << endl;
						}
						else {
							cout << "El grupo esta lleno" << endl;
						}
						//FIN IF interno

					}
				} else {
					cout << "No se encontro ningun curso con ese codigo" << endl;
				}
			}
			else {
				cout << "No se encontro ningun deportista con ese ID" << endl;
			}
			system("pause");
			break;

		case 4:
			system("CLS");
			cout << "Lista de cursos abiertos: \n";
			cout << gym->getListCursos()->mostrarCursosBasico() << endl;
			cout << "Digite el codigo del curso: ";
			cin >> cod;
			if (gym->getListCursos()->cursoEncontrado(cod)) {
				cout << "Curso encontrado!" << endl << endl;
				
				if (gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->cantidadElementos() >= 1) {
					cout << "Listado de grupos para el curso seleccionado: " << endl;
					cout << "# Grupo\t" << "Cupo" << endl;
					cout << gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->mostrarBasicoGrupos() << endl;
					cout << "Digite el numero del grupo: ";
					cin >> numAux;
					system("cls");
					cout << gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->toString() << endl;
				}
				else {
					cout << "El curso en cuestion no tiene grupos registrados.\n";
				}
			}
			else {
				cout << "El curso solicitado no existe" << endl;
			}
			system("pause");
			break;

		case 5:
			system("CLS");
			cout << "Lista de cursos abiertos: \n";
			cout << gym->getListCursos()->mostrarCursosBasico() << endl;
			cout << "Digite el codigo del curso: ";
			cin >> cod;
			if (gym->getListCursos()->cursoEncontrado(cod) == true) {
				cout << "Curso encontrado!" << endl << endl;

				cout << "Listado de grupos para el curso seleccionado: " << endl;
				cout << "# Grupo\t" << "Cupo" << endl;
				cout << gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->mostrarBasicoGrupos() << endl;
				cout << "Digite el numero del grupo: ";
				cin >> numAux;
				system("cls");
				cout << gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->reporteDepMatri() << endl;
			}
			else {
				cout << "El curso solicitado no existe" << endl;
			}
			system("pause");
			break;

		case 6:
			system("CLS");
			cout << "Digite el ID del deportista: ";
			cin >> idAux;
			if (gym->getListClientes()->clienteEncontrado(idAux)) {
				cout << "Deportista encontrado!" << endl << endl; 
				cout << gym->getListCursos()->mostrarCursosBasico();
				cout << "Digite el codigo del curso: ";
				cin >> cod;
				if (gym->getListCursos()->cursoEncontrado(cod)) {

					if (gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->verificarMatriculaExistente(idAux)) {
						system("cls");
						cout << "Curso encontrado." << endl << endl;
						gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->obtenerGrupoPorCliente(idAux)->desmatricular(idAux);
						gym->getListClientes()->obtenerCliente(idAux)->sumarRestarCantCursMatri(-1);
						cout << "El cliente ha sido desmatriculado con exito del grupo al que pertenecía en el curso indicado.\n";
					}
					else {
						cout << "El cliente no se encuentra matriculado a ningun grupo de este curso.\n";
					}

				}
				else {
					cout << "No se encontro ningun curso con ese codigo" << endl;
				}
			}
			else {
				cout << "No se encontró ningun deportista con ese ID.\n";
			}
			system("pause");
			break;

		case 7:
			salida = false;
			break;

		default:
			cout << "La opcion ingresada no es valida, intente de nuevo.\n";
			system("pause");
			break;
		}
		system("cls");
	}
}

void Interfaz::modificarGrupo() {
	int opc;
	string id, nombre, horaI, horaF, cod;
	int cupo, dia, mes, annio, semanas, numAux; 
	char d;
	bool salida = true;

	system("CLS");
	cout << gym->getListCursos()->mostrarCursosBasico();
	cout << "Digite el codigo del curso: ";
	cin >> cod;

	if (gym->getListCursos()->cursoEncontrado(cod)) {
		cout << "Curso encontrado!" << endl << endl;

		cout << "Listado de grupos para el curso seleccionado: " << endl;
		cout << "Grupo\t\tCupo\n";

		while (salida) {
			cout << gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->mostrarBasicoGrupos() << endl;
			cout << "Digite el numero del grupo que desea modificar: ";
			cin >> numAux;
			system("cls");
			if (gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->grupoEncontrado(numAux)) {
				cout << "Grupo encontrado!" << endl << endl;

				do{
					cout << "¿Que desea modificar?" << endl;
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
					system("cls");
					if (opc == 1) {
						cout << "Digite el nuevo ID del instructor: " << endl;
						cin >> id;
						gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->getInstructor()->setId(id);
						cout << "ID del instructor modificado con exito!\n";
						system("pause");
					}
					else {
						if (opc == 2) {
							cout << "Digite el nuevo nombre del instructor: " << endl;
							cin.ignore();
							getline(cin, nombre);
							gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->getInstructor()->setNombre(nombre);
							cout << "Nombre del instructor modificado con exito!\n";
							system("pause");
						}
						else {
							if (opc == 3) {
								cout << "Digite el nuevo cupo del grupo: " << endl;
								cin >> cupo;
								gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->setCupo(cupo);
								cout << "Cupo del grupo modificado con exito!\n";
								system("pause");
							}
							else {
								if (opc == 4) {
									cout << "Digite la nueva fecha de inicio: " << endl;
									cout << "Dia: " << endl;
									cin >> dia;
									cout << "Mes: " << endl;
									cin >> mes;
									cout << "Annio: " << endl;
									cin >> annio;
									Fecha* f = new Fecha(dia, mes, annio);
									gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->setFechaInicio(f);
									cout << "Fecha de inicio modificada con exito!\n";
									system("pause");
								}
								else {
									if (opc == 5) {
										cout << "Digite la nueva cantidad de semanas de duracion: " << endl;
										cin >> semanas;
										gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->setSemanas(semanas);
										cout << "Cantidad de semanas de duracion modificada con exito!\n";
										system("pause");
									}
									else {
										if (opc == 6) {
											cout << "Digite el nuevo dia de la semana para impartir el curso: " << endl;
											cin >> d;
											gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->setDia(d);
											cout << "Dia de la semana para impartir el curso modificado con exito!\n";
											system("pause");
										}
										else {
											if (opc == 7) {
												cout << "Digite la nueva hora de inicio: " << endl;
												cin >> horaI;
												gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->setHoraI(horaI);
												cout << "Hora de inicio modificada con exito!\n";
												system("pause");
											}
											else {
												if (opc == 8) {
													cout << "Digite la nueva hora de finalizacion: " << endl;
													cin >> horaF;
													gym->getListCursos()->obtenerCurso(cod)->getListGrupos()->obtenerGrupo(numAux)->setHoraF(horaF);
													cout << "Hora de finalizacion modificada con exito!\n";
													system("pause");
												}
												else {
													if (opc == 9) {
														salida = false;
													}
													else {
														cout << "Opcion incorrecta, por favor vuelva a intentarlo." << endl;
														system("pause");
													}
												}
											}
										}
									}
								}
							}
						}
					}
					system("cls");
				} while (salida);
			}
			system("cls");
		}
	}
	else {
		cout << "El curso solicitado no existe" << endl;
	}
}

void Interfaz::menuPagos() {
	bool salida = true, val;
	int opc, var;
	string id;

	while (salida) {
		cout << "1. Registro de nuevo pago." << endl;
		cout << "2. Reporte de pagos por deportista." << endl;
		cout << "3. Devolverse." << endl << endl;
		cout << "Digite una opcion: ";
		cin >> opc;

		switch (opc) {
		case 1:
			cout << "Digite el ID del deportista: ";
			cin >> id;
			if (gym->getListClientes()->clienteEncontrado(id)) {
				cout << "Deportista encontrado!" << endl << endl;
				cout << "Cuantas cuotas desea cancelar o pagar?: ";
				cin >> var;

				cout << "Monto a pagar: " << gym->getMensualidad() * var << endl;
				cout<<"Desea continuar con el pago? (1. Si || 0. No): ";
				cin >> val;
				if (val) {
					Fecha* actual = new Fecha();
					actual->actualizarPorActual();

					while (var != 0) {
						if (gym->getListClientes()->obtenerCliente(id)->getListPagos()->getPrimero() == nullptr) {
							gym->getListClientes()->obtenerCliente(id)->getListPagos()->insertarFinal(new Pago(actual, gym->getMensualidad()));
						}
						else {
							Fecha* ultimoPagado = gym->getListClientes()->obtenerCliente(id)->getListPagos()->obtenerUltimoElemento()->getFecha();
							if (ultimoPagado->getMes() == 12) {
								gym->getListClientes()->obtenerCliente(id)->getListPagos()->insertarFinal(new Pago(new Fecha(15, 1, ultimoPagado->getAnnio() + 1), gym->getMensualidad()));
							}
							else {
								gym->getListClientes()->obtenerCliente(id)->getListPagos()->insertarFinal(new Pago(new Fecha(15, ultimoPagado->getMes() + 1, ultimoPagado->getAnnio()), gym->getMensualidad()));
							}
						}
						var--;
					}
					cout << "\nPago realizado con exito!\n";
					system("PAUSE");
				}
			}
			else {
				cout << "No hay deportistas registrados con el ID indicado\n";
				system("PAUSE");
			}
			break;

		case 2:
			cout << "Digite el ID del deportista: ";
			cin >> id;
			if (gym->getListClientes()->clienteEncontrado(id)) {
				system("CLS");
				cout << "Deportista encontrado!" << endl << endl;
				if (gym->getListClientes()->obtenerCliente(id)->getListPagos()->getPrimero() == nullptr) {
					cout<<"El cliente aun no ha realizado ningun pago.\n";
				}
				else {
					cout << "Historial de pagos del cliente: \n\n";
					cout << "Fecha de pago\t\t" << "Mes\t\t" << "Monto" << endl;
					cout << gym->getListClientes()->obtenerCliente(id)->getListPagos()->toString();
				}
				system("PAUSE");
			}
			break;

		case 3:
			salida = false;
			break;

		default:
			cout << "La opcion indicada no existe, favor vuelva a intentarlo." << endl;
			system("pause");
			break;
		}
		system("cls");
	}

}