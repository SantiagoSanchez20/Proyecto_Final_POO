#include "Personaje.h"
#include <iostream>

/**
 * @file Personaje.cpp
 * @brief IMPLEMENTACIÓN de los metodos de la clase base Personaje.
 */

Personaje::Personaje(std::string nombre) : nombre(nombre), vida(100) {
    std::cout << "Ha nacido un nuevo personaje: " << this->nombre << std::endl;
}

// Implementación del ataque generico para un Personaje base.
void Personaje::atacar() const {
    std::cout << this->nombre << " realiza un ataque generico." << std::endl;
}

void Personaje::recibirDanio(int danio) {
    this->vida -= danio;
    std::cout << this->nombre << " recibe " << danio << " de danno. Vida restante: " << this->vida << std::endl;
}

std::string Personaje::getNombre() const {
    return this->nombre;
}
