//
// Created by duque on 10/11/2025.
//

#include "Arma.h"
#include "Player.h"

// --- Constructor ---
Arma::Arma(const std::string& nombre,
           const std::string& descripcion,
           int danioAdicional,
           const std::string& efectoEspecial)
    // 1. Llama al constructor de la clase base (Item)
    : Item(nombre, descripcion),
    // 2. Inicializa los atributos propios de Arma
      danioAdicional(danioAdicional),
      efectoEspecial(efectoEspecial)
{

}

// --- Implementación de la Herencia ---
void Arma::usar(Player* jugador) {

    jugador->equiparArma(this);
}
