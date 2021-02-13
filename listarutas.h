#pragma once
#include"nodoruta.h"
class listaruta
{
	private:
    nodoruta* first;
    nodoruta* actual;
    public:
    listaruta();
    ~listaruta();
    void agregarIni(ruta*);
    void agregarFinal(ruta*);
    string toString();
    bool estaVacia();
    bool eliminarEspecifico(string);
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busquedaid(string);//ciudad partida y llegada
    ruta* busquedaid2(string);
    ruta* rutamoda();
    void guardar();
	listaruta* Leer();
};

