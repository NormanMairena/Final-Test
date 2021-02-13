#pragma once
#include"reservacion.h"
class nodoreservacion
{
		private:
	reservacion* C;
	nodoreservacion* sig;
public:
	nodoreservacion(reservacion*, nodoreservacion*);
	~nodoreservacion();
	void setreservacion(reservacion*);
	reservacion* getreservacion();
	void setSig(nodoreservacion*);
	nodoreservacion* getSig();
	string toStringnodoreservacion();
};

