#include "avion.h"

avion::avion(string c, int m)
{
	this->codigo = c;
	this->cantmax = m;
}

avion::~avion()
{
}

void avion::setcodigo(string c)
{
	this->codigo = c;
}

void avion::setcantmax(int c)
{
	this->cantmax = c;
}

string avion::getcodigo()
{
	return codigo;
}

int avion::getcantmaz()
{
	return cantmax;
}

string avion::tostring()
{
	stringstream s;
	s << "--Avion--" << endl
		<< "codigo: " << codigo << endl
		<< "cantidad maxima de pasajeros: " << cantmax << endl;
	return s.str();
}

void avion::guardar(ofstream& c)
{
	c << getcodigo() << endl
		<< getcantmaz() << endl;
}

avion* avion::cargar(ifstream& estFile)
{
	string id;
	int maz;
	if (!(estFile >> id)) { return NULL; }
	if (!(estFile >> maz)) { return NULL; }
	return new avion(id, maz);
}
