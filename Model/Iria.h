#ifndef CLASE18POO_IRIA_H
#define CLASE18POO_IRIA_H
#include "NPC.h"
#include "Player.h"
class Iria : public NPC{
public:
    Iria();
    //implementacion de herencia desde (NPC)
    virtual void interactuar(Player *jugador) override;

    //Metodos

    void darBuff(Player *jugador);
    void darPistaLlave();
};
#endif //CLASE18POO_IRIA_H