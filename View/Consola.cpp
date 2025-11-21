#include "Consola.h"
#include "../Model/Inventario.h"
#include "../Model/Item.h"
#include "../Model/Arma.h" // <--- Asegúrate de que este include esté aquí
#include <iostream>
#include <cstdlib>
#include <limits>

// --- Funciones que ya tenías (Se quedan igual) ---

void Consola::mostrarBienvenida() {
    std::cout << "\n======================================" << std::endl;
    std::cout << "  BIENVENIDO AL CASTILLO BASTION INMORTAL " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Un heroe sube al castillo para conseguir la Aureus y salvar a su pueblo." << std::endl;
    std::cout << "El reto: vencer al guardian final para reclamar la Aureus. " << std::endl;
}

void Consola::mostrarGameOver(bool victoria) {
    if (victoria) {
        std::cout << "\n\n*** FELICIDADES, HAS RECLAMADO LA AUREUS! ***\n" << std::endl;
    } else {
        std::cout << "\n\n*** HAS SIDO DERROTADO. GAME OVER. ***\n" << std::endl;
    }
}

void Consola::limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Consola::esperarEnter() {
    std::cout << "\n[Presiona ENTER para continuar...]";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// --- AQUÍ ESTÁ EL CAMBIO PRINCIPAL ---
// Reemplaza tu función anterior con esta versión:

int Consola::seleccionarItemInventario(Inventario& inventario) {
    std::cout << "\n=== SELECCIONA UN OBJETO ===" << std::endl;

    if (inventario.getCantidad() == 0) {
        std::cout << "(Inventario vacio)" << std::endl;
        return -1;
    }

    // Bucle mejorado para detectar Armas
    for (int i = 0; i < inventario.getCantidad(); ++i) {
        Item* item = inventario.obtenerItem(i);

        if (item != nullptr) {
            std::cout << "  " << (i + 1) << ". " << item->getNombre();

            // Intentamos ver si el item es un Arma
            Arma* arma = dynamic_cast<Arma*>(item);

            if (arma != nullptr) {
                // ¡ES UN ARMA! Mostramos daño y efecto
                std::cout << " (Dano: +" << arma->danioAdicional
                          << " | Efecto: " << arma->efectoEspecial << ")" << std::endl;
            }
            else {
                // NO ES ARMA (Es poción u otro). Mostramos descripción normal.
                std::cout << " (" << item->getDescripcion() << ")" << std::endl;
            }
        }
    }

    std::cout << "  0. Cancelar / Volver atras" << std::endl;
    std::cout << "> ";

    int opcion;
    std::cin >> opcion;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (opcion <= 0 || opcion > inventario.getCantidad()) {
        return -1;
    }

    return (opcion - 1);
}