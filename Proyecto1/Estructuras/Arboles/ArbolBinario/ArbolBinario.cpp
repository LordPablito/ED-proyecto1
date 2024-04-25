#include "ArbolBinario.h"

#include <vcruntime.h>

void ArbolBinario::InsertarNodo(NodoBase* Nodo)
{
    if (!Raiz)
    {
        return;
    }
    Insertar(Raiz, Nodo);
}

NodoBase* ArbolBinario::BuscarNodo(NodoBase* NodoRaiz, int Llave)
{
    if (!NodoRaiz)
    {
        return nullptr;
    }

    if (NodoRaiz->GetLlave() == Llave)
    {
        return NodoRaiz;
    }

    if (Llave < NodoRaiz->GetLlave())
    {
        return BuscarNodo(NodoRaiz->Izquierda, Llave);
    }
    return BuscarNodo(NodoRaiz->Derecha, Llave);
    
}

void ArbolBinario::Insertar(NodoBase* NodoRaiz, NodoBase* Nodo)
{
    if (!NodoRaiz)
    {
        NodoRaiz = Nodo;
        return;
    }

    if (Nodo->GetLlave() < NodoRaiz->GetLlave())
    {
        Insertar(NodoRaiz->Izquierda, Nodo);
    }
    else
    {
        Insertar(NodoRaiz->Derecha, Nodo);
    }
}
