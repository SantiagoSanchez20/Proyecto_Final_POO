#ifndef CLASE18POO_MAELOR_H
#define CLASE18POO_MAELOR_H
#include "NPC.h"
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
class Maelor : public NPC{
public:
    Maelor();
    ~Maelor();

    virtual void interactuar(Player *jugador) override;
    void darConsejo();

    // CAMBIO IMPORTANTE: Ahora devuelve bool (true si acierta, false si falla)
    bool iniciarAdivinanza(Player* jugador);

    void darPocion(Player* jugador);
};
#endif //CLASE18POO_MAELOR_H