#pragma once
#include"nodotripulante.h"
class listatripulantes
{
private:
    nodotripulante* first;
    nodotripulante* actual;
public:
    listatripulantes();
    ~listatripulantes();
    void agregarIni(tripulante*);
    void agregarFinal(tripulante*);
    string toString();
    bool estaVacia();
    bool eliminarEspecifico(string);
    void ordenarLista();
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busquedaid(string);
    tripulante* busquedaid2(string);
     void guardar();
	listatripulantes* Leer();
};

