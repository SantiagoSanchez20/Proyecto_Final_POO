
#ifndef CLASE18POO_SALA_H
#define CLASE18POO_SALA_H
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "../Controller/GameManager.h"

class Player;
class Personaje;
class Item;
class GameManager;

class Sala {
public:

    virtual ~Sala() {}

    virtual void alEntrar(GameManager* game, Player* jugador) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << descripcion << std::endl;
    }

    //Muestra las opciones (A, B, C...) específicas de esta sala.
    //Muestra las salidas genéricas (D, E...).
    //Lee el input del usuario (un 'char').
    //Ejecuta la lógica para esa opción (llama a game->iniciarCombate, etc.).

    virtual void manejarTurno(GameManager* game, Player* jugador);

protected:
    std::string descripcion;
    std::string nombre;
    Sala(std::string _nombre, std::string _desc)
        : nombre(_nombre), descripcion(_desc) {}
    char presentarOpcionesYLeerInput(const std::vector<std::string>& opciones);
};

#endif //CLASE18POO_SALA_H