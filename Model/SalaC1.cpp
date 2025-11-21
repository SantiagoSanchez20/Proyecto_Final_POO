#include "SalaC1.h"
#include "../Controller/GameManager.h"
#include "Player.h"
#include "Trampa.h"
#include <iostream>
#include <map>

// Constructor
SalaC1::SalaC1() : Sala(
    "C1",
    "Camara de las Reliquias. Estanterias con reliquias; una daga antigua brilla en la penumbra."
), puzzleResuelto(false), dagaRecogida(false)
{
    salidas["Avanzar hacia la Camara del Acolito"] = "C2";
    salidas["Regresar al Vestibulo"] = "S";
    trampasEnSala.push_back(new Trampa("Dardos Ocultos", 10));
}

// Evento al entrar
void SalaC1::alEntrar(GameManager* game, Player* jugador) {
    Sala::alEntrar(game, jugador);

    if (!puzzleResuelto) {
        std::cout << "\n¡CLICK! Pisas una placa de presion en el suelo..." << std::endl;
        if (!trampasEnSala.empty()) {
            trampasEnSala[0]->activar(jugador);
        }
    }
}

// Menú de opciones
void SalaC1::manejarTurno(GameManager* game, Player* jugador) {

    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    // 1. Opciones Específicas
    if (!puzzleResuelto) {
        opciones.push_back("Resolver puzzle de las estanterias");
    }
    else if (!dagaRecogida) {
        opciones.push_back("Tomar la Daga de Velo");
    }

    // 2. Salidas, Inventario, Salir
    char inicioSalidas = 'a' + opciones.size();

    for (auto const& [texto, id] : this->salidas) {
        opciones.push_back(texto);
        mapaSalidas[inicioSalidas] = id;
        inicioSalidas++;
    }

    opciones.push_back("Ver Inventario");
    char opcionInventario = inicioSalidas++;
    opciones.push_back("Salir del Juego");
    char opcionSalir = inicioSalidas++;

    char eleccion = presentarOpcionesYLeerInput(opciones);

    // 3. Procesar
    if (!puzzleResuelto && eleccion == 'a') {
        std::cout << "\nMueves los libros en el orden correcto..." << std::endl;
        std::cout << "¡CLICK! Escuchas los mecanismos de las trampas desactivarse." << std::endl;
        this->puzzleResuelto = true;
    }
    else if (puzzleResuelto && !dagaRecogida && eleccion == 'a') {
        game->transferirItemDeSalaAInventario("Daga de Velo", this, jugador);
        this->dagaRecogida = true;
    }
    else if (mapaSalidas.count(eleccion)) {
        game->cambiarSala(mapaSalidas[eleccion]);
    }
    else if (eleccion == opcionInventario) {
        jugador->inventario->mostrar();
        std::cout << "(Enter para continuar)";
        std::cin.get();
    }
    else if (eleccion == opcionSalir) {
        game->terminarJuego(false);
    }
    else {
        std::cout << "Opcion no valida." << std::endl;
    }
}