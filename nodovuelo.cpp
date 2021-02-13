#include "nodovuelo.h"
nodovuelo::nodovuelo(vuelo* c, nodovuelo* N) {
	C = c;
	sig = N;
}
nodovuelo:: ~nodovuelo(){}
void nodovuelo::setvuelo(vuelo* C) { this->C = C; }
vuelo* nodovuelo::getvuelo() { return C; }
void nodovuelo::setSig(nodovuelo* sig) { this->sig = sig; }
nodovuelo* nodovuelo::getSig() { return sig; }
string nodovuelo::toStringnodovuelo() { return C->tostring(); }

