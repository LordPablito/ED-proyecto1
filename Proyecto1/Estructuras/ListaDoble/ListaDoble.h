#pragma once
#include "../Nodos/NodoBase.h"

class ListaDoble
{
public:
    ListaDoble() { primero = nullptr; }
    ~ListaDoble();

    void InsertarInicio(NodoBase* NuevoNodo);
    void InsertarFinal(NodoBase* NuevoNodo);
    void InsertarPos(NodoBase* NuevoNodo, int pos);
    bool ListaVacia() { return primero == nullptr; }
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();

private:
    NodoBase* primero;
};

