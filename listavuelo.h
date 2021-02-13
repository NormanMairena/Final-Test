#pragma once
#include"nodovuelo.h"
class listavuelo
{
	private:
    nodovuelo* first;
    nodovuelo* actual;
    public:
    listavuelo();
    ~listavuelo();
    void agregarIni(vuelo*);
    void agregarFinal(vuelo*);
    string toString();
    bool estaVacia();
    bool eliminarEspecifico(string);
    void ordenarLista();
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busquedaid(string);
    vuelo* busquedaid2(string);
    void guardar(ofstream&);
	static listavuelo* Leer(ifstream&);
};

