#pragma once
#include<fstream>
#include"nodopersona.h"
class listaclientes
{
private:
    nodocliente* first;
    nodocliente* actual;
public:
    listaclientes();
    ~listaclientes();
    void agregarIni(cliente*);
    void agregarFinal(cliente*);
    string toString();
    bool estaVacia();
    bool eliminarEspecifico(string);
    void ordenarLista();
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busquedaid(string);
    cliente* busquedaid2(string);
   
    void guardar();
	listaclientes* Leer();
};

