#pragma once
#include "avion.h"
class nodoavion
{
	private:
	avion* C;
	nodoavion* sig;
public:
	nodoavion(avion*, nodoavion*);
	~nodoavion();
	void setavion(avion*);
	avion* getavion();
	void setSig(nodoavion*);
	nodoavion* getSig();
	string toStringnodoavion();
};

