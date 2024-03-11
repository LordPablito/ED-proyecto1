#include <fstream>
#include <iostream>
#include <string>
#include "Menu.cpp"
#include "Estructuras/ListaSimple/ListaSimple.h"
#include "Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"

static const string DIRECTORIO = "C:/Users/Usuario/Desktop/Proyecto1-20240310T043157Z-001/Proyecto1/Archivos/";

ListaSimple* CargarPasillos(string NombreArchivo)
{
    ifstream Archivo;
    ListaSimple* ListaArchivo = new ListaSimple();
    const string Directorio = DIRECTORIO+NombreArchivo;
    Archivo.open(Directorio);
    for(string Linea; getline(Archivo, Linea);)
    {
        ListaArchivo->InsertarFinal(new NodoPasillo(Linea));
    }
    return ListaArchivo;
}

int main()
{
    Menu();
    ListaSimple* Lista = CargarPasillos("Pasillos.txt");
    Lista->Mostrar();
    std::cout<<std::endl;
    return 0;
}
