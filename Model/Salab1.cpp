#include "Salab1.h"
#include "../Controller/GameManager.h"
#include "Player.h"
#include "Maelor.h"
#include "SoldadoCorrupto.h"

SalaB1::SalaB1() : Sala(
    "B1",
    "Sala del Custodio. Un salón con estandartes raídos. Un anciano monje - Maelor - medita."
), maelorYaInterpenso(false), maelorAtacado(false)
{
}

void SalaB1::manejarTurno(GameManager* game, Player* jugador) {

    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    // Solo mostramos opciones de Maelor si no ha sido atacado
    if (!maelorAtacado) {
        opciones.push_back("Saludar Maelor");     // A
        opciones.push_back("Rodear a anciano");    // B
        opciones.push_back("Atacar a el anciano"); // C
    }

    opcionActual = 'a' + opciones.size();

    // Añadir salida para avanzar
    opciones.push_back("Avanzar (a B2)");
    mapaSalidas[opcionActual] = "B2";
    opcionActual++;

    // Añadir salida para regresar
    opciones.push_back("Devolverse de sala (a S)");
    mapaSalidas[opcionActual] = "S";
    opcionActual++;

    //  Mostrar menú y leer input
    char eleccion = presentarOpcionesYLeerInput(opciones);

    // Procesar Input

    // Opciones Específicas
    if (!maelorAtacado && eleccion == 'a') { // Saludar Maelor
        Maelor* m = game->findPersonaje<Maelor*>("Maelor", this);
        if (m && !maelorYaInterpenso) {
            std::cout << "Te acercas a Maelor. El anciano abre los ojos..." << std::endl;
            m->iniciarAdivinanza(jugador); // Método de Persona B
            this->maelorYaInterpenso = true;
        } else if (m) {
             std::cout << "Maelor medita en silencio." << std::endl;
        }
    }
    else if (!maelorAtacado && eleccion == 'b') { // Rodear
        Maelor* m = game->findPersonaje<Maelor*>("Maelor", this);
        if (m && !maelorYaInterpenso) {
            std::cout << "El anciano te detiene. 'Espera...'." << std::endl;
            m->iniciarAdivinanza(jugador);
            this->maelorYaInterpenso = true;
        } else if (m) {
             std::cout << "Maelor medita en silencio." << std::endl;
        }
    }
    else if (!maelorAtacado && eleccion == 'c') { // Atacar
        std::cout << "¡Atacas al anciano! De las sombras emergen guardias." << std::endl;
        this->maelorAtacado = true;
        game->removePersonaje("Maelor", this); // Maelor se va

        // Crea y añade los nuevos enemigos
        Enemigo* s1 = new SoldadoCorrupto();
        Enemigo* s2 = new SoldadoCorrupto();
        this->personajesEnSala.push_back(s1);
        this->personajesEnSala.push_back(s2);

        // Llama al combate
        game->iniciarCombate(jugador, s1, true);
        if (jugador->hp > 0) {
            game->iniciarCombate(jugador, s2, true);
        }
    }
    else if (mapaSalidas.count(eleccion)) {
        game->cambiarSala(mapaSalidas[eleccion]);
    }
    else {
        std::cout << "Opción no válida." << std::endl;
    }
}