#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <string>
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
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


    int getCantidad() const;         // Para saber cuántos items hay
    Item* obtenerItem(int indice);   // Para obtener el item "1", "2", etc.
};

#endif // INVENTARIO_H