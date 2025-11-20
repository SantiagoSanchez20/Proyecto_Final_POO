#include "Trampa.h"
#include "Player.h" // Necesario para restar vida (hp)
#include <iostream>

// Constructor
Trampa::Trampa(std::string n, int d) : nombre(n), dano(d) {}

// Lógica de activación
void Trampa::activar(Player* jugador) {
    std::cout << "\n*** CUIDADO ***" << std::endl;
    std::cout << "¡La trampa '" << nombre << "' se ha activado!" << std::endl;

    jugador->hp -= dano;
    if (jugador->hp < 0) jugador->hp = 0;

    std::cout << "Recibes " << dano << " puntos de dano." << std::endl;
    std::cout << "Tu HP actual: " << jugador->hp << std::endl;
}