#pragma once

class NodoBase
{
public:
    NodoBase* Siguiente;
    NodoBase* Anterior;
    int Vistas = 0;
    int Busquedas = 0;

    virtual void Mostrar();
};
