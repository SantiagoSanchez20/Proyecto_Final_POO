#include "Item.h"
// Implementación del constructor
Item::Item(const std::string& nombre, const std::string& descripcion)
    : nombre(nombre), descripcion(descripcion) {
    // Constructor
}
// Implementación de los getters
std::string Item::getNombre() const {
    return this->nombre;
}

std::string Item::getDescripcion() const {
    return this->descripcion;
}