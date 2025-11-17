
#ifndef CLASE18POO_SALAFINAL_H
#define CLASE18POO_SALAFINAL_H


#pragma once
#include "Sala.h"

class SalaFinalE : public Sala {
public:
    bool jefeVencido;
    bool aureusRecogida;

    SalaFinalE(); // Constructor
    virtual void manejarTurno(GameManager* game, Player* jugador) override;
};



#endif //CLASE18POO_SALAFINAL_H