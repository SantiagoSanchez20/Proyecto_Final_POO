#include "SalaC2.h"
#include "../Controller/GameManager.h"
#include "Player.h"
#include "Ladron.h"
#include "Personaje.h"
#include "Iria.h"

SalaC2::SalaC2() : Sala(
    "C2",
    "Cámara del Acólito. Un ladrón está saqueando un cuerpo."
), ladronVencido(false), iriaYaAparecio(false)
{
    salidas["Avanzar (a E)"] = "E";
    salidas["Devolverse de sala (a C1)"] = "C1";
}

void SalaC2::manejarTurno(GameManager* game, Player* jugador) {
    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    // Opciones Específicas
    if (!ladronVencido) {
        opciones.push_back("Hablar con la persona"); // A [cite: 87]
        opciones.push_back("Atacar a la persona");   // B [cite: 89]
    }

    // Salidas
    opcionActual = 'a' + opciones.size();

    opciones.push_back("Avanzar (a E)");
    mapaSalidas[opcionActual] = "E";
    opcionActual++;

    opciones.push_back("Devolverse de sala (a C1)"); // [cite: 91]
    mapaSalidas[opcionActual] = "C1";
    opcionActual++;

    // --- LEER INPUT Y PROCESAR ---
    char eleccion = presentarOpcionesYLeerInput(opciones);

    Enemigo* ladron = game->findPersonaje<Enemigo*>("Ladron", this);

    if (!ladronVencido && eleccion == 'a') {
        if (ladron) {
            std::cout << "El ladrón te mira con hostilidad. ¡Te ataca!" << std::endl;
            game->iniciarCombate(jugador, ladron, false);
            // CORRECCIÓN: Usamos getHp()
            if(ladron->getHp() <= 0) this->ladronVencido = true;
        } else {
             std::cout << "El ladrón ya no está." << std::endl;
        }
    }
    else if (!ladronVencido && eleccion == 'b') { // Atacar [cite: 90]
        if (ladron) {
            std::cout << "¡Atacas al ladrón antes de que reaccione!" << std::endl;
            game->iniciarCombate(jugador, ladron, true);
            if(ladron->getHp() <= 0) this->ladronVencido = true;
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