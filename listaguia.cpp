#include "listaguia.h"
listaguias::listaguias():first(NULL), actual(NULL) {}
listaguias::~listaguias() {}
bool listaguias::estaVacia() {
	if (first == NULL) { return true; }
	return false;
}
void listaguias::agregarIni(guia* dato) {
	first = new nodoguia(dato, first);
}
void listaguias::agregarFinal(guia* C) {
	actual = first;
	if (estaVacia()) {
		first = new nodoguia(C, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new nodoguia(C, NULL));
	}
}
bool listaguias::eliminarEspecifico(string  x) { 
	nodoguia* panterior = NULL;
	actual = first;
	if (first == NULL) {
		return false;
	}
	if (first->getguia()->getced() == x) {
		actual = actual->getSig();
		delete (first);
		first = actual;
		return true;
	}
	while (actual != NULL && actual->getguia()->getced() != x) {
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
bool listaguias::eliminarIni() {
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
bool listaguias::eliminaFinal() {
	actual = first;
	nodoguia* anterior = NULL;
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
int listaguias::cuentaNodos() {
	int cont = 0;
	actual = first;
	while (first != NULL) {
		first = first->getSig();
		cont++;
	}
	return cont;
}
bool listaguias::busquedaid(string id) {
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getguia()->getced() == id) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
guia* listaguias::busquedaid2(string id2) {
	if (estaVacia()) {
		return NULL;
	}
	else {
		if (busquedaid(id2) != false) {
			return actual->getguia();
		}
		return NULL;
		cout << "no encontro" << endl;
	}
}

void listaguias::guardar()
{
	actual = first;
	ofstream c;
	c.open("Guias.txt", ios::app);

	while (actual != NULL) {
		actual->getguia()->guardar(c);
		actual = actual->getSig();
	}
	c.close();
}

listaguias* listaguias::Leer()
{
	ifstream c;
	c.open("Guias.txt", ios::in);
	listaguias* li = new listaguias();
	guia* C = NULL;
	while (c.good())
	{
		C = guia::cargar(c);
		if (C != NULL)
		{

			li->agregarFinal(C);
		}
	}
	c.close();
	return li;
}

//void listaguias::guardar(ofstream& c)
//{
//	actual = first;
//	while (actual != NULL) {
//		actual->getguia()->guardar(c);
//		actual = actual->getSig();
//	}
//}
//listaguias* listaguias::Leer(ifstream& c)
//{
//	listaguias* li = new listaguias();
//	guia* C = NULL;
//	while (c.good())
//	{
//		C = guia::leer(c);
//		if (C!=NULL)
//		{
//
//			li->agregarFinal(C);
//		}
//	}
//	return li;
//}
string listaguias::toString() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringnodoguia() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
void listaguias::ordenarLista() {
	actual = first;
	nodoguia* aux = NULL;
	guia* c;
	while (actual->getSig() != NULL) {
		aux = actual->getSig();
		while (aux != NULL) {
			if (actual->getguia()->getced() > aux->getguia()->getced()) {
				c = aux->getguia();
				aux->setguia(actual->getguia());
				actual->setguia(c);
			}
			aux = aux->getSig();
		}
		actual = actual->getSig();
	}
}

