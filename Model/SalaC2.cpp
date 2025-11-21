#include "SalaC2.h"
#include "../Controller/GameManager.h"
#include "Player.h"
#include "Ladron.h"
#include "Enemigo.h" // Necesario para findPersonaje
#include <iostream>
#include <limits>
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
SalaC2::SalaC2() : Sala(
    "C2",
    "Camara del Acolito. Un ladron esta saqueando un cuerpo."
), ladronVencido(false), iriaYaAparecio(false)
{
}

void SalaC2::manejarTurno(GameManager* game, Player* jugador) {
    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    // Variables dinámicas
    char letraHablar = '\0';
    char letraAtacar = '\0';
    char letraAvanzar = '\0';
    char letraRegresar = '\0';
    char letraInventario = '\0';
    char letraSalir = '\0';

    // --- 1. Construcción del Menú ---

    if (!ladronVencido) {
        opciones.push_back("Hablar con la persona");
        letraHablar = opcionActual++;

        opciones.push_back("Atacar a la persona");
        letraAtacar = opcionActual++;
    }

    // Salidas
    opciones.push_back("Avanzar (a E)");
    letraAvanzar = opcionActual++;

    opciones.push_back("Devolverse de sala (a C1)");
    letraRegresar = opcionActual++; // La guardamos manual o en mapa
    mapaSalidas[letraRegresar] = "C1";

    // Inventario y Salir
    opciones.push_back("Ver Inventario / Usar Items");
    letraInventario = opcionActual++;

    opciones.push_back("Salir del Juego");
    letraSalir = opcionActual++;

    // --- 2. Leer Input ---
    char eleccion = presentarOpcionesYLeerInput(opciones);

    // --- 3. Lógica ---

    Enemigo* ladron = game->findPersonaje<Enemigo*>("Ladron", this);

    // CASO: Hablar (El ladrón es hostil, así que ataca)
    if (!ladronVencido && letraHablar != '\0' && eleccion == letraHablar) {
        if (ladron) {
            std::cout << "\nIntentas dialogar..." << std::endl;
            std::cout << "[Ladron] ¡Atras! ¡Este botin es mio!" << std::endl;
            std::cout << "El ladron te mira con hostilidad. ¡Te ataca!" << std::endl;

            // false = Enemigo ataca primero
            game->iniciarCombate(jugador, ladron, false);

            if(ladron->getHp() <= 0) this->ladronVencido = true;
        }
        std::cout << "(Presiona Enter)..."; std::cin.get();
    }

    // CASO: Atacar (Tú tienes la iniciativa)
    else if (!ladronVencido && letraAtacar != '\0' && eleccion == letraAtacar) {
        if (ladron) {
            std::cout << "\n¡Atacas al ladron antes de que reaccione!" << std::endl;

            // true = Jugador ataca primero
            game->iniciarCombate(jugador, ladron, true);

            if(ladron->getHp() <= 0) this->ladronVencido = true;
        }
        std::cout << "(Presiona Enter)..."; std::cin.get();
    }

    // CASO: Avanzar (AQUÍ ESTÁ EL CAMBIO QUE PEDISTE)
    else if (eleccion == letraAvanzar) {
        if (!ladronVencido) {
            // --- BLOQUEO Y COMBATE FORZADO ---
            std::cout << "\nIntentas pasar de largo hacia el Salon Central..." << std::endl;
            std::cout << "¡El Ladron salta frente a ti cortandote el paso!" << std::endl;
            std::cout << "[Ladron] ¿Crees que puedes ignorarme? ¡Paga el peaje con tu vida!" << std::endl;

            if (ladron) {
                // false = Enemigo ataca primero porque te interceptó
                game->iniciarCombate(jugador, ladron, false);

                if (ladron->getHp() <= 0) {
                    this->ladronVencido = true;
                    std::cout << "\nCon el ladron fuera de combate, el camino esta libre." << std::endl;
                }
            }
            std::cout << "(Presiona Enter)..."; std::cin.get();
            // No cambiamos de sala automáticamente para que el jugador lea el resultado
        }
        else {
            // Si ya está vencido, pasamos
            game->cambiarSala("E");
        }
    }

    // CASO: Regresar
    else if (mapaSalidas.count(eleccion)) {
        game->cambiarSala(mapaSalidas[eleccion]);
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