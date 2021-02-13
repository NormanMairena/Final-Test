#include "listaavion.h"
listaavion::listaavion():first(NULL), actual(NULL) {}
listaavion::~listaavion() {}
bool listaavion::estaVacia() {
	if (first == NULL) { return true; }
	return false;
}
void listaavion::agregarIni(avion* dato) {
	first = new nodoavion(dato, first);
}
void listaavion::agregarFinal(avion* C) {
	actual = first;
	if (estaVacia()) {
		first = new nodoavion(C, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new nodoavion(C, NULL));
	}
}
bool listaavion::eliminarEspecifico(string  x) { 
	nodoavion* panterior = NULL;
	actual = first;
	if (first == NULL) {
		return false;
	}
	if (first->getavion()->getcodigo() == x) {
		actual = actual->getSig();
		delete (first);
		first = actual;
		return true;
	}
	while (actual != NULL && actual->getavion()->getcodigo() != x) {
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
bool listaavion::eliminarIni() {
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
bool listaavion::eliminaFinal() {
	actual = first;
	nodoavion* anterior = NULL;
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
int listaavion::cuentaNodos() {
	int cont = 0;
	actual = first;
	while (first != NULL) {
		first = first->getSig();
		cont++;
	}
	return cont;
}
bool listaavion::busquedaid(string id) {
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getavion()->getcodigo() == id) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
avion* listaavion::busquedaid2(string id2) {
	if (estaVacia()) {
		return NULL;
	}
	else {
		if (busquedaid(id2) != false) {
			return actual->getavion();
		}
		return NULL;
		cout << "no encontro" << endl;
	}
}

void listaavion::guardar()
{
	actual = first;
	ofstream c;
	c.open("Aviones.txt", ios::app);

	while (actual != NULL) {
		actual->getavion()->guardar(c);
		actual = actual->getSig();
	}
	c.close();
}

listaavion* listaavion::Leer()
{
	ifstream c;
	c.open("Aviones.txt", ios::in);
	listaavion* li = new listaavion();
	avion* C = NULL;
	while (c.good())
	{
		C = avion::cargar(c);
		if (C != NULL)
		{

			li->agregarFinal(C);
		}
	}
	c.close();
	return li;
}

//void listaavion::guardar(ofstream& c)
//{
//	actual = first;
//	while (actual != NULL) {
//		actual->getavion()->guardar(c);
//		actual = actual->getSig();
//	}
//}
//listaavion* listaavion::Leer(ifstream& c)
//{
//	listaavion* li = new listaavion();
//	avion* C = NULL;
//	while (c.good())
//	{
//		C = avion::leer(c);
//		if (C!=NULL)
//		{
//
//			li->agregarFinal(C);
//		}
//	}
//	return li;
//}
string listaavion::toString() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringnodoavion() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
void listaavion::ordenarLista() {
	actual = first;
	nodoavion* aux = NULL;
	avion* c;
	while (actual->getSig() != NULL) {
		aux = actual->getSig();
		while (aux != NULL) {
			if (actual->getavion()->getcodigo() > aux->getavion()->getcodigo()) {
				c = aux->getavion();
				aux->setavion(actual->getavion());
				actual->setavion(c);
			}
			aux = aux->getSig();
		}
		actual = actual->getSig();
	}
}


