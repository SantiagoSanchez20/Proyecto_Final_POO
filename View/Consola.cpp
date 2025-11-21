#include "Consola.h"
#include "../Model/Inventario.h"
#include "../Model/Item.h"
#include "../Model/Arma.h" // Necesario para poder acceder a dañoAdicional y efectoEspecial
#include <iostream>
#include <cstdlib>
#include <limits>
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
// --- Función de Bienvenida ---
// Muestra el texto narrativo al iniciar el programa.
void Consola::mostrarBienvenida() {
    std::cout << "\n======================================" << std::endl;
    std::cout << "  BIENVENIDO AL CASTILLO BASTION INMORTAL " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Un heroe sube al castillo para conseguir la Aureus y salvar a su pueblo." << std::endl;
    std::cout << "El reto: vencer al guardian final para reclamar la Aureus. " << std::endl;
}

// --- Función de Fin de Juego ---
// Muestra un mensaje distinto dependiendo si ganaste (true) o perdiste (false).
void Consola::mostrarGameOver(bool victoria) {
    if (victoria) {
        std::cout << "\n\n*** FELICIDADES, HAS RECLAMADO LA AUREUS! ***\n" << std::endl;
    } else {
        std::cout << "\n\n*** HAS SIDO DERROTADO. GAME OVER. ***\n" << std::endl;
    }
}

// --- Función para Limpiar Pantalla ---
// Borra todo el texto de la consola para que el juego se vea ordenado.
void Consola::limpiarPantalla() {
    // Verifica si estamos en Windows (_WIN32)
    #ifdef _WIN32
        system("cls"); // Comando de Windows
    #else
        system("clear"); // Comando de Linux/Mac
    #endif
}

// --- Función de Pausa ---
// Detiene el programa hasta que el usuario presione Enter.
void Consola::esperarEnter() {
    std::cout << "\n[Presiona ENTER para continuar...]";
    // Limpia el buffer por si quedó basura de un cin anterior
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Espera a que se presione una tecla
    std::cin.get();
}

// --- Función Principal del Inventario ---
// Muestra la lista de objetos, detecta si son armas para mostrar stats,
// y devuelve el índice del objeto que el usuario eligió.
int Consola::seleccionarItemInventario(Inventario& inventario) {
    std::cout << "\n=== SELECCIONA UN OBJETO ===" << std::endl;

    // 1. Si no hay nada, avisamos y salimos devolviendo -1 (error/cancelar)
    if (inventario.getCantidad() == 0) {
        std::cout << "(Inventario vacio)" << std::endl;
        return -1;
    }

    // 2. Recorremos todos los items del inventario
    for (int i = 0; i < inventario.getCantidad(); ++i) {
        Item* item = inventario.obtenerItem(i);

        if (item != nullptr) {
            // Imprimimos el número (i + 1 para que empiece en 1, no en 0)
            std::cout << "  " << (i + 1) << ". " << item->getNombre();

            // --- TRUCO DE POLIMORFISMO ---
            // Intentamos convertir el Item* genérico a un Arma*.
            // Si funciona, 'arma' tendrá datos. Si no (es una poción), será nullptr.
            Arma* arma = dynamic_cast<Arma*>(item);

            if (arma != nullptr) {
                // ES UN ARMA: Mostramos sus estadísticas de combate
                std::cout << " (Dano: +" << arma->danioAdicional
                          << " | Efecto: " << arma->efectoEspecial << ")" << std::endl;
            }
            else {
                // ES OTRO ITEM (Poción): Mostramos solo su descripción
                std::cout << " (" << item->getDescripcion() << ")" << std::endl;
            }
        }
    }

    // Opción de salida
    std::cout << "  0. Cancelar / Volver atras" << std::endl;
    std::cout << "> ";

    // 3. Leer la elección del usuario
    int opcion;
    std::cin >> opcion;

    // Limpiamos buffer para evitar errores si escribe letras
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // 4. Validar la opción
    // Si elige 0 o un número mayor a la cantidad de items, cancelamos.
    if (opcion <= 0 || opcion > inventario.getCantidad()) {
        return -1;
    }

    // 5. Devolver el índice real
    // El usuario ve "1", pero el vector usa "0", así que restamos 1.
    return (opcion - 1);
}