#pragma once
#include"Persona.h"
class guia: public Persona
{
private:
	string telefono;
	string especialidad;
public:
	guia(string = "nombre", string = "apellido", string = "ced", string = "telefono", string = "especialidad");
	~guia();
	void settelefono(string);
	void setespecialidad(string);

	string gettelefono();
	string getespecialidad();
	string tostring();
	void guardar(ofstream&);
	static guia* cargar(ifstream&);
};

