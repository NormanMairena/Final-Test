#pragma once
#include<iostream>
#include <sstream>
using namespace std;



int convertirInt(std::string s) {
	std::stringstream r(s);
	int v;
	r >> v;
	return v;
}

double convertirDouble(std::string s) {
	std::stringstream r(s);
	double v;
	r >> v;
	return v;
}

double calcularCategoria(int cat, double precio)
{
	if (cat==2)
	{
		precio = (precio * 0.30) + precio;
	}
	if (cat==3)
	{
		precio = precio - (precio * 0.10);
	}
	if (cat==4)
	{
		precio = precio - (precio * 0.5);
	}
	return precio;
}
