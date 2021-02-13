#pragma once
#include"nodoavion.h"
class listaavion
{
	private:
    nodoavion* first;
    nodoavion* actual;
    public:
    listaavion();
    ~listaavion();
    void agregarIni(avion*);
    void agregarFinal(avion*);
    string toString();
    bool estaVacia();
    bool eliminarEspecifico(string);
    void ordenarLista();
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busquedaid(string);
    avion* busquedaid2(string);
    void guardar();
	listaavion* Leer();
};

