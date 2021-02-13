#include "nodoavion.h"
nodoavion::nodoavion(avion* c, nodoavion* N) {
	C = c;
	sig = N;
}
nodoavion:: ~nodoavion(){}
void nodoavion::setavion(avion* C) { this->C = C; }
avion* nodoavion::getavion() { return C; }
void nodoavion::setSig(nodoavion* sig) { this->sig = sig; }
nodoavion* nodoavion::getSig() { return sig; }
string nodoavion::toStringnodoavion() { return C->tostring(); }