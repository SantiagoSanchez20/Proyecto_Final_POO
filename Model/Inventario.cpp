//
// Created by duque on 10/11/2025.
//

#include "Inventario.h"
#include "Item.h"
#include <iostream>
//Constructor de Inventario.cpp
Inventario::Inventario()
{
    std::cout << "Inventario constructor" << std::endl;
}
//Destructor para borrar el inventario

Inventario::~Inventario()
{
    for (Item* item : items)
    {
        std::cout << "Borrando Inventario....." << std::endl;
        delete item; //Aqui esta eliminando la memoria, sirve cuando el usuario se muere.
    }
    items.clear();
}

//Creamos la funcion de agregar item

void Inventario::AgregarItem(Item* item)
{
    items.push_back(item);
    std::cout << "Has agregado: " << item->getNombre()<<std::endl;
}

void Inventario::removerItem(Item* item)
{
    //Usamos el remove para borrar el item si el jugador desea eliminarlo
    items.remove(item);
    std::cout << "Has removido: " << item->getNombre()<<std::endl;
}
void Inventario::mostrarInventario()
{
    std::cout << "----Inventario----" << std::endl;

    if (items.empty())
    {
        std::cout << " (Vacio)" << std::endl;

    } else
    {
        int i = 1;
        for (Item* item : items)
        {
            std::cout << i << ". " << item->getNombre() << std::endl;
            i++;
        }
    }
    std::cout <<"---------------------\n" << std::endl;

}


