#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
class Persona
{
protected:
	string nom;
	string apellido;
	string ced;
public:
	Persona(string= "nombre", string= "apellido", string= "ced");
	string getnom();
	string getapelli();
	string getced();

	void setnom(string);
	void setapelli(string);
	void setced(string);
	string tostring();
	~Persona();
};

