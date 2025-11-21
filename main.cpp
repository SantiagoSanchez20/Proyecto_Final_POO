#include <iostream>
#include "Controller/GameManager.h"
// 1. Incluimos  la librería de Windows
#ifdef _WIN32
#include <windows.h>
#include <ctime>
#endif

int main() {
//Configura la consola para UTF-8 al arrancar
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif



    // --- ACTIVAR EL AZAR---
    // "Siembra" la aleatoriedad usando la hora actual del reloj.
    // Sin esto, el juego siempre sacaría los mismos números.
    std::srand(static_cast<unsigned int>(std::time(0)));

    GameManager juego;
    juego.iniciarJuego();
    return 0;
}