#include "Consola.h"
#include "..\Model/Inventario.h" // <--- Necesario para usar el inventario
#include "..\Model/Item.h"       // <--- Necesario para ver el nombre del item
#include <iostream>
#include <cstdlib>      // Para system("cls")
#include <limits>       // Para limpiar el buffer de entrada

// --- Lo que ya tenías ---
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

// --- LO NUEVO QUE DEBES AGREGAR AL FINAL ---

void Consola::limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Consola::esperarEnter() {
    std::cout << "\n[Presiona ENTER para continuar...]";
    // Ignora cualquier caracter que haya quedado en el buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); // Espera una tecla
}

int Consola::seleccionarItemInventario(Inventario& inventario) {
    std::cout << "\n=== SELECCIONA UN OBJETO ===" << std::endl;

    if (inventario.getCantidad() == 0) {
        std::cout << "(Inventario vacio)" << std::endl;
        // esperarEnter(); // Opcional, depende de tu flujo
        return -1;
    }

    // Mostramos los items numerados: 1. Pocion, 2. Daga...
    for (int i = 0; i < inventario.getCantidad(); ++i) {
        Item* item = inventario.obtenerItem(i);
        if (item != nullptr) {
            std::cout << "  " << (i + 1) << ". " << item->getNombre()
                      << " (" << item->getDescripcion() << ")" << std::endl;
        }
    }
    std::cout << "  0. Cancelar / Volver atras" << std::endl;
    std::cout << "> ";

    int opcion;
    std::cin >> opcion;

    // Limpiamos el buffer por seguridad (por si escribe letras)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (opcion <= 0 || opcion > inventario.getCantidad()) {
        return -1; // Cancelar o opción inválida
    }

    // Convertimos el número del usuario (1) al índice del vector (0)
    return (opcion - 1);
}