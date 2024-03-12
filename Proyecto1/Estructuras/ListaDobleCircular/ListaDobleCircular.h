#pragma once
#include "../Nodos/NodoBase.h"

class ListaDobleCircular
{
public:
    ListaDobleCircular() { primero = nullptr; }
    ~ListaDobleCircular();

    void InsertarInicio(NodoBase* NuevoNodo);
    void InsertarFinal(NodoBase* NuevoNodo);
    void InsertarPos(NodoBase* NuevoNodo, int pos);
    bool ListaVacia() { return primero == nullptr; }
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();

    NodoBase* GetPrimero() const
    {
        return primero;
    }

private:
    NodoBase* primero;
};