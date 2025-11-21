#include "Arma.h"
#include "Player.h"

// --- Constructor ---
Arma::Arma(const std::string& nombre,
           const std::string& descripcion,
           int danioAdicional,
           const std::string& efectoEspecial,
           int chanceCritico,
           int chanceAturdir)
    : Item(nombre, descripcion),
      danioAdicional(danioAdicional),
      efectoEspecial(efectoEspecial),
      chanceCritico(chanceCritico),
      chanceAturdir(chanceAturdir)
{
}

// --- Implementación de la Herencia ---
void Arma::usar(Player* jugador) {

    jugador->equiparArma(this);
}
