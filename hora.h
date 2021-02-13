#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class hora
{
private:
	int _hora, minutos, segundos;
public:
	hora(int= 0, int= 0, int= 0);
	~hora();
	void sethora(int);
	void setmin(int);
	void setseg(int);
	int gethora();
	int getmin();
	int getseg();

	string tostring();
};

