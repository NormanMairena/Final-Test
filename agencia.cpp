#include "agencia.h"


agencia::agencia(string nom, string ced, string telef, listaclientes* clientes, listaguias* quias, listatripulantes* tripulantes, listaavion* aviones, listaruta* rutas , listavuelo* vuelos, listareservaciones* reserva)
{
	this->nombre = nom;
	this->cedula = ced;
	this->telefono = telef;
	this->Clientes = clientes;
	this->Guias = quias;
	this->Tripurantes = tripulantes;
	this->Aviones = aviones;
	this->Rutas = rutas;
	this->Vuelos = vuelos;
	this->Reservaciones = reserva;
}

agencia::~agencia()
{
}

void agencia::setnombre(string c)
{
	this->nombre = c;
}

void agencia::setcedula(string c)
{
	this->cedula = c;
}

void agencia::settelefono(string c)
{
	this->telefono = c;
}

string agencia::getnombre()
{
	return nombre;
}

string agencia::getcedula()
{
	return cedula;
}

string agencia::gettelefono()
{
	return telefono;
}

listaclientes* agencia::getClientes()
{
	return Clientes;
}

listaguias* agencia::getGuias()
{
	return Guias;
}

listatripulantes* agencia::getTripulantes()
{
	return Tripurantes;
}

listaavion* agencia::getAviones()
{
	return Aviones;
}

listaruta* agencia::getRutas()
{
	return Rutas;
}

void agencia::opcion1()
{
	string id;
	 int cantmax;
	cout << "--Registrar un nuevo avion--" << endl;
	cout << "ingrese el id" << endl;
	cin >> id;
	if (Aviones->busquedaid(id)==false)
	{
		cout << "ingrese la cantidad max de pasajeros" << endl;
		cantmax = ValidarEntero();
		avion* A = new avion(id, cantmax);
		Aviones->agregarFinal(A);
	}
	else
	{
		cout << "ese avion ya existe" << endl;
	}
	cout<<Aviones->toString();
}

void agencia::opcion2()
{
	string nom, apell, ced, numtar;
	cout << "--Registrar un nuevo Cliente--" << endl;
	cout << "ingrese el id" << endl;
	cin >> ced;
	if (Clientes->busquedaid(ced) == false)
	{
		cout << "ingrese su nombre" << endl;
		cin >> nom;
		cout << "ingrese su apellido" << endl;
		cin >> apell;
		cout << "ingrese su numero de tarjeta" << endl;
		cin >> numtar;

		cliente* C = new cliente(nom, apell, ced, numtar);
		Clientes->agregarFinal(C);
	}
	else
	{
		cout << "cliente existente" << endl;
	}

	cout << Clientes->toString();
}

void agencia::opcion3()
{
	string nom, apell, id, telef, especialidad;
	cout << "--Ingresar guias--" << endl;
	cout << "ingrese si id" << endl;
	cin >> id;
	if (Guias->busquedaid(id)==false)
	{
		cout << "ingrese su nombre" << endl;
		cin >> nom;
		cout << "ingrese su apellido" << endl;
		cin >> apell;
		cout << "ingrese su especialidad" << endl;
		cin >> especialidad;
		cout << "ingrese su telefono" << endl;
		cin >> telef;
		guia* G = new guia(nom, apell, id, telef, especialidad);
		Guias->agregarFinal(G);
	}
	else
	{
		cout <<" guia existente" << endl;
	}
	cout << Guias->toString();
}

void agencia::opcion4()
{
	string nom, apell, id, carnet, rol;
	cout << "--Ingresar tripulante--" << endl;
	cout << "ingrese su carnet" << endl;
	cin >> carnet;
	if (Tripurantes->busquedaid(carnet)==false)
	{
		cout << "ingrese su nombre" << endl;
		cin >> nom;
		cout << "ingrese su apellido" << endl;
		cin >> apell;
		cout << "ingrese su identificacion" << endl;
		cin >> id;
		cout << "ingrese su puesto" << endl;
		cin >> rol;
		tripulante* T = new tripulante(nom,apell,id,carnet, rol);
		Tripurantes->agregarFinal(T);
	}
	else
	{
		cout << "Tripulante existente" << endl;
	}
	cout << Tripurantes->toString();
}

void agencia::opcion5()
{
	string id, ciuOrigen, paisorigen, ciudaddestino, paisdestino;
		double precio, duracion;
	cout << "--Ingresar nuevas rutas--" << endl;
	cout << "ingrese el id" << endl;
	cin >> id;
	if (Rutas->busquedaid(id)==false)
	{

		cout << "ingrese el precio" << endl;
		cin >> precio;
		cout << "ingresela duracion" << endl;
		cin >> duracion;
		cin.get();
		cout << "ingrese la ciudad de origen" << endl;
		getline(cin, ciuOrigen);
		cout << "ingrese el pais de origen" << endl;
		getline(cin, paisorigen);
		cout << "ingrese la ciudad de destino" << endl;
		getline(cin, ciudaddestino);
		cout << "ingrese el pais de destino" << endl;
		getline(cin, paisdestino);

		ruta* R = new ruta(id, ciuOrigen, paisorigen, ciudaddestino, paisdestino, precio, duracion);
		Rutas->agregarFinal(R);
	}
	else
	{
		cout << "ruta existente" << endl;
	}
	cout<<Rutas->toString();

}

void agencia::opcion6()
{
	string code, idavion, idruta;
	int ora, min, seg, dia, mes, annio;
	cout << "--ingresar vuelos--" << endl;
	cout << "digite el codigo de su nuevo vuelo" << endl;
	cin >> code;
	if (Vuelos->busquedaid(code) == false)
	{
		cout << Aviones->toString() << endl;
		cout << "escoja un avion (id)" << endl;
		cin >> idavion;
		if (Aviones->busquedaid(idavion))
		{
			cout << Rutas->toString() << endl;
			cout << "digite el id de la ruta" << endl;
			cin >> idruta;
			if (Rutas->busquedaid(idruta))
			{
				listatripulantes* LT = new listatripulantes();
				string bandera = "si";
				cout << Tripurantes->toString() << endl;
				cout << "ingrese los tripulantes, ingrese(no) para salir" << endl;
				while (bandera == "si")
				{
					string trip;
					cin >> trip;

					if (Tripurantes->busquedaid(trip))
					{
						LT->agregarFinal(Tripurantes->busquedaid2(trip));
					}
					cout << "desea seguir ingresando mas tripulantes al vuelo? (si / no)" << endl;
					cin >> bandera;

				}

				if (LT->estaVacia()==false)
				{
					cout << "digite la hora" << endl;
					cin >> ora;
					cout << "digite los mins" << endl;
					cin >> min;
					cout << "digite los segundos" << endl;
					cin >> seg;
					cout << "digite el dia" << endl;
					cin >> dia;
					cout << "digite el mes" << endl;
					cin >> mes;
					cout << "digite el annio" << endl;
					cin >> annio;


					
					hora* H = new hora(ora, min, seg);
					fecha* F = new fecha(dia, mes, annio);
					vuelo* V = new vuelo(code, H, F, Aviones->busquedaid2(idavion), Rutas->busquedaid2(idruta), LT);
					Vuelos->agregarFinal(V);

					cout << Vuelos->toString()<<endl;
				}
			}
			else
			{
				cout << "ruta no existe" << endl;
			}
		}
		else
		{
			cout << "avion no existe" << endl;
		}



	}
	else
	{
		cout << "Vuelo existente" << endl;

	}
	
}

void agencia::opcion7()
{
	string idguia, idcliente, codevuelo;
	cout << "--REalizar reservacion--" << endl;
	if (Clientes->estaVacia()==false && Vuelos->estaVacia()==false && Guias->estaVacia()==false )
	{
		cout<<Guias->toString()<<endl;
		cout << "digite el carnet (Guia)" << endl;
		cin >> idguia;
		if (Guias->busquedaid(idguia)==true)
		{
			cout << Clientes->toString() << endl;
			cout << "el id el cliente" << endl;
			cin >> idcliente;
			if (Clientes->busquedaid(idcliente))
			{
				cout << Vuelos->toString() << endl;
				cout << "ingrese el codigo de vuelo" << endl;
				cin >> codevuelo;
				if (Vuelos->busquedaid(codevuelo))
				{
					string code;
					int cant, categoria;
					float tot;
					cout << "ingrese el codigo de reservacion" << endl;
					cin >> code;
					if (Reservaciones->busquedaid(code)==false)
					{
						int ora, min, seg, dia, mes, annio, cantvoletos;
						cout << "digite la cantidad de voletos" << endl;
						cantvoletos = ValidarEntero();
						cout << "digite la categoria" << endl;
						categoria = ValidarEntero();
						cout << "digite la hora de salida" << endl;
						ora = ValidarEntero();
						cout << "digite los mins" << endl;
						cin >> min;
						cout << "digite los segundos" << endl;
						cin >> seg;
						cout << "digite el dia" << endl;
						cin >> dia;
						cout << "digite el mes" << endl;
						cin >> mes;
						cout << "digite el annio" << endl;
						cin >> annio;


						
						hora* H2 = new hora(ora, min, seg);
						fecha* F2 = new fecha(dia, mes, annio);
						
						reservacion* R = new reservacion(code,cantvoletos,categoria, 0,H2,F2,Vuelos->busquedaid2(codevuelo), Clientes->busquedaid2(idcliente), Guias->busquedaid2(idguia) );
						R->calcular(cantvoletos, Vuelos->busquedaid2(codevuelo)->getruta()->getprecio());
						Reservaciones->agregarFinal(R);
						cout<<Reservaciones->toString();
					}
					else
					{
						cout << "codigo de reservacion existente" << endl;
					}
				}
				else
				{
					cout << "el vuelo no existe" << endl;
				}
			}
			else
			{
				cout << "el cliente no existe" << endl;
			}
		}
		else
		{
			cout << "el guia no existe" << endl;
		}
	}
	else
	{
		cout << "sistema no disponible" << endl;
	}
}

void agencia::opcion8()
{
	cout<<Vuelos->toString();
	string codevuelo;
	cout << "digite el codigo del vuelo" << endl;
	cin >> codevuelo;
	if (Vuelos->busquedaid(codevuelo)==true)
	{
		cout << "vuelo numero " << codevuelo << endl;
		
		cout << "----Resercaviones----" << endl;
		cout<<Reservaciones->opcion8(codevuelo);
	}
	else
	{
		cout << "ese vuelo no existe" << endl;
	}
}

void agencia::opcion9()
{
	cout << "------informacion de los vuelos-----" << endl;
	cout<<Vuelos->toString();
}

void agencia::opcion10()
{
	cout << "---Clientes de un vuelo---" << endl;
	cout<<Vuelos->toString();
	string codevuelo;
	cout << "digite el codigo del vuelo" << endl;
	cin >> codevuelo;
	if (Vuelos->busquedaid(codevuelo) == true)
	{
		cout << "vuelo numero " << codevuelo << endl;
		
		cout << "----Clientes----" << endl;
		cout << Reservaciones->opcion10(codevuelo)<<endl;
		
	}
	else
	{
		cout << "ese vuelo no existe" << endl;
	}
	cin.get();
}

void agencia::opcion11()
{
	cout << "---Ingreso total por vuelo---" << endl;
	string codevuelo;
	cout << "digite el codigo del vuelo" << endl;
	cin >> codevuelo;
	if (Vuelos->busquedaid(codevuelo) == true)
	{
		cout << "vuelo numero " << codevuelo << endl;
		cout << "ganancias por primera clase------------ " <<Reservaciones->montoprimeraclase(codevuelo) - (Reservaciones->montoprimeraclase(codevuelo)*0.13) << endl;
		cout << "ganancias por primera clase(IVA)------- "<<Reservaciones->montoprimeraclase(codevuelo) << endl;
		cout << "ganancias por segunda clase------------ " <<Reservaciones->montosegunda(codevuelo) - (Reservaciones->montosegunda(codevuelo) * 0.13)<< endl;
		cout << "ganancias por segunda clase(IVA)------- " << Reservaciones->montosegunda(codevuelo) << endl;
		cout << "ganancias por tercera clase------------ " << Reservaciones->montotercera(codevuelo) - (Reservaciones->montotercera(codevuelo) * 0.13) << endl;
		cout << "ganancias por tercera clase(IVA)------- " << Reservaciones->montotercera(codevuelo) << endl;
		cout << "ganancias por cuarta clase------------- " << Reservaciones->montocuarta(codevuelo) - (Reservaciones->montocuarta(codevuelo) * 0.13) << endl;
		cout << "ganancias por cuarta clase(IVA)-------- " << Reservaciones->montocuarta(codevuelo) << endl<<endl;
		cout << "Ganancias brutas totales--------------- "<< Reservaciones->montoprimeraclase(codevuelo) - (Reservaciones->montoprimeraclase(codevuelo) * 0.13)+ Reservaciones->montosegunda(codevuelo) - (Reservaciones->montosegunda(codevuelo) * 0.13)+ Reservaciones->montotercera(codevuelo) - (Reservaciones->montotercera(codevuelo) * 0.13) + Reservaciones->montocuarta(codevuelo) - (Reservaciones->montocuarta(codevuelo) * 0.13) << endl;
		cout << "Ganancias totales (IVA)---------------- " << Reservaciones->montoprimeraclase(codevuelo) + Reservaciones->montosegunda(codevuelo)+ Reservaciones->montotercera(codevuelo)+ Reservaciones->montocuarta(codevuelo) << endl;

	}
	else
	{
		cout << "ese vuelo no existe" << endl;
	}
}

void agencia::opcion12()
{
	cout << "---Tripulacion de un vuelo---" << endl;
	cout << Vuelos->toString();
	string codevuelo;
	cout << "digite el codigo del vuelo" << endl;
	cin >> codevuelo;
	if (Vuelos->busquedaid(codevuelo) == true)
	{
		cout << "vuelo numero " << codevuelo << endl;

		cout << "----Tripulacion----" << endl;
		cout << Vuelos->busquedaid2(codevuelo)->gettripulantes()->toString() << endl;

	}
	else
	{
		cout << "ese vuelo no existe" << endl;
	}
}

void agencia::opcion13()
{
	cout << "---Clientes de primera de un vuelo---" << endl;
	cout << Vuelos->toString();
	string codevuelo;
	cout << "digite el codigo del vuelo" << endl;
	cin >> codevuelo;
	if (Vuelos->busquedaid(codevuelo) == true)
	{
		cout << "vuelo numero " << codevuelo << endl;
		cout<<Reservaciones->opcion13(codevuelo)<<endl;
		
		

	}
	else
	{
		cout << "ese vuelo no existe" << endl;
	}
}

void agencia::opcion14()
{
	cout << "el destino de moda actualmente es: ";
	cout<<Rutas->rutamoda()->getCiudad2();
}

void agencia::opcion15()
{
	Clientes=Clientes->Leer();
	Guias = Guias->Leer();
	Tripurantes = Tripurantes->Leer();
	Aviones = Aviones->Leer();
	Rutas = Rutas->Leer();
	cout << Rutas->toString();
	cout << "se han cargado datos de archivos, tenga cuidado al cargar, se suplantan los datos no guardados" << endl;
}

void agencia::opcion16()
{
	if (Clientes->estaVacia()==false)
	{
		Clientes->guardar();
	}
	if (Guias->estaVacia()==false)
	{
		Guias->guardar();
	}
	if (Tripurantes->estaVacia()==false)
	{
		Tripurantes->guardar();
	}
	if (Aviones->estaVacia()==false)
	{
		Aviones->guardar();
	}
	if (Rutas->estaVacia()==false)
	{
		Rutas->guardar();
	}

}



int agencia::ValidarEntero()
{
		int	Respuesta;
		bool validar = true;
		while (validar) {
			if (cin >> Respuesta) {
				return Respuesta;
			}
			else {
				cout << "Respuesta invalida, digite un numero entero(Ej.1, 2 ,3 ...)" << endl;
				cin >> Respuesta;
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
}

	void agencia::validarEntradaMenuPrincipal(int opcion, int parametro1, int parametro2)
	{
		if (opcion<parametro1 || opcion>parametro2) {
			cout << "Opcion invalida" << endl;
			cout << "Digite nuevamente el numero que desea" << endl;
			opcion = ValidarEntero();
		}
	}


	void agencia::Menu()
	{
		int opcionInicio = 1;
		int opcionMenu = 5;
		while (opcionInicio == 1) {
			cout << "-------Agencia de viajes-------" << endl;
			cout << nombre << endl;
			cout << "1.ingresar un avion" << endl;
			cout << "2.ingresar clientes" << endl;
			cout << "3.ingresar guias" << endl;
			cout << "4.ingresar tripulantes " << endl;
			cout << "5.ingresar rutas" << endl;
			cout << "6.ingresar vuelos" << endl;
			cout << "7.Reservar" << endl;
			cout << "8.Detalle de reservaciones por codigo de vuelo" << endl;
			cout << "9.Reportar detalle de vuelos" << endl;
			cout << "10-Reportar clientes de un determinado vuelo" << endl;
			cout << "11-Reportar  y calcular monto total de un vuelo" << endl;
			cout << "12-Reporte de la tripulación de un vuelo" << endl;
			cout << "13- Reportar clientes que viajan en primera clase de un vuelo" << endl;
			cout << "14-Reportar la ruta mas solicitada" << endl;
			cout << "15- Cargar archivos" << endl;
			cout << "16- salir" << endl;
			opcionMenu= ValidarEntero();
			
			cout << "Digite <ENTER> para continuar" << endl;
			cin.get();
			cin.get();
			system("cls");
			switch (opcionMenu) {
			case 1:
				opcion1();

				break;
			case 2:
				opcion2();
				break;
			case 3:
				opcion3();
				break;
			case 4:
				opcion4();
				break;
			case 5:
				opcion5();
				break;
				
			case 6:
				opcion6();
				break;
				
			case 7:
				opcion7();
				break;
				
			case 8:
				opcion8();
				break;
				
			case 9:
				opcion9();
				break;
				
			case 10:
				opcion10();
				break;
				
			case 11:
				
				opcion11();
				
				break;
				
			case 12:
				opcion12();
				break;
				
			case 13:
				opcion13();
				break;
				
			case 14:
				//opcion14();
				break;
				
			case 15:
				opcion15();
				break;
			case 16:
				opcion16();
				exit(0);
				break;
			}
			cout << "desea continuar? 1)-> si  2)-> no" << endl;
			opcionInicio=ValidarEntero();
		}


	}