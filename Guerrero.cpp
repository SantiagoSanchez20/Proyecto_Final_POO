#include "Guerrero.h"
#include <iostream>

/**
 * @file Guerrero.cpp
 * @brief IMPLEMENTACIÓN de los métodos de la clase Guerrero.
 */

Guerrero::Guerrero(std::string nombre) : Personaje(nombre), furia(100) {
    // Llama al constructor de Personaje para inicializar 'nombre' y 'vida'.
}

// Implementación específica de 'atacar' para el Guerrero.
void Guerrero::atacar() const {
    std::cout << "!El Guerrero " << this->nombre << " carga con su gran espada!" << std::endl;
}
