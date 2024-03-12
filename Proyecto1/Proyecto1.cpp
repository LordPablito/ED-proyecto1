#include <fstream>
#include <iostream>
#include <string>
#include "Menu.cpp"
#include "Estructuras/ListaDoble/ListaDoble.h"
#include "Estructuras/ListaSimple/ListaSimple.h"
#include "Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "Estructuras/Nodos/NodosDerivados/Producto/NodoProducto.h"

static const string DIRECTORIO = "../Archivos/";

ListaSimple* CargarPasillos(string NombreArchivo)
{
    ifstream Archivo;
    ListaSimple* ListaArchivo = new ListaSimple();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    string Basura;
    getline(Archivo, Basura);
    for(string Linea; getline(Archivo, Linea);)
    {
        ListaArchivo->InsertarFinal(new NodoPasillo(Linea));
    }
    return ListaArchivo;
}

ListaDoble* CargarProductosPasillo(string NombreArchivo)
{
    ifstream Archivo;
    ListaDoble* ListaArchivo = new ListaDoble();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    string Basura;
    getline(Archivo, Basura);
    for(string Linea; getline(Archivo, Linea);)
    {
        ListaArchivo->InsertarFinal(new NodoProducto(Linea));
    }
    return ListaArchivo;
}

ListaDoble* CargarInventario(string NombreArchivo)
{
    ifstream Archivo;
    ListaDoble* ListaArchivo = new ListaDoble();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    string Basura;
    getline(Archivo, Basura);
    for(string Linea; getline(Archivo, Linea);)
    {
        ListaArchivo->InsertarFinal(new NodoProducto(Linea));
    }
    return ListaArchivo;
}

int main()
{
    //Menu();
    ListaSimple* ListaPasillos = CargarPasillos("Pasillos.txt");
    ListaDoble* ListaProds = CargarProductosPasillo("ProductosPasillos.txt");
    
    
    ListaPasillos->Mostrar();
    cout<<endl;
    ListaProds->Mostrar();
    std::cout<<std::endl;
    return 0;
}
