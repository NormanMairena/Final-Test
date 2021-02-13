#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "agencia.h"
using namespace std;

void main()
{
	listaclientes* C= new listaclientes();
	listaguias* G= new listaguias();
	listatripulantes* T = new listatripulantes();
	listaavion* AV = new listaavion();
	listaruta* R = new listaruta();
	listavuelo* V = new listavuelo();
	listareservaciones* Res = new listareservaciones();
	agencia* A = new agencia("Avianca", "00-11111-0", "23233232", C, G, T,AV,R,V,Res);
	A->Menu();
	cin.get();
}