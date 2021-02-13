#include "listaclientes.h"
listaclientes::listaclientes():first(NULL), actual(NULL) {}
listaclientes::~listaclientes() {}
bool listaclientes::estaVacia() {
	if (first == NULL) { return true; }
	return false;
}
void listaclientes::agregarIni(cliente* dato) {
	first = new nodocliente(dato, first);
}
void listaclientes::agregarFinal(cliente* C) {
	actual = first;
	if (estaVacia()) {
		first = new nodocliente(C, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new nodocliente(C, NULL));
	}
}
bool listaclientes::eliminarEspecifico(string  x) { //Busca por placa
	nodocliente* panterior = NULL;
	actual = first;
	if (first == NULL) {
		return false;
	}
	if (first->getcliente()->getced() == x) {
		actual = actual->getSig();
		delete (first);
		first = actual;
		return true;
	}
	while (actual != NULL && actual->getcliente()->getced() != x) {
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
bool listaclientes::eliminarIni() {
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
bool listaclientes::eliminaFinal() {
	actual = first;
	nodocliente* anterior = NULL;
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
int listaclientes::cuentaNodos() {
	int cont = 0;
	actual = first;
	while (first != NULL) {
		first = first->getSig();
		cont++;
	}
	return cont;
}
bool listaclientes::busquedaid(string id) {
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getcliente()->getced() == id) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
cliente* listaclientes::busquedaid2(string id2) {
	if (estaVacia()) {
		return NULL;
	}
	else {
		if (busquedaid(id2) != false) {
			return actual->getcliente();
		}
		return NULL;
		cout << "no encontro" << endl;
	}
}

void listaclientes::guardar()
{
	actual = first;
	ofstream c;
	c.open("Clientes.txt", ios::app);

	while (actual != NULL) {
		actual->getcliente()->guardar(c);
		actual = actual->getSig();
	}
	c.close();
}

listaclientes* listaclientes::Leer()
{
	ifstream c;
	c.open("Clientes.txt", ios::in);
	listaclientes* li = new listaclientes();
	cliente* C = NULL;
	while (c.good())
	{
		C = cliente::cargar(c);
		if (C != NULL)
		{

			li->agregarFinal(C);
		}
	}
	c.close();
	return li;
}

//void listaclientes::guardar(ofstream& c)
//{
//	actual = first;
//	while (actual != NULL) {
//		actual->getcliente()->guardar(c);
//		actual = actual->getSig();
//	}
//}
//listaclientes* listaclientes::Leer(ifstream& c)
//{
//	listaclientes* li = new listaclientes();
//	Cliente* C = NULL;
//	while (c.good())
//	{
//		C = Cliente::leer(c);
//		if (C!=NULL)
//		{
//
//			li->agregarFinal(C);
//		}
//	}
//	return li;
//}
string listaclientes::toString() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringnodocliente() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
void listaclientes::ordenarLista() {
	actual = first;
	nodocliente* aux = NULL;
	cliente* c;
	while (actual->getSig() != NULL) {
		aux = actual->getSig();
		while (aux != NULL) {
			if (actual->getcliente()->getced() > aux->getcliente()->getced()) {
				c = aux->getcliente();
				aux->setcliente(actual->getcliente());
				actual->setcliente(c);
			}
			aux = aux->getSig();
		}
		actual = actual->getSig();
	}
}
