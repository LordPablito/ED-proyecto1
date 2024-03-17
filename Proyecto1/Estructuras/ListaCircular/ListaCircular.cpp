#include "ListaCircular.h"

#include <iostream>

ListaCircular::ListaCircular() : primero(nullptr) {}

ListaCircular::~ListaCircular()
{
    if (ListaVacia())
    {
        return;
    }

    NodoBase* Aux = primero;
    while (Aux->Siguiente != primero)
    {
        NodoBase* temp = Aux;
        Aux = Aux->Siguiente;
        delete temp;
    }
    delete Aux;
    primero = nullptr;
}

void ListaCircular::InsertarInicio(NodoBase* NuevoNodo)
{
    if (ListaVacia())
    {
        primero = NuevoNodo;
        primero->Siguiente = primero;
    }
    else
    {
        NodoBase* ultimo = primero;
        while (ultimo->Siguiente != primero)
        {
            ultimo = ultimo->Siguiente;
        }
        NuevoNodo->Siguiente = primero;
        primero = NuevoNodo;
        ultimo->Siguiente = primero;
    }
}

void ListaCircular::InsertarFinal(NodoBase* NuevoNodo)
{
    if (ListaVacia())
    {
        primero = NuevoNodo;
        primero->Siguiente = primero;
    }
    else
    {
        NodoBase* ultimo = primero;
        while (ultimo->Siguiente != primero)
        {
            ultimo = ultimo->Siguiente;
        }
        ultimo->Siguiente = NuevoNodo;
        NuevoNodo->Siguiente = primero;
    }
}

void ListaCircular::InsertarPos(NodoBase* NuevoNodo, int pos)
{
    if (pos <= 1)
    {
        InsertarInicio(NuevoNodo);
    }
    else if (pos > largoLista())
    {
        InsertarFinal(NuevoNodo);
    }
    else
    {
        NodoBase* Aux = primero;
        for (int i = 2; i < pos; i++)
        {
            Aux = Aux->Siguiente;
        }
        NuevoNodo->Siguiente = Aux->Siguiente;
        Aux->Siguiente = NuevoNodo;
    }
}

bool ListaCircular::ListaVacia()
{
    return primero == nullptr;
}

void ListaCircular::BorrarFinal()
{
    if (ListaVacia())
    {
        std::cout << "No hay elementos en la lista." << std::endl;
        return;
    }

    if (primero->Siguiente == primero) // Solo un nodo en la lista
    {
        delete primero;
        primero = nullptr;
        return;
    }

    NodoBase* Aux = primero;
    while (Aux->Siguiente->Siguiente != primero)
    {
        Aux = Aux->Siguiente;
    }
    NodoBase* temp = Aux->Siguiente;
    Aux->Siguiente = primero;
    delete temp;
}

void ListaCircular::BorrarInicio()
{
    if (ListaVacia())
    {
        std::cout << "No hay elementos en la lista." << std::endl;
        return;
    }

    if (primero->Siguiente == primero) // Solo un nodo en la lista
    {
        delete primero;
        primero = nullptr;
        return;
    }

    NodoBase* ultimo = primero;
    while (ultimo->Siguiente != primero)
    {
        ultimo = ultimo->Siguiente;
    }
    NodoBase* temp = primero;
    primero = primero->Siguiente;
    ultimo->Siguiente = primero;
    delete temp;
}

void ListaCircular::BorrarPosicion(int pos)
{
    if (ListaVacia())
    {
        std::cout << "Lista vacía." << std::endl;
        return;
    }

    if (pos <= 0 || pos > largoLista())
    {
        std::cout << "Posición inválida." << std::endl;
        return;
    }

    if (pos == 1)
    {
        BorrarInicio();
        return;
    }

    NodoBase* Aux = primero;
    for (int i = 1; i < pos - 1; i++)
    {
        Aux = Aux->Siguiente;
    }
    NodoBase* temp = Aux->Siguiente;
    Aux->Siguiente = temp->Siguiente;
    delete temp;
}

void ListaCircular::Mostrar()
{
    if (ListaVacia())
    {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    NodoBase* Aux = primero;
    do
    {
        Aux->Mostrar();
        Aux = Aux->Siguiente;
    } while (Aux != primero);
    std::cout << std::endl;
}

int ListaCircular::largoLista()
{
    if (ListaVacia())
    {
        return 0;
    }

    int cont = 0;
    NodoBase* Aux = primero;
    do
    {
        cont++;
        Aux = Aux->Siguiente;
    } while (Aux != primero);

    return cont;
}

NodoBase* ListaCircular::GetPrimero() const
{
    return primero;
}
