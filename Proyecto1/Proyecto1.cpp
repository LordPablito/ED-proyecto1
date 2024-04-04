#include <fstream>
#include <iostream>
#include <string>

#include "BibliotecaReportes/BibliotecaReportes.h"
#include "Estructuras/ListaDoble/ListaDoble.h"
#include "Estructuras/ListaSimple/ListaSimple.h"
#include "Estructuras/ListaDobleCircular/ListaDobleCircular.h"
#include "Estructuras/ListaCircular/ListaCircular.h"
#include "Estructuras/Nodos/NodosDerivados/Administrador/NodoAdmin.h"
#include "Estructuras/Nodos/NodosDerivados/Inventario/NodoInventario.h"
#include "Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "Estructuras/Nodos/NodosDerivados/Producto/NodoProducto.h"
#include "Estructuras/Nodos/NodosDerivados/Marca/NodoMarca.h"
#include "Estructuras/Nodos/NodosDerivados/Ciudad/NodoCiudad.h"
#include "Estructuras/TablaHash/TablaHash.h"
#include "Menu/MenuFunciones.h"

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
        if (Linea.empty()) continue;
        ListaArchivo->InsertarFinal(new NodoInventario(Linea));
    }
    return ListaArchivo;
}
ListaDobleCircular* CargarMarcaProductos(string NombreArchivo){
    ifstream Archivo;
    ListaDobleCircular* ListaArchivo = new ListaDobleCircular();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    string Basura;
    getline(Archivo, Basura);
    for(string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        ListaArchivo->InsertarFinal(new NodoMarca(Linea));
    }
    return ListaArchivo;
}
ListaCircular* CargarCiudad(string NombreArchivo){
    ifstream Archivo;
    ListaCircular* ListaArchivo = new ListaCircular();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    string Basura;
    getline(Archivo, Basura);
    for(string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        ListaArchivo->InsertarFinal(new NodoCiudad(Linea));
    }
    return ListaArchivo;
}
TablaHash* CargarAdmins(string NombreArchivo)
{
    ifstream Archivo;
    TablaHash* ListaArchivo = new TablaHash();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    for(string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        NodoAdmin* NuevoNodo = new NodoAdmin(Linea);
        ListaArchivo->InsertarNodo(NuevoNodo, NuevoNodo->CodAministrador);
    }
    return ListaArchivo;
}

int main()
{
    ListaSimple* ListaPasillos = CargarPasillos("Pasillos.txt");
    ListaDoble* ListaProds = CargarProductosPasillo("ProductosPasillos.txt");
    ListaDoble* ListaInventario = CargarInventario("Inventario.txt");
    ListaDobleCircular* ListaMarcas = CargarMarcaProductos("MarcasProductos.txt");
    ListaCircular* ListaCiudades = CargarCiudad("Ciudades.txt");
    TablaHash* TablaAdmins = CargarAdmins("Administradores.txt");
    TablaHash* TablaClientes = new TablaHash();
    ListaPasillos->Mostrar();

    bool EsAdmin = MenuFunciones::Login(TablaAdmins, TablaClientes);
    
    cout<<endl;
    ListaProds->Mostrar();
    cout<<endl;
    ListaInventario->Mostrar();
    cout<< endl;
    ListaMarcas->Mostrar();
    cout<<endl;
    ListaCiudades->Mostrar();
    cout<<endl;
    TablaAdmins->Mostrar();
    cout<<endl;

    BibliotecaReportes::ReportarPasillos(ListaPasillos);
    BibliotecaReportes::ReportarProductosPasillo(ListaProds);
    BibliotecaReportes::ReportarAdministradores(TablaAdmins);
    
    int opcion, subopcion1;

    do {
        // Mostrar el menú principal
        cout << "Menu:" << endl;
        cout << "1. Pasillo" << endl;
        cout << "2. Producto" << endl;
        cout << "3. Marca" << endl;
        cout << "4. Inventario" << endl;
        cout << "5. Clientes" << endl;
        cout << "6. Administrador" << endl;
        cout << "7. Ciudad" << endl;
        cout << "8. Salir" << endl;
        // Solicitar al usuario que ingrese una opción
        cout << "Ingrese el numero de opcion: ";
        cin >> opcion;
        system("CLS");

        // Realizar acciones según la opción seleccionada
        switch (opcion) {
            case 1:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Pasillo:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "3. Buscar" << endl;
                    cout << "4. Modificar" << endl;
                    cout << "0. Atras" << endl;

                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                        case 1:
                            MenuFunciones::InsertarPasillo(ListaPasillos);
                            break;
                        case 2:
                            MenuFunciones::EliminarPasillo(ListaPasillos);
                            break;
                        case 3:
                            MenuFunciones::BuscarPasillo(ListaPasillos);
                            break;
                        case 4:
                            MenuFunciones::ModificarPasillo(ListaPasillos);
                            break;
                        case 0:
                            cout << "Volviendo al menu principal..." << endl;
                            break;
                        default:
                            cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                            break;
                    }
                } while (subopcion1 != 0);
                break;
            case 2:
                do {
                    cout << "Producto:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "3. Buscar" << endl;
                    cout << "4. Modificar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");

                    switch (subopcion1)
                    {
                    case 1:
                        MenuFunciones::InsertarProducto(ListaProds, ListaPasillos);
                        break;
                    case 2:
                        MenuFunciones::EliminarProducto(ListaProds, ListaMarcas);
                        break;
                    case 3:
                        MenuFunciones::BuscarProducto(ListaProds, ListaPasillos);
                        break;
                    case 4:
                        MenuFunciones::ModificarProducto(ListaProds, ListaPasillos);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                        break;
                }
            } while (subopcion1 != 0);
            break;
            case 3:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Marca:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "3. Buscar" << endl;
                    cout << "4. Modificar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                switch (subopcion1) {
                    case 1:
                        MenuFunciones::InsertarMarcaProducto(ListaMarcas, ListaPasillos);
                        break;
                    case 2:
                        MenuFunciones::EliminarMarcaProducto(ListaMarcas);
                        break;
                    case 3:
                        MenuFunciones::EncontrarMarcaProducto(ListaMarcas);
                        break;
                    case 4:
                        MenuFunciones::ModificarMarcaProducto(ListaMarcas);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                    
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                        break;
                }
            } while (subopcion1 != 0);
            break;
            case 4:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Inventario:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "3. Buscar" << endl;
                    cout << "3. Modificar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                switch (subopcion1) {
                    case 1:
                        MenuFunciones::InsertarInventario(ListaInventario, ListaPasillos, ListaProds, ListaMarcas);
                        break;
                    case 2:
                        MenuFunciones::EliminarInventario(ListaInventario);
                        break;
                    case 3:
                        MenuFunciones::BuscarInventario(ListaInventario);
                        break;
                    case 4:
                        MenuFunciones::ModificarInventario(ListaInventario);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                        break;
                }
            } while (subopcion1 != 0);
            break;
            case 5:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Cliente:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                switch (subopcion1) {
                    case 1:
                        MenuFunciones::InsertarClientes(TablaClientes, ListaCiudades, 0);
                        break;
                    case 2:
                        MenuFunciones::EliminarClientes(TablaClientes, ListaCiudades);
                        break;
                    case 3:
                        MenuFunciones::EncontrarClientes(TablaClientes, ListaCiudades);
                        break;
                    case 4:
                        MenuFunciones::ModificarClientes(TablaClientes, ListaCiudades);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                        break;
                }
            } while (subopcion1 != 0);
            break;
            case 6:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Administrador:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "3. Buscar" << endl;
                    cout << "4. Modificar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                switch (subopcion1) {
                    case 1:
                        MenuFunciones::InsertarAdministrador(TablaAdmins, ListaCiudades);
                        break;
                    case 2:
                        MenuFunciones::EliminarAdministrador(TablaAdmins, ListaCiudades);
                        break;
                    case 3:
                        MenuFunciones::EncontrarAdministrador(TablaAdmins, ListaCiudades);
                        break;
                    case 4:
                        MenuFunciones::ModificarAdministrador(TablaAdmins, ListaCiudades);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                        break;
                }
            } while (subopcion1 != 0);
            break;
            case 7:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Ciudad:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "3. Buscar" << endl;
                    cout << "4. Modificar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                switch (subopcion1) {
                    case 1:
                        MenuFunciones:: InsertarCiudad(ListaCiudades);
                        break;
                    case 2:
                        MenuFunciones:: EliminarCiudad(ListaCiudades);
                        break;
                    case 3:
                        MenuFunciones::EncontrarCiudad(ListaCiudades);
                        break;
                    case 4:
                        MenuFunciones::ModificarCiudad(ListaCiudades);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                        break;
                }
            } while (subopcion1 != 0);
            break;
             case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor ingresa un número del 1 al 7." << endl;
                break;
        }
        system("CLS");
    } while (opcion != 8);

    return 0;
    
    //Menu();
    return 0;
}