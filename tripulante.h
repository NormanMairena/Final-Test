#pragma once
#include"Persona.h"
class tripulante: public Persona
{
private:
	string carnet;
	string rol;
public:
	tripulante(string= "nombre", string= "apellido", string= "ced", string= "carnet", string= "rol");
	~tripulante();
	void setcarnet(string);
	void setrol(string);

	string getcarnet();
	string getrol();
	string tostring();
	void guardar(ofstream&);
	static tripulante* cargar(ifstream&);
};

