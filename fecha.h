#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class fecha
{
private:
	int dia, mes, annio;
public:
	fecha(int = 0, int = 0, int = 0);
	~fecha();
	void setdia(int);
	void setmes(int);
	void setannio(int);
	int getdia();
	int getmes();
	int getannio();

	string tostring();
};

