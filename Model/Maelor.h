#ifndef CLASE18POO_MAELOR_H
#define CLASE18POO_MAELOR_H
#include "NPC.h"

class Maelor : public NPC{
    public:
    //Constructor
    Maelor();
    //Destructor
    ~Maelor();

    //Implementacion virtual para la interaccion con el jugador:
    virtual void interactuar(Player *jugador) override;

    // Implementacion para dar el consejo tactico o consejo ayuda
    void darConsejo();

    //Implementacion del dialogo de adivinanza para dar la respectiva recompensa de una pocion.
    void iniciarAdivinanza(Player* jugador);

    //Implementacion para dar la cura al jugador en el caso de que adivine

    void darPocion(Player* jugador);
};
#endif //CLASE18POO_MAELOR_H