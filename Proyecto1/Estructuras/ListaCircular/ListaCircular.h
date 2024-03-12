#pragma once
#include "../Nodos/NodoBase.h"

class ListaCircular
{
public:
    ListaCircular();
    ~ListaCircular();

    void InsertarInicio(NodoBase* NuevoNodo);
    void InsertarFinal(NodoBase* NuevoNodo);
    void InsertarPos(NodoBase* NuevoNodo, int pos);
    bool ListaVacia();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();

    NodoBase* GetPrimero() const;

private:
    NodoBase* primero;
};
