//
// Created by duque on 10/11/2025.
//

#ifndef CLASE18POO_ESPADABRUMA_H
#define CLASE18POO_ESPADABRUMA_H
#include "Arma.h"

//Alejadro esta clase se va usar para la sala de  sacar la espada.
class EspadaBruma : public Arma
{
    public:
    EspadaBruma()
    {
        nombre = "Espada de Bruma";
        danioAdicional = 10;
        efectoEspecial = "10% aturdir";

    }
};


#endif //CLASE18POO_ESPADABRUMA_H