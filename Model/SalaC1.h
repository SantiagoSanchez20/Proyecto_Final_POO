#ifndef CLASE18POO_SALAC1_H
#define CLASE18POO_SALAC1_H

#pragma once
#include "Sala.h"
#include <vector>

class Trampa; // Declaración adelantada para que compile rápido

class SalaC1 : public Sala {
public:
    // Vector para guardar las trampas de la sala
    std::vector<Trampa*> trampasEnSala;

    // Estados del puzzle
    bool puzzleResuelto;
    bool dagaRecogida;

    SalaC1(); // Constructor

    virtual void alEntrar(GameManager* game, Player* jugador) override;
    virtual void manejarTurno(GameManager* game, Player* jugador) override;
};

#endif