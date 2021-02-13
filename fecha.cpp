#include "fecha.h"

fecha::fecha(int d, int m, int a)
{
	this->dia = d;
	this->mes = m;
	this->annio = a;
}

fecha::~fecha()
{
}

void fecha::setdia(int c) 
{
	this->dia = c;
}

void fecha::setmes(int  c) 
{
	this->mes = c;
}

void fecha::setannio(int c)
{
	this->annio = c;
}

int fecha::getdia()
{
	return dia;
}

int fecha::getmes()
{
	return mes;
}

int fecha::getannio()
{
	return annio;
}

string fecha::tostring()
{
	stringstream s;

	s << dia << " / " << mes << " / " << annio << endl;
	return s.str();
}
