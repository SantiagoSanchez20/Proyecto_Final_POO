#ifndef CLASE18POO_PLAYER_H
#define CLASE18POO_PLAYER_H
#include "Inventario.h"
#include "Arma.h"
#include "Item.h"

class Enemigo;
class Player
{
private:
    int hp;
    int ataqueBase;
    Inventario inventario; //Inventario del jugador
    Arma armaEquipada;


public:

    //Constructor
    Player();

    //Metodos para Player.cpp
    void atacar(Enemigo* enemigo);
    void usarItem(Item* item);
    void mover();




};


#endif //CLASE18POO_PLAYER_H