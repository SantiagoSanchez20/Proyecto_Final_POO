#include "SalaB2.h"
#include "../Controller/GameManager.h"
#include "Player.h"
#include "Enemigo.h"
#include <iostream>
#include <limits>

SalaB2::SalaB2() : Sala(
    "B2",
    "Sala de arma misteriosa. Taller con yunques. Una espada nueva esta clavada en un bloque."
), jugadorYaObservo(false), espadaRecogida(false), guardiaVencido(false)
{
}

void SalaB2::manejarTurno(GameManager* game, Player* jugador) {

    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    // Variables para letras dinámicas
    char letraObservar = '\0';
    char letraSacarEspada = '\0';
    char letraTomarEspada = '\0';

    // --- 1. Construcción del Menú ---

    if (!guardiaVencido) {
        // Si el guardia sigue vivo...
        opciones.push_back("Observar la sala con atencion");
        letraObservar = opcionActual++;

        opciones.push_back("Intentar sacar la espada del bloque");
        letraSacarEspada = opcionActual++;
    }
    else if (!espadaRecogida) {
        // Si el guardia murió pero no tenemos la espada...
        opciones.push_back("Tomar la Espada de Bruma");
        letraTomarEspada = opcionActual++;
    }

    // Salidas
    opciones.push_back("Avanzar hacia el Salon Central (a E)");
    char letraAvanzar = opcionActual; // No la metemos al mapa automático para validar lógica si quieres
    mapaSalidas[letraAvanzar] = "E";
    opcionActual++;

    opciones.push_back("Regresar (a B1)");
    mapaSalidas[opcionActual] = "B1";
    opcionActual++;

    // --- 2. Leer Input ---
    char eleccion = presentarOpcionesYLeerInput(opciones);

    // --- 3. Lógica ---

    // CASO A: Observar (Esto te da la ventaja)
    if (!guardiaVencido && letraObservar != '\0' && eleccion == letraObservar) {
        std::cout << "\nTe tomas un momento para estudiar las sombras..." << std::endl;
        std::cout << "¡Lo ves! Hay un Guardia Pesado camuflado justo al lado del bloque." << std::endl;
        std::cout << "(Ahora sabes donde esta. Si atacas, tendras la ventaja)." << std::endl;

        this->jugadorYaObservo = true; // <--- ¡AQUÍ ACTIVAMOS LA VENTAJA!

        std::cout << "(Presiona Enter)..."; std::cin.get();
    }

    // CASO B: Sacar Espada (Inicia Combate)
    else if (!guardiaVencido && letraSacarEspada != '\0' && eleccion == letraSacarEspada) {
        Enemigo* guardia = game->findPersonaje<Enemigo*>("Guardian Pesado", this);

        if (guardia) {
            // LÓGICA DE INICIATIVA
            if (this->jugadorYaObservo) {
                // ESCENARIO 1: El jugador observó antes
                std::cout << "\nTe acercas a la espada, pero giras rapidamente hacia la sombra..." << std::endl;
                std::cout << "¡Sorprendes al Guardia Pesado antes de que pueda emboscarte!" << std::endl;
                std::cout << "--- TIENES LA INICIATIVA (ATACAS PRIMERO) ---" << std::endl;

                // true = Jugador Ataca Primero
                game->iniciarCombate(jugador, guardia, true);
            }
            else {
                // ESCENARIO 2: El jugador fue imprudente
                std::cout << "\nAgarras el mango de la espada..." << std::endl;
                std::cout << "¡CUIDADO! Un guantelete de metal te golpea desde las sombras." << std::endl;
                std::cout << "¡Es una emboscada del Guardia Pesado!" << std::endl;
                std::cout << "--- EL ENEMIGO TIENE LA INICIATIVA ---" << std::endl;

                // false = Jugador NO ataca primero (Enemigo ataca)
                game->iniciarCombate(jugador, guardia, false);
            }

            // Verificar si ganamos
            if (guardia->getHp() <= 0) {
                this->guardiaVencido = true;
                std::cout << "\nEl guardia cae con un estruendo metalico." << std::endl;
                std::cout << "Ahora puedes tomar la espada sin peligro." << std::endl;
            }
        } else {
            std::cout << "Extraño... sentías una presencia pero no hay nadie." << std::endl;
        }
        std::cout << "(Presiona Enter)..."; std::cin.get();
    }

    // CASO: Tomar Espada (Post-Combate)
    else if (guardiaVencido && !espadaRecogida && eleccion == letraTomarEspada) {
        game->transferirItemDeSalaAInventario("Espada de Bruma", this, jugador);
        this->espadaRecogida = true;
        std::cout << "(Presiona Enter)..."; std::cin.get();
    }

    // CASO: Salidas
    else if (mapaSalidas.count(eleccion)) {
        game->cambiarSala(mapaSalidas[eleccion]);
    }
    else {
        std::cout << "Opcion no valida." << std::endl;
    }
}