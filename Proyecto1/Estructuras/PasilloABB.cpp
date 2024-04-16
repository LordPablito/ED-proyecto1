#include <iostream>
#include <string>
#include <unordered_set> // Para mantener un conjunto de códigos de pasillo únicos

using namespace std;

// Definición de la estructura de un nodo del árbol
struct ArbolABB {
    int codigo;
    string nombre;
    ArbolABB* left;
    ArbolABB* right;

    // Constructor
    ArbolABB(int cod, const string& nom) : codigo(cod), nombre(nom), left(nullptr), right(nullptr) {}
};

ArbolABB* insertarPasillo(ArbolABB* raiz, int codigo, const string& nombre) {
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
        raiz->left = insertarPasillo(raiz->left, codigo, nombre);
    }
    else {
        raiz->right = insertarPasillo(raiz->right, codigo, nombre);
    }

    return raiz;
}


bool buscarPasillo(ArbolABB* raiz, int codigo) {
    if (raiz == nullptr) {
        return false;
    }

    // Si el código coincide con el código del nodo actual, el pasillo está presente
    if (codigo == raiz->codigo) {
        return true;
    }

    // Si el código es menor que el código del nodo actual, buscamos en el subárbol izquierdo
    if (codigo < raiz->codigo) {
        return buscarPasillo(raiz->left, codigo);
    }
    // Si el código es mayor que el código del nodo actual, buscamos en el subárbol derecho
    else {
        return buscarPasillo(raiz->right, codigo);
    }
}

// Función para modificarPasillo un pasillo en el árbol
void modificarPasillo(ArbolABB* raiz, int codigo, const string& nuevoNombre) {
    // Buscamos el pasillo que queremos modificarPasillo
    ArbolABB* node = nullptr;
    if (buscarPasillo(raiz, codigo)) {
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
// Función para imprimir el árbol en orden (recorrido inorden)
void imprimirEnOrden(ArbolABB* raiz) {
    if (raiz != nullptr) {
        imprimirEnOrden(raiz->left);
        cout << "Código: " << raiz->codigo << ", Pasillo: " << raiz->nombre << endl;
        imprimirEnOrden(raiz->right);
    }
}


int main() {
    ArbolABB* raiz = nullptr;
    unordered_set<int> codigos; // Conjunto para mantener un registro de los códigos de pasillo

    // Simulamos la carga de datos desde un archivo (reemplazar con la lógica real de lectura de archivo)
    // Aquí se agregarían las líneas de código para leer y procesar el archivo Pasillo.txt
    // Supondremos que los datos se cargan directamente como ejemplo

    // Datos de ejemplo
    // Cargamos algunos pasillos en el árbol
    raiz = insertarPasillo(raiz, 101, "Electrodomésticos");
    codigos.insert(101);
    raiz = insertarPasillo(raiz, 202, "Electrónica");
    codigos.insert(202);
    raiz = insertarPasillo(raiz, 303, "Ropa");
    codigos.insert(303);
    raiz = insertarPasillo(raiz, 404, "Juguetes");
    codigos.insert(404);

    // Intentamos insertarPasillo un pasillo duplicado
    raiz = insertarPasillo(raiz, 303, "Ropa");

    // Verificamos si un pasillo está presente en el árbol
    int codigoABuscar = 303;
    if (buscarPasillo(raiz, codigoABuscar)) {
        cout << "El pasillo con código " << codigoABuscar << " está en el registro. " << endl;
    } else {
        cout << "El pasillo con código " << codigoABuscar << " no existe. " << endl;
    }

    // Modificamos un pasillo
    int codigoAModificar = 404;
    string nuevoNombre = "Juguetes para niños";
    modificarPasillo(raiz, codigoAModificar, nuevoNombre);

    // Imprimimos el árbol en orden
    cout << "Árbol en orden: " << endl;
    imprimirEnOrden(raiz);

    return 0;
}
