//
// Created by duque on 10/11/2025.
//

#ifndef CLASE18POO_INVENTARIO_H
#define CLASE18POO_INVENTARIO_H
#include <vector>
#include "Item.h"


class Inventario
{
private:
    //Creamos un lista para que almacene todos los Objetos
    std::vector<Item*> items;


public:

    //Creamos el contructor
    Inventario();

    //Destructor para borrar los punteros en memoria
    ~Inventario();



    // Creamos una funcion para que cuando el jugador pueda agregar o quitar items(utlizados)
    bool agregarItem(Item* item);

    Item* buscarItem(const std::string& nombre);

    void mostrarItems() const;


};


#endif //CLASE18POO_INVENTARIO_H