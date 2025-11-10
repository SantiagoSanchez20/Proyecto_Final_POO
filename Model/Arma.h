//
// Created by duque on 10/11/2025.
//

#ifndef CLASE18POO_ARMA_H
#define CLASE18POO_ARMA_H
#include <string>

class Arma
{
protected:
    int danioAdicional;
    std::string nombre;
    std::string efectoEspecial;
public:
    Arma(){}
    virtual ~Arma(){}

    //Implementamos las funciones getters
    //Como estamos usandos protected , necesitamos funciones
    //para poddder leer los valores desde fuera.

    std::string getNombre()
{
    return nombre;
}

    int getDanioAdicional()
    {
        return danioAdicional;
    }
    std::string getEfectoEspecial()
    {
        return efectoEspecial;
    }

};


#endif //CLASE18POO_ARMA_H