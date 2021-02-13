#include "ruta.h"

ruta::ruta(string id,string CO, string PO, string CD, string PD, double Prec, double dur)
{
	this->ciudadOrigen = CO;
	this->paisOrigen = PO;
	this->ciudadDestino = CD;
	this->paisDestino = PD;
	this->precio = Prec;
	this->duracion = dur;
	this->id = id;
}

ruta::~ruta()
{
}

void ruta::setciudadOringen(string c)
{
	this->ciudadOrigen = c;
}

void ruta::setciudadDestino(string c)
{
	this->ciudadDestino = c;
}

void ruta::setpaisOrigen(string paisorig)
{
	this->paisOrigen = paisorig;
}

void ruta::setpaisDestino(string paisdest)
{
	this->paisDestino = paisdest;
}

void ruta::setprecio(double c)
{
	this->precio = c;
}

void ruta::setduracion(double c)
{
	this->duracion = c;
}

void ruta::setid(string c)
{
	this->id = c;
}

string ruta::getCiudad1()
{
	return ciudadOrigen;
}

string ruta::getCiudad2()
{
	return ciudadDestino;
}

string ruta::getPais1()
{
	return paisOrigen;
}

string ruta::getPais2()
{
	return paisDestino;
}

float ruta::getprecio()
{
	return precio;
}

float ruta::getduracion()
{
	return duracion;
}

string ruta::getid()
{
	return id;
}

string ruta::tostring()
{
	stringstream s;
	s << "--Ruta--" << endl
		<<"id: "<<id<<endl
		<< "Pais de origen: " << paisOrigen << endl
		<< "Ciudad de origen: " << ciudadOrigen << endl
		<< "Pais de destino: " << paisDestino << endl
		<< "Ciudad de destino: " << ciudadDestino << endl
		<< "precio: " << precio << endl
		<< "duracion: " << duracion << endl;
	return s.str();
}

void ruta::guardar(ofstream& c)
{
	c << getid() << endl
		<< getPais1() << endl
		<< getCiudad1() << endl
		<< getPais2() << endl
		<< getCiudad2() << endl
		<< getprecio() << endl
		<< getduracion() << endl;
}

ruta* ruta::cargar(ifstream& estFile)
{
	string id;
	string ciudadOrigen;
	string paisOrigen;
	string ciudadDestino;
	string paisDestino, precio2, duracion2;
	double precio;
	double duracion;
	if (!(estFile >> id)) { return NULL; }
	if (!(estFile>> paisOrigen)) { return NULL; }
	if (!(estFile>> ciudadOrigen)) { return NULL; }
	if (!(estFile>> paisDestino)) { return NULL; }
	if (!(estFile>> ciudadDestino)) { return NULL; }
	if (!(estFile >> precio2)) { return NULL; }
	if (!(estFile >> duracion2)) { return NULL; }
	precio = stod(precio2);
	duracion = stod(duracion2);
	return new ruta(id, ciudadOrigen, paisOrigen, ciudadDestino, paisDestino, precio , duracion);
}
