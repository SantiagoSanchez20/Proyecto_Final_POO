#include "GameManager.h"
#include "../View/Consola.h"
#include "../Model/Arma.h"
#include "../Model/Sala.h"
#include "../Model/SalaInicio.h"
#include "../Model/SalaB1.h"
#include "../Model/SalaB2.h"
#include "../Model/SalaC1.h"
#include "../Model/SalaC2.h"
#include "../Model/SalaFinal.h"
#include "../Model/Player.h"
#include "../Model/Inventario.h"
#include "../Model/Pocion.h"
#include "../Model/Maelor.h"
#include "../Model/SoldadoCorrupto.h"
#include "../Model/GuardianPesado.h"
#include "../Model/EspadaDeBruma.h"
#include "../Model/DagaVelo.h"
#include "../Model/Ladron.h"
#include "../Model/Iria.h"
#include "../Model/GuardianDeLumen.h"
#include "../Model/Item.h"
#include "../Model/Enemigo.h"
#include "../Model/Personaje.h"
#include "../Model/CollectibleItem.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <cctype>

/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */



// Constructor
GameManager::GameManager() : jugadorActual(nullptr), salaActual(nullptr),
                             juegoActivo(true), idSalaAnterior("") {}

// Destructor
GameManager::~GameManager() {
    delete jugadorActual;
    for (auto const& [key, val] : mapaDelJuego) {
        delete val;
    }
    mapaDelJuego.clear();
}

void GameManager::iniciarJuego() {
    Consola::mostrarBienvenida();

    // 1. Crear al Jugador
    jugadorActual = new Player();
    Pocion* pocionInicial = new Pocion("Pocion de Vida Menor", "Cura 20 HP", 20);
    jugadorActual->inventario->agregarItem(pocionInicial);

    // 2. Crear todas las salas y enemigos
    poblarMundo();

    // 3. Ir a la sala de inicio
    salaActual = mapaDelJuego["S"];

    if (!salaActual) {
         std::cout << "[FATAL] Error: La Sala de Inicio (S) es nula. El mapa falló en poblarse." << std::endl;
         return;
    }

    salaActual->alEntrar(this, jugadorActual);

    // 4. Arrancar el bucle
    buclePrincipal();
}

void GameManager::poblarMundo() {
    // Sala S: Vestíbulo Quebrado
    mapaDelJuego["S"] = new SalaInicio();

    // Sala B1: Sala del Custodio
    Sala* b1 = new SalaB1();
    b1->personajesEnSala.push_back(new Maelor());
    b1->personajesEnSala.push_back(new SoldadoCorrupto());
    mapaDelJuego["B1"] = b1;

    // Sala B2: Sala de arma misteriosa
    Sala* b2 = new SalaB2();
    b2->itemsEnSala.push_back(new EspadaDeBruma());
    b2->personajesEnSala.push_back(new GuardianPesado());
    mapaDelJuego["B2"] = b2;

    // Sala C1: Cámara de las Reliquias
    Sala* c1 = new SalaC1();
    c1->itemsEnSala.push_back(new DagaVelo());
    mapaDelJuego["C1"] = c1;

    // Sala C2: Cámara del Acólito
    Sala* c2 = new SalaC2();
    c2->personajesEnSala.push_back(new Ladron());
    mapaDelJuego["C2"] = c2;

    // Sala E: Salón Central (Jefe)
    Sala* e = new SalaFinalE();
    e->personajesEnSala.push_back(new GuardianDeLumen());
    e->itemsEnSala.push_back(new CollectibleItem("Aureus", "Fruta de la inmortalidad."));
    mapaDelJuego["E"] = e;
}
// --- IMPLEMENTACIÓN DE FLUJO ---
void GameManager::buclePrincipal() {
    while (juegoActivo && jugadorActual->getHp() > 0) {
        // 1. Actualizar Buffs (Resta turnos y borra los vencidos)
        //  Hacerlo ANTES de mostrar para que no se vean buffs con "0 turnos".
        jugadorActual->actualizarBuff();

        // 2. Mostrar Información de la Sala (Narrativa)
        mostrarInfoSala();

        // 3. Mostrar HUD del Jugador (¡NUEVO!)
        mostrarEstadoJugador();

        // 4. Manejar las opciones de la sala
        salaActual->manejarTurno(this, jugadorActual);
    }

    if (!juegoActivo) {
        // Juego terminado manualmente o victoria
    } else if (jugadorActual->getHp() <= 0) {
        terminarJuego(false);
    }
}

void GameManager::mostrarInfoSala() {

    std::cout << "\n--- " << salaActual->nombre << " ---" << std::endl;
      std::cout << "Descripcion en la sala: " << std::endl;

    // Mostrar Personajes
    if (!salaActual->personajesEnSala.empty()) {
        std::cout << "Ves a: ";
        for (Personaje* p : salaActual->personajesEnSala) {
            std::cout << p->getNombre() << (dynamic_cast<Enemigo*>(p) ? " (Hostil)" : "") << ". ";
        }
        std::cout << std::endl;
    }

    // Mostrar Items
    if (!salaActual->itemsEnSala.empty()) {
        std::cout << "Objetos en el suelo: ";
        for (Item* i : salaActual->itemsEnSala) {
            std::cout << i->getNombre() << ". ";
        }
        std::cout << std::endl;
    }
}

void GameManager::cambiarSala(const std::string& nombreSala) {
    if (nombreSala == "SALIR") {
        std::cout << "Decides abandonar el castillo. Fin de la partida." << std::endl;
        terminarJuego(false);
        return;
    }

    if (mapaDelJuego.find(nombreSala) == mapaDelJuego.end()) {
        std::cout << "[ERROR] La sala '" << nombreSala << "' no existe en el mapa." << std::endl;
        return;
    }

    //
    if (salaActual != nullptr) {
        //Guardamos el nombre actual (ej: "B2") antes de irnos a la nueva
        this->idSalaAnterior = salaActual->nombre;
    }

    salaActual = mapaDelJuego[nombreSala];
    salaActual->alEntrar(this, jugadorActual);
}

void GameManager::terminarJuego(bool victoria) {
    juegoActivo = false;
    Consola::mostrarGameOver(victoria);
}


void GameManager::iniciarCombate(Player* jugador, Enemigo* enemigo, bool jugadorAtacaPrimero) {

    // Si no, usa tu cout manual:
    std::cout << "\n\n========= INICIO DE COMBATE ==========" << std::endl;
    std::cout << "¡Te enfrentas a: " << enemigo->getNombre() << " (HP: " << enemigo->getHp() << ")!" << std::endl;

    bool enCombate = true;
    bool turnoJugador = jugadorAtacaPrimero;

    while (enCombate) {
        // Chequeo de Muerte
        if (enemigo->getHp() <= 0 || jugador->getHp() <= 0) break;

        // 1. Actualizar buffs (IMPORTANTE: Solo una vez por ronda, aquí lo haces en cada turno, está bien)
        jugador->actualizarBuff(); // Ojo: Revisa si tu función se llama actualizarBuff o actualizarBuffs

        // --- Turnos ---
        if (turnoJugador) {
            // TURNO JUGADOR
            std::cout << "\n--- Tu Turno (HP: " << jugador->getHp() << ") ---" << std::endl;
            std::cout << "1. Atacar" << std::endl;
            std::cout << "2. Usar Item" << std::endl;
            std::cout << "> ";

            // --- CAMBIO AQUÍ: Usamos 'char' en vez de 'int' ---
            char opcion;
            std::cin >> opcion;

            // Limpiamos el buffer por si escribieron "1abc"
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Comparamos con el CARÁCTER '1', no el número 1
            if (opcion == '1') {
                jugador->atacar(enemigo);
            }
            else if (opcion == '2') {
                int indice = Consola::seleccionarItemInventario(*jugador->inventario);

                if (indice != -1) {
                    Item* item = jugador->inventario->obtenerItem(indice);
                    if (item) {
                        jugador->usarItem(item);
                        // Borrar si es consumible
                        if (dynamic_cast<Arma*>(item) == nullptr) {
                            jugador->inventario->removerItem(item);
                        }
                        // IMPORTANTE: Usar item consume turno, salimos del if/else
                    }
                } else {
                    std::cout << "Volviendo al menu de combate..." << std::endl;
                    continue; // Vuelve al inicio del while sin cambiar turno
                }
            } else {
                std::cout << "Opcion invalida. Escribe 1 o 2." << std::endl;
                continue; // Vuelve a preguntar sin que el enemigo ataque
            }
        } else {
            // TURNO ENEMIGO
            std::cout << "\n--- Turno de " << enemigo->getNombre() << " ---" << std::endl;
            enemigo->atacar(jugador);
        }

        // --- Chequeo de Muerte Post-Ataque ---
        if (enemigo->getHp() <= 0) {
            std::cout << "\n¡Has vencido a " << enemigo->getNombre() << "!" << std::endl;

            // Lógica especial de Iria/Ladron
            if (dynamic_cast<Ladron*>(enemigo)) {
                SalaC2* salaC2 = dynamic_cast<SalaC2*>(salaActual);
                if (salaC2 && !salaC2->iriaYaAparecio) {
                    std::cout << "Al derrotar al ladrón, un fantasma emerge..." << std::endl;
                    Iria* iria = new Iria();
                    salaActual->personajesEnSala.push_back(iria);
                    iria->interactuar(jugador);
                    salaC2->iriaYaAparecio = true;
                    salaC2->ladronVencido = true;
                }
            }

            // NO borres al enemigo aquí si quieres saquearlo después en SalaB2 (Guardia Pesado)
            // Pero para Maelor/Soldados está bien borrarlo.
            // removePersonaje(enemigo->getNombre(), salaActual);

            enCombate = false;
        }
        else if (jugador->getHp() <= 0) {
            std::cout << "\nHas sido derrotado..." << std::endl;
            enCombate = false;
        }

        turnoJugador = !turnoJugador; // Cambio de turno
    }
    std::cout << "========= FIN DEL COMBATE ==========\n" << std::endl;
}

// La función que Salas usan para eliminar personajes (Maelor, Enemigos)
void GameManager::removePersonaje(const std::string& nombrePersonaje, Sala* sala) {
    auto stringToLower_local = [](const std::string& str) {
        std::string lower = str;
        std::transform(lower.begin(), lower.end(), lower.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        return lower;
    };

    std::string targetName = stringToLower_local(nombrePersonaje);

    sala->personajesEnSala.erase(
        std::remove_if(sala->personajesEnSala.begin(), sala->personajesEnSala.end(),
            [&](Personaje* p) {
                if (stringToLower_local(p->getNombre()) == targetName) {
                    delete p;
                    return true;
                }
                return false;
            }),
        sala->personajesEnSala.end()
    );
}

// La función que Salas usan para dar items (Espada, Daga, Aureus)
void GameManager::transferirItemDeSalaAInventario(const std::string& nombreItem, Sala* sala, Player* jugador) {
    auto stringToLower_local = [](const std::string& str) {
        std::string lower = str;
        std::transform(lower.begin(), lower.end(), lower.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        return lower;
    };

    std::string targetName = stringToLower_local(nombreItem);

    auto it = std::find_if(sala->itemsEnSala.begin(), sala->itemsEnSala.end(),
        [&](Item* i) { return stringToLower_local(i->getNombre()) == targetName; });

    if (it != sala->itemsEnSala.end()) {
        jugador->inventario->agregarItem(*it);
        sala->itemsEnSala.erase(it);
        std::cout << "Has recogido: " << nombreItem << std::endl;
    } else {
        std::cout << "No ves ningun '" << nombreItem << "' aqui." << std::endl;
    }
}

void GameManager::gestionarInventario(Player* jugador) {
    bool gestionando = true;

    while (gestionando) {
        // 1. Usamos la función de la Consola que muestra lista y pide número
        int indice = Consola::seleccionarItemInventario(*jugador->inventario);

        // 2. Si devuelve -1, es que el usuario eligió "0. Cancelar"
        if (indice == -1) {
            gestionando = false; // Salimos del bucle
        }
        else {
            // 3. Obtenemos el objeto real
            Item* item = jugador->inventario->obtenerItem(indice);

            if (item) {
                // 4. ¡USAMOS EL OBJETO!
                // Si es Poción -> Cura.
                // Si es Arma -> Se equipa.
                jugador->usarItem(item);

                // 5. Lógica de borrado (Si es poción se gasta)
                if (dynamic_cast<Arma*>(item) == nullptr) {
                    jugador->inventario->removerItem(item);
                }

                std::cout << "(Presiona Enter para continuar)...";
                std::cin.get();
            }
        }
    }
}
// Al final de GameManager.cpp

void GameManager::mostrarEstadoJugador() {
    std::cout << "\n================ ESTADO DEL JUGADOR ================" << std::endl;

    // 1. MOSTRAR HP
    std::cout << " VIDA: " << jugadorActual->getHp() << " HP" << std::endl;

    // 2. MOSTRAR ATAQUE (Con desglose)
    int ataqueTotal = jugadorActual->getDanoAtaqueTotal();
    int ataqueBase = jugadorActual->ataqueBase;
    int bonoArma = 0;
    int bonoBuffs = 0;

    if (jugadorActual->getArmaEquipada() != nullptr) {
        bonoArma = jugadorActual->getArmaEquipada()->danioAdicional;
    }

    // Calculamos cuánto viene de buffs restando lo demás
    bonoBuffs = ataqueTotal - ataqueBase - bonoArma;

    std::cout << " ATAQUE: " << ataqueTotal;
    std::cout << " (Base: " << ataqueBase;
    if (bonoArma > 0) std::cout << " + Arma: " << bonoArma;
    if (bonoBuffs > 0) std::cout << " + Buffs: " << bonoBuffs;
    std::cout << ")" << std::endl;

    // 3. MOSTRAR BUFFS ACTIVOS
    if (!jugadorActual->buffsActivos.empty()) {
        std::cout << " ESTADOS (BUFFS):" << std::endl;
        for (const auto& buff : jugadorActual->buffsActivos) {
            std::cout << "   * " << buff.nombre
                      << " (Quedan " << buff.turnosRestantes << " turnos)" << std::endl;
        }
    }
    std::cout << "====================================================" << std::endl;
}