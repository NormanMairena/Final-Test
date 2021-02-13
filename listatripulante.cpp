#include "listatripulante.h"
listatripulantes::listatripulantes():first(NULL), actual(NULL) {}
listatripulantes::~listatripulantes() {}
bool listatripulantes::estaVacia() {
	if (first == NULL) { return true; }
	return false;
}
void listatripulantes::agregarIni(tripulante* dato) {
	first = new nodotripulante(dato, first);
}
void listatripulantes::agregarFinal(tripulante* C) {
	actual = first;
	if (estaVacia()) {
		first = new nodotripulante(C, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new nodotripulante(C, NULL));
	}
}
bool listatripulantes::eliminarEspecifico(string  x) { //Busca por placa
	nodotripulante* panterior = NULL;
	actual = first;
	if (first == NULL) {
		return false;
	}
	if (first->gettripulante()->getced() == x) {
		actual = actual->getSig();
		delete (first);
		first = actual;
		return true;
	}
	while (actual != NULL && actual->gettripulante()->getced() != x) {
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
bool listatripulantes::eliminarIni() {
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
bool listatripulantes::eliminaFinal() {
	actual = first;
	nodotripulante* anterior = NULL;
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
int listatripulantes::cuentaNodos() {
	int cont = 0;
	actual = first;
	while (first != NULL) {
		first = first->getSig();
		cont++;
	}
	return cont;
}
bool listatripulantes::busquedaid(string id) {
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->gettripulante()->getcarnet() == id) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
tripulante* listatripulantes::busquedaid2(string id2) {
	if (estaVacia()) {
		return NULL;
	}
	else {
		if (busquedaid(id2) != false) {
			return actual->gettripulante();
		}
		return NULL;
		cout << "no encontro" << endl;
	}
}

void listatripulantes::guardar()
{
	actual = first;
	ofstream c;
	c.open("Tripulantes.txt", ios::app);

	while (actual != NULL) {
		actual->gettripulante()->guardar(c);
		actual = actual->getSig();
	}
	c.close();
}

listatripulantes* listatripulantes::Leer()
{
	ifstream c;
	c.open("Tripulantes.txt", ios::in);
	listatripulantes* li = new listatripulantes();
	tripulante* C = NULL;
	while (c.good())
	{
		C = tripulante::cargar(c);
		if (C != NULL)
		{

			li->agregarFinal(C);
		}
	}
	c.close();
	return li;
}

//void listatripulantes::guardar(ofstream& c)
//{
//	actual = first;
//	while (actual != NULL) {
//		actual->gettripulante()->guardar(c);
//		actual = actual->getSig();
//	}
//}
//listatripulantes* listatripulantes::Leer(ifstream& c)
//{
//	listatripulantes* li = new listatripulantes();
//	tripulante* C = NULL;
//	while (c.good())
//	{
//		C = tripulante::leer(c);
//		if (C!=NULL)
//		{
//
//			li->agregarFinal(C);
//		}
//	}
//	return li;
//}
string listatripulantes::toString() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringnodotripulante() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
void listatripulantes::ordenarLista() {
	actual = first;
	nodotripulante* aux = NULL;
	tripulante* c;
	while (actual->getSig() != NULL) {
		aux = actual->getSig();
		while (aux != NULL) {
			if (actual->gettripulante()->getced() > aux->gettripulante()->getced()) {
				c = aux->gettripulante();
				aux->settripulante(actual->gettripulante());
				actual->settripulante(c);
			}
			aux = aux->getSig();
		}
		actual = actual->getSig();
	}
}
