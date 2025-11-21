#include "GuardianDeLumen.h"
#include "Player.h"
#include <iostream>
#include <cmath> // Para static_cast

// --- Constructor ---
// Ajustamos la vida (HP) a 200 para que sea un jefe apropiado.
GuardianDeLumen::GuardianDeLumen() : Enemigo("Guardian de Lumen", 200, 12, 10),
fase(1), hpMax(200)  {
    std::cout << " El "<<this->nombre << " ha aparecido..... ¡Derrotalo! " << std::endl;
}

// --- Destructor
GuardianDeLumen::~GuardianDeLumen() {
    // Es suficiente con la definición vacía para que el Linker lo encuentre.
}
void GuardianDeLumen::cambiarFase() {
    if (!this->estaVivo() || this->hpMax == 0) {
        return;
    }

    float hpPorcent = (float)this->hp / this->hpMax;


    // Fase 3 (HP 1% a 39%)
    if (hpPorcent <= 0.39f && this->fase < 3 ) {
        this->fase = 3;
        this->ataque  += 3;
        std::cout << "El " << this->nombre << " ruge de furia y entra en.... ¡FASE 3!"<< std::endl;
        // La lógica del GameManager ya actualiza el HP máximo si fuera necesario.
    }

    // Fase 2 (HP 40% a 74%)
    else if (hpPorcent <= 0.74f && this->fase < 2 ) {
        this->fase = 2;
        this->ataque  += 2;
        std::cout << "El " << this->nombre << " concentra energia... ¡FASE 2!"<< std::endl;
    }
    // Fase 1 (75 % a 100%) - Por defecto.
}

void GuardianDeLumen::recibirDano(int cantidad) {
    this-> hp -= cantidad;
    if (this->hp < 0 ) {
        this->hp = 0;
    }
    std::cout << "El " << this->nombre << " recibe " << cantidad << " de dano. " <<
        "Vida restante: " << this-> hp << "/" << this->hpMax << std::endl;

    // Comprobamos el cambio de fase
    this-> cambiarFase();

    //Comprobamos si el jefe ha muerto
    if (!this->estaVivo()) { // O usando this->hp <= 0
        std::cout << "El " << this->nombre << " ha sido derrotado." << std::endl;
        // El GameManager maneja la recompensa
    }
}

void GuardianDeLumen::atacar(Player *objetivo) {
    if (!this->estaVivo()) {
        return;
    }

    switch (this->fase) {
        case 1:
            this->ataqueSimple(objetivo);
            break;
        case 2:
            this->ataqueEspecial(objetivo);
            break;
        case 3:
            this->ataqueFuerte(objetivo);
            break;
        default:
            this->ataqueSimple(objetivo);
            break;
    }
}

void GuardianDeLumen::ataqueSimple(Player* objetivo) {
    std::cout << "El " << this->nombre << " (Fase 1) lanza un golpe simple." << std::endl;
    objetivo->recibirDano(this->ataque);
}
void GuardianDeLumen::ataqueEspecial(Player* objetivo) {
    int danoEspecial = static_cast<int>(this->ataque * 1.15);
    std::cout << "El " << this->nombre << " (Fase 2) usa daño en area!" << std::endl;
    objetivo->recibirDano(danoEspecial);
}

void GuardianDeLumen::ataqueFuerte(Player* objetivo) {
    int danoFuerte = static_cast<int>(this->ataque * 1.2);
    std::cout << " El " << this->nombre << " (Fase 3) usa golpe fuerte!!!"<<std::endl;
    objetivo->recibirDano(danoFuerte);
}