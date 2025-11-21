#ifndef CLASE18POO_GAMEMANAGER_H
#define CLASE18POO_GAMEMANAGER_H
#pragma once

#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

// --- INCLUDES CLAVE PARA LA DEFINICIÓN DE TIPOS ---
// 1. Definición completa de Sala
#include "../Model/Sala.h"
// 2. Definición completa de Personaje (para getNombre())
#include "../Model/Personaje.h"


// Declaraciones de clases base que aún no se han incluido completamente
class Player;
class Enemigo;
class Item;

class GameManager {
public:
    //Para saber en que sala.
    std::string idSalaAnterior;

    //para que este el inventario en cada sala
    void gestionarInventario(Player* jugador);

    // --- Métodos de Flujo de Juego ---
    GameManager();
    ~GameManager();
    void iniciarJuego();




    // --- Métodos "Servicio" ---
    void iniciarCombate(Player* jugador, Enemigo* enemigo, bool jugadorAtacaPrimero);
    void cambiarSala(const std::string& nombreSala);
    void transferirItemDeSalaAInventario(const std::string& nombreItem, Sala* sala, Player* jugador);
    void removePersonaje(const std::string& nombrePersonaje, Sala* sala);
    void terminarJuego(bool victoria);

    // --- Getters ---
    Player* getJugador() { return jugadorActual; }

    template<typename T>
    T findPersonaje(const std::string& nombre, Sala* sala) {

        auto stringToLower_local = [](const std::string& str) {
            std::string lower = str;
            std::transform(lower.begin(), lower.end(), lower.begin(),
                           [](unsigned char c){ return std::tolower(c); });
            return lower;
        };

        std::string nombreLower = stringToLower_local(nombre);

        auto it = std::find_if(sala->personajesEnSala.begin(), sala->personajesEnSala.end(),
            [&](Personaje* p) {
                return stringToLower_local(p->getNombre()) == nombreLower;
            });

        if (it != sala->personajesEnSala.end()) {
            return dynamic_cast<T>(*it);
        }
        return nullptr;
    }

private:
    void buclePrincipal();
    void mostrarInfoSala();
    void poblarMundo();
    void mostrarEstadoJugador();
    Player* jugadorActual;
    Sala* salaActual;
    std::map<std::string, Sala*> mapaDelJuego;
    bool juegoActivo;
};

#endif //CLASE18POO_GAMEMANAGER_H