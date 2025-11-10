//
// Created by duque on 10/11/2025.
//

#ifndef CLASE18POO_DAGAVELO_H
#define CLASE18POO_DAGAVELO_H
#include "Arma.h"

class DagaVelo: public Arma
{
    DagaVelo()
    {
        nombre = "Espada de Velo";
        danioAdicional = 10;
        efectoEspecial = "+15% critico";
    }
};


#endif //CLASE18POO_DAGAVELO_H