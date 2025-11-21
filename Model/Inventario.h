#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <string>

class Item; // Declaración adelantada

class Inventario {
public:
    std::vector<Item*> items;

    Inventario();

    bool agregarItem(Item* item);

    // Función necesaria para cuando usas pociones
    void removerItem(Item* item);

    Item* buscarItem(const std::string& nombre);

    // Función que llama SalaC1
    void mostrar();
};

#endif // INVENTARIO_H