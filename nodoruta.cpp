#include "nodoruta.h"
nodoruta::nodoruta(ruta* c, nodoruta* N) {
	C = c;
	sig = N;
}
nodoruta:: ~nodoruta(){}
void nodoruta::setruta(ruta* C) { this->C = C; }
ruta* nodoruta::getruta() { return C; }
void nodoruta::setSig(nodoruta* sig) { this->sig = sig; }
nodoruta* nodoruta::getSig() { return sig; }
string nodoruta::toStringnodoruta() { return C->tostring(); }
