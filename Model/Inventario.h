//
// Created by duque on 10/11/2025.
//

#ifndef CLASE18POO_INVENTARIO_H
#define CLASE18POO_INVENTARIO_H
#include "vector"

class Inventario
{
private:
    std::vector<item> items;
public:
    // Creamos una funcion para que cuando el jugador pueda agregar o quitar items(utlizados)
    void AgregarItem(item);

    void removerItem(item);
    ~Inventario();

};


#endif //CLASE18POO_INVENTARIO_H