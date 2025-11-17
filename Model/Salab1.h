//
// Created by Usuario on 17/11/2025.
//

#ifndef CLASE18POO_SALAB1_H
#define CLASE18POO_SALAB1_H

#pragma once
#include "Sala.h"

class SalaB1 : public Sala {
public:
    bool maelorYaInterpenso;
    bool maelorAtacado;

    SalaB1();
    virtual void manejarTurno(GameManager* game, Player* jugador) override;
};
#endif