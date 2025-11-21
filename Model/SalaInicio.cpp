#include "SalaInicio.h"
#include "../Controller/GameManager.h"
#include "Player.h"
#include <iostream>
#include <vector>
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
SalaInicio::SalaInicio() : Sala(
    "S",
    "Vestibulo Quebrado. Puerta principal del castillo; antorchas apagadas; un corredor que se bifurca."
) {

}

void SalaInicio::manejarTurno(GameManager* game, Player* jugador) {

    std::vector<std::string> opciones;
    char opcionActual = 'a';

    // --- VARIABLES PARA LAS OPCIONES ---
    char letraDerecha = '\0';
    char letraIzquierda = '\0';
    char letraSalirCastillo = '\0';
    char letraInventario = '\0';

    // 1. Opción Derecha (B1)
    opciones.push_back("Ir hacia la puerta de la derecha ");
    letraDerecha = opcionActual++;

    // 2. Opción Izquierda (C1)
    opciones.push_back("Ir hacia la puerta de la izquierda ");
    letraIzquierda = opcionActual++;

    // 3. Opción Salir (Esta es la que termina el juego)
    opciones.push_back("Salir del castillo ");
    letraSalirCastillo = opcionActual++;

    // 4. Opción Inventario
    opciones.push_back("Ver Inventario / Usar Items");
    letraInventario = opcionActual++;

    // --- MOSTRAR Y LEER ---
    char eleccion = presentarOpcionesYLeerInput(opciones);

    // --- PROCESAR ---

    if (eleccion == letraDerecha) {
        game->cambiarSala("B1");
    }
    else if (eleccion == letraIzquierda) {
        game->cambiarSala("C1");
    }
    else if (eleccion == letraSalirCastillo) {
        std::cout << "\nDecides que esta aventura es demasiado para ti." << std::endl;
        std::cout << "Das media vuelta y abandonas el Bastion Inmortal." << std::endl;
        // False = Derrota/Rendición
        game->terminarJuego(false);
    }
    else if (eleccion == letraInventario) {
        game->gestionarInventario(jugador);
    }
    else {
        std::cout << "Opcion no valida." << std::endl;
    }
}