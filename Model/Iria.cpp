
#include "Buff.h"
#include "Iria.h"

/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
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
    Buff bendicion("Bendicion de Iria", 5, 5);
    jugador->agregarBuff(bendicion);
}
void Iria::darPistaLlave() {
    std::cout << "[Iria] Pista: Hay una arma poderosa.....que esta en una piedra....clavada...donde estara?.. busca en las otras habitaciones queriedo extraño.....regresate a las anteriores" << std::endl;
}