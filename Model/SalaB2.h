
#ifndef CLASE18POO_SALAB2_H
#define CLASE18POO_SALAB2_H

#pragma once
#include "Sala.h"
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
class SalaB2 : public Sala {
public:

    bool jugadorYaObservo;
    bool espadaRecogida;
    bool guardiaVencido;

    SalaB2();

    virtual void manejarTurno(GameManager* game, Player* jugador) override;
};
#endif