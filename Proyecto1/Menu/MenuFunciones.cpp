#include "MenuFunciones.h"
#include "../Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "../Estructuras/Nodos/NodosDerivados/Producto/NodoProducto.h"

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
}
#pragma endregion 