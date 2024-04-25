#include "PasilloABB.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


ArbolABB* CargarPasillo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);

    ArbolABB* raiz = nullptr;

    
    int codigo;
    string nombre;
    while (archivo >> codigo >> nombre) {
        raiz = insertarPasilloABB(raiz, codigo, nombre);
    }

    archivo.close();

    return raiz;
}
ArbolABB* insertarPasilloABB(ArbolABB* raiz, int codigo, const string& nombre) {
    // Si el árbol está vacío, creamos un nuevo nodo y lo devolvemos
    if (raiz == nullptr) {
        return new ArbolABB(codigo, nombre);
    }

    // Verificamos si el código ya está en el árbol
    if (raiz->codigo == codigo) {
        cout << "El código de pasillo '" << codigo << "' ya existe en el registro." << endl;
        return raiz;
    }

    
    if (codigo < raiz->codigo) {
        raiz->left = insertarPasilloABB(raiz->left, codigo, nombre);
    }
    else {
        raiz->right = insertarPasilloABB(raiz->right, codigo, nombre);
    }

    return raiz;
}

bool buscarPasilloABB(ArbolABB* raiz, int codigo) {
    if (raiz == nullptr) {
        return false;
    }

    // Si el código coincide con el código del nodo actual, el pasillo está presente
    if (codigo == raiz->codigo) {
        return true;
    }

    // Si el código es menor que el código del nodo actual, buscamos en el subárbol izquierdo
    if (codigo < raiz->codigo) {
        return buscarPasilloABB(raiz->left, codigo);
    }
    // Si el código es mayor que el código del nodo actual, buscamos en el subárbol derecho
    else {
        return buscarPasilloABB(raiz->right, codigo);
    }
}

void modificarPasilloABB(ArbolABB* raiz, int codigo, const string& nuevoNombre) {
    // Buscamos el pasillo que queremos modificar
    ArbolABB* node = nullptr;
    if (buscarPasilloABB(raiz, codigo)) {
        // Modificamos el nombre del pasillo
        node = raiz;
        while (node != nullptr && node->codigo != codigo) {
            if (codigo < node->codigo) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        if (node != nullptr) {
            node->nombre = nuevoNombre;
            cout << "El nombre del pasillo con código " << codigo << " ha sido modificado a '" << nuevoNombre << "'." << endl;
        }
    } else {
        cout << "El pasillo con código " << codigo << " no fue encontrado." << endl;
    }
}

void imprimirEnOrden(ArbolABB* raiz) {
    if (raiz != nullptr) {
        imprimirEnOrden(raiz->left);
        cout << "Código: " << raiz->codigo << ", Pasillo: " << raiz->nombre << endl;
        imprimirEnOrden(raiz->right);
    }
}
