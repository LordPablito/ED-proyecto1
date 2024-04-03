#include "BibliotecaReportes.h"

#include <fstream>

#include "../Estructuras/Nodos/NodosDerivados/Administrador/NodoAdmin.h"
#include "../Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "../Estructuras/Nodos/NodosDerivados/Producto/NodoProducto.h"

void BibliotecaReportes::ReportarPasillos(ListaSimple* ListaPasillos)
{
    ofstream Reporte("../Reportes/ReportePasillos.csv");
    //Reporte<<"HolaMundoProbando\n";

    ListaPasillos->IterarNodos([&Reporte](NodoBase* Nodo)
    {
        if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
        {
            Reporte<<std::to_string(Pasillo->Codigo)+","+Pasillo->Nombre+"\n";
        }
    });

    Reporte.close();
}

void BibliotecaReportes::ReportarProductosPasillo(ListaDoble* ListaProds)
{
    int NumPasillo = 0;
    cout<<"Ingrese el numero de pasillo: ";
    cin>>NumPasillo;
    
    ofstream Reporte("../Reportes/ReporteProdsPasillo.csv");

    ListaProds->IterarNodos([&Reporte, NumPasillo](NodoBase* Nodo)
    {
        if (NodoProducto* Producto = dynamic_cast<NodoProducto*>(Nodo))
        {
            if (NumPasillo != Producto->Pasillo) return;
            
            Reporte<<std::to_string(Producto->Pasillo)+"," + std::to_string(Producto->Producto) + "," + Producto->Nombre+"\n";
        }
    });
    Reporte.close();
}

void BibliotecaReportes::ReportarAdministradores(TablaHash* TablaAdmins)
{
    ofstream Reporte("../Reportes/ReporteAdmins.csv");

    TablaAdmins->IterarNodos([&Reporte](NodoBase* Nodo)
    {
        if (NodoAdmin* Admin = dynamic_cast<NodoAdmin*>(Nodo))
        {
            Reporte<<std::to_string(Admin->CodAministrador)+"," + Admin->Nombre + "," + std::to_string(Admin->CodCiudad) + ","+ std::to_string(Admin->Telefono)+ "," +Admin->Correo+"\n";
        }
    });
    Reporte.close();
}
