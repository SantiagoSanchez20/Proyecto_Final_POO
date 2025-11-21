#ifndef CLASE18POO_SALAINICIO_H
#define CLASE18POO_SALAINICIO_H
#pragma once
#include "Sala.h"

class SalaInicio : public Sala {
public:
    SalaInicio();


    //Agregamos el override para controlar las opciones manualmente
    virtual void manejarTurno(GameManager* game, Player* jugador) override;
};
#endif
