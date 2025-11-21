#include "SalaFinal.h"
#include "../Controller/GameManager.h"
#include "Player.h"
#include "Enemigo.h"

#include <iostream>


SalaFinalE::SalaFinalE() : Sala(
    "E",
    "Salon Central. Gran salon con un pedestal iluminado. La Aureus esta protegida por el Guardian de Lumen."
), jefeVencido(false), aureusRecogida(false)
{
}

void SalaFinalE::manejarTurno(GameManager* game, Player* jugador) {
    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    // Variables dinámicas para evitar errores de menú
    char letraAtacar = '\0';
    char letraTomar = '\0';
    char letraInventario = '\0';

    // --- 1. Opciones del Jefe / Aureus ---
    if (!jefeVencido) {
        opciones.push_back("Atacar al Guardian de Lumen");
        letraAtacar = opcionActual++;
    }
    else if (!aureusRecogida) {
        opciones.push_back("Tomar la Aureus");
        letraTomar = opcionActual++;
    }
    else {
        opciones.push_back("Has ganado. No hay nada mas que hacer.");
        // No guardamos letra porque esto es solo informativo antes de acabar
        opcionActual++;
    }

    // --- 2. Salidas (LÓGICA DINÁMICA DE CAMINO) ---

    // Verificamos de dónde vino el jugador para mostrar solo esa salida
    if (game->idSalaAnterior == "B2") {
        opciones.push_back("Devolverse de sala (a B2)");
        mapaSalidas[opcionActual] = "B2";
        opcionActual++;
    }
    else if (game->idSalaAnterior == "C2") {
        opciones.push_back("Devolverse de sala (a C2)");
        mapaSalidas[opcionActual] = "C2";
        opcionActual++;
    }
    else {
        // Caso de respaldo (si entraste directo o hubo un error)
        opciones.push_back("Devolverse de sala (a B2)");
        mapaSalidas[opcionActual] = "B2";
        opcionActual++;

        opciones.push_back("Devolverse de sala (a C2)");
        mapaSalidas[opcionActual] = "C2";
        opcionActual++;
    }

    // --- 3. Inventario (Esencial antes del jefe) ---
    opciones.push_back("Ver Inventario / Usar Items");
    letraInventario = opcionActual++;

    // --- 4. Leer Input ---
    char eleccion = presentarOpcionesYLeerInput(opciones);

    // --- 5. Procesar Lógica ---

    // CASO: Atacar al Jefe
    if (!jefeVencido && letraAtacar != '\0' && eleccion == letraAtacar) {
        Enemigo* jefe = game->findPersonaje<Enemigo*>("Guardian de Lumen", this);
        if (jefe) {
            std::cout << "\n¡El Guardian de Lumen despliega sus alas de energia!" << std::endl;
            std::cout << "¡LA BATALLA FINAL COMIENZA!" << std::endl;

            // Iniciar combate (true = jugador ataca primero por defecto, o false si prefieres dificultad)
            game->iniciarCombate(jugador, jefe, true);

            if (jefe->getHp() <= 0) {
                this->jefeVencido = true;
                std::cout << "\nCon un ultimo estruendo, la luz del Guardian se apaga." << std::endl;
                std::cout << "El camino hacia la Aureus esta libre." << std::endl;
            }
        }
        std::cout << "(Presiona Enter)..."; std::cin.get();
    }

    // CASO: Tomar la Aureus (Victoria)
    else if (jefeVencido && !aureusRecogida && letraTomar != '\0' && eleccion == letraTomar) {
        std::cout << "\nTe acercas al pedestal. La fruta dorada emite un calor reconfortante." << std::endl;
        std::cout << "Tomas la Aureus con tus manos..." << std::endl;

        game->transferirItemDeSalaAInventario("Aureus", this, jugador);
        this->aureusRecogida = true;

        // Fin del juego con victoria
        game->terminarJuego(true);
    }

    // CASO: Salidas (Regresar)
    else if (mapaSalidas.count(eleccion)) {
        game->cambiarSala(mapaSalidas[eleccion]);
    }

    // CASO: Inventario
    else if (eleccion == letraInventario) {
        game->gestionarInventario(jugador);
    }

    else {
        std::cout << "Opcion no valida." << std::endl;
    }
}