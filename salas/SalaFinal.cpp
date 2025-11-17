
#include "SalaFinal.h"
#include "GameManager.h"
#include "Player.h"
#include "Enemigo.h"
#include "GuardianDeLumen.h"

SalaFinalE::SalaFinalE() : Sala(
    "E",
    "Salón Central. Gran salón con un pedestal iluminado. La Aureus está protegida por el Guardián de Lúmen."
), jefeVencido(false), aureusRecogida(false)
{
}

void SalaFinalE::manejarTurno(GameManager* game, Player* jugador) {
    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    // Opciones Específicas
    if (!jefeVencido) {
        opciones.push_back("Atacar al Guardián de Lúmen"); // A
    } else if (!aureusRecogida) {
        opciones.push_back("Tomar la Aureus"); // A
    } else {
        opciones.push_back("Has ganado. No hay nada más que hacer.");
    }

    //  Salidas
    opcionActual = 'a' + opciones.size();

    opciones.push_back("Devolverse de sala (a B2)"); // (Se mostrará si vienes de B2)
    mapaSalidas[opcionActual] = "B2";
    opcionActual++;

    opciones.push_back("Devolverse de sala (a C2)"); // (Se mostrará si vienes de C2)
    mapaSalidas[opcionActual] = "C2";
    opcionActual++;

    //Leer Input
    char eleccion = presentarOpcionesYLeerInput(opciones);

    // --- 4. Procesar ---
    if (!jefeVencido && eleccion == 'a') {
        Enemigo* jefe = game->findPersonaje<Enemigo*>("Guardian de Lumen", this);
        if (jefe) {
            std::cout << "¡El Guardián de Lúmen te enfrenta! ¡La batalla final comienza!" << std::endl;
            game->iniciarCombate(jugador, jefe, true);
            if (jefe->hp <= 0) {
                this->jefeVencido = true;
                std::cout << "Con un último esfuerzo, el Guardián cae. La Aureus es tuya." << std::endl;
            }
        }
    }
    else if (jefeVencido && !aureusRecogida && eleccion == 'a') {
        std::cout << "Tomas la fruta mítica... El Bastión Inmortal ha sido conquistado." << std::endl;
        game->transferirItemDeSalaAInventario("Aureus", this, jugador);
        this->aureusRecogida = true;
        game->terminarJuego(true); // ¡VICTORIA!
    }
    else if (mapaSalidas.count(eleccion)) {
        game->cambiarSala(mapaSalidas[eleccion]);
    }
    else {
        std::cout << "Opción no válida." << std::endl;
    }
}