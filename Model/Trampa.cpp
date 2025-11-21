#include "Trampa.h"
#include "Player.h"
#include <iostream>

// Constructor
Trampa::Trampa(std::string n, int d) : nombre(n), dano(d) {}

// Lógica de activación
void Trampa::activar(Player* jugador) {
    std::cout << "\n*** CUIDADO ***" << std::endl;
    std::cout << "¡La trampa '" << nombre << "' se ha activado!" << std::endl;

    jugador->recibirDano(dano);

    std::cout << "Recibes " << dano << " puntos de dano." << std::endl;
    std::cout << "Tu HP actual: " << jugador->getHp() << std::endl;
}