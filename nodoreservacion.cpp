#include "nodoreservacion.h"

nodoreservacion::nodoreservacion(reservacion* c, nodoreservacion* N) {
	C = c;
	sig = N;
}
nodoreservacion:: ~nodoreservacion(){}
void nodoreservacion::setreservacion(reservacion* C) { this->C = C; }
reservacion* nodoreservacion::getreservacion() { return C; }
void nodoreservacion::setSig(nodoreservacion* sig) { this->sig = sig; }
nodoreservacion* nodoreservacion::getSig() { return sig; }
string nodoreservacion::toStringnodoreservacion() { return C->tostring(); }