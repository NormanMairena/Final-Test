#include "guia.h"

guia::guia(string n, string a, string c, string t, string e): Persona(n, a ,c)
{
	this->telefono = t;
	this->especialidad = e;
}

guia::~guia()
{
}

void guia::settelefono(string c)
{
	this->telefono = c;
}

void guia::setespecialidad(string r)
{
	this->especialidad = r;
}

string guia::gettelefono()
{
	return telefono;
}

string guia::getespecialidad()
{
	return especialidad;
}

string guia::tostring()
{
	stringstream s;
	s << "--Guia--" << endl
		<< Persona::tostring() << endl
		<< "telefono: " << telefono << endl
		<< "especialidad: " << especialidad << endl;

	return s.str();
}

void guia::guardar(ofstream& c)
{
	c << getnom() << endl
		<< getapelli() << endl
		<< getced() << endl
		<< gettelefono() << endl
		<< getespecialidad() << endl;
}

guia* guia::cargar(ifstream& estFile)
{
	string ced, nom, apell, telef, espe;
	if (!(estFile >> nom)) { return NULL; }
	if (!(estFile >> apell)) { return NULL; }
	if (!(estFile >> ced)) { return NULL; }
	if (!(estFile >> telef)) { return NULL; }
	if (!(estFile >> espe)) { return NULL; }
	return new guia(nom, apell, ced, telef, espe);
}

