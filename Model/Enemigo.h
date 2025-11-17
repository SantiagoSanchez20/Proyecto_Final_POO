//
// Created by ssanc on 15/11/2025.
//

#ifndef CLASE18POO_ENEMIGO_H
#define CLASE18POO_ENEMIGO_H
#include "Personaje.h"
#include "Player.h"

class Enemigo : public Personaje{
    public:

    int ataque;
    int experiencia;

    //Constructor para enemigo
    Enemigo(const std::string& nombre, int vida, int ataque, int experiencia);

    //Metodo atacar para el jugador

    virtual void atacar(Player* objetivo) ;

    //Virtual para sobreescribir recibiDaño
    virtual void recibirDano(int cantidad) override;




};


#endif //CLASE18POO_ENEMIGO_H