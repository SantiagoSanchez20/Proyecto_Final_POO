
#ifndef CLASE18POO_SALAC1_H
#define CLASE18POO_SALAC1_H

#pragma once
#include "Sala.h"
#include <vector>
class Trampa; // (De Santiago)

class SalaC1 : public Sala {
public:
    bool puzzleResuelto;
    bool dagaRecogida;
    std::vector<Trampa*> trampasEnSala;

    SalaC1();

    virtual void alEntrar(GameManager* game, Player* jugador) override;

    virtual void manejarTurno(GameManager* game, Player* jugador) override;
};
#endif