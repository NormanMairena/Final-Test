#pragma once
#include"nodoreservacion.h"
class listareservaciones
{
	private:
    nodoreservacion* first;
    nodoreservacion* actual;
    public:
    listareservaciones();
    ~listareservaciones();
    void agregarIni(reservacion*);
    void agregarFinal(reservacion*);
    string toString();
    bool estaVacia();
    bool eliminarEspecifico(string);
    void ordenarLista();
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busquedaid(string);
    reservacion* busquedaid2(string);
     string opcion8(string);
     string opcion10(string);
    
     double montoprimeraclase(string);
     double montosegunda(string);
     double montotercera(string);
     double montocuarta(string);
    string opcion13(string);
    void guardar(ofstream&);
	static listareservaciones* Leer(ifstream&);
};

