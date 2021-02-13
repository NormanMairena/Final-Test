#pragma once
#include"hora.h"
#include"fecha.h"
#include"ruta.h"
#include"avion.h"
#include "listatripulante.h"

class vuelo
{
private:
	string codigo;
	hora* Hora;
	fecha* Fecha;
	avion* Avion;
	ruta* Ruta;
	listatripulantes* Tripulantes;

public:
	vuelo(string = "codigo", hora* = NULL, fecha* = NULL, avion* = NULL, ruta* = NULL, listatripulantes* = NULL);
	~vuelo();

	//sets
	void setcodigo(string);
	
	//gts
	string getcodigo();
	hora* gethora();
	fecha* getfecha();
	avion* getavion();
	ruta* getruta();
	listatripulantes* gettripulantes();

	string tostring();
	


};
