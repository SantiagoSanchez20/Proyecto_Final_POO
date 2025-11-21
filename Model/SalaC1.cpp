#include "SalaC1.h"
#include "../Controller/GameManager.h"
#include "Player.h"
#include "Trampa.h"
#include "Inventario.h"
#include <iostream>
#include <map>
#include <limits>
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
// Constructor
SalaC1::SalaC1() : Sala(
    "C1",
    "Camara de las Reliquias. Estanterias con reliquias; una daga antigua brilla en la penumbra."
), puzzleResuelto(false), dagaRecogida(false)
{
    // NOTA: Ya no usamos el mapa 'salidas' automático para "Avanzar"
    // porque necesitamos controlar la lógica manualmente.
    // Solo dejamos la salida segura (Regresar) en el mapa si quisieramos,
    // pero lo haremos todo manual para mayor control.

    trampasEnSala.push_back(new Trampa("Dardos de Pared", 15)); // Daño 15
}

void SalaC1::alEntrar(GameManager* game, Player* jugador) {
    Sala::alEntrar(game, jugador);

    // Narrativa de entrada
    if (!puzzleResuelto) {
        std::cout << "Notas que el suelo tiene placas de presion extrañas." << std::endl;
        std::cout << "La puerta hacia la siguiente camara parece cerrada por un mecanismo." << std::endl;
    }
}

void SalaC1::manejarTurno(GameManager* game, Player* jugador) {

    std::vector<std::string> opciones;
    char opcionActual = 'a';

    // Variables para guardar letras dinámicas
    char letraPuzzle = '\0';
    char letraTomarDaga = '\0';
    char letraAvanzar = '\0';   // Salida bloqueada
    char letraRegresar = '\0';  // Salida segura
    char letraInventario = '\0';
    char letraSalir = '\0';

    // --- 1. Construcción del Menú ---

    // A. Puzzle (Si no está resuelto)
    if (!puzzleResuelto) {
        opciones.push_back("Resolver puzzle de las estanterias. ");
        letraPuzzle = opcionActual++;
    }
    // A. Tomar Daga (Si está resuelto pero no recogida)
    else if (!dagaRecogida) {
        opciones.push_back("Tomar la Daga de Velo");
        letraTomarDaga = opcionActual++;
    }

    // B. Avanzar (La trampa)
    opciones.push_back("Avanzar hacia la Camara del Acolito (C2)");
    letraAvanzar = opcionActual++;

    // C. Regresar
    opciones.push_back("Regresar al Vestibulo (S)");
    letraRegresar = opcionActual++;

    // D. Inventario
    opciones.push_back("Ver Inventario / Usar Items");
    letraInventario = opcionActual++;

    // E. Salir
    opciones.push_back("Salir del Juego");
    letraSalir = opcionActual++;

    // --- 2. Leer Input ---
    char eleccion = presentarOpcionesYLeerInput(opciones);

    // --- 3. Lógica ---

    // CASO: Resolver Puzzle
    if (!puzzleResuelto && letraPuzzle != '\0' && eleccion == letraPuzzle) {
        std::cout << "\nObservas los libros antiguos y encuentras un patron..." << std::endl;
        std::cout << "Mueves el tomo rojo, luego el azul..." << std::endl;
        std::cout << "¡CLICK! Los mecanismos de defensa se apagan. La puerta se desbloquea." << std::endl;
        this->puzzleResuelto = true;
        std::cout << "(Presiona Enter)..."; std::cin.get();
    }

    // CASO: Tomar Daga
    else if (puzzleResuelto && !dagaRecogida && letraTomarDaga != '\0' && eleccion == letraTomarDaga) {
        game->transferirItemDeSalaAInventario("Daga de Velo", this, jugador);
        this->dagaRecogida = true;
        std::cout << "(Presiona Enter)..."; std::cin.get();
    }

    // CASO: Avanzar (LA TRAMPA)
    else if (eleccion == letraAvanzar) {
        if (!puzzleResuelto) {
            // --- BLOQUEO Y DAÑO ---
            std::cout << "\nIntentas forzar la puerta hacia la camara del acolito..." << std::endl;
            std::cout << "¡CRACK! ¡No has desactivado la seguridad!" << std::endl;

            if (!trampasEnSala.empty()) {
                trampasEnSala[0]->activar(jugador); // Aplica daño y muestra mensaje
            }

            std::cout << "Retrocedes herido. Debes resolver el puzzle primero." << std::endl;
            std::cout << "(Presiona Enter)..."; std::cin.get();
            // NO CAMBIAMOS DE SALA
        }
        else {
            // --- PASE PERMITIDO ---
            game->cambiarSala("C2");
        }
    }

    // CASO: Regresar
    else if (eleccion == letraRegresar) {
        game->cambiarSala("S");
    }

    // CASO: Inventario
    else if (eleccion == letraInventario) {
        game->gestionarInventario(jugador);
    }

    // CASO: Salir
    else if (eleccion == letraSalir) {
        game->terminarJuego(false);
    }

    else {
        std::cout << "Opcion no valida." << std::endl;
    }
}