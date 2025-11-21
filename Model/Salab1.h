#ifndef CLASE18POO_SALAB1_H
#define CLASE18POO_SALAB1_H
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
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