#include "ArbolB.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void ArbolB::InsertarNodo(NodoBase* nuevoNodo) {
    if (!raiz) {
        raiz = nuevoNodo;
        return;
    }
    InsertarNodo(raiz, nuevoNodo);
}

NodoBase* ArbolB::BuscarNodo(int valor) {
    return BuscarNodo(raiz, valor);
}

NodoBase* ArbolB::BuscarNodo(NodoBase* NodoRaiz, int Llave) {
    if (!NodoRaiz) {
        return nullptr;
    }

    for (int i = 0; i < NodoRaiz->numClaves; ++i) {
        if (Llave == NodoRaiz->claves[i]) {
            return NodoRaiz;
        } else if (Llave < NodoRaiz->claves[i]) {
            
            return BuscarNodo(NodoRaiz->hijos[i], Llave);
        }
    }

    return BuscarNodo(NodoRaiz->hijos[NodoRaiz->numClaves], Llave);
}

void ArbolB::Insertar(NodoBase* NodoRaiz, NodoBase* nuevoNodo) {
    // Recorrer las claves del nodo en busca de la posición de inserción
    int i = NodoRaiz->numClaves - 1;
    if (NodoRaiz->esHoja) {
        // Si es una hoja, simplemente insertar la nueva clave
        while (i >= 0 && nuevoNodo->claves[i] > nuevoNodo->claves[i]) {
            NodoRaiz->claves[i + 1] = NodoRaiz->claves[i];
            i--;
        }
        NodoRaiz->claves[i + 1] = nuevoNodo->claves[i];
        NodoRaiz->numClaves++;
    } else {
        // Si no es una hoja, encontrar el hijo apropiado para insertar
        while (i >= 0 && nuevoNodo->claves[i] < nuevoNodo->claves[i]) {
            i--;
        }
        if (NodoRaiz->hijos[i + 1]->numClaves == 2 * grado - 1) {
            // Si el hijo está lleno, dividirlo antes de insertar
            dividirNodo(NodoRaiz->hijos[i + 1], nuevoNodo->claves[i + 1]);
            if (nuevoNodo->claves[i + 1] > NodoRaiz->claves[i + 1]) {
                i++;
            }
        }
        Insertar(NodoRaiz->hijos[i + 1], nuevoNodo);
    }
}
