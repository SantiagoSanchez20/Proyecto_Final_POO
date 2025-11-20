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


void Iria::darBuff(Player* jugador) {
    std::cout << "[Iria] Siente la luz de Lumen... ¡Te otorgo su bendicion!" << std::endl;

    // 1. Crear el objeto Buff:
    // (nombre, aumentoAtaque, turnosRestantes)
    // Damos 5 turnos (Iria te da el buff en el turno 1, te quedan 4)
    Buff bendicion("Bendicion de Iria", 5, 5);

    // 2. Añadirlo al jugador
    // El jugador se encargará de gestionarlo
    jugador->agregarBuff(bendicion);
}

void Iria::darPistaLlave() {
    std::cout << "[Iria] Pista: Hay una arma poderosa.....que esta en una piedra....clavada...donde estara?.. busca en las otras habitaciones queriedo extrano" << std::endl;
}