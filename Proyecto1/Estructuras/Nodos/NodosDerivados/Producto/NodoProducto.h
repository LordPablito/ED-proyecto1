#pragma once
#include <string>

#include "../../NodoBase.h"

class NodoProducto : public NodoBase
{
public:
    int Pasillo;
    int Producto;
    std::string Nombre;

    NodoProducto(const std::string& Linea);

    void Mostrar() override;
};
