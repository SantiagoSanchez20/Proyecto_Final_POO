#include "Consola.h"
#include <iostream>

void Consola::mostrarBienvenida() {
    std::cout << "\n======================================" << std::endl;
    std::cout << "  BIENVENIDO AL CASTILLO BASTIÓN INMORTAL " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Un héroe sube al castillo para conseguir la Aureus y salvar a su pueblo." << std::endl;
    std::cout << "El reto: vencer al guardián final para reclamar la Aureus. " << std::endl;
}

void Consola::mostrarGameOver(bool victoria) {
    if (victoria) {
        std::cout << "\n\n*** ¡FELICIDADES, HAS RECLAMADO LA AUREUS! ***\n" << std::endl;
    } else {
        std::cout << "\n\n*** HAS SIDO DERROTADO. GAME OVER. ***\n" << std::endl;
    }
}