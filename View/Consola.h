#ifndef CLASE18POO_CONSOLA_H
#define CLASE18POO_CONSOLA_H
#pragma once

#include <string>

// Declaración adelantada (para que sepa que existe Inventario sin incluir todo el archivo aquí)
class Inventario;

class Consola {
public:
    // --- Lo que ya tienes ---
    static void mostrarBienvenida();
    static void mostrarGameOver(bool victoria);

    // --- LO QUE DEBES AGREGAR ---

    // Limpia la consola (borra el texto anterior)
    static void limpiarPantalla();

    // Pausa el juego hasta que presiones Enter
    static void esperarEnter();

    /*
     Muestra el inventario numerado y pide elegir uno.
     El índice del item (0, 1, 2...) o -1 si cancela.
     */
    static int seleccionarItemInventario(Inventario& inventario);
};

#endif //CLASE18POO_CONSOLA_H