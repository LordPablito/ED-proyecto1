#include "MenuFunciones.h"

#include "../Estructuras/Nodos/NodosDerivados/Administrador/NodoAdmin.h"
#include "../Estructuras/Nodos/NodosDerivados/Inventario/NodoInventario.h"
#include "../Estructuras/Nodos/NodosDerivados/Marca/NodoMarca.h"
#include "../Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "../Estructuras/Nodos/NodosDerivados/Producto/NodoProducto.h"
#include "../Estructuras/Nodos/NodosDerivados/Ciudad/NodoCiudad.h"
#include "../Estructuras/Nodos/NodosDerivados/Clientes/NodoCliente.h"
#pragma region Login 
bool MenuFunciones::Login()
{
}
#pragma endregion

#pragma region Pasillo
void MenuFunciones::InsertarPasillo(ListaSimple* Lista)
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
    NodoBase* AuxPasilloIns = Lista->EncontrarPorPredicado([&CodPasillo](NodoBase* Nodo)
    {
        if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
        {
            return Pasillo->Codigo == CodPasillo;
        }
        return false;
    });

    if (AuxPasilloIns) return;
    Lista->InsertarFinal(new NodoPasillo(NombrePasillo, CodPasillo));
    Lista->Mostrar();
}

void MenuFunciones::EliminarPasillo(ListaSimple* Lista)
{
    int CodPasillo;
    cout << "Eliminando en la Opción 1." << endl;
    // Código correspondiente a eliminar en la opción 1

    cout<<"Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    NodoBase* AuxPasilloElim = Lista->GetPrimero();
    int IndicePasilloElim = 1;
    while (AuxPasilloElim)
    {
        if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(AuxPasilloElim))
        {
            if (Pasillo->Codigo == CodPasillo)
            {
                Lista->BorrarPosicion(IndicePasilloElim);
                break;
            }
        }
        IndicePasilloElim++;
        AuxPasilloElim = AuxPasilloElim->Siguiente;
    }
    Lista->Mostrar();
}

void MenuFunciones::BuscarPasillo(ListaSimple* Lista)
{
    int CodPasillo;
    cout<<"Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    NodoBase* Nodo = Lista->EncontrarPorPredicado([CodPasillo](NodoBase* Nodo)
    {
        if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
        {
            return Pasillo->Codigo == CodPasillo;
        }
        return false;
    });

    if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
    {
        Pasillo->Mostrar();
        cout<<"Pasillo encontrado"<<endl;
        return;
    }
    cout<<"Pasillo no encontrado"<<endl;
}

void MenuFunciones::ModificarPasillo(ListaSimple* Lista)
{
    int CodPasillo;
    cout<<"Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    NodoBase* Nodo = Lista->EncontrarPorPredicado([CodPasillo](NodoBase* Nodo)
    {
        if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
        {
            return Pasillo->Codigo == CodPasillo;
        }
        return false;
    });

    if (!dynamic_cast<NodoPasillo*>(Nodo))
    {
        cout<<"Pasillo no encontrado"<<endl;
        return;
    }
    NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo);
    Pasillo->Mostrar();

    string Nombre;
    cout<<"Ingrese el nuevo nombre del pasillo: ";
    cin >> Nombre;
    
    Pasillo->Nombre = Nombre;
    Pasillo->Mostrar();
}
#pragma endregion

#pragma region Producto
void MenuFunciones::InsertarProducto(ListaDoble* ListaProds, ListaSimple* ListaPasillo)
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

    NodoBase* AuxPasilloIns = ListaPasillo->EncontrarPorPredicado([&CodPasillo](NodoBase* Nodo)
        {
            if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
            {
                return Pasillo->Codigo == CodPasillo;
            }
            return false;
        });
    
    bool PasilloExiste = AuxPasilloIns!=nullptr;
    if (!PasilloExiste)
    {
        cout<<"Falló la inserción debido a que el pasillo "<<CodPasillo<<" no existe"<<endl;
        return;
    }

    NodoBase* AuxProdIns = ListaProds->EncontrarPorPredicado([CodProd](NodoBase* Nodo)
    {
        if(NodoProducto* Prod = dynamic_cast<NodoProducto*>(Nodo))
        {
            return Prod->Producto == CodProd;
        }
        return false;
    });
    
    bool ProdEsUnico = AuxProdIns==nullptr;
    if (!ProdEsUnico)
    {
        cout<<"Ya existe un producto con el código "<<CodProd<<" no existe"<<endl;
        return;
    }
    
    ListaProds->InsertarFinal(new NodoProducto(CodPasillo, CodProd, NombreProd));
    ListaProds->Mostrar();
}

void MenuFunciones::EliminarProducto(ListaDoble* Lista, ListaDobleCircular* ListaMarcas)
{
    int CodProd;
    cout << "Ingrese el código de producto: ";
    cin >> CodProd;

    NodoBase* AuxProdElim = Lista->GetPrimero();
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
    
    Lista->BorrarPosicion(IndiceProdElim);
    Lista->Mostrar();
}

void MenuFunciones::BuscarProducto(ListaDoble* Lista, ListaSimple* ListaPasillos)
{
    int CodPasillo;
    cout << "Ingrese el código de pasillo en el que buscar: ";
    cin >> CodPasillo;

    NodoBase* NPasillo = ListaPasillos->EncontrarPorPredicado([CodPasillo](NodoBase* Nodo)
    {
        if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
        {
            return Pasillo->Codigo == CodPasillo;
        }
        return false;
    });
    if (!NPasillo)
    {
        cout<<"El pasillo ingresado no existe"<<endl;
        return;
    }
    
    int CodProd;
    cout << "Ingrese el código de producto: ";
    cin >> CodProd;
    NodoBase* NProducto = ListaPasillos->EncontrarPorPredicado([CodProd](NodoBase* Nodo)
    {
        if (NodoProducto* Prod = dynamic_cast<NodoProducto*>(Nodo))
        {
            return Prod->Producto == CodProd;
        }
        return false;
    });
    if (NodoProducto* Prod = dynamic_cast<NodoProducto*>(NProducto))
    {
        Prod->Mostrar();
        cout<<"Se encontró el producto solocitado"<<endl;
        return;
    }
    cout<<"No se encontró el producto solocitado"<<endl;
    return;
}

void MenuFunciones::ModificarProducto(ListaDoble* Lista, ListaSimple* ListaPasillos)
{
    int CodProd;
    cout << "Ingrese el código de producto: ";
    cin >> CodProd;
    NodoBase* NProducto = ListaPasillos->EncontrarPorPredicado([CodProd](NodoBase* Nodo)
    {
        if (NodoProducto* Prod = dynamic_cast<NodoProducto*>(Nodo))
        {
            return Prod->Producto == CodProd;
        }
        return false;
    });

    if (!dynamic_cast<NodoProducto*>(NProducto))
    {
        cout<<"No se encontró el productor con el código "<<CodProd<<endl;
        return;
    }
    NodoProducto* Producto = dynamic_cast<NodoProducto*>(NProducto);
    Producto->Mostrar();
    string Nombre;
    cout<<"Ingrese el nuevo nombre del producto: ";
    cin>>Nombre;

    Producto->Nombre = Nombre;
    Producto->Mostrar();
}
#pragma endregion

#pragma region Inventario
void MenuFunciones::InsertarInventario(ListaDoble* ListaInventario, ListaSimple* ListaPasillos, ListaDoble* ListaProds,
    ListaDobleCircular* ListaMarcas)
{
    string LineaAdmin;
    cout<<"Ingrese la siguiente información separado por ';'"<<endl;
    cout<<"Codigo de pasillo;Codigo de producto;Codigo de marca;Nombre;CantidadGondola;Precio"<<endl;
    cin>>LineaAdmin;
    NodoInventario* InventarioNuevo = new NodoInventario(LineaAdmin);

    bool PasilloExiste = ListaPasillos->EncontrarPorPredicado([InventarioNuevo](NodoBase* Nodo)
    {
        if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
        {
            return Pasillo->Codigo == InventarioNuevo->Pasillo;
        }
        return false;
    })!=nullptr;

    bool ProductoExiste = ListaProds->EncontrarPorPredicado([InventarioNuevo](NodoBase* Nodo)
    {
        if (NodoProducto* Producto = dynamic_cast<NodoProducto*>(Nodo))
        {
            return Producto->Producto == InventarioNuevo->Producto;
        }
        return false;
    })!=nullptr;

    bool MarcaExiste = ListaMarcas->EncontrarPorPredicado([InventarioNuevo](NodoBase* Nodo)
    {
        if (NodoMarca* Marca = dynamic_cast<NodoMarca*>(Nodo))
        {
            return Marca->CodMarca == InventarioNuevo->Marca;
        }
        return false;
    })!=nullptr;

    bool InventarioExiste = ListaInventario->EncontrarPorPredicado([InventarioNuevo](NodoBase* Nodo)
    {
        if (NodoInventario* Inventario = dynamic_cast<NodoInventario*>(Nodo))
        {
            return Inventario->Inventario == InventarioNuevo->Inventario;
        }
        return false;
    })!=nullptr;

    if (PasilloExiste && ProductoExiste && MarcaExiste && !InventarioExiste)
    {
        ListaInventario->InsertarFinal(InventarioNuevo);
        cout<<"Inventario ingresado exitosamente!"<<endl;
        return;
    }
    cout<<"No se pudo insertar el inventario nuevo"<<endl;
}

void MenuFunciones::EliminarInventario(ListaDoble* ListaInventario)
{
    int CodInv;
    cout<<"Ingrese el codigo del inventario a eliminar: "<<endl;
    cin>>CodInv;
    
    NodoBase* Nodo = ListaInventario->EncontrarPorPredicado([CodInv](NodoBase* Nodo)
    {
        if (NodoInventario* Inventario = dynamic_cast<NodoInventario*>(Nodo))
        {
            return Inventario->Inventario == CodInv;
        }
        return false;
    });

    if (!Nodo)
    {
        cout<<"Inventario no encontrado"<<endl;
        return;
    }
    
    int PosEliminar = ListaInventario->ConseguirPosicion(Nodo);

    if (PosEliminar<0)
    {
        cout<<"Inventario no encontrado"<<endl;
        return;
    }
    
    ListaInventario->BorrarPosicion(PosEliminar);
    cout<<"Inventario borrado exitosamente!"<<endl;
}

void MenuFunciones::BuscarInventario(ListaDoble* ListaInventario)
{
    int CodInv;
    cout<<"Ingrese el codigo del inventario a buscar: "<<endl;
    cin>>CodInv;

    NodoBase* Nodo = ListaInventario->EncontrarPorPredicado([CodInv](NodoBase* Nodo)
    {
        if (NodoInventario* Inventario = dynamic_cast<NodoInventario*>(Nodo))
        {
            return Inventario->Inventario == CodInv;
        }
        return false;
    });
    if (NodoInventario* Inventario = dynamic_cast<NodoInventario*>(Nodo))
    {
        Inventario->Mostrar();
        cout<<"Inventario encontrado exitosamente"<<endl;
        return;
    }
    cout<<"Inventario no encontrado"<<endl;
}

void MenuFunciones::ModificarInventario(ListaDoble* ListaInventario)
{
    int CodInv;
    cout<<"Ingrese el codigo del inventario a buscar: "<<endl;
    cin>>CodInv;

    NodoBase* Nodo = ListaInventario->EncontrarPorPredicado([CodInv](NodoBase* Nodo)
    {
        if (NodoInventario* Inventario = dynamic_cast<NodoInventario*>(Nodo))
        {
            return Inventario->Inventario == CodInv;
        }
        return false;
    });
    if (!dynamic_cast<NodoInventario*>(Nodo))
    {
        cout<<"No se encontró el inventarion buscado"<<endl;
        return;
    }
    NodoInventario* InventarioModificado = dynamic_cast<NodoInventario*>(Nodo);
    InventarioModificado->Mostrar();
    string Nombre;
    int CantidadStock;
    int CodigoCanasta;

    cout<<"Ingrese el nuevo nombre del inventario: ";
    cin>>Nombre;
    cout<<"Ingrese la nueva cantidad en stock: ";
    cin>>CantidadStock;
    cout<<"Ingrese el codigo de canasta: ";
    cin>>CodigoCanasta;

    InventarioModificado->Nombre = Nombre;
    InventarioModificado->Cantidad = CantidadStock;
    InventarioModificado->CanastaBasica = CodigoCanasta;
    InventarioModificado->Mostrar();
    cout<<"Inventario actualizado exitosamente"<<endl;
}
#pragma endregion 

#pragma region Administrador
void MenuFunciones::InsertarAdministrador(TablaHash* TablaAdmins, ListaCircular* ListaCiudades)
{
    string LineaAdmin;
    cout<<"Ingrese la siguiente información separado por ';'"<<endl;
    cout<<"Codigo de aministrador, Nombre, Codigo de ciudad, Telefono, Correo"<<endl;
    cin >> LineaAdmin;

    NodoAdmin* Admin = new NodoAdmin(LineaAdmin);
    TablaAdmins->InsertarNodo(Admin, Admin->CodAministrador);
    TablaAdmins->Mostrar();
}

void MenuFunciones::EliminarAdministrador(TablaHash* TablaAdmins, ListaCircular* ListaCiudades)
{
    int CodAdmin;
    cout<<"Ingrese el código del administrador a borrar"<<endl;
    cin>>CodAdmin;

    TablaAdmins->EliminarNodo(CodAdmin, [CodAdmin](NodoBase* Nodo)
    {
        if (NodoAdmin* Admin = dynamic_cast<NodoAdmin*>(Nodo))
        {
            return Admin->CodAministrador == CodAdmin;
        }
        return false;
    });
    TablaAdmins->Mostrar();
}

void MenuFunciones::EncontrarAdministrador(TablaHash* TablaAdmins, ListaCircular* ListaCiudades)
{
    int CodAdmin;
    cout<<"Ingrese el código del administrador a borrar"<<endl;
    cin>>CodAdmin;

    NodoBase* Nodo = TablaAdmins->BuscarNodo(CodAdmin, [CodAdmin](NodoBase* Nodo)
    {
        if (NodoAdmin* Admin = dynamic_cast<NodoAdmin*>(Nodo))
        {
            return Admin->CodAministrador == CodAdmin;
        }
        return false;
    });

    if (NodoAdmin* Admin = dynamic_cast<NodoAdmin*>(Nodo))
    {
        cout<<"Se encontró el administrador: "<<endl;
        Admin->Mostrar();
        return;
    }
    cout<<"No se encontró el administrador solicitado";
    
}

void MenuFunciones::ModificarAdministrador(TablaHash* TablaAdmins, ListaCircular* ListaCiudades)
{
    int CodAdmin;
    cout<<"Ingrese el código del administrador a modificar"<<endl;
    cin>>CodAdmin;
    NodoBase* Nodo = TablaAdmins->BuscarNodo(CodAdmin, [CodAdmin](NodoBase* Nodo)
    {
        if (NodoAdmin* Admin = dynamic_cast<NodoAdmin*>(Nodo))
        {
            return Admin->CodAministrador == CodAdmin;
        }
        return false;
    });
    if (!dynamic_cast<NodoAdmin*>(Nodo))
    {
        cout<<"No se encontró el administrador con el código "<< CodAdmin<<endl;
        return;
    }
    NodoAdmin* Admin = dynamic_cast<NodoAdmin*>(Nodo);
    
    Admin->Mostrar();
    string Nombre;
    int CodCiudad;
    int Telefono;
    string Correo;

    cout<<"Ingrese el nuevo nombre del administrador: ";
    cin>>Nombre;
    cout<<"Ingrese el nuevo codigo de ciudad del administrador: ";
    cin>>CodCiudad;
    cout<<"Ingrese el nuevo telefono del administrador: ";
    cin>>Telefono;
    cout<<"Ingrese el nuevo correo del administrador: ";
    cin>>Correo;
    Admin->Nombre = Nombre;
    Admin->CodCiudad = CodCiudad;
    Admin->Telefono = Telefono;
    Admin->Correo = Correo;
    Admin->Mostrar();
    cout<<"Datos actualizados exitosamente"<<endl;
}
#pragma endregion 

#pragma region Marca
void MenuFunciones::InsertarMarcaProducto(ListaDoble* Lista, ListaSimple* ListaPasillos) {
    int codPasillo, codProducto, codMarca, cantidadGondola;
    double precio;
    string nombre;

    cout << "Ingrese el código de pasillo: ";
    cin >> codPasillo;
    // Verificar si el pasillo existe
    NodoBase* nodoPasillo = ListaPasillos->EncontrarPorPredicado([codPasillo](NodoBase* nodo) {
        if (NodoPasillo* pasillo = dynamic_cast<NodoPasillo*>(nodo)) {
            return pasillo->Codigo == codPasillo;
        }
        return false;
    });
    if (!nodoPasillo) {
        cout << "El pasillo ingresado no existe." << endl;
        return;
    }

    cout << "Ingrese el código de producto: ";
    cin >> codProducto;

    cout << "Ingrese el código de marca: ";
    cin >> codMarca;

    // Verificar si el código de marca ya existe
    NodoBase* nodoMarca = Lista->EncontrarPorPredicado([codMarca](NodoBase* nodo) {
        if (NodoMarca* marca = dynamic_cast<NodoMarca*>(nodo)) {
            return marca->CodMarca == codMarca;
        }
        return false;
    });
    if (nodoMarca) {
        cout << "El código de marca ya está en uso." << endl;
        return;
    }

    cout << "Ingrese el nombre de la marca: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese la cantidad en la góndola: ";
    cin >> cantidadGondola;

    cout << "Ingrese el precio: ";
    cin >> precio;

    Lista->InsertarFinal(new NodoMarca(codPasillo, codProducto, codMarca, nombre, cantidadGondola, precio));
    cout << "Marca de producto insertada correctamente." << endl;
}
void MenuFunciones::EliminarMarcaProducto(ListaDoble* Lista) {
    //Lista->EliminarTodo();
    cout << "Todas las marcas de productos han sido eliminadas." << endl;
}
void MenuFunciones::EncontrarMarcaProducto(ListaDoble* Lista) {
    int codPasillo, codProducto, codMarca;
    cout << "Ingrese el código de pasillo: ";
    cin >> codPasillo;
    cout << "Ingrese el código de producto: ";
    cin >> codProducto;
    cout << "Ingrese el código de marca: ";
    cin >> codMarca;

    NodoBase* nodoMarca = Lista->EncontrarPorPredicado([codPasillo, codProducto, codMarca](NodoBase* nodo) {
        if (NodoMarca* marca = dynamic_cast<NodoMarca*>(nodo)) {
            return marca->CodPasillo == codPasillo && marca->CodProducto == codProducto && marca->CodMarca == codMarca;
        }
        return false;
    });

    if (nodoMarca) {
        NodoMarca* marca = dynamic_cast<NodoMarca*>(nodoMarca);
        cout << "Marca de producto encontrada:" << endl;
        marca->Mostrar();
    } else {
        cout << "No se encontró la marca de producto." << endl;
    }
}
void MenuFunciones::ModificarMarcaProducto(ListaDoble* Lista) {
    int codPasillo, codProducto, codMarca;
    cout << "Ingrese el código de pasillo: ";
    cin >> codPasillo;
    cout << "Ingrese el código de producto: ";
    cin >> codProducto;
    cout << "Ingrese el código de marca: ";
    cin >> codMarca;

    NodoBase* nodoMarca = Lista->EncontrarPorPredicado([codPasillo, codProducto, codMarca](NodoBase* nodo) {
        if (NodoMarca* marca = dynamic_cast<NodoMarca*>(nodo)) {
            return marca->CodPasillo == codPasillo && marca->CodProducto == codProducto && marca->CodMarca == codMarca;
        }
        return false;
    });

    if (!nodoMarca) {
        cout << "No se encontró la marca de producto." << endl;
        return;
    }

    NodoMarca* marca = dynamic_cast<NodoMarca*>(nodoMarca);
    marca->Mostrar();

    string nombre;
    int cantidad;
    double precio;

    cout << "Ingrese el nuevo nombre de la marca: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese la nueva cantidad en la góndola: ";
    cin >> cantidad;

    cout << "Ingrese el nuevo precio: ";
    cin >> precio;

    marca->Nombre = nombre;
    marca->CantidadGondola = cantidad;
    marca->Precio = precio;

    cout << "Marca de producto modificada:" << endl;
    marca->Mostrar();
}

#pragma endregion

#pragma region Ciudades
void MenuFunciones:: InsertarCiudad(ListaCircular* ListaCiudades)
    {
    cout << "-----Ingresando ciudad-----";
    int CodCiudad;
    string nombre ;
    
    cout << "Digite codigo de la ciudad: ";
    cin >> CodCiudad;

    cout << "Ingrese el nombre de la ciudad: ";
    cin.ignore();
    getline(cin, nombre);

    NodoBase* auxCiudad = ListaCiudades->EncontrarPorPredicado([&CodCiudad](NodoBase* nodo) {
        if (NodoCiudad* ciudad = dynamic_cast<NodoCiudad*>(nodo)) {
            return ciudad->CodCiudad == CodCiudad;
        }
        return false;
    });

    if (auxCiudad) {
        cout << "La ciudad ya existe en la lista." << endl;
        return;
    }

    ListaCiudades->InsertarFinal(new NodoCiudad(CodCiudad, nombre));
    ListaCiudades->Mostrar();
}
void MenuFunciones:: EliminarCiudad(ListaCircular* ListaCiudades)
    {
        int CodCiudad;
        cout << "-----Eliminando Ciuad-----" << endl;
        cout << "Ingrese el codigo de la ciuada a eliminar: ";
        cin >> CodCiudad;

        NodoBase* auxCiudad = ListaCiudades->EncontrarPorPredicado([&CodCiudad](NodoBase* nodo)
        {
            if (NodoCiudad* ciudad = dynamic_cast<NodoCiudad*>(nodo))
            {
                return ciudad->CodCiudad == CodCiudad;
            }
            return false;
        });

        if (!auxCiudad)
        {
            cout << "La ciudad no existe en la lista." << endl;
            return;
        }

        ListaCiudades->BorrarPosicion(ListaCiudades->ConseguirPosicion(auxCiudad));
        //ListaCiudades->InsertarFinal(new NodoCiudad(CodCiudad, nombre));
        ListaCiudades->Mostrar();
     
    }
void MenuFunciones::EncontrarCiudad(ListaCircular* ListaCiudades) {
    int codCiudad;
    cout << "Ingrese el código de ciudad a buscar: ";
    cin >> codCiudad;

    NodoBase* nodoCiudad = ListaCiudades->EncontrarPorPredicado([codCiudad](NodoBase* nodo) {
        if (NodoCiudad* ciudad = dynamic_cast<NodoCiudad*>(nodo)) {
            return ciudad->CodCiudad == codCiudad;
        }
        return false;
    });

    if (nodoCiudad) {
        NodoCiudad* ciudad = dynamic_cast<NodoCiudad*>(nodoCiudad);
        cout << "Ciudad encontrada:" << endl;
        ciudad->Mostrar();
    } else {
        cout << "No se encontró la ciudad con el código " << codCiudad << endl;
    }
}
void MenuFunciones::ModificarCiudad(ListaCircular* ListaCiudades) {
    int codCiudad;
    cout << "Ingrese el código de ciudad a modificar: ";
    cin >> codCiudad;

    NodoBase* nodoCiudad = ListaCiudades->EncontrarPorPredicado([codCiudad](NodoBase* nodo) {
        if (NodoCiudad* ciudad = dynamic_cast<NodoCiudad*>(nodo)) {
            return ciudad->CodCiudad == codCiudad;
        }
        return false;
    });

    if (!nodoCiudad) {
        cout << "No se encontró la ciudad con el código " << codCiudad << endl;
        return;
    }

    NodoCiudad* ciudad = dynamic_cast<NodoCiudad*>(nodoCiudad);
    ciudad->Mostrar();

    string nombre;
    cout << "Ingrese el nuevo nombre de la ciudad: ";
    cin.ignore(); // Limpiar el buffer del teclado antes de leer el nombre
    getline(cin, nombre);

    ciudad->Nombre = nombre;
    cout << "Ciudad modificada:" << endl;
    ciudad->Mostrar();
}

#pragma endregion

#pragma region Clientes
#pragma endregion 