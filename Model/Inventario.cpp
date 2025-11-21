#include "Inventario.h"
#include "Item.h"
#include <iostream>
#include <algorithm> // Necesario para usar std::find

Inventario::Inventario() {
    // Se inicia vacío
}

bool Inventario::agregarItem(Item* item) {
    if (item != nullptr) {
        this->items.push_back(item);
        return true;
    }
    return false;
}

void Inventario::removerItem(Item* item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
    }
}

Item* Inventario::buscarItem(const std::string& nombre) {
    for (Item* item : this->items) {
        if (item->getNombre() == nombre) {
            return item;
        }
    }
    return nullptr; // No se encontró nada
}

void Inventario::mostrar() {
    std::cout << "\n=== TU INVENTARIO ===" << std::endl;

    if (items.empty()) {
        std::cout << "(Vacio)" << std::endl;
    } else {
        for (Item* item : items) {
            // Usamos los getters correctos
            std::cout << "- " << item->getNombre()
                      << " (" << item->getDescripcion() << ")" << std::endl;
        }
    }

    std::cout << "=====================" << std::endl;
}