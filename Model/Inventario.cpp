#include "Inventario.h"
#include "Item.h"
#include <iostream>
#include <algorithm> // Necesario para usar std::find
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
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

int Inventario::getCantidad() const {
    return this->items.size();
}

Item* Inventario::obtenerItem(int indice) {
    // Verificamos que el índice sea válido (que no sea menor a 0 ni mayor al tamaño)
    if (indice >= 0 && indice < this->items.size()) {
        return this->items[indice];
    }
    return nullptr; // Si piden un número inválido, devolvemos "nada"
}