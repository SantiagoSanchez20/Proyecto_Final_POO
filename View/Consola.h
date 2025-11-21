#ifndef CLASE18POO_CONSOLA_H
#define CLASE18POO_CONSOLA_H
#pragma once

#include <string>

class Consola {
public:
    // Muestra el mensaje inicial del juego
    static void mostrarBienvenida();

    // Muestra el mensaje final (Game Over o Victoria)
    static void mostrarGameOver(bool victoria);
};

#endif //CLASE18POO_CONSOLA_HOO_CONSOLA_H