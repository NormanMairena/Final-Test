#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"listaclientes.h"
#include"listaguia.h"
#include"listatripulante.h"
#include"listaavion.h"
#include"listarutas.h"
#include"listavuelo.h"
#include"listareservaciones.h"

using namespace std;
class agencia
{
private:
	string telefono;
	string cedula;
	string nombre;

	listaclientes* Clientes;
	listaguias* Guias;
	listatripulantes* Tripurantes;
	listaavion* Aviones;
	listaruta* Rutas;
	listavuelo* Vuelos;
	listareservaciones* Reservaciones;

public:
	agencia(string = "nombre", string = "cedula", string = "telefono", listaclientes* = NULL, listaguias* = NULL, listatripulantes* = NULL, listaavion* = NULL, listaruta* = NULL, listavuelo* = NULL, listareservaciones* = NULL);
	~agencia();
	void setnombre(string);
	void setcedula(string);
	void settelefono(string);
	//gets
	string getnombre();
	string getcedula();
	string gettelefono();

	listaclientes* getClientes();
	listaguias* getGuias();
	listatripulantes* getTripulantes();
	listaavion* getAviones();
	listaruta* getRutas();
	listaruta* getVuelos();
	listaruta* getReservaciones();
	

	//opciones------
	void opcion1();
	void opcion2();
	void opcion3();
	void opcion4();
	void opcion5();
	void opcion6();
	void opcion7();
	void opcion8();
	void opcion9();
	void opcion10();
	void opcion11();
	void opcion12();
	void opcion13();
	void opcion14();
	void opcion15();
	void opcion16();
	//----------------------
	void Menu();
	int ValidarEntero();
	void validarEntradaMenuPrincipal(int opcion, int parametro1, int parametro2);
	
};

