#pragma once
#include"cliente.h"
class nodocliente
{
	private:
	cliente* C;
	nodocliente* sig;
public:
	nodocliente(cliente*, nodocliente*);
	~nodocliente();
	void setcliente(cliente*);
	cliente* getcliente();
	void setSig(nodocliente*);
	nodocliente* getSig();
	string toStringnodocliente();
};

