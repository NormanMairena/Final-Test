#pragma once
#include"ruta.h"
class nodoruta
{
	private:
	ruta* C;
	nodoruta* sig;
public:
	nodoruta(ruta*, nodoruta*);
	~nodoruta();
	void setruta(ruta*);
	ruta* getruta();
	void setSig(nodoruta*);
	nodoruta* getSig();
	string toStringnodoruta();
};

