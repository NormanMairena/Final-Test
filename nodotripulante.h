#pragma once
#include"tripulante.h"
class nodotripulante
{
	private:
	tripulante* C;
	nodotripulante* sig;
public:
	nodotripulante(tripulante*, nodotripulante*);
	~nodotripulante();
	void settripulante(tripulante*);
	tripulante* gettripulante();
	void setSig(nodotripulante*);
	nodotripulante* getSig();
	string toStringnodotripulante();
};

