#include "listareservaciones.h"
listareservaciones::listareservaciones():first(NULL), actual(NULL) {}
listareservaciones::~listareservaciones() {}
bool listareservaciones::estaVacia() {
	if (first == NULL) { return true; }
	return false;
}
void listareservaciones::agregarIni(reservacion* dato) {
	first = new nodoreservacion(dato, first);
}
void listareservaciones::agregarFinal(reservacion* C) {
	actual = first;
	if (estaVacia()) {
		first = new nodoreservacion(C, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new nodoreservacion(C, NULL));
	}
}
bool listareservaciones::eliminarEspecifico(string  x) { 
	nodoreservacion* panterior = NULL;
	actual = first;
	if (first == NULL) {
		return false;
	}
	if (first->getreservacion()->getcodigo() == x) {
		actual = actual->getSig();
		delete (first);
		first = actual;
		return true;
	}
	while (actual != NULL && actual->getreservacion()->getcodigo() != x) {
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
bool listareservaciones::eliminarIni() {
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
bool listareservaciones::eliminaFinal() {
	actual = first;
	nodoreservacion* anterior = NULL;
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
int listareservaciones::cuentaNodos() {
	int cont = 0;
	actual = first;
	while (first != NULL) {
		first = first->getSig();
		cont++;
	}
	return cont;
}
bool listareservaciones::busquedaid(string id) {
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getreservacion()->getcodigo() == id) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
reservacion* listareservaciones::busquedaid2(string id2) {
	if (estaVacia()) {
		return NULL;
	}
	else {
		if (busquedaid(id2) != false) {
			return actual->getreservacion();
		}
		return NULL;
		cout << "no encontro" << endl;
	}
}

string listareservaciones::opcion8(string codevuelo)
{
	actual = first;
	stringstream s;
	while (actual != NULL) {
		if (actual->getreservacion()->getVUELO()->getcodigo()==codevuelo)
		{
			s << actual->getreservacion()->tostring() << endl;
		}
		actual = actual->getSig();
	}
	return s.str();
}

string listareservaciones::opcion10(string codevuelo)
{
	actual = first;
	stringstream s;
	while (actual != NULL) {
		if (actual->getreservacion()->getVUELO()->getcodigo() == codevuelo)
		{
			s << actual->getreservacion()->getCLIENTE()->tostring() << endl;
		}
		actual = actual->getSig();
	}
	return s.str();
}

double listareservaciones::montoprimeraclase(string codevuelo)
{
	actual = first;
	double result=0;
	while (actual != NULL) {
		if (actual->getreservacion()->getVUELO()->getcodigo() == codevuelo&&actual->getreservacion()->getcategoria()==1)
		{
			result = result + actual->getreservacion()->getmonto();
		}
		actual = actual->getSig();
	}
	return result;
}

double listareservaciones::montosegunda(string codevuelo)
{
	actual = first;
	double result=0;
	while (actual != NULL) {
		if (actual->getreservacion()->getVUELO()->getcodigo() == codevuelo && actual->getreservacion()->getcategoria() == 2)
		{
			result = result + actual->getreservacion()->getmonto();
		}
		actual = actual->getSig();
	}
	return result;
}

double listareservaciones::montotercera(string codevuelo)
{
	actual = first;
	double result=0;
	while (actual != NULL) {
		if (actual->getreservacion()->getVUELO()->getcodigo() == codevuelo && actual->getreservacion()->getcategoria() == 3)
		{
			result = result + actual->getreservacion()->getmonto();
		}
		actual = actual->getSig();
	}
	return result;
}

double listareservaciones::montocuarta(string codevuelo)
{
	actual = first;
	double result=0;
	while (actual != NULL) {
		if (actual->getreservacion()->getVUELO()->getcodigo() == codevuelo && actual->getreservacion()->getcategoria() == 4)
		{
			result = result + actual->getreservacion()->getmonto();
		}
		actual = actual->getSig();
	}
	return result;
}

string listareservaciones::opcion13(string codevuelo)
{
	stringstream s;
	actual = first;

	while (actual != NULL) {
		if (actual->getreservacion()->getVUELO()->getcodigo() == codevuelo && actual->getreservacion()->getcategoria() == 1)
		{
			s<<actual->getreservacion()->getCLIENTE()->tostring();
		}
		actual = actual->getSig();
	}
	return s.str();
}

//void listareservacion::guardar(ofstream& c)
//{
//	actual = first;
//	while (actual != NULL) {
//		actual->getreservacion()->guardar(c);
//		actual = actual->getSig();
//	}
//}
//listareservacion* listareservacion::Leer(ifstream& c)
//{
//	listareservacion* li = new listareservacion();
//	reservacion* C = NULL;
//	while (c.good())
//	{
//		C = reservacion::leer(c);
//		if (C!=NULL)
//		{
//
//			li->agregarFinal(C);
//		}
//	}
//	return li;
//}
string listareservaciones::toString() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringnodoreservacion() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
void listareservaciones::ordenarLista() {
	actual = first;
	nodoreservacion* aux = NULL;
	reservacion* c;
	while (actual->getSig() != NULL) {
		aux = actual->getSig();
		while (aux != NULL) {
			if (actual->getreservacion()->getcodigo() > aux->getreservacion()->getcodigo()) {
				c = aux->getreservacion();
				aux->setreservacion(actual->getreservacion());
				actual->setreservacion(c);
			}
			aux = aux->getSig();
		}
		actual = actual->getSig();
	}
}
