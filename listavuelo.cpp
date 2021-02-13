#include "listavuelo.h"
listavuelo::listavuelo():first(NULL), actual(NULL) {}
listavuelo::~listavuelo() {}
bool listavuelo::estaVacia() {
	if (first == NULL) { return true; }
	return false;
}
void listavuelo::agregarIni(vuelo* dato) {
	first = new nodovuelo(dato, first);
}
void listavuelo::agregarFinal(vuelo* C) {
	actual = first;
	if (estaVacia()) {
		first = new nodovuelo(C, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new nodovuelo(C, NULL));
	}
}
bool listavuelo::eliminarEspecifico(string  x) { 
	nodovuelo* panterior = NULL;
	actual = first;
	if (first == NULL) {
		return false;
	}
	if (first->getvuelo()->getcodigo() == x) {
		actual = actual->getSig();
		delete (first);
		first = actual;
		return true;
	}
	while (actual != NULL && actual->getvuelo()->getcodigo() != x) {
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
bool listavuelo::eliminarIni() {
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
bool listavuelo::eliminaFinal() {
	actual = first;
	nodovuelo* anterior = NULL;
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
int listavuelo::cuentaNodos() {
	int cont = 0;
	actual = first;
	while (first != NULL) {
		first = first->getSig();
		cont++;
	}
	return cont;
}
bool listavuelo::busquedaid(string id) {
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getvuelo()->getcodigo() == id) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
vuelo* listavuelo::busquedaid2(string id2) {
	if (estaVacia()) {
		return NULL;
	}
	else {
		if (busquedaid(id2) != false) {
			return actual->getvuelo();
		}
		return NULL;
		cout << "no encontro" << endl;
	}
}

//void listavuelo::guardar(ofstream& c)
//{
//	actual = first;
//	while (actual != NULL) {
//		actual->getvuelo()->guardar(c);
//		actual = actual->getSig();
//	}
//}
//listavuelo* listavuelo::Leer(ifstream& c)
//{
//	listavuelo* li = new listavuelo();
//	vuelo* C = NULL;
//	while (c.good())
//	{
//		C = vuelo::leer(c);
//		if (C!=NULL)
//		{
//
//			li->agregarFinal(C);
//		}
//	}
//	return li;
//}
string listavuelo::toString() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringnodovuelo() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
void listavuelo::ordenarLista() {
	actual = first;
	nodovuelo* aux = NULL;
	vuelo* c;
	while (actual->getSig() != NULL) {
		aux = actual->getSig();
		while (aux != NULL) {
			if (actual->getvuelo()->getcodigo() > aux->getvuelo()->getcodigo()) {
				c = aux->getvuelo();
				aux->setvuelo(actual->getvuelo());
				actual->setvuelo(c);
			}
			aux = aux->getSig();
		}
		actual = actual->getSig();
	}
}


