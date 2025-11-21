#include <iostream>
#include "Controller/GameManager.h"
// 1. Incluimos  la librería de Windows
#ifdef _WIN32
#include <windows.h>
#endif
int main() {
//Configura la consola para UTF-8 al arrancar
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    GameManager juego;
    juego.iniciarJuego();
    return 0;
}