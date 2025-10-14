#ifndef MAGO_H
#define MAGO_H

#include "Personaje.h"

/**
 * @class Mago
 * @brief DECLARACIÓN de la clase Mago.
 * Hereda de Personaje y añade sus propias características.
 */
class Mago : public Personaje { // Sintaxis de herencia pública
private:
    int mana; // Atributo específico del Mago.

public:
    // Constructor que llama al constructor de la clase base.
    Mago(std::string nombre);

    // Sobrescritura (Override) del método atacar.
    // La palabra 'override' es una buena práctica que le pide al compilador
    // verificar que este método realmente existe en la clase base.
    void atacar() const override;
};

#endif //MAGO_H
