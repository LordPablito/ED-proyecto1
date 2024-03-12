#include <fstream>
#include <iostream>
#include <string>

//#include "Menu.cpp"
#include "Estructuras/ListaDoble/ListaDoble.h"
#include "Estructuras/ListaSimple/ListaSimple.h"
#include "Estructuras/ListaDoble/ListaDobleCircular.h"
#include "Estructuras/ListaSimple/ListaCircular.h"
#include "Estructuras/Nodos/NodosDerivados/Inventario/NodoInventario.h"
#include "Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "Estructuras/Nodos/NodosDerivados/Producto/NodoProducto.h"
#include "Estructuras/Nodos/NodosDerivados/Marca/NodoMarca.h"
#include "Estructuras/Nodos/NodosDerivados/Ciudad/NodoCiudad.h"

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
    ListaDobleCircular* ListaArchivo = new ListaDobleCircular();
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
int main()
{
    ListaSimple* ListaPasillos = CargarPasillos("Pasillos.txt");
    ListaDoble* ListaProds = CargarProductosPasillo("ProductosPasillos.txt");
    ListaDoble* ListaInventario = CargarInventario("Inventario.txt");
    ListaDobleCircular* ListaMarcas = CargarMarcaProductos("MarcasProductos.txt");
    ListaCircular* ListaCiudades = CargarCiudad("Ciudades.txt");
    ListaPasillos->Mostrar();
    cout<<endl;
    ListaProds->Mostrar();
    cout<<endl;
    ListaInventario->Mostrar();
    cout<< endl;
    ListaMarcas->Mostrar();
    cout<<endl;
    ListaCiudades->Mostrar();
    cout<<endl;
    std::cout<<std::endl;

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

        // Realizar acciones según la opción seleccionada
        switch (opcion) {
            case 1:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Pasillo:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "0. Atras" << endl;

                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    
                    switch (subopcion1) {
                        case 1:
                            {
                                cout << "Insertando en la Opción 1." << endl;
                                // Código correspondiente a insertar en la opción 1
                                int CodPasillo;
                                string NombrePasillo;
                        
                                cout<<"Ingrese el código de pasillo: ";
                                cin >> CodPasillo;

                                cout<<"Ingrese el nombre de pasillo: ";
                                cin >> NombrePasillo;

                                //Check repeticion
                                NodoBase* AuxPasilloIns = ListaPasillos->GetPrimero();
                                while (AuxPasilloIns)
                                {
                                    if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(AuxPasilloIns))
                                    {
                                        if (Pasillo->Codigo == CodPasillo)
                                        {
                                            break;
                                        }
                                    }
                                    AuxPasilloIns = AuxPasilloIns->Siguiente;
                                }
                                ListaPasillos->InsertarFinal(new NodoPasillo(NombrePasillo, CodPasillo));
                                break;
                            }
                        case 2:
                            {
                                int CodPasillo;
                                cout << "Eliminando en la Opción 1." << endl;
                                // Código correspondiente a eliminar en la opción 1

                                cout<<"Ingrese el código de pasillo: ";
                                cin >> CodPasillo;

                                NodoBase* AuxPasilloElim = ListaPasillos->GetPrimero();
                                int IndicePasilloElim = 1;
                                while (AuxPasilloElim)
                                {
                                    if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(AuxPasilloElim))
                                    {
                                        if (Pasillo->Codigo == CodPasillo)
                                        {
                                            ListaPasillos->borrarPosicion(IndicePasilloElim);
                                            break;
                                        }
                                    }
                                    IndicePasilloElim++;
                                    AuxPasilloElim = AuxPasilloElim->Siguiente;
                                }
                                break;
                            }
                            
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
                    // Mostrar submenú para la opción 1
                    cout << "Producto:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    
                switch (subopcion1) {
                    case 1:
                        {
                            cout << "Insertando en la Opción 1." << endl;
                        // Código correspondiente a insertar en la opción 1
                        int CodPasillo;
                        int CodProd;
                        string NombreProd;

                        cout << "Ingrese el código de pasillo: ";
                        cin >> CodPasillo;

                        cout << "Ingrese el código de producto: ";
                        cin >> CodProd;

                        cout << "Ingrese el nombre de producto: ";
                        cin >> NombreProd;

                        NodoBase* AuxProdPasilloIns = ListaPasillos->GetPrimero();

                        bool PasilloExiste = false;
                        while (AuxProdPasilloIns)
                        {
                            if (NodoPasillo* Pasillo= dynamic_cast<NodoPasillo*>(AuxProdPasilloIns))
                            {
                                if (Pasillo->Codigo == CodPasillo)
                                {
                                    PasilloExiste = true;
                                }
                            }
                            AuxProdPasilloIns = AuxProdPasilloIns->Siguiente;
                        }
                        if (!PasilloExiste) break;
                    
                        NodoBase* AuxProdIns = ListaProds->GetPrimero();
                        bool ProdEsUnico = true;
                        while (AuxProdIns)
                        {
                            if (NodoProducto* Producto= dynamic_cast<NodoProducto*>(AuxProdIns))
                            {
                                if (Producto->Producto == CodProd)
                                {
                                    ProdEsUnico = false;    
                                }
                                
                            }
                            AuxProdIns = AuxProdIns->Siguiente;
                        }
                        if (!ProdEsUnico) break;

                        ListaProds->InsertarFinal(new NodoProducto(CodPasillo, CodProd, NombreProd));
                        break;
                        }
                        
                    case 2:
                        {
                            int CodProd;
                            cout << "Eliminando en la Opción 1." << endl;
                            // Código correspondiente a eliminar en la opción 1

                            cout << "Ingrese el código de producto: ";
                            cin >> CodProd;

                            NodoBase* AuxProdElim = ListaProds->GetPrimero();
                            int IndiceProdElim = 1;
                            while (AuxProdElim)
                            {
                                if (NodoProducto* Prod = dynamic_cast<NodoProducto*>(AuxProdElim))
                                {
                                    if (Prod->Producto == CodProd)
                                    {
                                        break;
                                    }
                                }
                                IndiceProdElim++;
                                AuxProdElim = AuxProdElim->Siguiente;
                            }
                            ListaProds->BorrarPosicion(IndiceProdElim);
                            break;
                        }
                        
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
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    
                switch (subopcion1) {
                    case 1:
                        cout << "Insertando en la Opción 1." << endl;
                        // Código correspondiente a insertar en la opción 1
                        break;
                    case 2:
                        cout << "Eliminando en la Opción 1." << endl;
                        // Código correspondiente a eliminar en la opción 1
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
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    
                switch (subopcion1) {
                    case 1:
                        cout << "Insertando en la Opción 1." << endl;
                        // Código correspondiente a insertar en la opción 1
                        break;
                    case 2:
                        cout << "Eliminando en la Opción 1." << endl;
                        // Código correspondiente a eliminar en la opción 1
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
                    
                switch (subopcion1) {
                    case 1:
                        cout << "Insertando en la Opción 1." << endl;
                        // Código correspondiente a insertar en la opción 1
                        break;
                    case 2:
                        cout << "Eliminando en la Opción 1." << endl;
                        // Código correspondiente a eliminar en la opción 1
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
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    
                switch (subopcion1) {
                    case 1:
                        cout << "Insertando en la Opción 1." << endl;
                        // Código correspondiente a insertar en la opción 1
                        break;
                    case 2:
                        cout << "Eliminando en la Opción 1." << endl;
                        // Código correspondiente a eliminar en la opción 1
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
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    
                switch (subopcion1) {
                    case 1:
                        cout << "Insertando en la Opción 1." << endl;
                        // Código correspondiente a insertar en la opción 1
                        break;
                    case 2:
                        cout << "Eliminando en la Opción 1." << endl;
                        // Código correspondiente a eliminar en la opción 1
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
    } while (opcion != 8);

    return 0;
    
    //Menu();
    return 0;
}