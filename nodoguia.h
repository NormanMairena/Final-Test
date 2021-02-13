#pragma once
#include"guia.h"
class nodoguia
{
	private:
	guia* C;
	nodoguia* sig;
public:
	nodoguia(guia*, nodoguia*);
	~nodoguia();
	void setguia(guia*);
	guia* getguia();
	void setSig(nodoguia*);
	nodoguia* getSig();
	string toStringnodoguia();
};

