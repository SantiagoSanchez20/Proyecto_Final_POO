#ifndef CLASE18POO_POCION_H
#define CLASE18POO_POCION_H
#include "Item.h"
#include <iostream>
class Pocion : public Item
{
private:
    int hpCurado;


public:
    Pocion(std::string nombrePocion, std::string descripPocion, int cura );

    //usamos override para sobrescribir la funcion virtual "usar" del item

    void usar(Player* jugador) override;

};


#endif //CLASE18POO_POCION_H