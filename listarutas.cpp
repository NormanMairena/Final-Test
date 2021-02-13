#include "listarutas.h"
listaruta::listaruta():first(NULL), actual(NULL) {}
listaruta::~listaruta() {}
bool listaruta::estaVacia() {
	if (first == NULL) { return true; }
	return false;
}
void listaruta::agregarIni(ruta* dato) {
	first = new nodoruta(dato, first);
}
void listaruta::agregarFinal(ruta* C) {
	actual = first;
	if (estaVacia()) {
		first = new nodoruta(C, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new nodoruta(C, NULL));
	}
}
bool listaruta::eliminarEspecifico(string  x) { 
	nodoruta* panterior = NULL;
	actual = first;
	if (first == NULL) {
		return false;
	}
	if (first->getruta()->getid()==x) {
		actual = actual->getSig();
		delete (first);
		first = actual;
		return true;
	}
	while (first->getruta()->getid() != x) {
		panterior = actual;
		actual = actual->getSig();
	}

	if (actual == NULL) { return false; }
	else {
		panterior->setSig(actual->getSig());
		delete actual;
		return true;
	}
	return false;
}
bool listaruta::eliminarIni() {
	if (estaVacia()) {
		return false;
	}
	else {
		actual = first;
		first = first->getSig();
		delete actual;
		return true;
	}
}
bool listaruta::eliminaFinal() {
	actual = first;
	nodoruta* anterior = NULL;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(anterior->getSig());
		delete actual;
		actual = first;
		return true;
	}
}
int listaruta::cuentaNodos() {
	int cont = 0;
	actual = first;
	while (first != NULL) {
		first = first->getSig();
		cont++;
	}
	return cont;
}
bool listaruta::busquedaid(string x) {
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (first->getruta()->getid()==x) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
ruta* listaruta::busquedaid2(string x) {
	if (estaVacia()) {
		return NULL;
	}
	else {
		if (busquedaid(x) != false) {
			return actual->getruta();
		}
		return NULL;
		cout << "no encontro" << endl;
	}
}

ruta* listaruta::rutamoda()
{
	int contador=0, contanterior=0;
	nodoruta* Winer=NULL;
	actual = first;
	while (first != NULL) {
		contanterior = contador;
		for (nodoruta* aux = first; aux->getSig()!=NULL; aux->getSig())
		{
			if (aux->getruta()->getCiudad2()==actual->getruta()->getCiudad2())
			{
				contador++;
			}
			
		}
		if (contador>contanterior)
		{
			Winer->setruta(actual->getruta());
		}
		
		first = first->getSig();	
	}
	return Winer->getruta();
	
		
}

void listaruta::guardar()
{
	actual = first;
	ofstream c;
	c.open("Rutas.txt", ios::app);

	while (actual != NULL) {
		actual->getruta()->guardar(c);
		actual = actual->getSig();
	}
	c.close();
}

listaruta* listaruta::Leer()
{
	ifstream c;
	c.open("Rutas.txt", ios::in);
	listaruta* li = new listaruta();
	ruta* C = NULL;
	while (c.good())
	{
		C = ruta::cargar(c);
		if (C != NULL)
		{

			li->agregarFinal(C);
		}
	}
	c.close();
	return li;
}



//void listaruta::guardar(ofstream& c)
//{
//	actual = first;
//	while (actual != NULL) {
//		actual->getruta()->guardar(c);
//		actual = actual->getSig();
//	}
//}
//listaruta* listaruta::Leer(ifstream& c)
//{
//	listaruta* li = new listaruta();
//	ruta* C = NULL;
//	while (c.good())
//	{
//		C = ruta::leer(c);
//		if (C!=NULL)
//		{
//
//			li->agregarFinal(C);
//		}
//	}
//	return li;
//}
string listaruta::toString() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringnodoruta() << endl;
		actual = actual->getSig();
	}
	return s.str();
}

