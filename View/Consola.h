#ifndef CLASE18POO_CONSOLA_H
#define CLASE18POO_CONSOLA_H
#pragma once // Evita que el archivo se incluya múltiples veces y cause errores de compilación

#include <string>

// --- Declaración Adelantada (Forward Declaration) ---
// Le decimos al compilador: "Existe una clase llamada Inventario, confía en mí".
// Hacemos esto en lugar de #include "Inventario.h" para evitar un "abrazo mortal"
// de inclusiones circulares (si Inventario incluyera Consola y viceversa).
class Inventario;

// Clase Consola: Es una clase de "Utilidad" (Helper Class).
// Todos sus métodos son 'static', lo que significa que no necesitas crear un objeto
// (no haces 'new Consola()'). Los usas directamente como 'Consola::limpiarPantalla()'.
class Consola {
public:

    // Muestra el mensaje narrativo de inicio (título, historia breve).
    static void mostrarBienvenida();

    // Muestra el mensaje final dependiendo de si ganaste (true) o perdiste (false).
    static void mostrarGameOver(bool victoria);

    // --- Utilidades de Pantalla ---

    // Borra todo el texto de la terminal para que el juego se vea limpio en cada turno.
    // (Usa 'cls' en Windows o 'clear' en Linux/Mac).
    static void limpiarPantalla();

    // Detiene la ejecución del programa hasta que el usuario presione la tecla Enter.
    // Útil para que el jugador pueda leer mensajes de combate o historia antes de que se borren.
    static void esperarEnter();

    // --- Menú Interactivo ---
    /*
     * Muestra una lista numerada de los objetos del inventario.
     * Si es un arma, muestra sus estadísticas.
     * Retorna:
     * - El índice del vector (0, 1, 2...) si el jugador elige un objeto válido.
     * - -1 si el jugador elige "Cancelar" o el inventario está vacío.
     */
    static int seleccionarItemInventario(Inventario& inventario);
};

#endif //CLASE18POO_CONSOLA_H