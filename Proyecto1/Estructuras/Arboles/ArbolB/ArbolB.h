#pragma once
#include "../../../Estructuras/Nodos/NodoBase.h"

class ArbolB {
public:
    NodoBase* raiz;
    int grado;

    ArbolB(int grado);
    virtual ~ArbolB();

    void InsertarNodo(NodoBase* nodo);
    NodoBase* Buscar(int codigo);
    void Eliminar(int codigo);

    NodoBase* BuscarNodo(NodoBase* NodoRaiz, int Llave);
};
