
#pragma once
#include"vuelo.h"
class nodovuelo
{
	private:
	vuelo* C;
	nodovuelo* sig;
public:
	nodovuelo(vuelo*, nodovuelo*);
	~nodovuelo();
	void setvuelo(vuelo*);
	vuelo* getvuelo();
	void setSig(nodovuelo*);
	nodovuelo* getSig();
	string toStringnodovuelo();
};

