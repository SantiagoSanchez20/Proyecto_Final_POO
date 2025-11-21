#ifndef CLASE18POO_SALA_H
#define CLASE18POO_SALA_H
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
// #include "../Controller/GameManager.h" <--- ¡ELIMINADO para romper el ciclo!
#include "Inventario.h"
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
class Player;
class Personaje;
class Item;
class GameManager;

class Sala {
public:
    // Variables necesarias para que funcione el juego
    std::string descripcion;
    std::string nombre;
    std::map<std::string, std::string> salidas;
    std::vector<Personaje*> personajesEnSala;
    std::vector<Item*> itemsEnSala;

    virtual ~Sala() {}

    virtual void alEntrar(GameManager* game, Player* jugador) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << descripcion << std::endl;
    }

    virtual void manejarTurno(GameManager* game, Player* jugador);

protected:
    Sala(std::string _nombre, std::string _desc)
        : nombre(_nombre), descripcion(_desc) {}
    char presentarOpcionesYLeerInput(const std::vector<std::string>& opciones);
};

#endif //CLASE18POO_SALA_HCLASE18POO_SALA_H