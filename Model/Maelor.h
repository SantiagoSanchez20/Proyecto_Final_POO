//
// Created by duque on 12/11/2025.
//

#ifndef CLASE18POO_MAELOR_H
#define CLASE18POO_MAELOR_H
#include "Personaje.h"
#include "Player.h"

class Maelor : public Personaje
{
public:
    //Constructor
    Maelor();
// Destructor
    ~Maelor();


    void atacar(Personaje* objetivo) const ;
    void dialogo(Player* hablar) const ;

};


#endif //CLASE18POO_MAELOR_H