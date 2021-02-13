#include "vuelo.h"

vuelo::vuelo(string code, hora* hr, fecha* fech, avion* avi, ruta* rut, listatripulantes* trips)
{
	this->codigo = code;
	this->Hora = hr;
	this->Fecha = fech;
	this->Avion = avi;
	this->Ruta = rut;
	this->Tripulantes = trips;
}

vuelo::~vuelo()
{

}

void vuelo::setcodigo(string s)
{
	this->codigo = s;
}

string vuelo::getcodigo()
{
	return codigo;
}

hora* vuelo::gethora()
{
	return Hora;
}

fecha* vuelo::getfecha()
{
	return Fecha;
}

avion* vuelo::getavion()
{
	return Avion;
}

ruta* vuelo::getruta()
{
	return Ruta;
}

listatripulantes* vuelo::gettripulantes()
{
	return Tripulantes;
}

string vuelo::tostring()
{
	stringstream s;
	s << "--Vuelo--" << endl
		<< "Codigo: " << codigo << endl
		<< "Hora: " << Hora->tostring() << endl
		<< "Fecha: " << Fecha->tostring() << endl
		<< "Ruta: " << Ruta->tostring() << endl
		<< "Avion: " << Avion->tostring() << endl
		<< "Tripulacion: " << Tripulantes->toString() << endl;

	return s.str();
}
