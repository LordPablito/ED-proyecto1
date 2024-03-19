#pragma once

class NodoBase
{
public:
    NodoBase* Siguiente;
    NodoBase* Anterior;

    virtual void Mostrar();
};
