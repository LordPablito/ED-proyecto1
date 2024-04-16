
#ifndef ARBOL_ABB_H
#define ARBOL_ABB_H

#include <string>
#include <unordered_set>

// Definición de la estructura de un nodo del árbol
struct ArbolABB {
    int codigo;
    std::string nombre;
    ArbolABB* left;
    ArbolABB* right;

    // Constructor
    ArbolABB(int cod, const std::string& nom) : codigo(cod), nombre(nom), left(nullptr), right(nullptr) {}
};

// Funciones para el árbol ABB
ArbolABB* CargarPasillo(const string& nombreArchivo);
ArbolABB* insertarPasilloABB(ArbolABB* raiz, int codigo, const std::string& nombre);
bool buscarPasilloABB(ArbolABB* raiz, int codigo);
void modificarPasilloABB(ArbolABB* raiz, int codigo, const std::string& nuevoNombre);
void imprimirEnOrden(ArbolABB* raiz);

#endif // ARBOL_ABB_H
