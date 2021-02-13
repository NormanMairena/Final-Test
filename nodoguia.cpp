#include "nodoguia.h"
nodoguia::nodoguia(guia* c, nodoguia* N) {
	C = c;
	sig = N;
}
nodoguia:: ~nodoguia(){}
void nodoguia::setguia(guia* C) { this->C = C; }
guia* nodoguia::getguia() { return C; }
void nodoguia::setSig(nodoguia* sig) { this->sig = sig; }
nodoguia* nodoguia::getSig() { return sig; }
string nodoguia::toStringnodoguia() { return C->tostring(); }
