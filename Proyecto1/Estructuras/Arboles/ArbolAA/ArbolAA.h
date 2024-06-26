#pragma once
#include <iostream>

#include "../../Nodos/NodoBase.h"

class ArbolAA {
public:
    NodoBase* root;
    
    NodoBase* skew(NodoBase* x) {
        //	cout<<"Rotacion derecha"<<endl;
        if (x == nullptr || x->Izquierda == nullptr)
            return x;
        
        if (x->Izquierda->nivel == x->nivel) {
            NodoBase* izq = x->Izquierda;
            x->Izquierda = izq->Derecha;
            izq->Derecha = x;
            return izq;
        }
        return x;
    }

    NodoBase* split(NodoBase* x) {
        //	cout<<"Rotacion izquierda"<<endl;
        if (x == nullptr || x->Derecha == nullptr || x->Derecha->Derecha == nullptr)
            return x;
        
        if (x->nivel == x->Derecha->Derecha->nivel) {
            NodoBase* der = x->Derecha;
            x->Derecha = der->Izquierda;
            der->Izquierda = x;
            der->nivel++;
            return der;
        }
        return x;
    }

    NodoBase* insertHelper(NodoBase* nodo, NodoBase* NodoNuevo) {
        if (nodo == nullptr) {
            nodo = NodoNuevo;
        } else if (NodoNuevo->GetLlave() < nodo->GetLlave()) {
            nodo->Izquierda = insertHelper(nodo->Izquierda, NodoNuevo);
        } else if (NodoNuevo->GetLlave() > nodo->GetLlave()) {
            nodo->Derecha = insertHelper(nodo->Derecha, NodoNuevo);
        }

        nodo = skew(nodo);
        nodo = split(nodo);
        return nodo;
    }

    NodoBase* EncontrarAux(NodoBase* Raiz, int Llave)
    {
        if (!Raiz) return nullptr;
        if (Raiz->GetLlave() == Llave) return Raiz;

        if (Llave< Raiz->GetLlave())
        {
            return EncontrarAux(Raiz->Izquierda, Llave);
        }
        else
        {
            return EncontrarAux(Raiz->Derecha, Llave);
        }
    }

public:
    ArbolAA() : root(nullptr) {}


    void insert(NodoBase* Nodo) {
        root = insertHelper(root, Nodo);
    }

    NodoBase* Encontrar(int Llave)
    {
        return EncontrarAux(root, Llave);
    }

    void print(NodoBase* temp) {
        if (!temp)
            return;
        print(temp->Izquierda);
        std::cout <<"Valor: "<<temp->GetLlave();
        std::cout<<" Nivel: "<<temp->nivel<< std::endl;
        print(temp->Derecha);
    }
};
