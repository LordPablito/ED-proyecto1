#pragma once
#include "../../NodoBase.h"

class NodoCliente : public NodoBase {
    public:
        std::string Cedula;
        std::string Nombre;
        int CodCiudad;
        int Telefono;
        std::string Correo;

        NodoCliente(std::string& Linea);
        void Mostrar() override;
    };