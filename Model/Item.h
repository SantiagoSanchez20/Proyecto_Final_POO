//
// Created by duque on 10/11/2025.
//

#ifndef CLASE18POO_ITEM_H
#define CLASE18POO_ITEM_H
#include <string>
#include "Player.h"
#include <iostream>
class Item
{
    protected:
    std::string nombre;
    std::string descripcion;
public:

    //constructor para item
    Item(std::string nombre, std::string descripcion): nombre(nombre), descripcion(descripcion) {}
    virtual ~Item() {}
    virtual void usar(Player* jugador) = 0;


    //Usamos los getters(para poder leer los datos protegidos de esta clase).


    std::string getNombre();
    std::string getDescripcion();



};


#endif //CLASE18POO_ITEM_H