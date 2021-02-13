#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class avion
{
private:
	string codigo;
	int cantmax;
public:
	avion(string = "code", int = 0);
	~avion();
	void setcodigo(string);
	void setcantmax(int);

	string getcodigo();
	int getcantmaz();
	string tostring();
	void guardar(ofstream&);
	static avion* cargar(ifstream&);
};

