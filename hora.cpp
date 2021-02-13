#include "hora.h"

hora::hora(int h, int m, int s)
{
	this->_hora = h;
	this->minutos = m;
	this-> segundos= s;
}

hora::~hora()
{
}

void hora::sethora(int d)
{
	this->_hora = d;
}

void hora::setmin(int c)
{
	this->minutos = c;
}

void hora::setseg(int s)
{
	this->segundos = s;
}

int hora::gethora()
{
	return _hora;
}

int hora::getmin()
{
	return minutos;
}

int hora::getseg()
{
	return segundos;
}

string hora::tostring()
{
	stringstream s;
	s << "--Hora--" << endl
		<< "( " << _hora << " / " << minutos << " / " << segundos << " )" << endl;
	return s.str();
}
