#pragma once
#include "../Estructuras/ListaDoble/ListaDoble.h"
#include "../Estructuras/ListaSimple/ListaSimple.h"
#include "../Estructuras/TablaHash/TablaHash.h"

class BibliotecaReportes
{
public:
    static void ReportarPasillos(ListaSimple* ListaPasillos);
    static void ReportarProductosPasillo(ListaDoble* ListaProds);
    static void ReportarAdministradores(TablaHash* TablaAdmins);
};
