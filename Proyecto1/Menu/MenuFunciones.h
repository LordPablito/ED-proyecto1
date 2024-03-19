#pragma once
#include "../Estructuras/ListaCircular/ListaCircular.h"
#include "../Estructuras/ListaDoble/ListaDoble.h"
#include "../Estructuras/ListaDobleCircular/ListaDobleCircular.h"
#include "../Estructuras/ListaSimple/ListaSimple.h"
#include "../Estructuras/TablaHash/TablaHash.h"

class MenuFunciones
{
public:

#pragma region Pasillo
    static void InsertarPasillo(ListaSimple* Lista);
    static void EliminarPasillo(ListaSimple* Lista);
    static void BuscarPasillo(ListaSimple* Lista);
    static void ModificarPasillo(ListaSimple* Lista);
#pragma endregion

#pragma region Producto
    static void InsertarProducto(ListaDoble* Lista, ListaSimple* ListaPasillo);
    static void EliminarProducto(ListaDoble* Lista, ListaDobleCircular* ListaMarcas);
    static void BuscarProducto(ListaDoble* Lista, ListaSimple* ListaPasillos);
    static void ModificarProducto(ListaDoble* Lista, ListaSimple* ListaPasillos);
#pragma endregion

#pragma region Inventario
    static void InsertarInventario(ListaDoble* ListaInventario, ListaSimple* ListaPasillos, ListaDoble* ListaProds,
                                   ListaDobleCircular* ListaMarcas);
    static void EliminarInventario(ListaDoble* ListaInventario);
    static void BuscarInventario(ListaDoble* ListaInventario);
    static void ModificarInventario(ListaDoble* ListaInventario);
#pragma endregion
    
#pragma region Administrador
    static void InsertarAdministrador(TablaHash* TablaAdmins, ListaCircular* ListaCiudades);
    static void EliminarAdministrador(TablaHash* TablaAdmins, ListaCircular* ListaCiudades);
    static void EncontrarAdministrador(TablaHash* TablaAdmins, ListaCircular* ListaCiudades);
    static void ModificarAdministrador(TablaHash* TablaAdmins, ListaCircular* ListaCiudades);
#pragma endregion 

#pragma region Marca
    static void InsertarMarcaProducto(ListaDoble* Lista, ListaSimple* ListaPasillos);
    static void EliminarMarcaProducto(ListaDoble* Lista);
    static void EncontrarMarcaProducto(ListaDoble* Lista);
    static void ModificarMarcaProducto(ListaDoble* Lista);
#pragma endregion

#pragma region Ciudades
    static void InsertarCiudad(ListaCircular* ListaCiudades);
    static void EliminarCiudad(ListaCircular* ListaCiudades);
    static void EncontrarCiudad(ListaCircular* ListaCiudades);
    static void ModificarCiudad(ListaCircular* ListaCiudades);
#pragma endregion

#pragma region Clientes
    static void InsertarClientes(TablaHash* TablaAdmins, ListaCircular* ListaCiudades);
    static void EliminarClientes(TablaHash* TablaAdmins, ListaCircular* ListaCiudades);
    static void EncontrarClientes(TablaHash* TablaAdmins, ListaCircular* ListaCiudades);
    static void ModificarClientes(TablaHash* TablaAdmins, ListaCircular* ListaCiudades);
#pragma endregion 
};
