//
// Created by duque on 10/11/2025.
//

#ifndef CLASE18POO_ARMA_H
#define CLASE18POO_ARMA_H
#include <string>
#include "Player.h"
#include "Item.h"

class Arma : public Item {
public:
    // --- Atributos Públicos

    int danioAdicional;
    std::string efectoEspecial;

    // --- Constructor ---
    Arma(const std::string& nombre,
         const std::string& descripcion,
         int danioAdicional,
         const std::string& efectoEspecial);

    // --- Implementación de la Herencia (Obligatoria) ---

    virtual void usar(Player* player) override;


};

#endif //CLASE18POO_ARMA_H