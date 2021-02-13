#include "cliente.h"

cliente::cliente(string n, string a, string c, string t):Persona(n, a, c)
{
	this->tarjeta = t;
}

cliente::~cliente()
{
}

void cliente::settarjeta(string c)
{
	this->tarjeta = c;
}

string cliente::gettarjeta()
{
	return tarjeta;
}

string cliente::tostring()
{
	stringstream s;
	s << "--Cliente--" << endl
		<< Persona::tostring() << endl
		<< "tarjeta: " << tarjeta << endl;

	return s.str();
}

void cliente::guardar(ofstream& c)
{
	c << getnom() << endl
		<< getapelli() << endl
		<< getced() << endl
		<< gettarjeta() << endl;
}

cliente* cliente::cargar(ifstream& estFile)
{
	string ced, nom, apell, tarjeta;
	if (!(estFile>>nom)) { return NULL; }
	if (!(estFile>>apell)) { return NULL; }
	if (!(estFile>>ced)) { return NULL; }
	if (!(estFile>>tarjeta)) { return NULL; }
	return new cliente(nom, apell, ced, tarjeta);

}
