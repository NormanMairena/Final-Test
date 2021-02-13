#pragma once
#include"hora.h"
#include"fecha.h"
#include"vuelo.h"
#include"cliente.h"
#include"guia.h"

class reservacion
{
private:
	string codigo;
	int cantVoletos;
	int categoria;
	double montotot;
	hora* HORA;
	fecha* FECHA;
	vuelo* VUELO;
	cliente* CLIENTE;
	guia* GUIA;
public:
	reservacion(string = "codigo" , int = 0, int= 0, double= 0, hora* = NULL ,  fecha* = NULL, vuelo* = NULL, cliente* = NULL, guia* = NULL ) ;

	~reservacion();
	string getcodigo();
	int getcantvoletos();
	int getcategoria();
	double getmonto();
	hora* getHORA();
	fecha* getFECHA();
	vuelo* getVUELO();
	void calcular(int, double);
	cliente* getCLIENTE();
	guia* getGUIA();

	string tostring();
	
};

