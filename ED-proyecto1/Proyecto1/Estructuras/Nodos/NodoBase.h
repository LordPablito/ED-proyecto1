#pragma once

class NodoBase
{
public:
    NodoBase* Siguiente;
    NodoBase* Anterior;

    NodoBase* Izquierda;
    NodoBase* Derecha;
    int FactorBalance;
    
    int Vistas = 0;
    int Busquedas = 0;

    virtual void Mostrar();
    virtual int GetLlave();
};
