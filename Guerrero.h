#ifndef GUERRERO_H
#define GUERRERO_H

#include "Personaje.h"

/**
 * @class Guerrero
 * @brief DECLARACIÓN de la clase Guerrero.
 * Hereda de Personaje y tiene su propio comportamiento.
 */
class Guerrero : public Personaje {
private:
    int furia; // Atributo específico del Guerrero.

public:
    // Constructor que llama al constructor de la clase base.
    Guerrero(std::string nombre);

    // Sobrescritura del método atacar.
    void atacar() const override;
};

#endif //GUERRERO_H
