//
// Created by duque on 10/11/2025.
//

#ifndef CLASE18POO_INVENTARIO_H
#define CLASE18POO_INVENTARIO_H
#include <list>
#include "Item.h"


class Inventario
{


public:
    //Creamos un lista para que almacene todos los Objetos
    std::list<Item*> items;

    //Creamos el contructor
    Inventario();

    //Destructor para borrar los punteros en memoria
    ~Inventario();

    // Creamos una funcion para que cuando el jugador pueda agregar o quitar items(utlizados)
    void AgregarItem(Item* item);
    void removerItem(Item* item);
    void mostrarInventario();



};


#endif //CLASE18POO_INVENTARIO_H