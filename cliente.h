#pragma once
#include"Persona.h"
class cliente:public Persona
{
private:
	string tarjeta;
public:
	cliente(string= "nombre", string= "apellido", string= "ced", string ="numero de tarj");
	~cliente();
	void settarjeta(string);
	string gettarjeta();
	string tostring();
	void guardar(ofstream&);
	static cliente* cargar(ifstream&);
};

