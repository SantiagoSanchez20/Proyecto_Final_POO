//
// Created by ssanc on 15/11/2025.
//

#include "Enemigo.h"
//enemigo.cpp dd

// --- Constructor ---
Enemigo::Enemigo(const std::string& nombre, int hp, int ataque, int experiencia)
    // 1. Llamamos al constructor de Personaje
    : Personaje(nombre, hp),
    // 2. Inicializamos nuestros propios atributos
      ataque(ataque),
      experiencia(experiencia)
{
    // Cuerpo del constructor (vacío)
}

//Implementamos la herencia de recibirDano

void Enemigo::recibirDano(int cantidad) {
    this->hp -= cantidad;

    if (this->hp < 0) {
        this->hp = 0;
    }

    std::cout << "[Enemigo] " << this->nombre << " recibe " << cantidad
        << " de dano. Vida restante: " << this-> hp << std::endl;

    //Implementamo un if para saber si esta vivo
    if (!this->estaVivo()) {
        std::cout << "[Enemigo] " << this->nombre << " ha sido derrotado." << std::endl;
        // NOTA: Aquí es donde el GameManager debería otorgar
        // la 'experiencia' al jugador.
    }
}

//---------Combate-------------

void Enemigo::atacar(Player* objetivo) {
    // Comprobaciones de estado
    if (!this->estaVivo()) {

        //Implementar aqui el nombre del cada jefe si hay en una sala

        std::cout << "[Enemigo] " << this->nombre << " no puede atacar, esta muerto." << std::endl;
        return;
    }
    if (!objetivo->estaVivo()) {
        // El enemigo no atacará a un jugador ya muerto
        return;
    }

    std::cout << "[Enemigo] " << this->nombre << " ataca a " << objetivo->getNombre()
        << " e inflige " << this->ataque << " de daño." << std::endl;

    // Aplicamos el daño al jugador
    objetivo->recibirDano(this->ataque);
}

