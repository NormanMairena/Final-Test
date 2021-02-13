#include "reservacion.h"

reservacion::reservacion(string code, int voletos, int clase, double precio, hora* H, fecha* F, vuelo* V, cliente* C, guia* G)
{
	this->codigo = code;
	this->cantVoletos = voletos;
	this->categoria = clase;
	this->montotot = precio;
	this->HORA = H;
	this->FECHA =F;
	this->VUELO =V;
	this->CLIENTE =C;
	this->GUIA =G;
}

reservacion::~reservacion()
{
}

string reservacion::getcodigo()
{
	return codigo;
}

int reservacion::getcantvoletos()
{
	return cantVoletos;
}

int reservacion::getcategoria()
{
	return categoria;
}

double reservacion::getmonto()
{
	return montotot;
}

hora* reservacion::getHORA()
{
	return HORA;
}

fecha* reservacion::getFECHA()
{
	return FECHA;
}

vuelo* reservacion::getVUELO()
{
	return VUELO;
}

void reservacion::calcular(int cat, double precio)
{
	if (cat == 2)
	{
		precio = (precio * 0.30) + precio;
	}
	if (cat == 3)
	{
		precio = precio - (precio * 0.10);
	}
	if (cat == 4)
	{
		precio = precio - (precio * 0.5);
	}
	montotot = precio * cat;
}

cliente* reservacion::getCLIENTE()
{
	return CLIENTE;
}

guia* reservacion::getGUIA()
{
	return GUIA;
}

string reservacion::tostring()
{
	stringstream s;
	s << "--Reservacion--" << endl
		<< "codigo: " << codigo << endl
		<< "cantidad de voletos: " << cantVoletos << endl
		<< "clase: " << categoria << endl
		<< "Hora: " << HORA->tostring() << endl
		<< "Fecha: " << FECHA->tostring() << endl
		<< "Vuelo: " << VUELO->tostring() << endl
		<< "Cliente: " << CLIENTE->tostring() << endl
		<< "Guia: " << GUIA->tostring() << endl
		<< "subtot : " << montotot - (montotot * 0.13) << endl
		<< "monto total: " << montotot << endl;
	return s.str();
}


