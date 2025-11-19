//
// Created by ssanc on 17/11/2025.
//
#include "Buff.h"
#include "Iria.h"


Iria::Iria(): NPC("Iria", "Escucha el viento, te guiara a la verdad."){

}


void Iria::interactuar(Player *jugador) {
    std::cout << "[Iria] " << this->dialogo << std::endl;

    //logica de iria: da una pista y un buff

    this->darPistaLlave();
    this->darBuff(jugador);

}
