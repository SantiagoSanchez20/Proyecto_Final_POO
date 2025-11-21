#ifndef CLASE18POO_COLLECTIBLEITEM_H
#define CLASE18POO_COLLECTIBLEITEM_H
#include "Item.h"
#include "Player.h" // Necesario para la firma de usar
#include <iostream>

/**
 * @brief Implementación de Item para objetos que se pueden recoger
 * pero no tienen un efecto activo al ser 'usados' desde el inventario.
 * (Ej: La Aureus).
 */
class CollectibleItem : public Item {
public:
    // El constructor llama al constructor de Item
    CollectibleItem(const std::string& nombre, const std::string& descripcion)
        : Item(nombre, descripcion) {}

    // Implementamos la función 'usar' (Obligatorio para no ser abstracta)
    virtual void usar(Player* jugador) override {
        std::cout << "[Item] El " << getNombre() << " es un objeto pasivo. No puedes usarlo desde el inventario." << std::endl;
    }
};

#endif //CLASE18POO_COLLECTIBLEITEM_H