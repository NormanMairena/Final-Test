#include "nodotripulante.h"
nodotripulante::nodotripulante(tripulante* c, nodotripulante* N) {
	C = c;
	sig = N;
}
nodotripulante:: ~nodotripulante(){}
void nodotripulante::settripulante(tripulante* C) { this->C = C; }
tripulante* nodotripulante::gettripulante() { return C; }
void nodotripulante::setSig(nodotripulante* sig) { this->sig = sig; }
nodotripulante* nodotripulante::getSig() { return sig; }
string nodotripulante::toStringnodotripulante() { return C->tostring(); }
