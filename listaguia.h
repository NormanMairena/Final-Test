#pragma once
#include"nodoguia.h"
class listaguias
{
	private:
    nodoguia* first;
    nodoguia* actual;
    public:
    listaguias();
    ~listaguias();
    void agregarIni(guia*);
    void agregarFinal(guia*);
    string toString();
    bool estaVacia();
    bool eliminarEspecifico(string);
    void ordenarLista();
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busquedaid(string);
    guia* busquedaid2(string);
	 void guardar();
	listaguias* Leer();
};

