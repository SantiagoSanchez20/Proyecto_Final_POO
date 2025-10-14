#include "Mago.h"
#include <iostream>

/**
 * @file Mago.cpp
 * @brief IMPLEMENTACIÓN de los métodos de la clase Mago.
 */

// El constructor de Mago debe llamar al constructor de Personaje
// para inicializar la parte que le corresponde a la clase base.
Mago::Mago(std::string nombre) : Personaje(nombre), mana(150) {
    // El cuerpo puede estar vacío o tener lógica adicional.
}

// Implementación específica de 'atacar' para el Mago.
void Mago::atacar() const {
    std::cout << "!El Mago " << this->nombre << " lanza un poderoso hechizo de fuego!" << std::endl;
}
