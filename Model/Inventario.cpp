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

bool Inventario::agregarItem(Item* item) {
    // Por ahora, asumimos capacidad infinita
    if (item != nullptr) {
        this->items.push_back(item);
        return true;
    }
    return false;
}

Item* Inventario::buscarItem(const std::string& nombre) {
    for (Item* item : this->items) {
        if (item->getNombre() == nombre) {
            return item;
        }
    }
    return nullptr; // No se encontró
}

void Inventario::mostrarItems() const {
    if (this->items.empty()) {
        std::cout << "[Inventario] Esta vacio." << std::endl;
        return;
    }

    std::cout << "--- INVENTARIO ---" << std::endl;
    for (const Item* item : this->items) {
        std::cout << "- " << item->getNombre() << " (" << item->getDescripcion() << ")" << std::endl;
    }
    std::cout << "------------------" << std::endl;
}


