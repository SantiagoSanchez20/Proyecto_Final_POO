#ifndef CLASE18POO_ARMA_H
#define CLASE18POO_ARMA_H
#include <string>
#include "Player.h"
#include "Item.h"

class Arma : public Item {
public:
    int danioAdicional;
    std::string efectoEspecial; // Texto descriptivo

    // --- ¡NUEVOS ATRIBUTOS PARA LA LÓGICA! ---
    int chanceCritico; // Porcentaje (0-100)
    int chanceAturdir; // Porcentaje (0-100)

    Arma(const std::string& nombre,
         const std::string& descripcion,
         int danioAdicional,
         const std::string& efectoEspecial,
         int chanceCritico = 0,   // Por defecto 0
         int chanceAturdir = 0);  // Por defecto 0

    virtual void usar(Player* jugador) override;
};

#endif //CLASE18POO_ARMA_H