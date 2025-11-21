
#include "SalaFinal.h"
#include "../Controller/GameManager.h"
#include "Player.h"
#include "Enemigo.h"
#include <iostream>
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
// --- Constructor ---
// Inicializa la sala final "E".
// Los flags empiezan en false: el jefe está vivo y la fruta aun no ha sido recogida.
SalaFinalE::SalaFinalE() : Sala(
    "E",
    "Salon Central. Gran salon con un pedestal iluminado. La Aureus esta protegida por el Guardian de Lumen."
), jefeVencido(false), aureusRecogida(false)
{
}

// --- Función Principal del Turno ---
void SalaFinalE::manejarTurno(GameManager* game, Player* jugador) {
    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    // --- Variables dinámicas ---
    // Necesarias porque el menú cambia drásticamente (Pelear -> Agarrar -> Ganar)
    char letraAtacar = '\0';
    char letraTomar = '\0';
    char letraInventario = '\0';

    // --- 1. Opciones del Jefe / Aureus ---

    // FASE 1: El Jefe está vivo
    if (!jefeVencido) {
        opciones.push_back("Atacar al Guardian de Lumen");
        letraAtacar = opcionActual++; // Guardamos la letra (ej: 'a')
    }
    // FASE 2: Jefe muerto, pero aun no tomamos el premio
    else if (!aureusRecogida) {
        opciones.push_back("Tomar la Aureus");
        letraTomar = opcionActual++; // Guardamos la letra (ej: 'a')
    }
    // FASE 3: Ya ganamos (texto informativo)
    else {
        opciones.push_back("Has ganado. No hay nada mas que hacer.");
        // No guardamos letra porque esto es solo informativo antes de acabar el turno
        opcionActual++;
    }

    // --- 2. Salidas (LÓGICA DINÁMICA DE CAMINO) ---
    // Aquí verificamos de qué sala vino el jugador para solo dejarlo volver por ahí.

    // Caso A: Vino por el camino del Guerrero (B2)
    if (game->idSalaAnterior == "B2") {
        opciones.push_back("Devolverse de sala (a B2)");
        mapaSalidas[opcionActual] = "B2";
        opcionActual++;
    }
    // Caso B: Vino por el camino del Pícaro (C2)
    else if (game->idSalaAnterior == "C2") {
        opciones.push_back("Devolverse de sala (a C2)");
        mapaSalidas[opcionActual] = "C2";
        opcionActual++;
    }
    // Caso C: Respaldo (Por si hubo un error o teletransporte, mostramos ambas)
    else {
        opciones.push_back("Devolverse de sala (a B2)");
        mapaSalidas[opcionActual] = "B2";
        opcionActual++;

        opciones.push_back("Devolverse de sala (a C2)");
        mapaSalidas[opcionActual] = "C2";
        opcionActual++;
    }

    // --- 3. Inventario (Esencial antes del jefe) ---
    // Permitimos al jugador curarse o equipar armas antes de pelear
    opciones.push_back("Ver Inventario / Usar Items");
    letraInventario = opcionActual++;

    // --- 4. Leer Input ---
    char eleccion = presentarOpcionesYLeerInput(opciones);

    // --- 5. Procesar Lógica ---

    // CASO: Atacar al Jefe
    if (!jefeVencido && letraAtacar != '\0' && eleccion == letraAtacar) {
        // Buscamos al jefe en la lista de personajes de la sala
        Enemigo* jefe = game->findPersonaje<Enemigo*>("Guardian de Lumen", this);

        if (jefe) {
            std::cout << "\n¡El Guardian de Lumen despliega sus alas de energia!" << std::endl;
            std::cout << "¡LA BATALLA FINAL COMIENZA!" << std::endl;

            // Iniciar combate (true = jugador ataca primero por defecto)
            game->iniciarCombate(jugador, jefe, true);

            // Si ganamos el combate
            if (jefe->getHp() <= 0) {
                this->jefeVencido = true; // Cambiamos a Fase 2
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

        // Pasamos el item al inventario (simbólico)
        game->transferirItemDeSalaAInventario("Aureus", this, jugador);
        this->aureusRecogida = true;

        // Terminamos el juego con Victoria (true)
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

    // Caso Default
    else {
        std::cout << "Opcion no valida." << std::endl;
    }
}