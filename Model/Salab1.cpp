#include "SalaB1.h"
#include "../Controller/GameManager.h"
#include "Player.h"
#include "Maelor.h"
#include "SoldadoCorrupto.h"
#include <iostream>
#include <limits>

SalaB1::SalaB1() : Sala(
    "B1",
    "Sala del Custodio. Un anciano monje - Maelor - bloquea el camino."
), maelorYaInterpenso(false), maelorAtacado(false)
{
}

void SalaB1::manejarTurno(GameManager* game, Player* jugador) {

    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    // Variables para guardar las letras dinámicas
    char letraHablar = '\0';
    char letraRodear = '\0';
    char letraAtacar = '\0';
    char letraAvanzar = '\0';

    // --- NUEVA VARIABLE PARA EL INVENTARIO ---
    char letraInventario = '\0';

    // --- 1. Construcción del Menú ---

    if (!maelorAtacado) {
        if (!maelorYaInterpenso) {
            // Caso 1: No hemos resuelto nada
            opciones.push_back("Hablar con Maelor (Adivinanza)");
            letraHablar = opcionActual++;

            opciones.push_back("Rodear a Maelor (Intentar escabullirse)");
            letraRodear = opcionActual++;

            opciones.push_back("Atacar a Maelor");
            letraAtacar = opcionActual++;
        } else {
            // Caso 2: Ya resolvimos
            opciones.push_back("Hablar de nuevo con Maelor");
            letraHablar = opcionActual++;
        }
    }

    // Salidas
    opciones.push_back("Avanzar hacia la Puerta del Fondo (a B2)");
    letraAvanzar = opcionActual++;

    opciones.push_back("Regresar al Vestibulo (a S)");
    mapaSalidas[opcionActual] = "S";
    opcionActual++;

    // --- AGREGAMOS LA OPCIÓN DE INVENTARIO AQUÍ ---
    opciones.push_back("Ver Inventario / Usar Items");
    letraInventario = opcionActual++; // Guardamos la letra que le toque

    // --- 2. Leer Input ---
    char eleccion = presentarOpcionesYLeerInput(opciones);

    // --- 3. Lógica ---

    // CASO: Hablar (A)
    if (!maelorAtacado && letraHablar != '\0' && eleccion == letraHablar) {
        Maelor* m = game->findPersonaje<Maelor*>("Maelor", this);
        if (m) {
            if (!maelorYaInterpenso) {
                bool resuelto = m->iniciarAdivinanza(jugador);
                if (resuelto) {
                    this->maelorYaInterpenso = true;
                    std::cout << "\n[Maelor] Puedes pasar, viajero." << std::endl;
                }
            } else {
                std::cout << "Maelor te sonrie. 'Ve con cuidado'." << std::endl;
            }
        }
        std::cout << "(Presiona Enter)..."; std::cin.get();
    }

    // CASO: Rodear (B)
    else if (!maelorAtacado && letraRodear != '\0' && eleccion == letraRodear) {
        Maelor* m = game->findPersonaje<Maelor*>("Maelor", this);
        if (m) {
            std::cout << "\nIntentas moverte sigilosamente hacia el lado derecho..." << std::endl;
            std::cout << "¡Maelor golpea el suelo con su baston!" << std::endl;
            std::cout << "[Maelor] No puedes pasar sin demostrar tu valia." << std::endl;
            std::cout << "(No lograste rodearlo. Vuelves a tu posición inicial)." << std::endl;
        }
        std::cout << "(Presiona Enter)..."; std::cin.get();
    }

    // CASO: Atacar (C)
    else if (!maelorAtacado && letraAtacar != '\0' && eleccion == letraAtacar) {
        std::cout << "¡Decides atacar al anciano! Maelor desaparece..." << std::endl;
        this->maelorAtacado = true;
        game->removePersonaje("Maelor", this);

        std::cout << "\n¡Un Soldado Corrupto salta de las sombras!" << std::endl;
        Enemigo* guardia = new SoldadoCorrupto();
        this->personajesEnSala.push_back(guardia);

        game->iniciarCombate(jugador, guardia, true);

        if (jugador->estaVivo()) {
            std::cout << "\nEl guardia ha caído. El camino está despejado." << std::endl;
        }
        std::cout << "(Presiona Enter)..."; std::cin.get();
    }

    // CASO: Avanzar
    else if (eleccion == letraAvanzar) {
        if (!maelorAtacado && !maelorYaInterpenso) {
            std::cout << "\n[BLOQUEADO] Maelor te cierra el paso." << std::endl;
            std::cout << "(Presiona Enter)..."; std::cin.get();
        }
        else {
            game->cambiarSala("B2");
        }
    }

    // CASO: Regresar
    else if (mapaSalidas.count(eleccion)) {
        game->cambiarSala(mapaSalidas[eleccion]);
    }

    // --- CASO: INVENTARIO
    else if (eleccion == letraInventario) {
        game->gestionarInventario(jugador);
    }

    else {
        std::cout << "Opcion no valida." << std::endl;
    }
}