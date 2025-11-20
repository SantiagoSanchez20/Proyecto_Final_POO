#include "SalaC2.h"
#include "../Controller/GameManager.h"
#include "Player.h"
#include "Ladron.h" // Para buscar al Ladrón

SalaC2::SalaC2() : Sala(
    "C2",
    "Cámara del Acólito. Un ladrón está saqueando un cuerpo."
), ladronVencido(false), iriaYaAparecio(false)
{
}

void SalaC2::manejarTurno(GameManager* game, Player* jugador) {
    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    //  Opciones Específicas
    if (!ladronVencido) {
        opciones.push_back("Hablar con la persona"); // A
        opciones.push_back("Atacar a la persona");   // B
    }

    // Salidas
    opcionActual = 'a' + opciones.size();

    opciones.push_back("Avanzar (a E)");
    mapaSalidas[opcionActual] = "E";
    opcionActual++;

    opciones.push_back("Devolverse de sala (a C1)");
    mapaSalidas[opcionActual] = "C1";
    opcionActual++;

    // Leer Input
    char eleccion = presentarOpcionesYLeerInput(opciones);

    // Procesar
    Enemigo* ladron = game->findPersonaje<Enemigo*>("Ladron", this);

    if (!ladronVencido && eleccion == 'a') { // Hablar
        if (ladron) {
            std::cout << "El ladrón te mira con hostilidad. ¡Te ataca!" << std::endl;
            game->iniciarCombate(jugador, ladron, false); // Enemigo ataca primero
            if(ladron->hp <= 0) this->ladronVencido = true;
        } else {
             std::cout << "El ladrón ya no está." << std::endl;
        }
    }
    else if (!ladronVencido && eleccion == 'b') { // Atacar
        if (ladron) {
            std::cout << "¡Atacas al ladrón antes de que reaccione!" << std::endl;
            game->iniciarCombate(jugador, ladron, true); // Jugador ataca primero
            if(ladron->hp <= 0) this->ladronVencido = true;
        } else {
             std::cout << "El ladrón ya no está." << std::endl;
        }
    }
    else if (mapaSalidas.count(eleccion)) {
        game->cambiarSala(mapaSalidas[eleccion]);
    }
    else {
        std::cout << "Opción no válida." << std::endl;
    }
}