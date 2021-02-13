#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class ruta
{
private:
	string id;
	string ciudadOrigen;
	string paisOrigen;
	string ciudadDestino;
	string paisDestino;
	double precio;
	double duracion;
public:
	ruta(string = "id", string = "ciudadOrigen", string = "paisOrigen", string= " ciudadDestino",	string= "paisDestino",	double =0, double =0);
	~ruta();
	//sets
	void setciudadOringen(string);
	void setciudadDestino(string);
	void setpaisOrigen(string);
	void setpaisDestino(string);
	void setprecio(double);
	void setduracion(double);
	void setid(string);
	//gets
	string getCiudad1();
	string getCiudad2();
	string getPais1();
	string getPais2();
	float getprecio();
	float getduracion();
	string getid();

	string tostring();

	void guardar(ofstream&);
	static ruta* cargar(ifstream&);

};

