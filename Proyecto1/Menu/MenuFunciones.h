#pragma once
#include "../Estructuras/ListaDoble/ListaDoble.h"
#include "../Estructuras/ListaDobleCircular/ListaDobleCircular.h"
#include "../Estructuras/ListaSimple/ListaSimple.h"

class MenuFunciones
{
public:

#pragma region Pasillo
    static void InsertarPasillo(ListaSimple* Lista);
    static void EliminarPasillo(ListaSimple* Lista);
#pragma endregion

#pragma region Producto
    static void InsertarProducto(ListaDoble* Lista, ListaSimple* ListaPasillo);
    static void EliminarProducto(ListaDoble* Lista, ListaDobleCircular* ListaMarcas);
#pragma endregion

    
};
