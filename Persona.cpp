#include "Persona.h"

Persona::Persona(string n, string a, string c)
{
	this->nom = n;
	this->apellido = a;
	this->ced = c;
}

string Persona::getnom()
{
	return nom;
}

string Persona::getapelli()
{
	return apellido;
}

string Persona::getced()
{
	return ced;
}

void Persona::setnom(string c)
{
	this->nom = c;
}

void Persona::setapelli(string c)
{
	this->apellido = c;
}

void Persona::setced(string c)
{
	this->ced = c;
}

string Persona::tostring()
{
	stringstream s;
		s<< "nombre: " << nom << endl
		<< "apellido: " << apellido << endl
		<< "cedula: " << ced << endl;

		return s.str();
}

Persona::~Persona()
{
}
