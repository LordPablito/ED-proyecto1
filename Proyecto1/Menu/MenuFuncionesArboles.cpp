#include "MenuFunciones.h"
#include "../Estructuras/Nodos/NodosDerivados/Administrador/NodoAdmin.h"
#include "../Estructuras/Nodos/NodosDerivados/Inventario/NodoInventario.h"
#include "../Estructuras/Nodos/NodosDerivados/Marca/NodoMarca.h"
#include "../Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "../Estructuras/Nodos/NodosDerivados/Producto/NodoProducto.h"
#include "../Estructuras/Nodos/NodosDerivados/Ciudad/NodoCiudad.h"
#include "../Estructuras/Nodos/NodosDerivados/Clientes/NodoCliente.h"

#pragma region Pasillos
void MenuFunciones::InsertarPasilloABB(ArbolBinario* Arbol)
{
    int CodPasillo;
    string NombreProd;

    cout << "Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    cout << "Ingrese el nombre de pasillo: ";
    cin >> NombreProd;

    NodoPasillo* NuevoNodo = new NodoPasillo(NombreProd, CodPasillo);
    Arbol->InsertarNodo(NuevoNodo);

    cout << "Insertado exitosamente!";
}

void MenuFunciones::BuscarPasilloABB(ArbolBinario* Arbol)
{
    int CodPasillo;
    
    cout << "Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    NodoBase* NodoEncontrado = Arbol->BuscarNodo(Arbol->Raiz, CodPasillo);

    if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(NodoEncontrado))
    {
        cout<<"Nodo encontrado!";
        Pasillo->Mostrar();
        return;
    }
    cout<<"Nodo no encontrado!";
}

void MenuFunciones::ModificarPasilloABB(ArbolBinario* Arbol)
{
    int CodPasillo;
    
    cout << "Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    NodoBase* NodoEncontrado = Arbol->BuscarNodo(Arbol->Raiz, CodPasillo);

    if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(NodoEncontrado))
    {
        cout<<"Nodo encontrado!";
        Pasillo->Mostrar();

        string Nombre;
        cout<<"Ingrese el nuevo nombre del pasillo: ";
        cin>>Nombre;

        Pasillo->Nombre = Nombre;
        Pasillo->Mostrar();
        cout<<"Actualizado correctamente"<<endl;
        return;
    }
    cout<<"Nodo no encontrado!";
}

#pragma endregion 

#pragma region Productos
void MenuFunciones::InsertarProductoAVL(ArbolAVL* Arbol)
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

    NodoProducto* Prod = new NodoProducto(CodPasillo, CodProd, NombreProd);
    Arbol->InsertarNodo(Arbol->Raiz, false, Prod);
    cout << "Insertado exitosamente!";
}

void MenuFunciones::BuscarProductoAVL(ArbolAVL* Arbol)
{
    string CodPasillo;
    string CodProd;
    
    cout << "Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    cout << "Ingrese el código de producto: ";
    cin >> CodProd;

    NodoBase* Nodo = Arbol->BuscarNodo(Arbol->Raiz, stoi(CodPasillo + CodProd));

    if (NodoProducto* NodoProd = dynamic_cast<NodoProducto*>(Nodo))
    {
        NodoProd->Mostrar();
        cout << "Elemento encontrado!";
    }
}

void MenuFunciones::ModificarProductoAVL(ArbolAVL* Arbol)
{
    string CodPasillo;
    string CodProd;
    
    cout << "Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    cout << "Ingrese el código de producto: ";
    cin >> CodProd;

    NodoBase* Nodo = Arbol->BuscarNodo(Arbol->Raiz, stoi(CodPasillo + CodProd));

    if (NodoProducto* NodoProd = dynamic_cast<NodoProducto*>(Nodo))
    {
        NodoProd->Mostrar();
        cout << "Elemento encontrado!";
        
        string Nombre;
        cout << "Ingrese el nuevo nombre: ";
        cin >> Nombre;
        NodoProd->Nombre = Nombre;
        return;
    }
    cout<<"No se encontro el producto especificado\n";
    
}

#pragma endregion

#pragma region Marca
void MenuFunciones::InsertarMarcaRN(ArbolRN* Arbol)
{
    int codPasillo, codProducto, codMarca, cantidadGondola;
    double precio;
    string nombre;

    cout << "Ingrese el código de pasillo: ";
    cin >> codPasillo;

    cout << "Ingrese el código de producto: ";
    cin >> codProducto;

    cout << "Ingrese el código de marca: ";
    cin >> codMarca;

    cout << "Ingrese el nombre de la marca: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese la cantidad en la góndola: ";
    cin >> cantidadGondola;

    cout << "Ingrese el precio: ";
    cin >> precio;

    NodoMarca* NuevaMarca = new NodoMarca(codPasillo, codProducto, codMarca, nombre, cantidadGondola, precio);
    Arbol->insertar(NuevaMarca);
}

void MenuFunciones::EncontrarMarcaRN(ArbolRN* Arbol)
{
    int CodMarca;
    cout << "Ingrese el código de marca: ";
    cin >> CodMarca;

    NodoBase* NodoEncontrado = Arbol->BusquedaM(CodMarca);
    if (NodoMarca* MarcaEncontrada = dynamic_cast<NodoMarca*>(NodoEncontrado))
    {
        MarcaEncontrada->Mostrar();
        cout<<"Encontrado!"<<endl;
        return;
    }
    cout<<"No encontrado!"<<endl;
}

void MenuFunciones::ModificarMarcaRN(ArbolRN* Arbol)
{
}
#pragma endregion

#pragma region Inventario
void MenuFunciones::InsertarInventarioAA(ArbolAA* Arbol)
{
    int CodPasillo, CodProd, CodMarca, CodInventario, Cantidad;
    double Precio;
    string Nombre;

    cout<<"Ingrese el codigo de pasillo: ";
    cin>>CodPasillo;

    cout<<"Ingrese el codigo de producto: ";
    cin>>CodProd;

    cout<<"Ingrese el codigo de marca: ";
    cin>>CodMarca;

    cout<<"Ingrese el codigo de inventario: ";
    cin>>CodInventario;

    cout<<"Ingrese la cantidad: ";
    cin>>Cantidad;

    cout<<"Ingrese el precio: ";
    cin>>Precio;

    cout<<"Ingrese el nombre: ";
    cin>>Nombre;

    string Linea = to_string(CodPasillo)+";"+to_string(CodProd)+";"+to_string(CodMarca)+";"+to_string(CodInventario)+";"+Nombre+";"+to_string(Cantidad)+";"+to_string(Precio);
    NodoInventario* NuevoInventario = new NodoInventario(Linea);
    Arbol->insert(NuevoInventario);
    NuevoInventario->Mostrar();
    cout<<"Inventario ingresado exitosamente";
}

void MenuFunciones::EncontrarInventarioAA(ArbolAA* Arbol)
{
    int CodInv;
    cout<<"Ingrese el codigo del inventario a buscar: "<<endl;
    cin>> CodInv;

    NodoBase* NodoEncontrado = Arbol->Encontrar(CodInv);

    if (NodoInventario* InvEncontrado = dynamic_cast<NodoInventario*>(NodoEncontrado))
    {
        InvEncontrado->Mostrar();
        cout<<"Inventario encontrado!"<<endl;
        return;
    }
    cout<<"Inventario no encontrado!"<<endl;
}

void MenuFunciones::ModificarInventarioAA(ArbolAA* Arbol)
{
}
#pragma endregion

#pragma region Administrador
void MenuFunciones::InsertarAdminB(ArbolB* Arbol) 
{
    cout << "Insertando en la Opción 1." << endl;
    int CodAdmin;
    std::string Nombre;
    int CodCiudad;
    int Telefono;
    std::string Correo;
    NodoAdmin(std::string& Linea);

    cout << "Ingrese el código de Administrador: ";
    cin >> CodAdmin;

    cout << "Ingrese su nombre: ";
    cin >> Nombre;

    cout << "Ingrese la Ciudad: ";
    cin >> CodCiudad;

    cout << "Ingrese su telefono: ";
    cin >> Telefono;

    cout << "Ingrese el correo: ";
    cin >> Correo;

    string Linea = to_string(CodAdmin)+";"+Nombre+";"+to_string(CodCiudad)+";"+to_string(Telefono)+";"+to_string(Correo);
    NodoAdmin* NuevoAdmin = new NodoAdmin(Linea);
    Arbol->insertar(NuevoAdmin);
    NuevoAdmin->Mostrar();
    cout<<"Administrador ingresado exitosamente";
}

void MenuFunciones::EncontrarAdminB(ArbolB* Arbol)
{
    int CodAdmin;
    cout<<"Ingrese el codigo del administrador a buscar: "<<endl;
    cin>>CodAdmin;

    NodoBase* Nodo= Arbol->BuscarNodo(ArbolB* Arbol);

    if (NodoAdmin* EncontradoArbolB = dynamic_cast<NodoAdmin*>(Nodo))
    {
        AdminEncontrado->Mostrar();
        cout<<"Administrador encontrado!"<<endl;
        return;
    }
    cout<<"Admnistrador no encontrado!"<<endl;
}

void MenuFunciones::ModificarAdminB(ArbolB* Arbol)
{

}
#pragma endregion


#pragma region Cliente
void MenuFunciones::InsertarClienteB(ArbolB* Arbol) 
{
    cout << "Insertando en la Opción 1." << endl;
    int Cedula;
    std::string Nombre;
    int CodCiudad;
    int Telefono;
    std::string Correo;
    NodoCliente(std::string& Linea);

    cout << "Ingrese la cedula del cliente: ";
    cin >> Cedula;

    cout << "Ingrese su nombre: ";
    cin >> Nombre;

    cout << "Ingrese la Ciudad: ";
    cin >> CodCiudad;

    cout << "Ingrese su telefono: ";
    cin >> Telefono;

    cout << "Ingrese el correo: ";
    cin >> Correo;

    string Linea = to_string(Cedula)+";"+Nombre+";"+to_string(CodCiudad)+";"+to_string(Telefono)+";"+to_string(Correo);
    NodoAdmin* NuevoAdmin = new NodoAdmin(Linea);
    Arbol->insertar(NuevoCiente);
    NuevoCliente->Mostrar();
    cout<<"Cliente ingresado exitosamente";
}

void MenuFunciones::EncontrarClienteB(ArbolB* Arbol)
{
    int Cedula;
    cout<<"Ingrese la cedula del cliente a buscar: "<<endl;
    cin>>Cedula;

    NodoBase* Nodo= Arbol->BuscarNodo(ArbolB* Arbol);

    if (NodoCliente* EncontradoArbolB = dynamic_cast<NodoCliente*>(Nodo))
    {
        ClienteEncontrado->Mostrar();
        cout<<"Cliente encontrado!"<<endl;
        return;
    }
    cout<<"Cliente no encontrado!"<<endl;
}

void MenuFunciones::ModificarAdminB(ArbolB* Arbol)
{
    
}
#pragma endregion