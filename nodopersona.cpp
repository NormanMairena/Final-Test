#include "nodopersona.h"
nodocliente::nodocliente(cliente* c, nodocliente* N) {
	C = c;
	sig = N;
}
nodocliente:: ~nodocliente(){}
void nodocliente::setcliente(cliente* C) { this->C = C; }
cliente* nodocliente::getcliente() { return C; }
void nodocliente::setSig(nodocliente* sig) { this->sig = sig; }
nodocliente* nodocliente::getSig() { return sig; }
string nodocliente::toStringnodocliente() { return C->tostring(); }