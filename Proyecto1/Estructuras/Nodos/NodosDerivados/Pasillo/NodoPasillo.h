#pragma once
#include <string>

#include "../../NodoBase.h"

class NodoPasillo: public NodoBase
{
public:
    std::string Nombre;
    int Codigo;

    NodoPasillo(std::string& Linea);
    void Mostrar() override;
};
