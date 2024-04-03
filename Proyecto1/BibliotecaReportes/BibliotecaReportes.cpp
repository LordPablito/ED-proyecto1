#include "BibliotecaReportes.h"

#include <fstream>

#include "../Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"

void BibliotecaReportes::ReportarPasillos(ListaSimple* ListaPasillos)
{
    ofstream Reporte("Reportes/ReportePasillos.txt");

    ListaPasillos->IterarNodos([&Reporte](NodoBase* Nodo)
    {
        if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
        {
            Reporte<<std::to_string(Pasillo->Codigo)+", "+Pasillo->Nombre+"\n";
        }
    });

    Reporte.close();
}
