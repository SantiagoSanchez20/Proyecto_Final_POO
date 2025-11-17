#include "SalaC1.h"
#include "GameManager.h"
#include "Player.h"
#include "Trampa.h" // (Clase de Persona B)

SalaC1::SalaC1() : Sala(
    "C1",
    "Cámara de las Reliquias. Estanterías con reliquias; una daga antigua brilla en la penumbra."
), puzzleResuelto(false), dagaRecogida(false)
{
    // Llenamos la sala con sus trampas
    trampasEnSala.push_back(new Trampa("Trampa de dardos", 10)); // 10 de daño
}

void SalaC1::alEntrar(GameManager* game, Player* jugador) {
    Sala::alEntrar(game, jugador);

    // Lógica de la trampa
    if (!puzzleResuelto) {
        std::cout << "\n¡AUCH! Al entrar, pisas una placa de presión. Unos dardos te golpean." << std::endl;
        trampasEnSala[0]->activar(jugador);
    }
}

void SalaC1::manejarTurno(GameManager* game, Player* jugador) {
    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    // Opciones Específicas
    if (!puzzleResuelto) {
        opciones.push_back("Resolver puzzle"); // A
    } else if (!dagaRecogida) {
        opciones.push_back("Tomar la Daga de Velo"); // A
    }

    // Salidas
    opcionActual = 'a' + opciones.size();

    opciones.push_back("Avanzar (a C2)");
    mapaSalidas[opcionActual] = "C2";
    opcionActual++;

    opciones.push_back("Devolverse de sala (a S)");
    mapaSalidas[opcionActual] = "S";
    opcionActual++;

    char eleccion = presentarOpcionesYLeerInput(opciones);

    //  Procesar
    if (!puzzleResuelto && eleccion == 'a') {
        std::cout << "Tras mover unos cuantos libros... ¡Click! Las trampas se desactivan." << std::endl;
        this->puzzleResuelto = true;
    }
    else if (puzzleResuelto && !dagaRecogida && eleccion == 'a') {
        game->transferirItemDeSalaAInventario("Daga de Velo", this, jugador);
        this->dagaRecogida = true;
    }
    else if (mapaSalidas.count(eleccion)) {
        game->cambiarSala(mapaSalidas[eleccion]);
    }
    else {
        std::cout << "Opción no válida." << std::endl;
    }
}