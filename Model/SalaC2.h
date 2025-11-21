
#ifndef CLASE18POO_SALAC2_H
#define CLASE18POO_SALAC2_H
#pragma once
#include "Sala.h"
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
class SalaC2 : public Sala {
public:
    bool ladronVencido;
    bool iriaYaAparecio;

    SalaC2();
    virtual void manejarTurno(GameManager* game, Player* jugador) override;
};
#endif