#include "tripulante.h"

tripulante::tripulante(string n, string a, string c, string car, string rol) :Persona(n, a, c)
{
	this->carnet = car;
	this->rol = rol;
}

tripulante::~tripulante()
{
}

void tripulante::setcarnet(string c)
{
	this->carnet = c;
}

void tripulante::setrol(string c)
{
	this->rol = c;
}

string tripulante::getcarnet()
{
	return carnet;
}

string tripulante::getrol()
{
	return rol;
}

string tripulante::tostring()
{
	stringstream s;
	s << "--Tripulante--" << endl
		<< Persona::tostring() << endl
		<< "carnet: " << carnet << endl
		<< "rol: " << rol << endl;
	return s.str();
}

void tripulante::guardar(ofstream& c)
{
	c << getnom() << endl
		<< getapelli() << endl
		<< getced() << endl
		<< getcarnet() << endl
		<< getrol() << endl;
}

tripulante* tripulante::cargar(ifstream& estFile)
{
	string ced, nom, apell, carnet, rol;
	if (!(estFile >> nom)) { return NULL; }
	if (!(estFile >> apell)) { return NULL; }
	if (!(estFile >> ced)) { return NULL; }
	if (!(estFile >> carnet)) { return NULL; }
	if (!(estFile >> rol)) { return NULL; }
	return new tripulante(nom, apell, ced, carnet, rol);
}
