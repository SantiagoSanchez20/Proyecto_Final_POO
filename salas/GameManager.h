
#pragma once
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

#include "Sala.h"
#include "Personaje.h"

class Player;
class Enemigo;
class Item;

class GameManager {
public:
    // Métodos de Flujo de Juego
    GameManager();
    ~GameManager();
    void iniciarJuego();

    // Métodos "Servicio
    void iniciarCombate(Player* jugador, Enemigo* enemigo, bool jugadorAtacaPrimero);
    void cambiarSala(const std::string& nombreSala);
    void transferirItemDeSalaAInventario(const std::string& nombreItem, Sala* sala, Player* jugador);
    void removePersonaje(const std::string& nombrePersonaje, Sala* sala);
    void terminarJuego(bool victoria);

    // Getters para que las salas obtengan info
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
                return stringToLower_local(p->nombre) == nombreLower;
            });
        if (it != sala->personajesEnSala.end()) {
            return dynamic_cast<T>(*it);
        }
        return nullptr;
    }

private:
    // Métodos Internos
    void buclePrincipal();
    void mostrarInfoSala();
    void poblarMundo();

    // Atributos de Estado del Juego
    Player* jugadorActual;
    Sala* salaActual;
    std::map<std::string, Sala*> mapaDelJuego;
    bool juegoActivo;
};